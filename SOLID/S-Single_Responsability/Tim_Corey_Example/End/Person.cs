using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

public class Person
{
    public string FirstName { get; set; }
    public string LastName { get; set; }
    public string PhoneNumber { get; set; }
    public string EmailAddress { get; set; }
}

public class Person_Data_Capture
{
    public static Person capture()
    {
        Person output = new Person();

        Console.Write("What is your first name:  ");
        output.FirstName = Console.ReadLine();

        Console.Write("What is your last name:  ");
        output.LastName = Console.ReadLine();

        return output;
    }
}

public class Person_Validator
{
    public static bool Validate(Person person)
    {
        if (string.IsNullOrWhiteSpace(person.FirstName))
        {
            StandardMessages.Display_Validation_Error("first_name");
            return false;
        }

        if (string.IsNullOrWhiteSpace(person.LastName))
        {
            StandardMessages.Display_Validation_Error("last_name");
            return false;
        }
        return true;
    }
}