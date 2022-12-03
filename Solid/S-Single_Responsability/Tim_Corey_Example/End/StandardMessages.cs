public class StandardMessages
{
    public static void Welcome_Message()
    {
        Console.WriteLine("Welcome to my aplication");
    }

    public static void End_Aplication()
    {
        Console.Write("Please Enter to close");
        Console.ReadLine();
    }

    public static void Display_Validation_Error(string field_name)
    {
        Console.WriteLine($"You did not give us a valid {field_name}");
    }
}