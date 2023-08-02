using System.Diagnostics;
class Program
{
    static void Main()
    {
        Console.WriteLine(Exam.Nombre);
        Console.WriteLine(Exam.Grupo);
        ExampleCase();
    }
    static void ExampleCase()
    {
        IInventory inv = Exam.GetInventory();
        ICategory root = inv.Root;
        ICategory alimentos = root.CreateSubcategory("Alimentos");
        ICategory electronica = root.CreateSubcategory("Electronica");
        ICategory carnicos = alimentos.CreateSubcategory("Carnicos");
        ICategory vegetales = alimentos.CreateSubcategory("Vegetales");
        ICategory electrodomesticos = electronica.CreateSubcategory("Electrodomesticos");
        ICategory informatica = electronica.CreateSubcategory("Informatica");
        alimentos.UpdateProduct("Arroz", 10);
        carnicos.UpdateProduct("Pescado", 5);
        carnicos.UpdateProduct("Carne de Cerdo", 10);
        vegetales.UpdateProduct("Tomate", 20);
        vegetales.UpdateProduct("Lechuga", 4);
        electrodomesticos.UpdateProduct("Lavadora", 2);
        informatica.UpdateProduct("Ordenador", 3);
        ICategory moviles = informatica.CreateSubcategory("Moviles");
        Debug.Assert(moviles == inv.GetCategory("Electronica", "Informatica", "Moviles"));
        informatica.UpdateProduct("Ordenador", -1);
        Debug.Assert(inv.GetProduct("Ordenador", "Electronica", "Informatica").Count == 2);
        moviles.UpdateProduct("Samsung Galaxy", 10);
        Debug.Assert(inv.GetProduct("Samsung Galaxy", "Electronica", "Informatica", "Moviles").Count == 10);
        foreach (var product in inv.FindAll(p => p.Count < 5))
        {
            Debug.Assert(product.Count > 0 && product.Count < 5);
        }
    }
}
