namespace good_substrings
{
    public class Test
    {
        public static void Main()
        {            
            string input = Console.ReadLine();
            bool[] good_bad_letters = Console.ReadLine().Select(x => x == '1').ToArray();
            int k = int.Parse(Console.ReadLine());
            int[] good_len = new int[input.Length+1];
            long[] p_pow = new long[input.Length+1];
            long[] prefix_hashes = new long[input.Length+1];
            good_len[0] = 0;
            p_pow[0] = 1;
            for (int len = 1; len <= input.Length; len++)
            {
                /*
                Accumulative tables.
                */
                good_len[len] = good_len[len-1] + (good_bad_letters[input[len-1] - 'a'] ? 0 : 1);
                prefix_hashes[len] = (prefix_hashes[len-1] + (input[len-1] - 'a'+1) * p_pow[len-1]) % 1000000003;
                p_pow[len] = p_pow[len - 1] * 31 % 1000000003;
            }
            long answer = 0;
            for (int len = 1; len <= input.Length; len++) // iterate over all possible lengths of a substring
            {
                HashSet<long> valids = new(); // a hash set to store hashes
                for (int index = 0; index <= input.Length - len; index++) // iterate over all the possible index that can be for that length.
                {
                    if (good_len[index+len] - good_len[index] <= k)
                    {
                        var hash = ((prefix_hashes[index + len] + 1000000003 - prefix_hashes[index]) % 1000000003) * p_pow[ input.Length - index] % 1000000003 ;
                        if (!valids.Contains(  hash  ))
                        {
                            valids.Add(hash);
                        }
                    }
                }
                answer += valids.Count;
            }
            Console.WriteLine(answer);
        }
    }
}