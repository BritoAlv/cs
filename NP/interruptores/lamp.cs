using System.Diagnostics;
public class Program
{
    public static void Main()
    {
        Random a = new Random();
        int row = 20;
        int column = 20;
        bool[,] map = new bool[row, column];
        for (int i = 0; i < row; i++)
        {
            for (int j = 0; j < column; j++)
            {
                map[i, j] = (a.NextDouble() > 0.5) ? true : false;
                //Console.Write((((map[i, j]) == true) ? 1 : 0).ToString().PadLeft(5) + " ");
            }
            //Console.WriteLine();
        }
        /*         map = new bool[5, 5]
                {
                    {true, false, false, true, false},
                    {false, true, false, false, false},
                    {false, true, false, false, false},
                    {true, false, false, false, false},
                    {false, true, true, false, true},
                }; */
        Stopwatch crono1 = new Stopwatch();
        crono1.Start();
        List<int> S1 = solution_1.get_min_sequence(map);
        crono1.Stop();
        Console.Write("Solución 1: ");
        foreach (var num in S1)
        {
            Console.Write(num + " ");
        }
        Console.WriteLine();
        Console.WriteLine(crono1.Elapsed);
        Console.WriteLine();

        Stopwatch crono2 = new Stopwatch();
        crono2.Start();
        List<int> S2 = solution_2.get_min_sequence(map);
        crono2.Stop();
        Console.Write("Solución 2: ");
        foreach (var num in S2)
        {
            Console.Write(num + " ");
        }
        Console.WriteLine();
        Console.WriteLine(crono2.Elapsed);
        Console.WriteLine();

        Stopwatch crono3 = new Stopwatch();
        crono3.Start();
        List<int> S3 = solution_3.get_min_sequence(map);
        crono3.Stop();
        Console.Write("Solución 3: ");
        foreach (var num in S3)
        {
            Console.Write(num + " ");
        }
        Console.WriteLine();
        Console.WriteLine(crono3.Elapsed);
        Console.WriteLine();

        Stopwatch crono4 = new Stopwatch();
        crono4.Start();
        List<int> S4 = solution_4.get_min_sequence(map);
        crono4.Stop();
        Console.Write("Solución 4: ");
        foreach (var num in S4)
        {
            Console.Write(num + " ");
        }
        Console.WriteLine();
        Console.WriteLine(crono4.Elapsed);
        Console.WriteLine();
    }
}





