using System.Text;
public class Test
{
    public static void Main()
    {
        Rectangle r = new Rectangle();
        r.Height = 5;
        r.Length = 10;
        r.Grow(10, 10);
        ImmutableRectangle a = new ImmutableRectangle(5, 10);
        a = a.Grow(10, 10);

        Func<int, int> addOne = (n => n + 1);
        Func<int, int, int> addNums = ( (x, y) => x + y);
        Func<int, bool> isZero = (n => n == 0);
        Console.WriteLine("Se añade 1 a 5 " + addOne(5));
        Console.WriteLine("Se comprueba si es 0 la suma -5+5 " + (isZero(addNums(-5,5))));

        int[] numbers = { 0, 1, 0, 3, 4, 0 };
        Console.WriteLine("Se cuentan la cantidad de ceros en un array " + numbers.Contar(isZero));

        bool[] bools = { false, true, false, false };

        Console.WriteLine("Se cuentan la cantidad de false en un array " + bools.Count(bln => bln == false));
        Console.WriteLine("Se cuentan la cantidad de true en un array " + bools.Count(bln => bln == true));

        string htmlButton = new StringBuilder()
                            .Append("<button")
                            .AppendWhen(" disabled", true)
                            .Append(">Click Me </button>")
                            .ToString();
    }
}