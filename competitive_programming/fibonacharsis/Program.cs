namespace fibonacharsis
{
    public class Test
    {
        static readonly long[] fib = new long[32];
        public static void Main()
        {
            fib[0] = 0;
            fib[1] = 1;
            for (long i = 2; i < fib.Length; i++)
            {
                fib[i] = fib[i - 1] + fib[i - 2];
            }
            int t = int.Parse(Console.ReadLine());
            int[] answers = new int[t];
            while (t > 0)
            {
                string[] numbers = Console.ReadLine().Split();
                int n = int.Parse(numbers[0]);
                int k = int.Parse(numbers[1]);
                answers[^t] = Alg(n, k);
                t--;
            }
            for (int i = 0; i < answers.Length; i++)
            {
                Console.WriteLine(answers[i]);
            }
        }
        private static int Alg(int last_element, int len)
        {
            /*
            last_element = f_2*fib_{len-1} + f_1*fib_{len-2}
            Problem is equivalent to counting non-negative solutions (a,b) with a <= b to the equation:
            last_element = b*fib[len-1] + a*fib[len-2];
            */
            if (len >= 30)
            {
                return 0;
            }
            int answer = 0;
            var part_solution = Solve_diop(fib[len - 1], fib[len - 2]);
            var x0 = part_solution.Item1 * last_element;
            var y0 = part_solution.Item2 * last_element;
            if (x0 <= 0)
            {
                var min_positive = (-x0 / fib[len - 2])-1;
                x0 += min_positive * fib[len - 2];
                y0 -= min_positive * fib[len - 1];
                while (y0 >= 0)
                {
                    if (x0 >= y0 && y0 >= 0)
                    {
                        answer++;
                    }
                    x0 += fib[len - 2];
                    y0 -= fib[len - 1];
                }
            }
            else if (y0 <= 0)
            {
                var min_positive = (-y0 / fib[len - 1])-1;
                x0 -= min_positive * fib[len - 2];
                y0 += min_positive * fib[len - 1];
                while (x0 >= 0)
                {
                    if (x0 >= y0 && y0 >= 0)
                    {
                        answer++;
                    }
                    x0 -= fib[len - 2];
                    y0 += fib[len - 1];
                }
            }
            return answer;
        }


        public static (long, long) Solve_diop(long a, long b)
        {
            if (a < 0)
            {
                var temp = Solve_diop(-a, b);
                temp.Item1 = -temp.Item1;
                return temp;
            }
            if (b < 0)
            {
                var temp = Solve_diop(a, -b);
                temp.Item2 = -temp.Item2;
                return temp;
            }
            if (a < b)
            {
                var ans = Solve_diop(b, a);
                long temp = ans.Item1;
                ans.Item1 = ans.Item2;
                ans.Item2 = temp;
                return ans;
            }
            if (b == 1)
            {
                return (-1, a + 1);
            }
            var anss = Solve_diop(a - (a / b) * b, b);
            return (anss.Item1, anss.Item2 - (a / b) * anss.Item1);
        }
    }
}