public class Test
{
    public static void Main()
    {
        string[] input = Console.ReadLine().Split();
        long l = long.Parse(input[0]);
        long r = long.Parse(input[1]);
        Console.WriteLine(alg(l, r));
    }

    public static long alg(long l, long r)
    {
        string binary1 = Convert.ToString(r, 2);
        string binary2 = Convert.ToString(l, 2).PadLeft(binary1.Length, '0');
        string answer = "";
        for (int i = 0; i < binary1.Length; i++)
        {
            if (binary1[i] == binary2[i])
            {
                answer = answer + '0';
            }
            else
            {
                for (int j = i; j < binary1.Length; j++)
                {
                    answer = answer + '1';
                }
                break;
            }
        }
        return Convert.ToInt64(answer, 2);
    }
}