public static class Lee
{
    static int[] dx = new int[8] { 1, -1, 0, 0, -1, -1, 1, 1 }; // last four are diagonals
    static int[] dy = new int[8] { 0, 0, 1, -1, -1, 1, -1, 1 };
    public static void checker() // to check if implementation is fine,
    {
        int cant_rows = 4;
        int cant_columns = 4;
        Random rnd = new Random();

        while (true)
        {
            // generate a random boolean map
            bool[,] casillas_prohibidas = new bool[cant_rows, cant_columns]; // true cells están prohibidas
            for (int i = 0; i < cant_rows; i++)
            {
                for (int j = 0; j < cant_columns; j++)
                {
                    casillas_prohibidas[i, j] = (rnd.NextDouble() > 0.5); // 0.8 para reducir la probabilidad de casillas prohibidas.
                }
            }
            bool[,] copy = (bool[,])casillas_prohibidas.Clone();
            int start_row = rnd.Next(cant_rows);
            int start_column = rnd.Next(cant_columns);
            casillas_prohibidas[start_row, start_column] = false;
            int[,] board = Lee.lee(casillas_prohibidas, start_row, start_column);
            if (!Lee.is_fine(board))
            {
                PrintArray.PrintTable(board);
                PrintArray.PrintTable(copy);
                board = Lee.lee(copy, start_row, start_column, true);
                break;
            }
            else
            {
                Console.WriteLine("this is fine");
            }
        }
        return;
    }
    public static bool is_fine(int[,] distancias)
    {
        for (int i = 0; i < distancias.GetLength(0); i++)
        {
            for (int j = 0; j < distancias.GetLength(1); j++)
            {
                if (distancias[i, j] > 0)
                {
                    for (int desp = 0; desp < dx.Length; desp++)
                    {
                        if (inside_cell(i + dx[desp], j + dy[desp]) && Math.Abs(distancias[i, j] - distancias[i + dx[desp], j + dy[desp]]) >= 2)
                        {
                            return false;
                        }
                    }

                }
            }
        }
        return true;

        bool inside_cell(int a, int b)
        {
            // this first check first if the cell is inside the board, and also check if
            // its value is 0 because if its greater than zero we dont need to change it
            // because by definition and property of the algorithm every number is the
            // minimal distance.  
            if ((a >= 0) && (a < distancias.GetLength(0)) && (b >= 0) && (b < distancias.GetLength(1)) && distancias[a, b] > 0)
            {
                return true;
            }
            return false;
        }
    }

    /// <summary>
    /// 
    /// </summary>
    /// <param name="casillas_prohibidas"> para saber que casillas están prohibidas, </param>
    /// <param name="fila_inicial"></param>
    /// <param name="columna_inicial"></param>
    /// <returns>     
    /// Devuelve un arreglo distancias que contiene valores enteros su leyenda es la siguiente:
    /// 0 es la casilla de donde partimos,
    /// -10 la casilla es prohibida,
    /// -1 esta casilla es inalcanzable,
    /// >0 menor distancia de la casilla inicial a ella.
    /// </returns>
    public static int[,] lee(bool[,] prohibidas, int fila_inicial, int columna_inicial, bool print = false)
    {
        int filas = prohibidas.GetLength(0);
        int columnas = prohibidas.GetLength(1);
        int[,] distancias = new int[filas, columnas];
        // marcar la casilla por donde empezamos con valor 1
        distancias[fila_inicial, columna_inicial] = 1;
        Queue<Tuple<int, int>> cola = new Queue<Tuple<int, int>>();
        cola.Enqueue(new Tuple<int, int>(fila_inicial, columna_inicial));

        while (cola.Count > 0)
        {
            // extract first element of the cola, look at its neighbours and to the valid
            // ones update its value and add them to the cola.
            Tuple<int, int> actual = cola.Dequeue();
            update_neighbours(actual.Item1, actual.Item2);
            if (print)
            {
                PrintArray.PrintTable(distancias);
                Console.ReadKey();
            }


        }


        void update_neighbours(int j, int l)
        {
            int valor = distancias[j, l] + 1;
            // check neigbours and update its value and to the queue
            for (int desp = 0; desp < dx.Length; desp++)
            {
                set_value(j + dx[desp], l + dy[desp]);
            }

           
            void set_value(int a, int b)
            {
                if ((a >= 0) && (a < filas) && (b >= 0) && (b < columnas)) // cell is inside the board.
                {
                    if (prohibidas[a, b])
                    {
                        distancias[a, b] = -9; // the cell is prohibida
                    }
                    else if ((distancias[a, b] == 0)) // no es prohibida y su valor es cero, o sea no ha sido actualizada.
                    {
                        cola.Enqueue(new Tuple<int, int>(a, b)); // la mandamos pa la cola al final
                        distancias[a, b] = valor; // actualizamos su valor
                    }
                }
            }
        }

        // substract 1 to set cell value according to problem. esto es para ajustar los valores a la leyenda definida.    
        for (int i = 0; i < filas; i++)
        {
            for (int j = 0; j < columnas; j++)
            {
                distancias[i, j] = distancias[i, j] - 1;
            }
        }
        if (print)
        {
            PrintArray.PrintTable(distancias);
        }
        return distancias;
    }
}