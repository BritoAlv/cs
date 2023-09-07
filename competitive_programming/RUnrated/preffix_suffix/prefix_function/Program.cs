namespace suffix_preffix
{
    public class Test
    {
        public static void Main()
        {
            string S = Console.ReadLine();
            int[] pi = new int[S.Length];
            int[] count = new int[S.Length];
            for (int i = 1; i < pi.Length; i++)
            {
                int k = pi[i - 1];
                while (k > 0)
                {
                    if (S[i] == S[k])
                    {
                        break;
                    }
                    k = pi[k - 1];

                }
                if (S[i] == S[k])
                {
                    pi[i] = k + 1;
                    count[k + 1]++;
                }
            }

            Stack<int> ans = new();
            int start = pi[^1];
            while (start > 0)
            {
                ans.Push(start);
                start = pi[start-1];
            }
            for (int len = S.Length - 1; len >= 1; len--)
            {
                if (count[len] > 0)
                {
                    count[pi[len-1]] += count[len];
                }    
            }
            Console.WriteLine(ans.Count+1);
            while (ans.Count > 0)
            {
                var popped = ans.Pop();
                Console.WriteLine(popped + " " + (count[popped] + 1));
            }
            Console.WriteLine(S.Length + " " + 1);
        }
    }
}