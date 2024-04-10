namespace SeminarioConcurrencia;

/*
A semaphor has a name, an initial capacity, and a maximum number of threads that can access the critical section. 

Interface: 
    WaitOne() : wait for a free capacity.
    Release() : release capacity.
*/

public class MySemaphore
{
    public MySemaphore(string name, int initial_capacity = 0, int maxThreads = 100)
    {
        this.name = name;
        _maxThreads = maxThreads;
        capacity = initial_capacity;
        printer = new PrettyPrint();
    }
    public MySemaphore(string name, PrettyPrint printer, int initial_capacity = 0, int maxThreads = 100)
    {
        this.name = name;
        _maxThreads = maxThreads;
        capacity = initial_capacity;
        this.printer = printer;
    }
    int capacity;
    private readonly string name;
    readonly int _maxThreads;
    readonly PrettyPrint printer;
    readonly object lock1 = new();

    public void WaitOne()
    {
        Monitor.Enter(lock1);
        try
        {
            while (capacity == 0)
            {
                Monitor.Wait(lock1);
            }
            capacity--;
        }
        finally
        {
            Monitor.Exit(lock1);
        }
    }

    public void WaitOne(string callerID)
    {
        /*
        create a lock object thas is only free when capacity > 0, so that the only way a thread has access to it is when capacity > 0.
        */
        printer.Print("will try to enter the lock to request capacity", callerID, "    ");
        Monitor.Enter(lock1);
        try
        {
            printer.Print("entered the lock to check capacity", callerID, "    ");
            while (capacity == 0)
            {
                printer.Print("waiting for capacity, so releasing lock, but pending", callerID);
                Monitor.Wait(lock1);
            }
            printer.Print("there was capacity for me", callerID, "    ");
            capacity--;
            printer.Print($"capacity now is {capacity}", "Semaphor " + name, "    ");
        }
        finally
        {
            printer.Print("exited the lock after waiting", callerID, "    ");
            Monitor.Exit(lock1);
        }
    }

    public void Release(int how_many)
    {
        Monitor.Enter(lock1);
        try
        {
            capacity += how_many; // atomic operation due to implicit assembly instructions.
            if (capacity > _maxThreads)
            {
                capacity = _maxThreads;
            }
            Monitor.PulseAll(lock1);
        }
        finally
        {
            Monitor.Exit(lock1);
        }
    }
    public void Release(int how_many, string callerID)
    {
        printer.Print("will try to enter the lock to release capacity", callerID, "    ");
        Monitor.Enter(lock1);
        try
        {
            printer.Print("entered the lock to update capacity", callerID, "    ");
            capacity += how_many; // atomic operation due to implicit assembly instructions.
            if (capacity > _maxThreads)
            {
                capacity = _maxThreads;
            }
            printer.Print($"capacity is now {capacity}", "Semaphor " + name, "    ");
            printer.Print($"Notifying all threads waiting for capacity", "Semaphor " + name, "    ");
            Monitor.PulseAll(lock1);
        }
        finally
        {
            printer.Print("exited the lock after releasing", callerID, "    ");
            Monitor.Exit(lock1);
        }
    }
}