namespace SeminarioConcurrencia;

public static partial class Program
{
    public static void TestSemaphor()
    {
        PrettyPrint printer = new();
        Random random = new();
        MySemaphore semaphore = new("main", printer, 3, 3);
        // Create an array of threads.
        Workers[] workers = [
            new("A", random.Next(1000, 2000)),
            new("B", random.Next(1000, 2000)),
            new("C", random.Next(1000, 2000)),
            new("D", random.Next(1000, 2000)),
            new("E", random.Next(1000, 2000)),
            new("F", random.Next(1000, 2000)),
            new("G", random.Next(1000, 2000)),
            ];

        Thread[] threads = new Thread[workers.Length];
        for (int i = 0; i < workers.Length; i++)
        {
            int index = i;
            threads[i] = new(
                () =>
                {
                    semaphore.WaitOne(workers[index].Name);
                    workers[index].Work(printer);
                    printer.Print("Will try to releasing capacity", workers[index].Name);
                    semaphore.Release(1, workers[index].Name);
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