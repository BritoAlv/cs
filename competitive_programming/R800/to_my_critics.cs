namespace to_my_critics
{
    public class Test
    {
        public static void Algorithm()
        {
            int test_cases = int.Parse(Console.ReadLine());
            while (test_cases > 0)
            {
                int[] values = Console.ReadLine().Split().Select(x => int.Parse(x)).ToArray();

                if (
                    values[0] + values[1] >= 10 ||
                    values[0] + values[2] >= 10 ||
                    values[1] + values[2] >= 10)
                {
                    Console.WriteLine("YES");
                }
                else
                {
                    Console.WriteLine("NO");
                }
                test_cases--;
            }
        }
    }
}