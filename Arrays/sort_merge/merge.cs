public static class merge_sort
{
    public static void basic_0(int[] source, int start, int end)
    // start and end both included.
    {
        if (start < end)
        {
            // sort halve of the array using recursion
            basic_0(source, start, (start+end)/2);  
            basic_0(source, (start+end)/2+1, end );

            // join halves using two-finger-algorithm
            List<int> result = new List<int>(end-start+1);
            int finger1 = start;
            int finger2 = (start+end)/2+1;
            while (finger1 <= (start+end)/2 && finger2 <= end)
            {
                if(source[finger1] <  source[finger2])
                {
                    result.Add(source[finger1]);
                    finger1 = finger1 + 1;
                }
                else
                {
                    result.Add(source[finger2]);
                    finger2 = finger2 + 1;
                }                
            }

            // when this process ends there are two options either finger1 = finger2 or finger2 = end but not both happen at the same time.
            while (finger1 <= (start+end)/2)
            {
                result.Add(source[finger1]);
                finger1 = finger1 + 1;
            }
            while (finger2 <= end)
            {
                result.Add(source[finger2]);
                finger2 = finger2 + 1;
            }
            for (int i = start; i <= end; i++)
            {
                source[i] = result[i-start];
            }            
        }
    } 



    public static void Main()
    {
        int[] test_sort = new int[] { 1, 4, 3, 2, 5, 3 };
        merge_sort.basic_0(test_sort, 0, test_sort.Length-1);
        foreach (int num in test_sort)
        {
            Console.WriteLine(" " + num + " ");
        }
    }
}
