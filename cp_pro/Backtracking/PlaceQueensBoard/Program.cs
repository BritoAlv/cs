class queens
{

    public static void Main()
    {
        // input n integer value
        int n = 8;
        int[] tablero_vacio = new int[n];
        for (int i = 0; i < n; i++)
        {
            tablero_vacio[i] = -1;
        }
        reinas(n, tablero_vacio, 0);
    }

    public static bool is_partially_valid(int[] tablero, int actual_columna)
    {
        for (int i = 0; i < actual_columna; i++)
        {
            if (tablero[i] == tablero[actual_columna])
            {
                return false;
            }
        }

        for (int i = 0; i < actual_columna; i++)
        {
            int dif_columnas = actual_columna - i;
            if ((  Math.Abs((tablero[i] - tablero[actual_columna])) == dif_columnas ))
            {
                return false;
            }
        }
        return true;
    }

    public static void reinas(int n, int[] actual_tablero, int columna)
    {
        if (columna == n)
        {
            // print the board stuff.
            List<char[]> board = new List<char[]>();
            for (int i = 0; i < actual_tablero.Length; i++)
            {
                board.Add(new char[actual_tablero.Length]);
            }
            for (int i = 0; i < actual_tablero.Length; i++)
            {
                // we are at column i,
                for (int j = 0; j < actual_tablero.Length; j++)
                {
                    // we are at row j
                    if(j == actual_tablero[i] )
                    {
                        // place a queen
                        board[j][i] = 'Q';
                    }
                    else
                    {
                        board[j][i] = 'X';
                    }
                }
            }
            foreach (var row in board)
            {
                foreach (var value in row)
                {
                    Console.Write(value + " ");
                }
                Console.WriteLine(" ");
            }            
            //
            Console.WriteLine(" ");
            return;
        }

        for (int i = 0; i < n; i++)
        {
            // put a queen in row i at column columna, check if it is valid, if it is, call the funcion in the next column
            int temp = actual_tablero[columna];
            actual_tablero[columna] = i;
            if (is_partially_valid(actual_tablero, columna))
            {
                reinas(n, actual_tablero, columna + 1);
            }
            actual_tablero[columna] = temp;
        }

    }
}