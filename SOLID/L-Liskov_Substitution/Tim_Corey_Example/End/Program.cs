public class Program
{
    public static void Main()
    {
        IManager accountingVP = new Manager();
        accountingVP.FirstName = "Emma";
        accountingVP.LastName = "Stone";
        accountingVP.CalculatePerHourRate(4);
        /*
        Should be posible to use Manager next instead of Employee
        without breaking the contract.
        */
        Employee emp = new Employee();
        emp.FirstName = "Tim";
        emp.LastName = "Corey";
        emp.AssignManager(accountingVP);
        emp.CalculatePerHourRate(2);

        Console.WriteLine($"{emp.FirstName}'s salary is ${emp.Salary}/hours");
        Console.ReadLine();
    }
}