public static class solution_3
{
    // esta solución es como las otros, pero con podas, expected to be more fast.

    /*
    esta solución en vez de generar todos los subconjuntos de los números de 0 a m-1, 
    quitaré algunos índices que no considero necesario tener en cuenta. Y generaré los
    subconjuntos con estos restantes.
    */
    public static List<int> get_min_sequence(bool[,] map)
    {
        /*
        bool[a,b] means that switch a controls lamp b
        */

        // global setup
        int number_lamps = map.GetLength(1);
        List<int> min_secuence = new List<int>(map.GetLength(0));
        List<int> valid_switches = new List<int>();
        // builing a not empty and not valid sequence to be like int.MAX of the switches. 
        for (int i = 0; i < map.GetLength(0); i++)
        {
            min_secuence.Add(i);
            valid_switches.Add(i);
        }
        min_secuence.Add(map.GetLength(0));
        bool[] lamps_on = new bool[map.GetLength(1)];
        int cant_lamps_on = 0;
        bool[] actual_sequence = new bool[map.GetLength(0)];
        int cant_switches = 0;
        // global setup

        //  si un interruptor controla todas las lámparas entonces debemos devolverlo directamente.
        //  si un interruptor no controla ninguna lámpara podemos quitarlo de los válidos.
        for (int i = 0; i < map.GetLength(0); i++)
        {
            bool all_lamps = true;
            bool at_least_one = false;
            for (int j = 0; j < map.GetLength(1); j++)
            {
                if (map[i, j])
                {
                    at_least_one = true;
                }
                else
                {
                    all_lamps = false;
                }
            }
            if (!(at_least_one))
            {
                valid_switches.Remove(i);
            }
            if (all_lamps)
            {
                return new List<int>() { i };
            }
        }

        // ahora si una lámpara es controlada por solamente un interruptor debemos añadirlo a el subconjunto necesariamente,
        HashSet<int> forced = new HashSet<int>();
        for (int i = 0; i < map.GetLength(1); i++) // recorremos por la columna
        {
            int index = 0;
            bool only_one = false;
            bool at_least_one = false;
            for (int j = 0; j < map.GetLength(0); j++) // recorremos por las filas
            {
                if (map[j, i])
                {
                    if (!at_least_one)
                    {
                        only_one = true;
                        at_least_one = true;
                        index = j;
                    }
                    else
                    {
                        only_one = false;
                    }
                }
            }
            if (only_one)
            {
                if (!forced.Contains(index)) // because it is possible that two lamps are only turn ob by the same switch
                {
                    forced.Add(index);
                    valid_switches.Remove(index);
                    cant_switches++;
                    for (int z = 0; z < map.GetLength(1); z++)
                    {
                        if (map[index, z])
                        {
                            if (!lamps_on[z])
                            {
                                cant_lamps_on++;
                            }
                            if (lamps_on[z])
                            {
                                cant_lamps_on--;
                            }
                            lamps_on[z] = !(lamps_on[z]);
                        }
                    }
                }


            }
        }


        void backtracking(int index_interruptor)
        {
            // this should generate all the subsets of the interruptores and for each one check if it turn on all the lamps.

            // base case either interruptor is big enough or we know already a secuence with minimal length.
            if (index_interruptor == valid_switches.Count || cant_switches >= min_secuence.Count) // it's not a valid secuence. last check is a poda.
            {
                return;
            }
            int interruptor = valid_switches[index_interruptor];
            // turn on current switch
            execute_switch(interruptor); // O(n)
            cant_switches++;
            actual_sequence[interruptor] = true;

            // if is valid update secuence 
            if (is_valid()) // constant time
            {
                valid_secuence(actual_sequence); // O(n)
            }
            // if is not valid we need to keep going
            else
            {
                backtracking(index_interruptor + 1);
            }
            // now we put the state of the lamps as before the backtrack
            execute_switch(interruptor); // O(n)
            actual_sequence[interruptor] = false; // remove is O(1) in HashSet
            cant_switches--;

            // we do the backtrack but without this interruptor.
            backtracking(index_interruptor + 1);
        }


        void valid_secuence(bool[] mask)
        {
            if (cant_switches < min_secuence.Count)
            {
                min_secuence = new List<int>(cant_switches);
                for (int i = 0; i < map.GetLength(0); i++)
                {
                    if (mask[i])
                    {
                        min_secuence.Add(i);
                    }
                }
            }
        }

        void execute_switch(int interruptor)
        {
            for (int i = 0; i < map.GetLength(1); i++)
            {
                if (map[interruptor, i])
                {
                    if (lamps_on[i])
                    {
                        cant_lamps_on--;
                    }
                    else
                    {
                        cant_lamps_on++;
                    }
                    lamps_on[i] = !lamps_on[i];
                }
            }
        }

        bool is_valid()
        {
            return (cant_lamps_on == map.GetLength(1));
        }

        // check if the forced are solutions.
        if (is_valid())
        {
            valid_secuence(actual_sequence); // O(n)
        }
        else
        {
            // execute the backtracking.
            backtracking(0);
        }
        // add to the working secuence the forced switches.
        foreach (var num in forced)
        {
            min_secuence.Add(num);
        }
        // return min_sequence.
        return (min_secuence.Count <= map.GetLength(0)) ? min_secuence : new List<int>();
    }
}
