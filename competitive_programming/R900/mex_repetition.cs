namespace mex_repetition
{
    public class Test
    {
        public static void Algorithm()
        {
            long test_cases = long.Parse(Console.ReadLine());
            while (test_cases > 0)
            {
                int[] fix = Console.ReadLine().Split().Select(x => int.Parse(x)).ToArray();
                int n = fix[0];
                int k = fix[1];
                List<int> values = Console.ReadLine().Split().Select(x => int.Parse(x)).ToList();

                bool[] used = new bool[n + 1];
                for (int i = 0; i < n; i++)
                {
                    used[values[i]] = true;
                }

                int index = 0;
                while (used[index])
                {
                    index++;
                }
                values.Add(index);
                int[] answer = new int[n];
                if (k % (n + 1) == 0)
                {
                    answer[0] = values[0];
                }
                else
                {
                    answer[0] = values[^(k % (n + 1))];
                }

                int current_pos = 0;
                while (values[current_pos] != answer[0])
                {
                    current_pos++;
                }
                for (int i = 1; i < n; i++)
                {
                    answer[i] = values[(current_pos + i) % (n + 1)];
                }
                Console.WriteLine(string.Join(" ", answer));
                test_cases--;
            }
        }
    }
}