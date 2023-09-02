namespace comparison_string
{
    public class Test
    {
        public static void Algorithm()
        {
            int test_cases = int.Parse(Console.ReadLine());
            while (test_cases > 0)
            {
                int n = int.Parse(Console.ReadLine());
                string binary1 = Console.ReadLine();
                int max_dif = 2;
                int current_dif = 1;
                for (int i = 0; i < n; i++)
                {
                    if (i == n - 1 || binary1[i] != binary1[i + 1])
                    {
                        if (current_dif + 1 > max_dif)
                        {
                            max_dif = current_dif + 1;
                        }
                        current_dif = 1;
                    }
                    else
                    {
                        current_dif++;
                    }
                }
                Console.WriteLine(max_dif);
                test_cases--;
            }
        }
    }
}