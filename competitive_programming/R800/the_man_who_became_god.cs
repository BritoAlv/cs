namespace the_man_who_became_god
{
    public class Test
    {
        public static void Algorithm()
        {
            int test_cases = int.Parse(Console.ReadLine());
            while (test_cases > 0)
            {
                int[] fix = Console.ReadLine().Split().Select(x => int.Parse(x)).ToArray();
                int n = fix[0];
                int k = fix[1];
                int[] values = Console.ReadLine().Split().Select(x => int.Parse(x)).ToArray();
                int[] diferences = new int[n - 1];
                for (int i = 0; i < n - 1; i++)
                {
                    diferences[i] = Math.Abs(values[i] - values[i + 1]);
                }
                Array.Sort(diferences);
                long answer = 0;
                for (int i = 0; i < diferences.Length - k+1; i++)
                {
                    answer += diferences[i];
                }
                Console.WriteLine(answer);
                test_cases--;
            }
        }
    }
}