public static class heap_sort
{
    public static void basic_0(int[] read)
    {
        min_heap<int> A = new min_heap<int>(read);
        for (int i = 0; i < read.Length; i++)
        {
            read[i] = A.extract_min();            
        }
    }
}
