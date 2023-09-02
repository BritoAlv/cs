namespace longest_divisor_interval
{
    public class Test
    {
        public static void Algorithm()
        {
            long test_cases = long.Parse(Console.ReadLine());
            while (test_cases > 0)
            {
                long n = long.Parse(Console.ReadLine());
                List<int> divisors = new();
                int answer = 1;
                divisors.Add(1);
                for (int i = 2; i <= 1000000; i++)
                {
                    if (n % i == 0)
                    {
                        answer++;
                    }
                    else
                    {
                        break;
                    }
                }
                Console.WriteLine(answer);
                test_cases--;
            }
        }
    }
}