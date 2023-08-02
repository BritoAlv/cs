public class Test
{
    public static void Main()
    {
        string[] nk = Console.ReadLine().Split(" ");
        int n = int.Parse(nk[0]);
        int k = int.Parse(nk[1]);
        long[] exactly_bad_positiions = new long[k];
        long answer = 1;
        for (int i = 1; i <= k; i++)
        {
            answer += Combinations(n, i) * Exactly_bad_posicions(exactly_bad_positiions, i);
        }

        Console.WriteLine(answer);
    }
    private static Int64 Exactly_bad_posicions(Int64[] array, int i)
    {
        if (array[i - 1] > 0)
        {
            return array[i - 1];
        }
        else
        {
            if (i == 1)
            {
                array[0] = 0;
                return 0;
            }
            if (i == 2)
            {
                array[1] = 1;
                return 1;
            }
            else
            {
                Int64 answer = (i - 1) * (Exactly_bad_posicions(array, i - 1) + Exactly_bad_posicions(array, i - 2));
                array[i - 1] = answer;
                return answer;
            }
        }
    }
    private static Int64 Combinations(int n, int i)
    {
        Int64 answer = 1;
        for (int j = 0; j < i; j++)
        {
            answer = answer * (n - j) / (j + 1);
        }
        return answer;
    }
}