namespace united_we_stand;

public class Test
{
    public static void Algorithm()
    {
        int test_cases = int.Parse(Console.ReadLine());
        while (test_cases > 0)
        {
            int n = int.Parse(Console.ReadLine());
            var values = Console.ReadLine().Split().Select(int.Parse);
            int max = 0;
            foreach (var item in values)
            {
                if (item > max)
                {
                    max = item;
                }
            }
            List<int> b = new();
            List<int> c = new();

            foreach (var item in values)
            {
                if (item == max)
                {
                    c.Add(item);
                }
                else
                {
                    b.Add(item);
                }
            }                
            if (c.Count == n) 
            {
                Console.WriteLine(-1);
            }
            else
            {
                Console.WriteLine(b.Count + " " + c.Count);
                Console.WriteLine(string.Join(" ", b));
                Console.WriteLine(String.Join(" ", c));
            }    
            test_cases--;
        }
    }
}
