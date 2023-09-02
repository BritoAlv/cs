namespace balanced_round
{
    public class Test
    {
        public static void Algorithm()
        {
            int test_cases = int.Parse(Console.ReadLine());
            while (test_cases > 0)
            {
                int[] fix = Console.ReadLine().Split().Select(x => int.Parse(x)).ToArray();
                int n = fix[0];
                int k = fix[1];

                int[] values = Console.ReadLine().Split().Select(x => int.Parse(x)).ToArray();

                Array.Sort(values);
                List<int> positions = new();

                for (int i = 1; i < n; i++)
                {
                    if (values[i] - values[i - 1] > k)
                    {
                        positions.Add(i);
                    }
                }
                int answer = n;
                if (positions.Count > 0)
                {
                    answer = Math.Max(positions[0], n - positions[^1]);
                }

                for (int i = 1; i < positions.Count; i++)
                {
                    if (positions[i] - positions[i - 1] > answer)
                    {
                        answer = positions[i] - positions[i - 1];
                    }
                }
                Console.WriteLine(n - answer);

                test_cases--;
            }
        }
    }
}