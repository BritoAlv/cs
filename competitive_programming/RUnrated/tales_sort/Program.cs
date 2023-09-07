namespace tales_sort
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

                int answer = 0;
                int max = values[0];
                bool works = false;
                for (int i = 1; i < values.Length; i++)
                {
                    if (values[i] < max)
                    {
                        answer = max;
                        works = true;
                    }
                    if (values[i] > max)
                    {
                        max = values[i];
                    }
                }
                Console.WriteLine(answer);
                number_cases--;
            }
        }
    }
}