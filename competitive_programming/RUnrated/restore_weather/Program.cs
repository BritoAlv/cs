public class Test
{
    public static void Main()
    {
        int test_cases = int.Parse(Console.ReadLine());
        List<int[]> answers = new List<int[]>();
        while (test_cases > 0)
        {
            string[] first_line = Console.ReadLine().Split();
            int n = int.Parse(first_line[0]);
            int k = int.Parse(first_line[1]);

            List<(int, int)> second_line = Console.ReadLine().Split().Select((x,m) => (m,int.Parse(x))).ToList();
            int[] third_line = Console.ReadLine().Split().Select(x => int.Parse(x)).ToArray();
            answers.Add(algorithm(second_line, third_line));
            test_cases--;
        }
        foreach (var resp in answers)
        {
            foreach (var temp in resp)
            {
                Console.Write(temp + " ");
            }
            Console.WriteLine();
        }
    }

    static int[] algorithm(List<(int, int)> estimated, int[] real)
    {
        
        Array.Sort(real);
        int[] answer = new int[real.Length];
        int index = 0;
        foreach (var item in estimated.OrderBy(x => x.Item2))
        {
            answer[ item.Item1] = real[index];
            index++;
        }
        
        return answer;
    }
}