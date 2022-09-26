using BenchmarkDotNet.Attributes;
using BenchmarkDotNet.Columns;
using BenchmarkDotNet.Configs;
using BenchmarkDotNet.Exporters.Csv;
using BenchmarkDotNet.Reports;
using BenchmarkDotNet.Running;


public class Program
{
    public static void Main()
    {
        // test is implementation is fine
        // Lee.checker();
        // test

        // watch the process with this code
        /*
        int cant_rows = 7;
        int cant_columns = 5;
        Random rnd = new Random();
        bool[,] casillas_prohibidas = new bool[cant_rows, cant_columns]; // true cells están prohibidas
        for (int i = 0; i < cant_rows; i++)
        {
            for (int j = 0; j < cant_columns; j++)
            {
                casillas_prohibidas[i, j] = (rnd.NextDouble() > 0.5); // 0.8 para reducir la probabilidad de casillas prohibidas.
            }
        }
        int start_row = rnd.Next(cant_rows);
        int start_column = rnd.Next(cant_columns);
        casillas_prohibidas[start_row, start_column] = false;
        int[,] board = Lee.lee(casillas_prohibidas, start_row, start_column, true);
        // watch
        */
        // benchmark the algorithm with this code.
        BenchmarkRunner.Run<benchmark>();
        // benchmark
    }
}



