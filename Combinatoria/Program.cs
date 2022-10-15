class permutacion
{
    public static void Main()
    {
        List<int> numbers = new List<int>() { 1, 2, 3, 4, 5, 6, 7 };
        Console.WriteLine("Estas son las variaciones: ");
        generate_variaciones(numbers, 2);
        Console.WriteLine();
        Console.WriteLine("Estas son las permutaciones: ");
        generate_combinaciones(numbers, 3);
    }


    /*
    given a list of numbers (there may be repeated ones return all its variacionrd) 
    */
    public static void generate_variaciones(List<int> numbers, int size)
    {
        // Básico Sin Optimizar.
        bool[] taken = new bool[numbers.Count];
        variacion(new List<int>(size), taken, numbers);
        void variacion(List<int> actual_variacion, bool[] tomadas, List<int> numbers)
        {
            if (actual_variacion.Count == size)
            {
                // do whatever with the variacion
                foreach (var num in actual_variacion)
                {
                    Console.Write(num + " ");
                }
                Console.WriteLine();
                return;
            }
            else
            {
                for (int i = 0; i < numbers.Count; i++)
                {
                    if (condition_to_pick(i))
                    {
                        tomadas[i] = true;
                        actual_variacion.Add(numbers[i]);
                        variacion(actual_variacion, taken, numbers);
                        actual_variacion.RemoveAt(actual_variacion.Count - 1);
                        tomadas[i] = false;
                    }
                }
            }
            /*
            the condition here to pick an element is that it hasn't been taken before.
            Porque son sin repetición, en caso contrario, no hay condición
            */
            bool condition_to_pick(int i)
            {
                return !tomadas[i];
            }
        }
    }


    public static void generate_combinaciones(List<int> numbers, int size)
    {
        // combinacion(new List<int>(size), numbers);
        combinacion_optimized(new bool[numbers.Count], 0, 0);

        /*
        Básico Sin Optimizar.
        */
        void combinacion(List<int> actual_combinacion, List<int> numbers)
        {
            if (actual_combinacion.Count == size)
            {
                // do whatever with the combinación.
                foreach (var num in actual_combinacion)
                {
                    Console.Write(num + " ");
                }
                Console.WriteLine();
                return;
            }
            else
            {
                for (int i = 0; i < numbers.Count; i++)
                {
                    if (condition_to_pick(i))
                    {
                        actual_combinacion.Add(numbers[i]);
                        combinacion(actual_combinacion, numbers);
                        actual_combinacion.RemoveAt(actual_combinacion.Count - 1);
                    }
                }
            }
            /*
            the condition here to pick an element is that is greater than the ones picked before. porque son sin repetición, como
            el elemento que escogemos es mayor que los anteriores es distinto a lo anteriores si queremos que sea con repetición,
            entonces basta con cambiar > por >=. 
            */
            bool condition_to_pick(int i)
            {
                if (actual_combinacion.Count > 0)
                {
                    return numbers[i] > actual_combinacion.Max();
                }
                return true;
            }
        }

        void combinacion_optimized(bool[] tomadas, int cant_tomadas, int lower)
        /*
        En esta solución usamos una máscara booleana para el backtracking, llevamos la cuenta de la variación que tenemos y el número que tenemos que poner. el
        tema de la condición to pick lo eliminamos al llevar lower.
        */
        {
            if (cant_tomadas == size)
            {
                // do whatever with the combinación.
                for (int i = 0; i < numbers.Count; i++)
                {
                    if (tomadas[i])
                    {
                        Console.Write(numbers[i] + " ");
                    }
                }
                Console.WriteLine();
                return;
            }
            else
            {
                for (int i = lower; i < numbers.Count; i++)
                {
                    tomadas[i] = true;
                    combinacion_optimized(tomadas, cant_tomadas + 1, i + 1);
                    tomadas[i] = false;
                }
            }
        }

    }

}