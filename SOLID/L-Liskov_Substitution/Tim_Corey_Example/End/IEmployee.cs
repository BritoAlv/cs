/*
This is what I expect about an Employee to do, not more.
*/
public interface IEmployee
{
    string FirstName { get; set; }
    string LastName { get; set; }
    decimal Salary { get; set; }
    void CalculatePerHourRate(int rank);
}
