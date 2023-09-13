namespace more_wrong
{
    public class Test
    {
        public static void Main()
        {
            int test_cases = int.Parse(Console.ReadLine());
            while (test_cases > 0)
            {
                int n = int.Parse(Console.ReadLine());
                int[] values = Console.ReadLine().Split().Select(x => int.Parse(x)).ToArray();
                Console.WriteLine(Mex(values));
                while (true)
                {
                    int got = int.Parse(Console.ReadLine());
                    if(got == -2)
                    {
                        return;
                    }
                    else if(got == -1)
                    {
                        break;
                    }
                    else
                    {
                        Console.WriteLine(got);
                    }
                }
                test_cases--;
            }
        }

        private static int Mex(int[] values)
        {
            Array.Sort(values);
            if (values[0] != 0)
            {
                return 0;
            }
            for(int i = 1; i < values.Length; i++)
            {
                if (values[i] - values[i-1] != 1)
                {
                    return values[i - 1] + 1;
                }                
            }
            return values[^1] + 1;           
        }
    }
}