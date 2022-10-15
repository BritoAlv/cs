class permutacion
{
    public static void Main()
    {
        List<int> numbers = new List<int>(){2,3,4,5,6};
        bool[] taken = new bool[numbers.Count];
        permutaciones("", taken,  numbers);
    }


    /*
    given a list of numbers (there may be repeated ones return all its permutaciones) 
    */
    public static void permutaciones( string actual_permutation, bool[] taken, List<int> numbers )
    {
        if(actual_permutation.Length == taken.Length)
        {
            Console.WriteLine(actual_permutation);
            return;
        }
        else
        {
            for (int i = 0; i < numbers.Count; i++)
            {
                if (taken[i] == false)
                {
                    taken[i] = true;
                    actual_permutation = actual_permutation + numbers[i];
                    permutaciones(actual_permutation, taken, numbers);
                    actual_permutation = actual_permutation.Substring(0, actual_permutation.Length-1);
                    taken[i] = false;                    
                }
            }
        }
    }
}