using Xunit;
public class JacktheHeapRipper
{
    [Fact]
    public void Test_Insert()
    {
        min_heap<int> heap = new min_heap<int>();
        for (int i = 101; i > 0; i--)
        {
            heap.insert(i);
        }
        Assert.Equal(1, heap.get_min());
    }


    [Fact]
    public void TestHeap()
    {
        min_heap<int> to_be_tested = new min_heap<int>();
        Random random = new Random();
        for (int i = 0; i < 10; i++)
        {
            int priority = 0;
            to_be_tested.insert(priority);
            for (int j = 0; j < 100; j++)
            {
                priority = random.Next(1, 200);
                to_be_tested.insert(priority);
            }
            IList<int> arr = to_be_tested.A;
            int arraysize = arr.Count;
            for (int j = 0; j < arraysize; j++)
            {
                int l = 2 * j + 1;
                int r = 2 * j + 2;
                if (l < arraysize)
                {
                    if (arr[j] > arr[l])
                    {
                        Assert.Equal(false, true);
                    }
                }
                if (r < arraysize)
                {
                    if (arr[j] > arr[r])
                    {
                        Assert.Equal(false, true);
                    }
                }
            }
        }
        Assert.Equal(true, true);
    }

    [Fact]
    public void test_all_less_than()
    {
        min_heap<int> heap = new min_heap<int>();
        for (int i = 101; i >= 0; i--)
        {
            heap.insert(i);
        }
        Assert.Equal(49 * 50 / 2, min_heap<int>.get_all_less_than(heap, 50).Sum());
    }

    [Fact]
    public void test_get_k_th_smallest()
    {
        min_heap<int> heap = new min_heap<int>();
        for (int i = 101; i > 0; i--)
        {
            heap.insert(i);
        }
        Assert.Equal(30, min_heap<int>.get_k_th_smallest(heap, 30));
    }
}

