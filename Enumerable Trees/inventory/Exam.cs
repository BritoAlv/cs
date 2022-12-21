public class Exam
{
    public static IInventory GetInventory()
    {
        return new Inventory(new Category(""));
    }
    public static string Nombre => "Alvaro Luis Gonzalez Brito";
    public static string Grupo => "C113";
}

