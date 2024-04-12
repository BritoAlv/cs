public class CLock
{
    public object object1 = new object();
    public object object2 = new object();
    public void M() 
    {
        lock(object1)
        {
            
        }
    }
    
    public void N()
    {
        lock(object1)
        {
            
        }
    }

    public void L()
    {
        lock(object2)
        {
            
        }
    }
}