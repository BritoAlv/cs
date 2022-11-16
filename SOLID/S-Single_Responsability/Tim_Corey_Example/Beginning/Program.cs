public class Program
{
    public static void Main()
    {
        /*
        esta clase tiene primero una parte de bienvenida
        */
        Console.WriteLine("Welcome to my aplication");
        Person user = new Person();

        /*
        tiene una parte de obtener información
        */
        Console.Write("What is your first name:  ");
        user.FirstName = Console.ReadLine();

        Console.Write("What is your last name:  ");
        user.LastName = Console.ReadLine();


        /*
        tiene una parte de validar información
        */
        if(string.IsNullOrWhiteSpace(user.FirstName))
        {
            Console.WriteLine("You did not give us a valid first name");
            Console.ReadLine();
            return;
        }

        if(string.IsNullOrWhiteSpace(user.LastName))
        {
            Console.WriteLine("You did not give us a valid last name");
            Console.ReadLine();
            return;
        }

        /*
        tiene una parte de enseñar el resultado.
        */
        Console.WriteLine($"Your username is {user.FirstName.Substring(0, 1)} {user.LastName}");
        Console.ReadLine();

    }
}

/*
Como consecuencia esta clase tendría 4 responsabilidades, dar la bienvenida, obtener la información, validar la información, y enseñar la información.

Lo que estaría mal, deberíamos tener una clase para cada una  de estas cuatro responsabilidades.s
*/