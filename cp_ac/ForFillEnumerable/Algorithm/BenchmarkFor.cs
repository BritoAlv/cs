using BenchmarkDotNet.Attributes;
public class BenchmarkFor
{
    private int[] data;   
    [Params(1000, 10000, 20000, 30000, 100000, 200000, 300000, 400000, 500000)]
    public int N;

    [GlobalSetup]
    public void MakeSetup()
    {
        // maybe you need an ***INITIAL*** setup.
        data = new int[N];
    }

    [Benchmark(Description = "Setup")] // do not change this name
    public void Setup()
    {
        // there is nothing to do so ...
        int[] a = new int[1]; // avoiding time be NA or something like that.
    }
    [Benchmark(Description = "For")]
    public void Algorithm()
    {
        // execute code setup first. ( the same of method Setup ) .
        int[] a = new int[1];

        // now execute the algorithm.
        for (int i = 0; i < data.Length; i++)
        {
            data[i] = 1;
        }
    }
}