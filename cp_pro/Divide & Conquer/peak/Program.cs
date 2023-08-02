using BenchmarkDotNet.Attributes;
using BenchmarkDotNet.Columns;
using BenchmarkDotNet.Configs;
using BenchmarkDotNet.Exporters.Csv;
using BenchmarkDotNet.Reports;
using BenchmarkDotNet.Running;

public class config : ManualConfig
{
    public CsvExporter exporter = new CsvExporter(
    CsvSeparator.CurrentCulture,
    new SummaryStyle(
        cultureInfo: System.Globalization.CultureInfo.CurrentCulture,
        printUnitsInHeader: true,
        printUnitsInContent: false,
        timeUnit: Perfolizer.Horology.TimeUnit.Microsecond,
        sizeUnit: SizeUnit.B
    ));
    public config()
    {
        AddExporter(exporter);
    }
}

[Config(typeof(config))]
[MemoryDiagnoser]
public class benchmark
{
    public int[][] values;
    [Params(1000, 2000, 4000, 8000, 16000, 32000, 64000)]
    public int size { get; set; }
    [GlobalSetup]
    public void Setup()
    {
        int start = 0;
        values = new int[size][];
        for (int i = 0; i < size; i++)
        {
            values[i] = new int[size];
            for (int j = 0; j < size; j++)
            {
                values[i][j] = start;
                start++;
            }
        }
    }

    /*[Benchmark]
    public Tuple<int, int> twod_peak() => peak_algs.twod_peak(values, 0, size - 1, 0, size - 1);*/
    [Benchmark]
    public int oned_peak() => peak_algs.oned_peak(values[0], 0, size - 1);

}
public static class program
{
    public static void Main()
    {
        BenchmarkRunner.Run<benchmark>();
    }
}



public static class peak_algs
{
    public static bool is_oned_peak(int[] A, int index)
    {
        int left = Math.Max(0, index - 1);
        int right = Math.Min(A.Length - 1, index + 1);
        if (A[left] <= A[index] && A[index] >= A[right])
        {
            return true;
        }
        return false;
    }
    public static bool inside_board(int[,] A, int a, int b)
    {
        // this first check first if the cell is inside the board, and also check if
        // its value is 0 because if its greater than zero we dont need to change it
        // because by definition and property of the algorithm every number is the
        // minimal distance.  
        if ((a >= 0) && (a < A.GetLength(0)) && (b >= 0) && (b < A.GetLength(1)))
        {
            return true;
        }
        return false;
    }

    public static bool inside_bboard(int[][] A, int a, int b)
    {
        // this first check first if the cell is inside the board, and also check if
        // its value is 0 because if its greater than zero we dont need to change it
        // because by definition and property of the algorithm every number is the
        // minimal distance.  
        if ((a >= 0) && (a < A.Length) && (b >= 0) && (b < A[0].Length))
        {
            return true;
        }
        return false;
    }


    public static bool is_twod_peak(int[][] A, int index_row, int index_column)
    {

        if (inside_bboard(A, index_row + 1, index_column) && A[index_row + 1][index_column] > A[index_row][index_column])
        {
            return false;
        }
        if (inside_bboard(A, index_row - 1, index_column) && A[index_row - 1][index_column] > A[index_row][index_column])
        {
            return false;
        }
        if (inside_bboard(A, index_row, index_column + 1) && A[index_row][index_column + 1] > A[index_row][index_column])
        {
            return false;
        }
        if (inside_bboard(A, index_row, index_column - 1) && A[index_row][index_column - 1] > A[index_row][index_column])
        {
            return false;
        }
        return true;
    }

    public static int oned_peak(int[] A, int start, int end)
    // return the index of an element in the array that is a peak.
    // expected complexity is log(n).
    {
        if ((end - start + 1) < 3)
        {
            return (A[start] >= A[end]) ? start : end;
        }
        else
        {
            int mid = (end + start + 1) / 2;
            if (A[mid] < A[mid - 1])
            {
                return oned_peak(A, start, mid - 1);
            }
            else if (A[mid] < A[mid + 1])
            {
                return oned_peak(A, mid + 1, end);
            }
            else
            {
                return mid;
            }
        }
    }

    public static Tuple<int, int> twod_peak(int[][] A, int start_row, int end_row, int start_column, int end_column)
    {
        if (start_row == end_row)
        {
            return new Tuple<int, int>(start_row, oned_peak(A[start_row], start_column, end_column));
        }
        else if (start_column == end_column)
        {
            return new Tuple<int, int>(oned_peak(A[start_column], start_row, end_row), start_column);
        }
        else
        {
            // now compute middle row and middle column: constant time
            int middle_row = (start_row + end_row) / 2;
            int middle_column = (start_column + end_column) / 2;
            bool is_peak = true;
            // check if element at the middle is a 2d peak: constant time
            if (middle_row + 1 <= end_row && A[middle_row][middle_column] < A[middle_row + 1][middle_column])
            {
                is_peak = false;
            }
            if (middle_row - 1 >= start_row && A[middle_row][middle_column] < A[middle_row - 1][middle_column])
            {
                is_peak = false;
            }
            if (middle_column + 1 <= end_column && A[middle_row][middle_column] < A[middle_row][middle_column + 1])
            {
                is_peak = false;
            }
            if (middle_column - 1 >= start_column && A[middle_row][middle_column] < A[middle_row][middle_column - 1])
            {
                is_peak = false;
            }

            if (is_peak)
            {
                return new Tuple<int, int>(middle_row, middle_column);
            }
            // now i should find the maximal in the row or in the column O(m+n) time
            Tuple<int, int> max = new Tuple<int, int>(middle_row, middle_column);
            for (int i = start_column; i <= end_column; i++)
            {
                if (A[middle_row][i] > A[max.Item1][max.Item2])
                {
                    max = new Tuple<int, int>(middle_row, i);
                }
            }
            for (int i = start_row; i <= end_row; i++)
            {
                if (A[i][middle_column] > A[max.Item1][max.Item2])
                {
                    max = new Tuple<int, int>(i, middle_column);
                }
            }
            // at this point I have computed the max calue, but the problem is that i need to know 
            // in what cuadrant it is.
            // 1rts cuadrant is from start_row to middle_row-1, and start_column to middle_column-1
            // 2ds cuadrant is from middle_row+1 to end_row and and start_column to middle_column-1
            // 3rts cuadrant is from start_row to middle_row-1 and middle_column+1 to end_column
            // 4rts cuadrant is from middle_row+1 to end_row and and middle_column+1 to end_column
            // call recursively the function.
            if (max.Item1 == middle_row)
            {
                if (max.Item2 < middle_column && middle_column - 1 >= start_column) // look to first and second cuadrant
                {
                    if (max.Item1 - 1 >= start_row && A[max.Item1][max.Item2] < A[max.Item1 - 1][max.Item2])
                    {
                        return twod_peak(A, start_row, middle_row - 1, start_column, middle_column - 1);
                    }
                    if (max.Item1 + 1 <= end_row && A[max.Item1][max.Item2] < A[max.Item1 + 1][max.Item2])
                    {
                        return twod_peak(A, middle_row + 1, end_row, start_column, middle_column - 1);
                    }
                }
                else if (middle_column + 1 <= end_column) // look at third and four cuadrant
                {
                    if (max.Item1 - 1 >= start_row && A[max.Item1][max.Item2] < A[max.Item1 - 1][max.Item2])
                    {
                        return twod_peak(A, start_row, middle_row - 1, middle_column + 1, end_column);
                    }
                    if (max.Item1 + 1 <= end_row && A[max.Item1][max.Item2] < A[max.Item1 + 1][max.Item2])
                    {
                        return twod_peak(A, middle_row + 1, end_row, middle_column + 1, end_column);
                    }
                }
            }
            if (max.Item2 == middle_column)
            {
                if (max.Item1 < middle_row && middle_row - 1 >= start_row) // look to first and 3rst cuadrant
                {
                    if (max.Item2 - 1 >= start_column && A[max.Item1][max.Item2] < A[max.Item1][max.Item2 - 1])
                    {
                        return twod_peak(A, start_row, middle_row - 1, start_column, middle_column - 1);
                    }
                    if (max.Item2 + 1 <= end_column && A[max.Item1][max.Item2] < A[max.Item1][max.Item2 + 1])
                    {
                        return twod_peak(A, middle_row + 1, end_row, middle_column + 1, end_column);
                    }
                }
                else if (middle_row + 1 <= end_row) // look at second  and four
                {
                    if (max.Item2 - 1 >= start_column && A[max.Item1][max.Item2] < A[max.Item1][max.Item2 - 1])
                    {
                        return twod_peak(A, middle_row + 1, end_row, start_column, middle_column - 1);
                    }
                    if (max.Item2 + 1 <= end_column && A[max.Item1][max.Item2] < A[max.Item1][max.Item2 + 1])
                    {
                        return twod_peak(A, middle_row + 1, end_row, middle_column + 1, end_column);
                    }
                }
            }
            return max;


        }
    }
}


/* public class test
{
    public static void Main()
    {
        // generate random 1D Array
        Random random = new Random();
        int number_rows = 1000000;
        int number_columns = 100000000;
        int[][] values = new int[number_rows][];
        for (int z = 0; z < 1000000; z++)
        {
            for (int i = 0; i < number_columns; i++)
            {
                values[i] = new int[number_columns];
                for (int j = 0; j < number_columns; j++)
                {
                    values[i][j] = random.Next(10000000);
                }
            }
            Tuple<int, int> result = peak_algs.twod_peak(values, 0, number_rows - 1, 0, number_columns - 1);
            if (!(peak_algs.is_twod_peak(values, result.Item1, result.Item2)))
            {
                Console.WriteLine("mistake");
            }
        }




    }
} */