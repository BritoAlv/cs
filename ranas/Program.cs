using System.Diagnostics;
public class ranas
{
    public static void Main()
    {
        Stopwatch a = new Stopwatch();
        a.Start();
        int resultado1 = max_choc(new bool[,] {
            { false, false, false, false, false, false, false, false },
            { false, false, false, false, false, true, false, true },
            { false, false, false, false, false, false, true, false },
            { false, false, true, false, true, true, true, true }
            }, new int[] { 0,1, 3,4 });
        a.Stop();
        Console.WriteLine(resultado1);
        Console.WriteLine(a.Elapsed);
    }

    public static int max_choc(bool[,] board, int[] frog_pos)
    {
        int best = 0;
        backtracking_2(new int[frog_pos.Length], 0, 0, 0, frog_pos);
        bool repeated_values(int[] r)
        {
            // return true if array r has repeated values.
            HashSet<int> m = new HashSet<int>();
            for (int i = 0; i < r.Length; i++)
            {
                if (m.Contains(r[i]))
                {
                    return true;
                }
                else
                {
                    m.Add(r[i]);
                }
            }
            return false;
        }
        void backtracking_1(int[] direcciones, int frog_row, int choc_comidos, int[] frog_pos)
        {
            // si estamos en la última fila solamente hay que devolver el chocolate.
            if (frog_row == board.GetLength(0) - 1)
            {
                if (choc_comidos > 0 && best > 0)
                {
                    best = Math.Max(choc_comidos, best);
                }
                else if (choc_comidos > 0)
                {
                    best = choc_comidos;
                }
            }
            else
            {
                // hay que realizar el movimiento, y llamar el movimiento en la proxima fila si es válido.
                int[] new_frog_pos = new int[frog_pos.Length];
                int update_choc = choc_comidos;
                // paso 1, realizar el movimiento
                for (int i = 0; i < direcciones.Length; i++)
                {
                    new_frog_pos[i] = frog_pos[i] + direcciones[i];
                    if (new_frog_pos[i] < 0 || new_frog_pos[i] > board.GetLength(1) - 1)
                    {
                        return;
                    }
                }

                // paso 2, verificar si es válido en el sentido de que no tiene ranas en dos lugares iguales.
                if (repeated_values(new_frog_pos))
                {
                    return;
                }

                // paso 3, el movimiento fue valido por lo que debemos agregar los chocolate válidos.
                for (int i = 0; i < frog_pos.Length; i++)
                {
                    if (board[frog_row + 1, new_frog_pos[i]])
                    {
                        update_choc++;
                    }
                }
                if (update_choc == 8)
                {
                    int a = 1;
                }

                // paso 4 ya actualizamos los chocolates, ahora tenemos que llamar a el segundo backtracking
                // recursivamente.
                int[] variacion = new int[new_frog_pos.Length];
                backtracking_2(variacion, 0, frog_row + 1, update_choc, new_frog_pos);
            }
        }

        void backtracking_2(int[] actual_variacion, int index, int frog_row, int choc_comidos, int[] frog_pos)
        {
            if (index == actual_variacion.Length)
            {
                backtracking_1(actual_variacion, frog_row, choc_comidos, frog_pos);
            }
            else
            {
                for (int i = -1; i <= 1; i++)
                {
                    int temp = actual_variacion[index];
                    actual_variacion[index] = i;
                    backtracking_2(actual_variacion, index + 1, frog_row, choc_comidos, frog_pos);
                    actual_variacion[index] = temp;
                }
            }
        }
        return best;
    }
}