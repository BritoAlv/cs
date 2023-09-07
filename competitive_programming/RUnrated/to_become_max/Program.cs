namespace to_become_max
{
    public class Test
    {
        public static void Main()
        {
            long number_cases = long.Parse(Console.ReadLine());
            while (number_cases > 0)
            {
                long[] info = Console.ReadLine().Split().Select(long.Parse).ToArray();

                long n = info[0];
                long k = info[1];

                long[] values = Console.ReadLine()
                    .Split()
                    .Select(long.Parse)
                    .ToArray();

                Dictionary<(long, long), long> dp = new();

                long current_max = values.Max();
                long answer = current_max;
                long current_operations = 0;
                while (current_operations < long.MaxValue)
                {
                    current_operations = Get_least(current_max + 1, values, dp);
                    if (current_operations <= k)
                    {
                        if (current_max+1 > answer)
                        {
                            answer = current_max + 1;
                        }
                    }
                    current_max++;
                }
                Console.WriteLine(answer);
                number_cases--;
            }
        }

        /*
        para cada posible máximo obtenible recorrer todas las casillas donde es posible obtenerlo y calcular cuantos
        steps son necesarios para obtenerlo, escoger el mínimo entre todas las casillas, y guardarlo, devolver lo menor
        posible en a lo más de k operaciones.

        notar que para obtener un valor v en una casilla t, hay que hacer v-t pasos más la cantidad de pasos requerida en hacer
        el valor (v-1) en la casilla a la derecha, o si ya posee el valor v. No puede poseer un valor mayor que v porque si no no sería el
        máximo. So either tiene v o un valor menor que él.

        the problem is equivalent to para cada posición del array tratar de calcular el mayor valor posible que se pueda obtener
        hasta llegar a el punto en que no se pueda obtener más usando dp, y guardar el mayor valor obtenido en una cantidad <= k pasos.
        */

        static long Get_least(long v, long[] values, Dictionary<(long, long), long> dp)
        {
            long answer = long.MaxValue;
            for (long i = 0; i < values.Length - 1; i++)
            {
                var attempt = Get_least_position(v - 1, i + 1, values, dp);
                if (attempt < 0)
                {
                    if (answer < long.MaxValue)
                    {
                        break;
                    }
                    continue;
                }
                if (v - values[i] + attempt < answer)
                {
                    answer = v - values[i] + attempt;
                }
            }
            return answer;
        }

        static long Get_least_position(long value, long position, long[] values, Dictionary<(long, long), long> dp)
        {
            if (dp.ContainsKey((position, value)))
            {
                return dp[(position, value)];
            }
            if (position == values.Length -1)
            {
                if (value == values[^1])
                {
                    dp[(position, value)] = 0;
                    return 0;
                }
                dp[(position, value)] = -1;
                return -1;
            }
            if (value - values[position] < 0 || position >= values.Length)
            {
                /*
                value can't be obtained so return -1;
                */
                dp[(position, value)] = -1;
                return -1;
            }
            if (value - values[position] == 0)
            {
                dp[(position, value)] = 0;
                return 0;
            }

            if (value - values[position] > 0)
            {
                if (values[position+1] >= value)
                {
                    dp[(position, value)] = value - values[position];
                    return value - values[position];
                }
                var attempt = Get_least_position(value - 1, position + 1, values, dp);
                if (attempt >= 0)
                {
                    dp[(position, value)] = value - values[position] + attempt;
                    return value - values[position] + attempt;
                }
                else
                {
                    dp[(position, value)] = -1;
                    return -1;
                }
            }
            dp[(position, value)] = -1;
            return -1;
        }
    }
}