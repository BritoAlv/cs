using BenchmarkDotNet.Columns;
using BenchmarkDotNet.Reports;
using BenchmarkDotNet.Running;
public class Complexity_Column : IColumn
{
    public Complexity_Column(string name, Func<double, double> complexity)
    {
        Id = name;
        Complexity = complexity;
        ColumnName = name;
    }
    public string Id { get; }
    public Func<double, double> Complexity { get; }
    public string ColumnName { get; }
    public bool AlwaysShow => true;

    public ColumnCategory Category => ColumnCategory.Statistics;

    public int PriorityInCategory => 1000;

    public bool IsNumeric => true;

    public UnitType UnitType => UnitType.Dimensionless;

    public string Legend => Id;

    public string GetValue(Summary summary, BenchmarkCase benchmarkCase)
    {
        double size = GetValueById(summary, benchmarkCase, "ParamColumn.N");
        if (Id.StartsWith("Time"))
        {
            double average = GetValueById(summary, benchmarkCase, "StatisticColumn.Mean");
            return (average / Complexity(size)).ToString();
        }
        else
        {
            double memory = GetValueById(summary, benchmarkCase, "Allocated Memory");
            return (memory / Complexity(size)).ToString();
        }
    }

    private static double GetValueById(Summary summary, BenchmarkCase benchmarkCase, string id)
    {
        var result = summary.GetColumns().First(x => x.Id == id).GetValue(summary, benchmarkCase);
        return ParseDouble(result, summary.Style.TimeUnit, summary.Style.SizeUnit);
    }

    public string GetValue(Summary summary, BenchmarkCase benchmarkCase, SummaryStyle style)
    {
        return GetValue(summary, benchmarkCase);
    }
    private static double ParseDouble(string value, Perfolizer.Horology.TimeUnit unit_time, BenchmarkDotNet.Columns.SizeUnit unit_memory)
    {
        value = value.Replace(",", "");
        string first_part = "";
        string second_part = "";
        int i = 0;
        while (i < value.Length && char.IsDigit(value[i]))
        {
            first_part = first_part + value[i];
            i++;
        }
        i++;
        while (i < value.Length && char.IsDigit(value[i]))
        {
            second_part = second_part + value[i];
            i++;
        }
        var first = first_part == "" ? 0 : int.Parse(first_part);
        var second = second_part == "" ? 0 : int.Parse(second_part);
        var abs_value = first + Math.Pow(10, -second_part.Length) * second;
        return ConvertToUnit(value, abs_value, unit_time, unit_memory);
    }
    public bool IsAvailable(Summary summary)
    {
        return true;
    }

    public bool IsDefault(Summary summary, BenchmarkCase benchmarkCase)
    {
        return true;
    }
    private static double ConvertToUnit(string value, double abs_value, Perfolizer.Horology.TimeUnit unit_time, BenchmarkDotNet.Columns.SizeUnit unit_memory)
    {
        if (unit_time == Perfolizer.Horology.TimeUnit.Nanosecond)
        {

            if (value.EndsWith("ns")) // nanosecond
            {
                abs_value = abs_value * Math.Pow(10, 0);
            }
            else if (value.EndsWith("us") || value.EndsWith("μs")) // microsecond
            {
                abs_value = abs_value * Math.Pow(10, 3);
            }
            else if (value.EndsWith("ms")) // millisecond
            {
                abs_value = abs_value * Math.Pow(10, 6);
            }
            else if (value.EndsWith("s")) // second.
            {
                abs_value = abs_value * Math.Pow(10, 9);
            }
        }

        if (unit_time == Perfolizer.Horology.TimeUnit.Microsecond)
        {

            if (value.EndsWith("ns")) // nanosecond
            {
                abs_value = abs_value * Math.Pow(10, -3);
            }
            else if (value.EndsWith("us") || value.EndsWith("μs")) // microsecond
            {
                abs_value = abs_value * Math.Pow(10, 0);
            }
            else if (value.EndsWith("ms")) // millisecond
            {
                abs_value = abs_value * Math.Pow(10, 3);
            }
            else if (value.EndsWith("s")) // second.
            {
                abs_value = abs_value * Math.Pow(10, 6);
            }
        }

        if (unit_time == Perfolizer.Horology.TimeUnit.Millisecond)
        {

            if (value.EndsWith("ns")) // nanosecond
            {
                abs_value = abs_value * Math.Pow(10, -6);
            }
            else if (value.EndsWith("us") || value.EndsWith("μs")) // microsecond
            {
                abs_value = abs_value * Math.Pow(10, -3);
            }
            else if (value.EndsWith("ms")) // millisecond
            {
                abs_value = abs_value * Math.Pow(10, 0);
            }
            else if (value.EndsWith("s")) // second.
            {
                abs_value = abs_value * Math.Pow(10, 3);
            }
        }


        if (unit_memory == BenchmarkDotNet.Columns.SizeUnit.B)
        {
            if (value.EndsWith("GB"))
            {
                abs_value = abs_value * Math.Pow(10, 9);
            }
            else if (value.EndsWith("MB"))
            {
                abs_value = abs_value * Math.Pow(10, 6);
            }
            else if (value.EndsWith("KB"))
            {
                abs_value = abs_value * Math.Pow(10, 3);
            }
            else if (value.EndsWith("B"))
            {
                abs_value = abs_value * Math.Pow(10, 0);
            }
        }

        if (unit_memory == BenchmarkDotNet.Columns.SizeUnit.KB)
        {
            if (value.EndsWith("GB"))
            {
                abs_value = abs_value * Math.Pow(10, 6);
            }
            else if (value.EndsWith("MB"))
            {
                abs_value = abs_value * Math.Pow(10, 3);
            }
            else if (value.EndsWith("KB"))
            {
                abs_value = abs_value * Math.Pow(10, 0);
            }
            else if (value.EndsWith("B"))
            {
                abs_value = abs_value * Math.Pow(10, -3);
            }
        }
        return abs_value;
    }
}