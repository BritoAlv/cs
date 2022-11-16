public class Logger : ILogger
{
    public void log(string message)
    {
        Console.WriteLine($"Write To Console: {message}");
    }
}
