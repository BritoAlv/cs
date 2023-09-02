namespace sort_with_step
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
                int[] pos = new int[n];
                for (int i = 0; i < n; i++)
                {
                    pos[values[i] - 1] = i + 1;
                }
                int to_fix = 0;
                for (int i = 0; i < n; i++)
                {
                    if (Math.Abs(pos[i] - (i + 1)) % k != 0)
                    {
                        to_fix++;
                    }
                }

                if (to_fix == 2)
                {
                    Console.WriteLine("1");
                }
                else if (to_fix == 0)
                {
                    Console.WriteLine("0");
                }
                else
                {
                    Console.WriteLine("-1");
                }
                test_cases--;
            }
        }
    }
}
