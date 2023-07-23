using BenchmarkDotNet.Columns;
using BenchmarkDotNet.Configs;
using BenchmarkDotNet.Diagnosers;
using BenchmarkDotNet.Exporters.Csv;
using BenchmarkDotNet.Reports;

namespace MyBenchMarks;

public class MyConfig : ManualConfig
{
    public MyConfig(Func<double, double> timeComplexity , Func<double, double> memoryComplexity)
    {
        this.AddLogger(DefaultConfig.Instance.GetLoggers().ToArray());
        this.AddColumnProvider(DefaultConfig.Instance.GetColumnProviders().ToArray());
        SummaryStyle summary =  new SummaryStyle(
            cultureInfo: System.Globalization.CultureInfo.CurrentCulture,
            printUnitsInHeader: false,
            printUnitsInContent: false,
            timeUnit: Perfolizer.Horology.TimeUnit.Nanosecond,
            sizeUnit: SizeUnit.B);
        this.SummaryStyle = summary;
        this.AddExporter(new CsvExporter(CsvSeparator.CurrentCulture, this.SummaryStyle));
        this.AddColumn(new Complexity_Column("Time_Complexity", timeComplexity));
        this.AddColumn(new Complexity_Column("Memory_Complexity", memoryComplexity));
        this.AddDiagnoser(new MemoryDiagnoser(new MemoryDiagnoserConfig()));
    }
}