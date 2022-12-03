public class CEO:Employee
{
    public override void CalculatePerHourRate(int rank)
    {
        decimal baseAmount = 150M;
        Salary = baseAmount;
    }

    /*
    this not implemented implies that a CEO is not an Employee, due to
    the definition of the Employee.
    */
    public override void AssignManager(Employee manager)
    {
        throw new Exception("CEO has no manager");
    }

    public void GeneratePerformanceReview()
    {
        Console.WriteLine("I'm reviewing a direct report's performance");
    }

    public void FireSomeone()
    {
        Console.WriteLine("You're fired");
    }
}