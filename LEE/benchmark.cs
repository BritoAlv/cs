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
    public Random rnd = new Random();
    public int start_row;
    public int start_column;
    public bool[,] prohibidas;
    [Params(10,100,1000,10000)]
    public int cant_columns { get; set; }
    [Params(10,100,1000,10000)]
    public int cant_rows { get; set; }
    [GlobalSetup]
    public void Setup()
    {
        start_row = rnd.Next(cant_rows);
        start_column = rnd.Next(cant_columns);
        prohibidas = new bool[cant_rows, cant_columns];
        for (int i = 0; i < cant_rows; i++)
        {
            for (int j = 0; j < cant_columns; j++)
            {
                prohibidas[i, j] = (rnd.NextDouble() > 0.5); // 0.8 para reducir la probabilidad de casillas prohibidas.
            }
        }

    }
    [Benchmark]
    public void lee_1() => Lee.lee(prohibidas, start_row, start_column);
}
