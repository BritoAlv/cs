public class sudoku
{
    public static void Main()
    {
        int n = 9; // n should be perfect square
        int[,] board = new int[n,n];
        fill_sudoku(board, 0);
        /*
        define a method that given a board with some entries fill the board trying to make
        a sudoku and print it, else print this is not valid, to create sudoku.
        */
    }
    public static bool is_partially_valid(int[,] actual_boardint, int pos_row, int pos_column)
    {

        for (int i = 0; i < actual_boardint.GetLength(0); i++)
        {
            // that row can't have this number repeated.
            // loop through columns
            // board[pos_row, i]
            if( (i != pos_column) && actual_boardint[pos_row, i] == actual_boardint[pos_row, pos_column])
            {
                return false;
            }

            // that column can't have this number repeated.
            // loop through rows
            // board[i, pos_column]        
            if( (i != pos_row) && actual_boardint[i, pos_column] == actual_boardint[pos_row, pos_column])
            {
                return false;
            }
        }
        // the small box can't have this number repeated.
        // find small_square of pos.
        int len = (int)(Math.Sqrt(actual_boardint.GetLength(0)));
        int start_row_small_square = (pos_row/len)*len;
        int start_column_small_square = (pos_column/len)*len;
            
        for (int k = start_column_small_square; k < start_column_small_square + len ; k++)
        {
            for (int l = start_row_small_square; l < start_row_small_square + len; l++)
            {
                if ( (!(pos_row == l) || !(pos_column == k)) && actual_boardint[pos_row, pos_column] == actual_boardint[l,k])
                {
                    return false;
                }
            }
        }
        return true;
    }
    public static void fill_sudoku(int[,] actual_tablero, int iteration)
    {
        int len = actual_tablero.GetLength(0);
        if(iteration == actual_tablero.Length)
        {
            for (int i = 0; i < len; i++)
            {
                for (int j = 0; j < actual_tablero.GetLength(1); j++)
                {
                    Console.Write(actual_tablero[i,j] + " ");
                }
                Console.WriteLine();
            }
            Console.WriteLine();
            return;
        }

        int row = iteration / len;
        int column = iteration % len;
        for (int i = 1; i <= len; i++)
        {
            int temp = actual_tablero[row, column];
            actual_tablero[row, column] = i;
            if (is_partially_valid(actual_tablero, row, column))
            {
                fill_sudoku(actual_tablero, iteration+1);
            }
            actual_tablero[row, column] = temp;
        }
    }
}


