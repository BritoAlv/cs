namespace split_sort
{
    public class TestI
    {
        public static void Algorithm()
        {
            int test_cases = int.Parse(Console.ReadLine());
            while (test_cases > 0)
            {
                int n = int.Parse(Console.ReadLine());
                int[] values = Console.ReadLine().Split().Select(x => int.Parse(x)).ToArray();

                Dictionary<int, int> positions = new();
                for (int i = 0; i < values.Length; i++)
                {
                    positions[values[i]] = i + 1;
                }
                int answer = 0;
                int upper = n;
                while (upper > 1)
                {
                    if (positions[upper] - (n - upper) == upper)
                    {
                        upper--;
                    }
                    if (upper <= 1)
                    {
                        break;
                    }
                    var low = upper - 1;
                    while (positions[low] < positions[low + 1])
                    {
                        low--;
                        if (low == 0)
                        {
                            answer--;
                            break;
                        }
                    }
                    upper = low;
                    answer++;
                    /**/
                }
                Console.WriteLine(answer);
                test_cases--;
            }

        }

    }
}

