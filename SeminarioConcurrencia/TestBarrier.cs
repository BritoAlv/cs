namespace SeminarioConcurrencia;

public static partial class Program
{
    public static void TestBarrier()
    {
        PrettyPrint printer = new();
        Random random = new();
        Workers[] workers = [
            new("A", random.Next(1000, 2000)),
            new("B", random.Next(1000, 2000)),
            new("C", random.Next(1000, 2000)),
            new("D", random.Next(1000, 2000)),
            new("E", random.Next(1000, 2000)),
            new("F", random.Next(1000, 2000)),
            new("G", random.Next(1000, 2000)),
            ];
        MyBarrier myBarrier = new(
            workers.Length,
            () =>
            {
                printer.Print("Finished preparing ingredients", "Action");
            },
            printer
            );
        Thread[] threads = new Thread[workers.Length];
        for (int i = 0; i < workers.Length; i++)
        {
            int index = i;
            threads[i] = new(
                () =>
                {
                    myBarrier.SignalAndWait(workers[index].Name);
                    workers[index].Work(printer);
                }
            );
            threads[index].Start();
        }
        foreach (var thread in threads)
        {
            thread.Join();
        }
    }
}
