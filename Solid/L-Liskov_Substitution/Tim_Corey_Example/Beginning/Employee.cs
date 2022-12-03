public class Employee
{
    public string FirstName { get; set; }
    public string LastName{ get; set; }

    public Employee Manager { get; set; } = null;
    public decimal Salary{ get; set; }

    public virtual void AssignManager(Employee manager)
    {
        Manager = manager;
    }

    public virtual void CalculatePerHourRate(int rank)
    {
        decimal baseAmount = 12.5M;
        Salary = baseAmount + rank * 2;
    }
}