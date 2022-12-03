/*
A CEO is manager, but not managed, this is done using BaseEmployee.
*/
public class CEO: BaseEmployee, IManager
{
    public override void CalculatePerHourRate(int rank)
    {
        decimal baseAmount = 150M;
        Salary = baseAmount;
    }
    public void GeneratePerformanceReview()
    {
        Console.WriteLine("I'm reviewinf a direct report's performance");
    }
    public void FireSomeone()
    {
        Console.WriteLine("You're fired");
    }
}