using BenchmarkDotNet.Attributes;
public class BenchmarkCopyX2
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
    [Benchmark(Description = "CopyX2")]
    public void Algorithm()
    {
        // execute code setup first. ( the same of method Setup ) .
        int[] a = new int[1];

        // now execute the algorithm.
        Memset<int>(data, 1);
    }

    public static void Memset<T>(T[] array, T elem)
    {
        int length = array.Length;
        array[0] = elem;
        int count;
        for (count = 1; count <= length / 2; count *= 2)
            Array.Copy(array, 0, array, count, count);
        Array.Copy(array, 0, array, count, length - count);
    }
}
