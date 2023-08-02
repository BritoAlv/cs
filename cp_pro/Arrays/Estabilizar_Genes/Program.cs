public class RealSequence : Sequence
{
    public bool Equals(Sequence a)
    {
        for (int i = 0; i < 4; i++)
        {
            if ((this.replace_letters[i] > a.how_many_letters[i]))
            {
                return false;
            }
        }
        return true;
    }
    public int size;
    public int[] replace_letters; // the ones that have positive value > 0 .
    public int at_least;
    public RealSequence(string b) : base(b)
    {
        size = b.Length;
        replace_letters = new int[4];
        for (int i = 0; i < 4; i++)
        {
            replace_letters[i] = how_many_letters[i] - size / 4;
            if (replace_letters[i] < 0) { replace_letters[i] = 0; }
            at_least = at_least + replace_letters[i];
        }
    }
}
public class Sequence
{
    public string secuence;
    public int[] how_many_letters;
    public Sequence(string a)
    {
        secuence = a;
        how_many_letters = how_many(a);
    }
    public static int[] how_many(string a)
    {
        int[] result = new int[4];
        for (int i = 0; i < a.Length; i++)
        {
            if (a[i] == 'A') { result[0] = result[0] + 1; }
            else if (a[i] == 'C') { result[1] = result[1] + 1; }
            else if (a[i] == 'G') { result[2] = result[2] + 1; }
            else if (a[i] == 'T') { result[3] = result[3] + 1; }
        }
        return result;
    }
    public static string get_sub(RealSequence a)
    {
        for (int i = a.at_least; i <= a.secuence.Length - 1; i++) // AAAA, at least vale 3, i toma a lo más 3.
        {
            // método para obtener todas las subcadenas posibles de longitud i.
            for (int j = 0; j <= a.secuence.Length - i; j++)
            {
                Sequence test = new Sequence(a.secuence.Substring(j, i));
                if (a.Equals(test))
                {
                    return test.secuence;
                }
            }
        }
        return "";
    }
}
public class Program
{
    public static void Main()
    {
        while (true)
        {
            Console.WriteLine("Introduzca una secuencia: ");
            string secuencia = Console.ReadLine();
            //string secuencia = "GAAATAAA";
            RealSequence a = new RealSequence(secuencia);
            Console.WriteLine("La menor subcadena es: " + Sequence.get_sub(a));
        }
    }
}