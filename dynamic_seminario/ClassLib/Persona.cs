namespace f;

public class Persona
{
    public readonly string name;

    public Persona(string name)
    {
        this.name = name;
    }

    public void Saluda()
    {
        Console.WriteLine($"Hola, soy {name}");
    }
}
