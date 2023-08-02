namespace prefix_function_queries
{
    public class Test
    {
        public static void Main()
        {
            string S = Console.ReadLine();
            var pi = Prefix_function(S);
            int number_queries = int.Parse(Console.ReadLine());
            TrieNode root = new('@', -1);
            int[] answer = new int[10];
            while (number_queries > 0)
            {
                string q = Console.ReadLine();
                TrieNode actual = root;
                int count = 0;
                while (count < q!.Length)
                {
                    var next = actual.Find(q[count]);
                    if (next == null)
                    {
                        for (int i = count; i < q.Length; i++)
                        {
                            int k = i == 0 ? pi[^1] : answer[i - 1];
                            while (k > 0)
                            {
                                if (q[i] == ((k >= S.Length) ? q[k - S.Length] : S[k]))
                                {
                                    break;
                                }
                                else
                                {
                                    if (k <= S.Length)
                                    {
                                        k = pi[k - 1];
                                    }
                                    else
                                    {
                                        k = answer[k - S.Length - 1];
                                    }
                                }
                            }
                            answer[i] = q[i] == ((k >= S.Length) ? q[k - S.Length] : S[k]) ? k + 1 : 0;
                            Console.Write(answer[i] + " ");
                            actual = actual.Add(q[i], answer[i]);
                        }
                        break;
                    }
                    else
                    {
                        answer[count] = next.Value;
                        Console.Write(answer[count] + " ");
                        count++;
                        actual = next;
                    }
                }
                number_queries--;
            }
        }
        public static int[] Prefix_function(string s)
        {
            int[] pi = new int[s.Length];
            pi[0] = 0;
            for (int i = 1; i < s.Length; i++)
            {
                int k = pi[i - 1];
                while (k > 0)
                {
                    if (s[i] == s[k])
                    {
                        break;
                    }
                    else
                    {
                        k = pi[k - 1];
                    }
                }
                if (s[i] == s[k])
                {
                    pi[i] = k + 1;
                }
            }
            return pi;
        }
        public class TrieNode
        {
            public TrieNode(char letter, int value)
            {
                Letter = letter;
                Value = value;
            }
            public char Letter { get; }
            public int Value { get; }
            public Dictionary<char, TrieNode> childs = new();
            internal TrieNode? Find(char v)
            {
                if (childs.ContainsKey(v))
                {
                    return childs[v];
                }
                return null;
            }
            internal TrieNode Add(char v, int index)
            {
                var trieNode = new TrieNode(v, index);
                childs[v] = trieNode;
                return trieNode;
            }
        }
    }
}