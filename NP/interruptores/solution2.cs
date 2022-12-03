public static class solution_2
{
    /*
    This solution obtains all the subsets, now for every of them counts how many switches it has, 
    and for every switch how many lamps him/it turns on. This generate
    all subsets in the order defined by the backtracking.
    */
    public static List<int> get_min_sequence(bool[,] valores)
    {
        // global setup
        int min = int.MaxValue;
        List<int> result = new List<int>();
        // global setup 
        Lampar(valores, new bool[valores.GetLength(0)], new bool[valores.GetLength(1)], 0);
        return result;
        void Lampar(bool[,] valores, bool[] inter, bool[] lamp, int pos)
        {
            if (pos == inter.Length) // obtain subsets.
            {
                // counting switches.
                int cant = 0;
                for (int i = 0; i < valores.GetLength(0); i++)
                {
                    if (inter[i])
                    {
                        cant++;
                    }
                    else
                    {
                        continue;
                    }
                    if (cant >= min)
                    {
                        break; // stop if there are a lot
                    }
                    for (int j = 0; j < valores.GetLength(1); j++)
                    {
                        if (valores[i, j])
                        {
                            lamp[j] = !(lamp[j]);
                        }
                    }
                }

                // counting switches.

                if (check(lamp) && cant < min) // turns on all the lamps and have less interruptores than min.
                {
                    min = cant;
                    result = new List<int>(inter.Length);
                    for (int i = 0; i < inter.Length; i++)
                    {
                        if (inter[i])
                        {
                            result.Add(i);
                        }
                    }
                }
            }
            // backtracking part very abstracted resumido está totalmente aparte del core de la función.
            if (pos < inter.Length)
            {
                Lampar(valores, inter, new bool[lamp.Length], pos + 1);
                inter[pos] = true;
                Lampar(valores, inter, new bool[lamp.Length], pos + 1);
                inter[pos] = false;
            }
        }
        bool check(bool[] mask)
        {
            for (int i = 0; i < mask.Length; i++)
                if (!mask[i])
                {
                    return false;
                }
            return true;
        }
    }
}