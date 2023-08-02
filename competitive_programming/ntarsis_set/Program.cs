namespace ntarsis_set
{
    public class Test
    {
        public static void Main()
        {
            int number_cases = int.Parse(Console.ReadLine());
            long[] answers = new long[number_cases];
            while (number_cases > 0)
            {
                string[] val = Console.ReadLine().Split();
                int[] values = Console.ReadLine().Split().Select(x => int.Parse(x)).ToArray();
                answers[^number_cases] = Alg(int.Parse(val[1]), values);
                number_cases--;
            }
            foreach (var ans in answers)
            {
                Console.WriteLine(ans);
            }
        }
        public static long Alg(int number_days, int[] values)
        {
            if (values[0] != 1)
            {
                return 1;
            }
            long last_winner = 1;
            long number_x = 0;
            long index = 0;
            long already_found = 0;
            long counter = 1;
            while (already_found < number_days)
            {
                if (index == values.Length)
                {
                    last_winner = (number_days - already_found)*values.Length + last_winner;
                    already_found++;
                    break;
                }
                else if (values[index] == counter)
                {
                    number_x++;
                    index++;
                    continue;
                }
                else if (number_x + last_winner == counter)
                {
                    already_found++;
                    last_winner = number_x + last_winner;
                }
                counter++;
            }
            return last_winner;
        }
    }
}