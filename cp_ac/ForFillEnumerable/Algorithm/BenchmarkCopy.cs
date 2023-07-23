using BenchmarkDotNet.Attributes;
public class BenchmarkCopy
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
    [Benchmark(Description = "CopyConsecutive")]
    public void Algorithm()
    {
        // execute code setup first. ( the same of method Setup ) .
        int[] a = new int[1];
        // now execute the algorithm.

        int BLOCK_SIZE = 256;
        if (data.Length < 2 * BLOCK_SIZE)
        {
            for (int i = 0; i < data.Length; i++)
            {
                data[i] = 1;
            }
        }
        else
        {
            int fullBlocks = data.Length / BLOCK_SIZE;
            // Initialize first block
            for (int j = 0; j < BLOCK_SIZE; j++) data[j] = 1;
            // Copy successive full blocks
            for (int blk = 1; blk < fullBlocks; blk++)
            {
                Array.Copy(data, 0, data, blk * BLOCK_SIZE, BLOCK_SIZE);
            }
            for (int rem = fullBlocks * BLOCK_SIZE; rem < data.Length; rem++)
            {
                data[rem] = 1;
            }
        }
    }
}