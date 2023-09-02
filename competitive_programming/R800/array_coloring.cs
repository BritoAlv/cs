namespace array_coloring
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
                int sum = values.Sum();
                if (n == 1 || sum % 2 == 1)
                {
                    Console.WriteLine("NO");
                }
                else
                {
                    Console.WriteLine("YES");
                }
                test_cases--;
            }
        }
    }
}