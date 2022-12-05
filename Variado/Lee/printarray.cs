public static class PrintArray
{
    public static void PrintTable<T>(T[,] table)
    {
        int totalFilas = table.GetLength(0);
        int totalColumnas = table.GetLength(1);
        Console.WriteLine("====================================================");
        for (int f = 0; f < totalFilas; f++)
        {
            for (int c = 0; c < totalColumnas; c++)
            {
                Console.Write(table[f, c].ToString().PadLeft(5) + " ");
            }
            Console.WriteLine();
        }
        Console.WriteLine("====================================================");
    }
}