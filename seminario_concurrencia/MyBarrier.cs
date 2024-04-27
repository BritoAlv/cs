namespace SeminarioConcurrencia;

/*
The Barrier class is a synchronization primitive that enables multiple threads to work on a task in parallel and wait until all threads have completed their work before moving on to the next step in the program.

Barrier when you want to synchronize threads at certain points in their execution.

2. **Barrier**: This class is used when you want to make sure that a group of threads have all reached a certain point before any of them continue. When a thread calls `SignalAndWait`, it is blocked until all other threads have also called `SignalAndWait`. This is useful when you have a multi-threaded algorithm where each thread needs to wait for all others to finish a certain step before it can proceed to the next step.

*/

public class MyBarrier(int nthreads, Action action, PrettyPrint printer, int initialCount = 0)
{
    private readonly int nthreads = nthreads;
    private int threads_inside = initialCount;
    private readonly Action action = action;
    private readonly PrettyPrint printer = printer;
    private readonly MySemaphore semaphoreLock = new("lock", 1, 1);
    private readonly MySemaphore semaphoreAux = new("aux", 0, nthreads);
    public void SignalAndWait(string callerID)
    {
        printer.Print("SignalAndWait started: ", callerID);
        try
        {
            Checker(callerID);
            semaphoreAux.WaitOne();
        }
        finally
        {
            semaphoreAux.Release(1);
        }

    }
    void Checker(string callerID)
    {
        try
        {
            printer.Print("Checker started so wait to check condition ", callerID);
            semaphoreLock.WaitOne();
            threads_inside++;
            printer.Print("CallChecker  ", callerID);
            if (threads_inside == nthreads)
            {
                printer.Print("All threads are up to date so perform action: ", "Barrier");
                action();
                printer.Print("Barrier allows threads to pass: ", "Barrier");
                threads_inside = 0;
                semaphoreAux.Release(nthreads);
            }
        }
        finally
        {
            printer.Print("Checker finished so release lock ", callerID);
            semaphoreLock.Release(1);
        }
    }

    public void SignalAndWait()
    {
        try
        {
            Checker();
            semaphoreAux.WaitOne();
        }
        finally
        {
            semaphoreAux.Release(1);
        }
    }
    void Checker()
    {
        try
        {
            semaphoreLock.WaitOne();
            threads_inside++;
            if (threads_inside == nthreads)
            {
                action();
                threads_inside = 0;
                semaphoreAux.Release(nthreads);
            }
        }
        finally
        {
            semaphoreLock.Release(1);
        }
    }
}