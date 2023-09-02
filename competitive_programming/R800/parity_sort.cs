namespace parity_sort
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
                int[] sorted = new int[n];
                Array.Copy(values, sorted, n);
                Array.Sort(sorted);
                string answer = "YES";
                for (int i = 0; i < n; i++)
                {
                    /*
                    i represents the smallest element in the array.
                    now tuples[0] at item 1 contain the smallest
                    */
                    if ( (sorted[i] + values[i]) % 2 == 1)
                    {
                        answer = "NO";
                        break;
                    }
                }
                Console.WriteLine(answer);
                test_cases--;
            }
        }
    }
}