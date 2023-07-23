namespace MyBenchMarks;
using BenchmarkDotNet.Running;
using System.Runtime;
public class Execution
{
    public static void Main()
    {
        /*
         Run each of your benchmarks. Passing As Arguments Both Time And Memory Complexity.
         BEGIN
         */
        //BenchmarkRunner.Run<BenchmarkBufferCopy>(new MyConfig(x => x, x => 1));
        //BenchmarkRunner.Run<BenchmarkCopyX2>(new MyConfig(x => x, x => 1));
        //BenchmarkRunner.Run<BenchmarkCopy>(new MyConfig(x => x, x => 1));
        //BenchmarkRunner.Run<BenchmarkEnumerable>(new MyConfig(x => x, x => x));
        //BenchmarkRunner.Run<BenchmarkFor>(new MyConfig(x => x, x => 1));
        BenchmarkRunner.Run<BenchmarkFill>(new MyConfig(x => x, x => 1));
        /*
        END
        */

        /*
        Copy all resulting csv from your benchmarks  files to statistics folders.
        */
        DirectoryInfo folder = new DirectoryInfo("./BenchmarkDotNet.Artifacts/results");
        DirectoryInfo destination = new DirectoryInfo("../Statistics");
        var csvs = folder.GetFiles().Where(x => x.Name.EndsWith(".csv"));
        foreach (var csv in csvs)
        {
            // as you can see the name of the file starts with benchmark so we remove it.
            csv.CopyTo(destination.FullName + "/" + csv.Name.Substring(9).Replace("-report", ""), true);
        }
    }
}
