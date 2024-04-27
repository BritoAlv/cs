
namespace SeminarioConcurrencia;
public static partial class Program
{
    public static void TestCountDown()
    {
        PrettyPrint printer = new();
        Random random = new();
        // Create an array of threads.
        Workers[] workers = [
            new("A", random.Next(1000000, 2000000)),
            new("B", random.Next(1000, 2000)),
            new("C", random.Next(1000, 2000)),
            new("D", random.Next(1000, 2000)),
            new("E", random.Next(1000, 2000)),
            new("F", random.Next(1000, 2000)),
            new("G", random.Next(1000, 2000)),
            ];

        MyCountDown countDown = new(workers.Length, printer);
        
        Thread[] threads = new Thread[workers.Length];
        for (int i = 0; i < workers.Length; i++)
        {
            int index = i;
            threads[i] = new(
                () =>
                {
                    workers[index].Work(printer);
                    countDown.Signal(workers[index].Name);
                    printer.Print("Say to countdown that the work is done .", workers[index].Name);
                }
            );
            threads[index].Start();
        }
        printer.Print("Waiting for all work to be done", "Main");
        countDown.Wait("Main");
        printer.Print("All work is done", "Main");

        foreach (var thread in threads)
        {
            thread.Join();
        }
    }
}