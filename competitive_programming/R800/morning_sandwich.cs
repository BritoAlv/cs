namespace morning_sandwich
{
    public class Test
    {
        public static void Algorithm()
        {
            int test_cases = int.Parse(Console.ReadLine());
            while (test_cases > 0)
            {
                int[] values = Console.ReadLine().Split().Select(x => int.Parse(x)).ToArray();
                int b = values[0];
                int c = values[1];
                int h = values[2];

                Console.WriteLine(1 + 2 * Math.Min(b - 1, c + h));

                test_cases--;
            }
        }
    }
}