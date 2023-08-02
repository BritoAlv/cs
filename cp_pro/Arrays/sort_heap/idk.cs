public static class idk
{
    /////////////////////////////////////////////////////////////////////////////////////////////////
    /// aplication of the heap to merge sorted lists. <summary>
    /////////////////////////////////////////////////////////////////////////////////////////////////   

    /*
    merge list of same type of objects
    */
    public static List<T> merge_k_list<T>(params List<T>[] lists) where T : IComparable
    {
        Dictionary<int, List<id_element<T>>> a = new Dictionary<int, List<id_element<T>>>();
        for (int i = 0; i < lists.Count(); i++)
        {
            a[i] = new List<id_element<T>>();
            foreach (var item in lists[i])
            {
                id_element<T> temp = new id_element<T>(i, item);
                a[i].Add(temp);
            }
        }
        List<id_element<T>> c = merge_k_list(a);
        List<T> result = new List<T>();
        foreach (var item in c)
        {
            result.Add(item.val);
        }
        return result;
    }


    /* 
    merge list of diferent type of objects.
    */
    public static List<id_element<T>> merge_k_list<T>(Dictionary<int, List<id_element<T>>> lists) where T : IComparable
    {
        // takes k sorted lists of elements of id_element we use char to identifie the list,
        // so two elements in the same list have sAme char value.
        List<id_element<T>> result = new List<id_element<T>>();
        min_heap<id_element<T>> b = new min_heap<id_element<T>>();
        int total = 0;
        foreach (var item in lists)
        {
            int templ = item.Value.Count();
            if (templ > 0)
            {
                b.insert(item.Value[0]);
                total = total + templ;
            }
        }
        for (int i = 0; i < total; i++)
        {
            id_element<T> temp = b.extract_min();
            lists[temp.id].RemoveAt(0);
            result.Add(temp);
            if (lists[temp.id].Count > 0)
            {
                b.insert(lists[temp.id][0]);
            }
        }
        return result;
    }
}
