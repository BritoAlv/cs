namespace escalator_conversions
{
    public class Test
    {
        public static void Algorithm()
        {
            int test_cases = int.Parse(Console.ReadLine());
            while (test_cases > 0)
            {
                int[] values = Console.ReadLine().Split().Select(x => int.Parse(x)).ToArray();
                int n = values[0];
                int m = values[1];
                int k = values[2];
                int H = values[3];

                int[] heights = Console.ReadLine().Split().Select(x => int.Parse(x)).ToArray();
                int answer = 0;
                foreach (int alt in heights)
                {
                    var height_diference = Math.Max(H, alt) - Math.Min(H, alt);
                    if ( height_diference > 0 && height_diference % k == 0 && height_diference / k < m )
                    {
                        answer++;
                    }
                }
                Console.WriteLine(answer);
                test_cases--;
            }
        }
    }
}