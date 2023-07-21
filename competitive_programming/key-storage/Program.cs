public class Test
{
    public static void Main()
    {
        var ans = generate_multiset(123456);
        Console.WriteLine(algorithm(ans, ans.Values.Sum()+1 , ans.Values.Sum()+1)-1);
    }
    
    public static Dictionary<long, long> generate_multiset(long n, long seed = 2)
    {
        Dictionary<long, long> answer = new Dictionary<long, long>();
        while (n > 0)
        {
            var next_n = n / seed;
            if (!answer.ContainsKey(n % seed))
            {
                answer[n % seed] = 0;
            }
            answer[n % seed]++;
            n = next_n;
            seed++;
        }
        return answer;
        /*
        but what I need really is foreach value that the seed take how many distinct remainders are less than it. 
        */
    }
    static long compute_factorial( long n)
    {
        long answer = 1;
        for (long i = 2; i <= n; i++)
        {
            answer *= i;
        }
        return answer;
    }
}