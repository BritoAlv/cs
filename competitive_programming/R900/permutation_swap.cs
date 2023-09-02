namespace permutation_swap
{
    public class Test
    {
        public static void Algorithm()
        {
            int test_cases = int.Parse(Console.ReadLine());
            while (test_cases > 0)
            {
                int n = int.Parse(Console.ReadLine());
                int[] values = Console.ReadLine().Split().Select(x => int.Parse(x)).ToArray();
                int[] pos = new int[n];
                for (int i = 0; i < n; i++)
                {
                    pos[values[i] - 1] = i + 1;
                }

                Console.WriteLine(Gcd(pos.Select((x, y) => (Math.Abs(x - (y + 1)))).Where(x => x > 0).ToList()));
                test_cases--;
            }
        }

        public static int Gcd(int a, int b)
        {
            if (a < b)
            {
                (a, b) = (b, a);
            }

            /*
            a >= b
            */

            if (a % b == 0)
            {
                return b;
            }
            else
            {
                return Gcd(a % b, b);
            }
        }

        public static int Gcd(List<int> numbers)
        {
            if (numbers.Count == 1)
            {
                return numbers[0];
            }
            else
            {
                var initial_gcd = Gcd(numbers[0], numbers[1]);
                for (int i = 2; i < numbers.Count; i++)
                {
                    initial_gcd = Gcd(initial_gcd, numbers[i]);
                }
                return initial_gcd;
            }
        }
    }


}
