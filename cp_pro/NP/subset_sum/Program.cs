using BenchmarkDotNet.Attributes;
using BenchmarkDotNet.Columns;
using BenchmarkDotNet.Configs;
using BenchmarkDotNet.Exporters.Csv;
using BenchmarkDotNet.Reports;
using BenchmarkDotNet.Running;

public class config : ManualConfig
{
    public CsvExporter exporter = new CsvExporter(
    CsvSeparator.CurrentCulture,
    new SummaryStyle(
        cultureInfo: System.Globalization.CultureInfo.CurrentCulture,
        printUnitsInHeader: true,
        printUnitsInContent: false,
        timeUnit: Perfolizer.Horology.TimeUnit.Microsecond,
        sizeUnit: SizeUnit.B
    ));
    public config()
    {
        AddExporter(exporter);
    }
}

[Config(typeof(config))]
[MemoryDiagnoser]
public class benchmark
{
    public int[] set;
    [Params(5, 6, 7, 8, 9)]
    public int size { get; set; }
    public int k;
    public bool[] mask;
    [GlobalSetup]
    public void Setup()
    {
        set = random_utils.generate_array(size);
        Random a = new Random();
        k = size * 1000 + 1;
        mask = new bool[size];
    }

    [Benchmark]
    public bool with_list() => SubsetSum.WithList(set, k, 0, new List<int>(set.Length));
    [Benchmark]
    public bool with_mask() => SubsetSum.WithMask(set, k, 0, mask);
    [Benchmark]
    public bool with_counter() => SubsetSum.WithCounter(set, k, 0, 0);
    [Benchmark]
    public bool without_extra_params() => SubsetSum.WithoutExtraParam(set, k, 0);
}
public static class program
{
    public static void Main()
    {
        BenchmarkRunner.Run<benchmark>();
    }
}

