public class subsets
{
    public static void Main()
    {
        // given a set of integers print all its subsets.
        List<int> set = new List<int>(){2,3,4,7};
        subset(set, 0, "");
    }

    public static void subset(List<int> set, int pos_of_set, string actual_sub_set)
    {
        
        if(pos_of_set == set.Count)
        {
            Console.WriteLine(actual_sub_set);
            return;
        }
        subset(set, pos_of_set+1, actual_sub_set);
        subset(set, pos_of_set+1, actual_sub_set+set[pos_of_set]);
    }

    
}