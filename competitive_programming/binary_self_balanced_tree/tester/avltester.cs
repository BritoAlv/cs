using avlfb;
using Xunit;
public class JacktheAVLRipper
{
    [Fact]
    public void TestRankAVL()
    {
        Node a = new Node(1);
        for (int i = 2; i < 100; i++)
        {
            a = Node.insert_avl(i, a);
        }

        for (int i = 2; i < 100; i++)
        {
            Assert.Equal(i - 1, Node.rank(a, i));
        }
    }

    [Fact]
    public void TestSelectAVL()
    {
        Node a = new Node(1);
        for (int i = 2; i < 100; i++)
        {
            a = Node.insert_avl(i, a);
        }
        for (int i = 1; i < 100; i++)
        {
            Assert.Equal(Node.InOrder(a).ElementAt(i-1), Node.select(a, i-1));
        }
    }


    [Fact]
    public void TestAVLInsert()
    {
        Node a = new Node(-1);
        Random rand = new Random();
        List<int> values = new List<int>() { -1 };
        for (int i = 0; i < 10000; i++)
        {
            int insert = rand.Next(1, 1000);
            if (!values.Contains(insert))
            {
                values.Add(insert);
                a = Node.insert_avl(insert, a);
            }
        }
        var sum_fine = values.Sum();
        var bst_sum = Node.Pre_Order(a).Select(x => x.value).Sum();
        Assert.Equal(sum_fine, bst_sum);
    }



    [Fact]
    public void TestAVLDelete()
    {
        Node a = new Node(-1);
        Random rand = new Random();
        List<int> values = new List<int>() { -1 };
        for (int i = 0; i < 10000; i++)
        {
            int insert = rand.Next(1, 1000);
            if (!values.Contains(insert))
            {
                values.Add(insert);
                a = Node.insert_avl(insert, a);
            }

            int delete = rand.Next(1, 1000);
            values.Remove(delete);
            a = Node.delete_avl(delete, a);
        }
        var sum_fine = values.Sum();
        var bst_sum = Node.Pre_Order(a).Select(x => x.value).Sum();
        Assert.Equal(sum_fine, bst_sum);
    }

    [Fact]
    public void TestRotations()
    {
        Node a = new Node(1);
        a = Node.insert_avl(2, a);
        a = Node.insert_avl(3, a);
        Assert.Equal(2, a.value);
        a = Node.insert_avl(5, a);
        a = Node.insert_avl(8, a);
        a = Node.insert_avl(13, a);
        Assert.Equal(5, a.value);
        a = Node.insert_avl(21, a);
        a = Node.insert_avl(34, a);
        a = Node.delete_avl(8, a);
        a = Node.delete_avl(21, a);
        a = Node.delete_avl(34, a);
        a = Node.delete_avl(13, a);
        Assert.Equal(2, a.value);
    }
    [Fact]
    public void TestInvariantMantained()
    {
        Node a = new Node(-1);
        Random rand = new Random();
        List<int> values = new List<int>() { -1 };
        for (int i = 0; i < 10000; i++)
        {
            int insert = rand.Next(1, 1000);
            if (!values.Contains(insert))
            {
                values.Add(insert);
                a = Node.insert_avl(insert, a);
            }

            int delete = rand.Next(1, 1000);
            values.Remove(delete);
            a = Node.delete_avl(delete, a);
        }
        values.Sort();
        Assert.Equal(values, Node.InOrder(a).Select(x => x.value));
    }
}