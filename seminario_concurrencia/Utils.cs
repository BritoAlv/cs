public class PrettyPrint
{
    Dictionary<string, ConsoleColor> pairs = new Dictionary<string, ConsoleColor>();
    static ConsoleColor[] allColors = [
        ConsoleColor.Red, 
        ConsoleColor.Green, 
        ConsoleColor.Blue, 
        ConsoleColor.Yellow, 
        ConsoleColor.Magenta, 
        ConsoleColor.Cyan, 
        ConsoleColor.White,
        ConsoleColor.DarkYellow,
        ConsoleColor.DarkBlue,
        ConsoleColor.DarkGreen,
        ConsoleColor.DarkMagenta];
    public void Print(string message, string caller, string space = "")
    {
        lock (this)
        {
            if (!pairs.ContainsKey(caller))
            {
                ConsoleColor[] availableColors = allColors
                    .Except(pairs.Values)
                    .Where(x => x != Console.ForegroundColor)
                    .ToArray();

                if (availableColors.Length > 0)
                {
                    pairs[caller] = Console.ForegroundColor = availableColors[new Random().Next(availableColors.Length)];
                }
            }
            Console.ForegroundColor = pairs[caller];
            Console.WriteLine(space + $"{caller}: {message}");
            Console.ResetColor();
        }
    }
}