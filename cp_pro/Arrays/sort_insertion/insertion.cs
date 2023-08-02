// implementations of insertion sort.
public static class insertion_sort
{
    public static void basic_0(int[] source)
    /* 
    The thing is that inside the while there are three constant operations.
    */
    {
        for (int i = 1; i < source.Length; i++) // n-1 iterations, so O(n)
        {
            int j = i;
            // the array from position 0 to j-1 is sorted always, so now insert source[i] in that array, keeping it sorted.
            while((j > 0) && (source[j-1] > source[j]) ) 
            // has to go from i-1 to 0, checking, in each check, it compares and after that do the swap.
            {                
                int temp = source[j-1];
                source[j-1] = source[j];
                source[j] = temp;
                j--;
            }
        }
    }
    public static void swaps_2<T>(T[] source) where T : IComparable<T>
    //Esto significa que este metodo funcionara para todo tipo T tal que implemente el metodo CompareTo() con objetos de su mismo tipo
    {
        for (int i = 1; i < source.Length; i++)
        {
            int j = i;
            while((j > 0) && (source[j-1].CompareTo(source[j]) > 0))
            //Por convenio, decir que a.CompareTo(b) > 0 es analogo a decir a > b 
            {                
                T temp = source[j-1];
                source[j-1] = source[j];
                source[j] = temp;
                j--;
            }
        }
    }


    public static void basic_1(int[] source)
    {
        for (int i = 1; i < source.Length; i++) // n-1 iterations, so O(n)
        {
            // the array from position 0 to j-1 is sorted always, so now insert source[i] in that array, keeping it sorted.
            // binary search to insert source[i] in correct position.
            // find index where to insert, and after that shift indexes.
            int l = 0;
            int r = i-1;
            int mid = 0;
            while(r-l > 1)
            // as long as l-r > 1 we ensure that l < r and that mid is inside
            {
                mid = (l+r)/2;
                if( source[mid] == source[i])
                {
                    l = mid;
                    r = mid;
                }
                else if ( source[mid] > source[i])
                {
                    r = mid-1;
                }
                else
                {
                    l = mid+1;
                }
            }
            // we have either l = r or r = l+1 bases cases of recursivity.
            int pos;
            if (source[i] <= source[l])
            {
                pos = l; //
            }
            else if(source[i] > source[r] )
            {
                pos = r+1; // 
            }
            else
            {
                pos = r;
            }
            int temp = source[i];
            // shift process
            for (int j = i; j >= pos+1; j--)
            {
                source[j] = source[j-1];
            }
            source[pos] = temp;
        }        
    }
    public static void binary_search_2<T>(T[] source) where T: IComparable<T>
    {
        for (int i = 1; i < source.Length; i++) // n-1 iterations, so O(n)
        {
            // the array from position 0 to j-1 is sorted always, so now insert source[i] in that array, keeping it sorted.
            // binary search to insert source[i] in correct position.
            // find index where to insert, and after that shift indexes.
            int l = 0;
            int r = i-1;
            int mid = 0;
            while(r-l > 1)
            // as long as l-r > 1 we ensure that l < r and that mid is inside
            {
                mid = (l+r)/2;
                if( source[mid].CompareTo(source[i]) == 0)
                {
                    l = mid;
                    r = mid;
                }
                else if ( source[mid].CompareTo(source[i]) > 0)
                {
                    r = mid-1;
                }
                else
                {
                    l = mid+1;
                }
            }
            // we have either l = r or r = l+1 bases cases of recursivity.
            int pos;
            if (source[i].CompareTo(source[l]) <= 0)
            {
                pos = l; //
            }
            else if(source[i].CompareTo(source[r]) > 0 )
            {
                pos = r+1; // 
            }
            else
            {
                pos = r;
            }
            T temp = source[i];
            // shift process
            for (int j = i; j >= pos+1; j--)
            {
                source[j] = source[j-1];
            }
            source[pos] = temp;
        }        
    }
}

public class insertion{
    public static void Main()
    {
        int[] test_sort = random_utils.generate_array(100);
        insertion_sort.swaps_2(test_sort);
        foreach (int num in test_sort)
        {
            Console.WriteLine(" " + num + " ");
        }       
    }
}
