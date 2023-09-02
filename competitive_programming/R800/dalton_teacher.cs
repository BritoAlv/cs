namespace dalton_teacher
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

                int count = 0;
                for (int i = 0; i < n; i++)
                {
                    if (values[i] == i+1)
                    {
                        count++;
                    }
                }

                Console.WriteLine(count / 2 + count % 2);

                test_cases--;
            }
        }
    }
}