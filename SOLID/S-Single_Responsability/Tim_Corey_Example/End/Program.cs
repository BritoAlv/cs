public class Program
{
    public static void Main()
    {
        /*
        responsability goes to the class standard messages
        */
        StandardMessages.Welcome_Message();

        /*
        responsability goes to the capture class
        */
        Person user = Person_Data_Capture.capture();

        /*
        responsability goes to the validate_class
        */
        bool is_user_valid = Person_Validator.Validate(user);
        if(!is_user_valid)
        {
            StandardMessages.End_Aplication();
            return;
        }
        /*
        responsability goes to CreateAccount 
        */
        Account_Generator.CreateAccount(user);

        StandardMessages.End_Aplication();
    }
}

/*
Finally what did this class was execute a list of methods, just one thing,
control the flow of the aplication, it doesn't contain implementations, those are
other responsabilities. Broke the aplication into more parts, this
allow better changes for the future.
*/

/*
each responsabiity can be designed at its own.
*/