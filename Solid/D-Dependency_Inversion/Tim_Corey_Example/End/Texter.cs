public class Texter : IMessageSender
{
    public void SendMessage(IPerson person, string message)
    {
        Console.WriteLine($"I'm texting {person.FirstName} to say {message}");
    }
}
