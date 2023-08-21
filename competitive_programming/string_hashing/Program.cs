namespace string_hashing
{
    public class Hasher
    {
        readonly long[] prefix_hashes;
        private readonly string s;
        private readonly int M;
        readonly long[] p_pows;
        public Hasher(string s, int p = 31, int M = 1000000000 + 3)
        {
            prefix_hashes = new long[s.Length + 1];
            p_pows = new long[s.Length + 1];
            p_pows[0] = 1;
            for (int len = 1; len <= s.Length; len++)
            {
                prefix_hashes[len] = (prefix_hashes[len-1] + (s[len-1] - 'a' + 1) * p_pows[len-1]) % M;
                p_pows[len] = p * p_pows[len-1] % M;
            }
            this.s = s;
            this.M = M;
        }
        public long Get_hash_substring(int i, int j)
        {
            if (i > j)
            {
                (i, j) = (j, i);
            }
            return (prefix_hashes[j + 1] + M - prefix_hashes[i]) % M;
        }
        public static long Compute_hash(string s, long p = 31, long M = 1000000000 + 3)
        {
            long hash = 0;
            long p_pow = 1;
            for (int i = 0; i < s.Length; i++)
            {
                hash += p_pow * (s[i] - 'a' + 1) % M;
                p_pow = p * p_pow % M;
            }
            return hash;
        }
        public int Count_different_substrings()
        {
            int answer = 0;
            for (int len = 1; len <= s.Length; len++)
            {
                HashSet<long> hashes = new();
                for (int index = 0; index <= s.Length - len; index++)
                {
                    var hash = Get_hash_substring(index, index + len - 1) * p_pows[ s.Length - index] % M;
                    if (!hashes.Contains(hash))
                    {
                        hashes.Add(hash);
                    }
                }
                answer += hashes.Count;
            }
            return answer;
        }           
    }
    public class Test
    {
        public static void Main()
        {
            Hasher hasher = new("acbacbacaa");
            Console.WriteLine(hasher.Count_different_substrings());
        }
    }
}