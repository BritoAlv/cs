namespace preffix_suffix
{
    public class Test
    {
        public static void Main()
        {
            string S = Console.ReadLine();
            int[] z = new int[S.Length];
            z[0] = 0;
            int l = 0;
            for (int i = 1; i < S.Length; i++)
            {
                z[i] = Math.Min(z[i - l], Math.Max(0, l + z[l] - i));
                while (i + z[i] < S.Length && S[z[i]] == S[i + z[i]])
                {
                    z[i]++;
                }
                if (i + z[i] > l + z[l])
                {
                    l = i;
                }
            }
            Queue<int> valid = new();
            List<int> counts = new();
            for (int position = S.Length - 1; position >= 1; position--)
            {
                if (z[position] > 0)
                {
                    /*
                    add it to the count.
                    */
                    counts.Add(z[position]);
                }
                if (z[position] + position == S.Length)
                {
                    /*
                    this is a valid position, so store it.
                    */
                    valid.Enqueue(z[position]);
                }
            }
            valid.Enqueue(S.Length);
            counts.Sort();
            Console.WriteLine(valid.Count);
            while (valid.Count > 0)
            {
                var popped = valid.Dequeue();
                Console.WriteLine(popped + " " + (Floor_list(counts, popped, 0, counts.Count - 1) + 1));
            }
        }

        public static int Floor_list(List<int> sortedList, int k, int start, int end)
        {
            /*
            return how many values in the list are greater or equal than k.               
            */
            if (start > end)
            {
                return 0;
            }
            if (start == end)
            {
                return sortedList[start] >= k ? 1 : 0;
            }
            else
            {
                /*
                compare element at the middle with k and make branches dividing in two parts the entry.
                */
                int middle = (start + end) / 2;
                if (sortedList[middle] >= k)
                {
                    return Floor_list(sortedList, k, 0, middle - 1) + (end - middle + 1);
                }
                else
                {
                    return Floor_list(sortedList, k, middle + 1, end);
                }
            }
        }
    }
}