namespace SeminarioConcurrencia;

/*
1. ** CountdownEvent **: This class is used when you want to wait for a certain number of signals before continuing execution. You initialize a `CountdownEvent` with a count, and each call to `Signal` decreases the count. When the count reaches zero, all waiting threads are unblocked. This is useful when you have multiple tasks that can complete in any order, and you want to wait until all of them are done.

CountDown interface()
{
    Signal, inform this thread is finished.
    Wait => main thread should wait until countdown is 0,
}
*/

public class MyCountDown(int count, PrettyPrint printer)
{
    public int Count { get; private set; } = count;
    public PrettyPrint Printer { get; } = printer;
    readonly MySemaphore mySemaphoreAux = new("Aux", 1, 1);
    readonly MySemaphore mySemaphoreLock = new("Lock", 0, 1);
    public void Signal(string callerID)
    {
        Printer.Print($"Try to decrease count: {Count} ", callerID);
        mySemaphoreAux.WaitOne();
        Printer.Print("Is entering critical section " + Count, callerID);
        Count--;
        if (Count == 0)
        {
            Printer.Print("Count is zero so release locked thread", callerID);
            mySemaphoreLock.Release(1);
        }
        Printer.Print("Is exiting critical section " + Count, callerID);
        mySemaphoreAux.Release(1);
    }
    public void Wait(string callerID)
    {
        mySemaphoreLock.WaitOne();
    }
}