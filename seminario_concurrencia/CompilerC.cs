public class CCompilerLock
{
    public object object1 = new object();

    public object object2 = new object();

    public void M()
    {
        object obj = object1;
        bool lockTaken = false;
        try
        {
            Monitor.Enter(obj, ref lockTaken);
        }
        finally
        {
            if (lockTaken)
            {
                Monitor.Exit(obj);
            }
        }
    }

    public void N()
    {
        object obj = object1;
        bool lockTaken = false;
        try
        {
            Monitor.Enter(obj, ref lockTaken);
        }
        finally
        {
            if (lockTaken)
            {
                Monitor.Exit(obj);
            }
        }
    }

    public void L()
    {
        object obj = object2;
        bool lockTaken = false;
        try
        {
            Monitor.Enter(obj, ref lockTaken);
        }
        finally
        {
            if (lockTaken)
            {
                Monitor.Exit(obj);
            }
        }
    }
}
