/*  
an employee has a manager, ie is managed, so that is it.
*/
public class Employee : BaseEmployee, IManaged
{
    public IManager Manager{ get; set; }

    public virtual void AssignManager(IManager manager)
    {
        Manager = manager;
    }
}
