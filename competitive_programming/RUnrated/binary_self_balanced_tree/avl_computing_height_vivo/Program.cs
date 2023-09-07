using avlvivo;
using BenchmarkDotNet.Attributes;
using BenchmarkDotNet.Running;
[MemoryDiagnoser]
public class Test
{
     
    /*
    |      Method |     Mean |   Error |  StdDev | Allocated
    |------------ |---------:|--------:|--------:|------------; 
    | INSERT_VIVO |   2.143 s| 0.0065 s| 0.0058 s| 45.78 MB   ;
    */
    [Benchmark(Description = "INSERT_VIVO")]
    public void Algorithm()
    {
        Node a = new Node(-1);
        for (int i = 2000000; i < 3000000; i++)
        {
            a = Node.insert_avl(i, a);
        }
    }
    public static void Main()
    {
        BenchmarkRunner.Run<Test>();
    }
}