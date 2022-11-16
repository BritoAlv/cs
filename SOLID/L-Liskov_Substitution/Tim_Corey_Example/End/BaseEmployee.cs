/*
this class is abstract because no one is a base emloyee, 
everyone is something more, reason to make this abstract,
also other reason is because, to implement the interface
there is to implement each property/method on it, this is
a way to avoid that. 
*/
public abstract class BaseEmployee : IEmployee
{
    public string FirstName { get; set; }
    public string LastName { get; set; }
    public decimal Salary { get; set; }
    public virtual void CalculatePerHourRate(int rank)
    {
        decimal baseAmount = 12.5M;
        Salary = baseAmount + rank * 2;
    }
}