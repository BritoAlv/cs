namespace channel
{
    public class Test
    {
        public static void Algorithm()
        {
            int test_cases = int.Parse(Console.ReadLine());
            while (test_cases > 0)
            {
                int[] vars = Console.ReadLine().Split().Select(x => int.Parse(x)).ToArray();
                int n = vars[0];
                int a = vars[1];
                int q = vars[2];
                string info = Console.ReadLine();
                int index = 0;
                int person_out = 0;
                int already_read = a;
                int online = 0;
                while (index < q)
                {
                    if (info[index] == '-')
                    {
                        person_out--;
                    }
                    if (info[index] == '+')
                    {
                        person_out++;
                        online++;
                    }
                    if (person_out == 1)
                    {
                        already_read++;
                        person_out--;
                    }
                    index++;
                }
                if (already_read == n)
                {
                    Console.WriteLine("YES");
                }
                else if (a + online < n)
                {
                    Console.WriteLine("NO");
                }
                else
                {
                    Console.WriteLine("MAYBE");
                }
                test_cases--;
            }

        }
    }
}