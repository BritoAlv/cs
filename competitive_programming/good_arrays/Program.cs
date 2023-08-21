namespace good_arrays
{
    public class Test
    {
        public static void Main()
        {
            int number_cases = int.Parse(Console.ReadLine());
            while (number_cases > 0)
            {
                int len = int.Parse(Console.ReadLine());
                int[] values = Console.ReadLine().Split().Select(x => int.Parse(x)).ToArray();
                bool works = true;
                int one_counts = 0;
                long sum = 0; 
                for (int i = 0; i < values.Length; i++)
                {
                    if (values[i] == 1)
                    {
                        one_counts++;
                    }
                    else
                    {
                        sum += values[i];
                    }
                }
                int no_one = len - one_counts;
                
                if (len == 1)
                {
                    works = false;
                }

                if (sum - no_one < one_counts)
                {
                    works = false;
                }
                Console.WriteLine(works ? "YES" : "NO");
                number_cases--;
            }
        }
    }
}