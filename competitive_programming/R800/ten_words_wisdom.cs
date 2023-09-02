namespace ten_words_wisdom
{
    public class Test
    {
        public static void Algorithm()
        {
            int test_cases = int.Parse(Console.ReadLine());
            while (test_cases > 0)
            {
                int n = int.Parse(Console.ReadLine());
                int index = 1;
                int value_answer = -1;
                int index_answer = -1;
                while (n > 0)
                {
                    int[] values = Console.ReadLine().Split().Select(x => int.Parse(x)).ToArray();
                    if(values[0] <= 10 && values[1] >= value_answer)
                    {
                        index_answer = index;
                        value_answer = values[1];
                    }
                    index++;
                    n--;
                }
                Console.WriteLine(index_answer);
                test_cases--;
            }
        }
    }
}