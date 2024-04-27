namespace SeminarioConcurrencia;

public class Workers(string name, int timeWorkin)
{
    public string Name { get; } = name;
    public int TimeWorkin { get; } = timeWorkin;
    public void Work(PrettyPrint printer)
    {
        printer.Print("Now I will work : ... : done", Name);
    }
}