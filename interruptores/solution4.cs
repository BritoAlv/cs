public static class solution_4
{
    /*
    this is a diferent solution because this one will generate all subsets of size 1,
    check and if not generate all subsets of size 2, and so on, until it generates all
    subsets of size all interruptors. 
    */
    public static List<int> get_min_sequence(bool[,] map)
    {
        int number_lamps = map.GetLength(1);
        List<int> min_sequence = new List<int>();
        for (int i = 1; i <= map.GetLength(0); i++) // generate subsets of size i
        {
            if (subsets(map.GetLength(0)-1, 0, new int[i], 0))
            {
                break;
            }
        }
        return min_sequence;
        /*
        La siguiente función toma como argumento range, que representa los números de 0 a range, toma una
        variable que se llama cuantas que indica cuantos elementos tiene la combinación, y un entero que
        se llama menor a poner que indica a partir de que parte de 0 a m añadir elementos a la combinación.
        */
        bool subsets(int range, int cuantas , int[] actual_comb, int menorAPoner)
        {
            if (cuantas == actual_comb.Length) // we have a comb so we need to check if it is a valid one.
            {
                int cant_lamps_on = 0;
                bool[] lamps_on = new bool[map.GetLength(1)];
                for (int i = 0; i < actual_comb.Length; i++)
                {
                    for (int j = 0; j < map.GetLength(1); j++)
                    {
                        if (map[actual_comb[i], j])
                        {
                            if (lamps_on[j])
                            {
                                lamps_on[j] = false;
                                cant_lamps_on--;
                            }
                            else
                            {
                                lamps_on[j] = true;
                                cant_lamps_on++;
                            }
                        }
                    }
                }
                if (cant_lamps_on == map.GetLength(1))
                {
                    min_sequence = actual_comb.ToList();
                    return true;
                }
                return false;
            }
            else
            {
                for (int k = menorAPoner; k <= range; k++)
                {
                    actual_comb[cuantas] = k;
                    if (subsets(range, cuantas + 1, actual_comb, k + 1))
                    {
                        return true;
                    }
                }
            }
            return false;
        }    
    }
}