public static class solution_1
{
    public static List<int> get_min_sequence(bool[,] map)
    {
        /*
        bool[a,b] means that switch a controls lamp b
        */

        // global setup
        int number_lamps = map.GetLength(1);
        List<int> min_secuence = new List<int>(map.GetLength(0));
        // builing a not empty and not valid sequence to be like int.MAX to 
        for (int i = 0; i <= map.GetLength(0); i++)
        {
            min_secuence.Add(i);
        }
        bool[] lamps_on = new bool[map.GetLength(1)];
        int cant_lamps_on = 0;
        bool[] actual_sequence = new bool[map.GetLength(0)];
        int cant_switches = 0;
        // global setup

        void backtracking(int interruptor)
        {
            // this should generate all the subsets of the interruptores and for each one check if it turn on all the lamps.

            // base case either interruptor is big enough or we know already a secuence with minimal length.
            if (interruptor == map.GetLength(0) || cant_switches >= min_secuence.Count) // it's not a valid secuence. last check is a poda.
            {
                return;
            }

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
                backtracking(interruptor + 1);
            }
            // now we put the state of the lamps as before the backtrack
            execute_switch(interruptor); // O(n)
            actual_sequence[interruptor] = false; // remove is O(1) in HashSet
            cant_switches--;

            // we do the backtrack but without this interruptor.
            backtracking(interruptor + 1);
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
        // execute the backtracking.
        backtracking(0);
        // return min_sequence.
        return (min_secuence.Count <= map.GetLength(0)) ? min_secuence : new List<int>();
    }
}
