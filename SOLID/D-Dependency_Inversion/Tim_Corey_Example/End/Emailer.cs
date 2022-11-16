public class Emailer : IMessageSender
{
    public void SendMessage(IPerson person, string message)
    {
        Console.WriteLine($"Simulating Sending email to {person.EmailAddress}");
    }
}
