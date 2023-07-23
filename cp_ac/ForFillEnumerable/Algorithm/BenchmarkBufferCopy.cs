using BenchmarkDotNet.Attributes;
public class BenchmarkBufferCopy
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
    [Benchmark(Description = "BufferCopy")]
    public void Algorithm()
    {
        // execute code setup first. ( the same of method Setup ) .
        int[] a = new int[1];
        // now execute the algorithm.
        MemSetBlockX2(data, 1);
    }

    static void MemSetBlockX2(int[] array, int value)
    {
        int block = 32;
        int index = 0;
        int length = Math.Min(block, array.Length);

        //Fill the initial array
        while (index < length)
        {
            array[index++] = value;
        }

        length = array.Length;
        while (index < length)
        {
            int actualBlockSize = Math.Min(block, length - index);
            Buffer.BlockCopy(array, 0, array, index << 2, actualBlockSize << 2);
            index += block;
            block *= 2;
        }
    }
}