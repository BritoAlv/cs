public class min_heap<T> where T : IComparable<T> // Notice that T are the priorities.
{
    public IList<T> A;
    public min_heap()
    {
        this.A = new List<T>();
    }
    public int Count => A.Count;
    public min_heap(IList<T> B) // O(n)
    {
        /*
        analysis looks O(n log n) but it's not, it's linear. because the sum i / 2^i converges.
        */
        this.A = B;
        for (int i = (B.Count) / 2 - 1; i >= 0; i--)
        {
            fix_child(i);
        }
    }

    public T get_at(int index)
    {
        return this.A[index];
    }
    public T get_min() // O(1)
    {
        return this.A[0];
    }

    public void fix_father(int index) // O(log n)
    {
        int father = (index - 1) / 2;
        if (father >= 0)
        {
            if (this.A[index].CompareTo(this.A[father]) < 0)
            {
                T temp = this.A[father];
                this.A[father] = this.A[index];
                this.A[index] = temp;
                fix_father(father);
            }
        }
    }
    public void fix_child(int index) // O(log n)
    {
        // compute index of child of index.
        int chil1 = 2 * index + 1;
        int chil2 = 2 * index + 2;

        // store A[index] in a  temp variable
        T temp = this.A[index];
        if (chil2 < this.A.Count) // index have two children
        {
            // set variable child to menor of the two indexes.
            int child = chil2;
            if (this.A[chil1].CompareTo(this.A[chil2]) < 0)
            {
                child = chil1;
            }
            if (this.A[child].CompareTo(this.A[index]) < 0)
            {
                this.A[index] = this.A[child];
                this.A[child] = temp;
                fix_child(child);
            }

        }
        else if (chil2 == this.A.Count) // have only left children
        {
            if (this.A[chil1].CompareTo(this.A[index]) < 0)
            {

                this.A[index] = this.A[chil1];
                this.A[chil1] = temp;
            }
        }
        else
        {
            // doesn't have either left or right child so we are done.
        }
    }

    public void insert(T val) // O(log n)
    {
        // insert a value into the heap
        int its = this.A.Count;
        this.A.Add(val);
        fix_father(its);
    }

    public T extract_min() // O(log n)
    {
        T temp = this.A[0];
        if (this.A.Count == 1)
        {
            this.A.RemoveAt(0);
        }
        else
        {
            this.A[0] = this.A.Last();
            this.A.RemoveAt(this.A.Count - 1);
            fix_child(0);
        }
        return temp;
    }

    public min_heap<T> union(min_heap<T> a, min_heap<T> b) // O(n+m)
    {
        IList<T> result = new List<T>(a.A.Count + b.A.Count);
        foreach (var item in a.A)
        {
            result.Add(item);
        }
        foreach (var item in b.A)
        {
            result.Add(item);
        }
        return new min_heap<T>(result);
    }

    public override string ToString()
    {
        return print(this.A.ToArray());
    }

    private static string print<T>(T[] a)
    {
        int cant_levels = (int)Math.Ceiling((Math.Log2(a.Length) + 0.000001));
        string[,] bid = new string[2 * cant_levels - 1, 1 + 2 * ((int)Math.Pow(2, cant_levels) - 2)];
        int espaciado = (1 == (int)Math.Pow(2, cant_levels - 1)) ? 0 : (int)Math.Pow(2, cant_levels - 1);
        static void fill(string[,] arr, T[] a, int index_row, int index_column, int space, int ind)
        {
            // pos y is in the rows, pos x is in the columns
            arr[index_row, index_column] = a[ind].ToString();
            int start = index_column - space;
            int end = index_column + space;
            for (int i = start; i < index_column; i++)
            {
                arr[index_row, i] = "-";
            }
            for (int i = index_column + 1; i <= end; i++)
            {
                arr[index_row, i] = "-";
            }
            if (index_row + 1 < arr.GetLength(0))
            {
                arr[index_row + 1, start] = "-";
                arr[index_row + 1, end] = "-";
            }

            // left child of index i in array a is 2*i+1
            space = (space / 2 > 1) ? space / 2 : 0;
            if (2 * ind + 1 < a.Length)
            {
                fill(arr, a, index_row + 2, start, space, (2 * ind + 1));
            }
            if (2 * ind + 2 < a.Length)
            {
                fill(arr, a, index_row + 2, end, space, (2 * ind + 2));
            }
        }
        fill(bid, a, 0, (int)Math.Pow(2, cant_levels) - 2, espaciado, 0);
        string result = "";
        for (int i = 0; i < bid.GetLength(0); i++)
        {
            for (int j = 0; j < bid.GetLength(1); j++)
            {
                if (String.IsNullOrEmpty(bid[i, j]))
                {
                    result = result + " ";
                }
                else if (bid[i, j] == "-")
                {
                    result = result + "-";
                }
                else
                {
                    result = result + bid[i, j];
                }
            }
            result = result + "\n";
        }
        return result;
    }

    /// <summary>
    /// get the k-smallest element in the heap. O(log k!)
    /// </summary>
    /// <param name="heap"></param>
    /// <param name="k"></param>
    /// <returns></returns>
    public static T get_k_th_smallest(min_heap<T> heap, int k)
    {
        min_heap<(T,int)> aux = new min_heap<(T,int)>();
        aux.insert( (heap.get_min(), 0) );
        var obtained_elements = 0;
        while(aux.Count > 0)
        {
            var current = aux.extract_min();
            Console.WriteLine(heap.get_at(current.Item2));
            if (2*current.Item2 +2 < heap.Count)
            {
                aux.insert( (heap.get_at(2 * current.Item2 + 2), 2 * current.Item2 + 2));
            }
            if (2*current.Item2+1 < heap.Count)
            {
                aux.insert((heap.get_at(2 * current.Item2 + 1), 2 * current.Item2 + 1));
            }
            obtained_elements+= 1;
            if (obtained_elements == k)
            {
                return heap.get_at(current.Item2);
            }
        }
        throw new Exception("Heap doesn't have at least k-elements");
    }

    /// <summary>
    /// Check if the k-th smallest element in the heap is less than x.
    /// </summary>
    /// <param name="k"></param>
    /// <param name="heap"></param>
    /// <param name="x"></param>
    /// <returns></returns>
    public static bool k_th_is_less(min_heap<T> heap, T x, int k)
    {
        /*
        Claim: condition is equivalent to check if exist k elements in the heap that are less than x.

        Proof: 
        1) Assume that the k-smallest element is less than x, then because it's the k-smallest this implies that there are k elements less than x.
        2) Assume we found k elements that are less than x, in the worst case the first one will be at position 1, so because there are k-elements the k-th should be less than x.  
        */
        return get_all_less_than(heap, x, k).Count >= k;
    }


    /// <summary>
    /// Given a min-heap return at most "how_many" elements in the heap with priority less than priority x. 
    /// </summary>
    /// <param name="heap"></param>
    /// <param name="x"></param>
    /// <param name="how_many"></param>
    /// <returns></returns>
    public static List<T> get_all_less_than(min_heap<T> heap, T x, int how_many = int.MaxValue)
    {
        /*
        expected complexity of this method is O(elements found)
        */
        List<T> answer = new List<T>();
        if (how_many == 0)
        {
            return answer;
        }
        Stack<int> stack = new Stack<int>(); // stack will store index of valid nodes.
        var start = heap.get_min();
        if (start.CompareTo(x) == -1)
        {
            stack.Push(0);
            answer.Add(start);
        }
        while (stack.Count > 0 && answer.Count < how_many)
        {
            /* notice that after each element is found, it is pushed, and popped only once in the stack, complexity of this is O( elements ), also for each element found is done a constant amount work (finding two more). */
            int index = stack.Pop();
            int left_index = 2 * index + 1;
            int right_index = 2 * index + 2;
            if (left_index < heap.Count)
            {
                var left = heap.get_at(left_index);
                if (left.CompareTo(x) == -1)
                {
                    stack.Push(left_index);
                    answer.Add(left);
                    if (answer.Count == how_many)
                    {
                        break;
                    }
                }
            }
            if (right_index < heap.Count)
            {
                var right = heap.get_at(right_index);
                if (right.CompareTo(x) == -1)
                {
                    stack.Push(right_index);
                    answer.Add(right);
                }
            }
        }
        return answer;
    }
}
