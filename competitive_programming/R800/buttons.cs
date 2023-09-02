namespace buttons
{
    public class Test
    {
        public static void Algorithm()
        {
            int test_cases = int.Parse(Console.ReadLine());
            while (test_cases > 0)
            {
                int[] entry = Console.ReadLine().Split().Select(x => int.Parse(x)).ToArray();
                int a = entry[0];
                int b = entry[1];
                int c = entry[2];
                if ( (a >= b && c % 2 == 1) || (a > b && c % 2 == 0))
                {
                    Console.WriteLine("First");
                }
                else 
                {
                    Console.WriteLine("Second");
                }
                test_cases--;
            }
        }
    }
}