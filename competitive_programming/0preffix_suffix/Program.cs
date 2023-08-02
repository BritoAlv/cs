namespace preffix_suffix
{
    public class Test
    {
        public static void Main()
        {
            string S = Console.ReadLine();
            int[] pi = new int[S.Length];
            pi[0] = 0;
            for (int i = 1; i < S.Length; i++)
            {
                int k = pi[i - 1];
                while (k > 0)
                {
                    if (S[i] == S[k])
                    {
                        break;
                    }
                    else
                    {
                        k = pi[k - 1];
                    }
                }
                if (S[i] == S[k])
                {
                    pi[i] = k + 1;
                }
            }
            var count = new int[S.Length + 1];
            for (int i = 1; i < S.Length; i++)
            {
                var start = pi[i];
                while (start > 0)
                {
                    count[start]++;
                    start = pi[start - 1];
                }
            }

            Stack<(int, int)> values = new();
            values.Push((S.Length, 1));
            var begin = pi[^1];
            while (begin > 0)
            {
                values.Push((begin, count[begin] + 1));
                begin = pi[begin - 1];
            }
            Console.WriteLine(values.Count);
            while (values.Count > 0)
            {
                var popp = values.Pop();
                Console.WriteLine(popp.Item1 + " " + popp.Item2);
            }

        }
    }
}