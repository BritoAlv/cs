public static class Exam
{
    public static IEnumerable<ITree<T>> MaximalSubtreesWhere<T>(ITree<T> tree, Predicate<T> predicate)
    {
        if (IsValidSubTree(tree, predicate))
        {
            yield return tree;
        }
        else
        {
            foreach (var child in tree.Children)
            {
                foreach (var submaxtree in MaximalSubtreesWhere(child, predicate))
                {
                    yield return submaxtree;
                }
            }
        }
    }
    public static IEnumerable<ITree<T>> Solution<T>(ITree<T> tree, Predicate<T> pred)
    {
        var mscs = tree.Children.Select(ch => (ch, Solution(ch, pred)));
        if (pred(tree.Value) && mscs.All(msc => msc.Item2.Take(1).Contains(msc.Item1)))
        {
            yield return tree;
        }
        else
        {
            foreach (var msc in mscs)
            {
                foreach (var child in msc.Item2)
                {
                    yield return child;
                }
            }
        }
    }
    public static IEnumerable<ITree<T>> Solution2<T>(ITree<T> tree, Predicate<T> predicate)
    {
        var mock = new MockTree<T>(tree);
        return MaximalSubtreesWherePrivate(mock, predicate);
    }

    private static IEnumerable<ITree<T>> MaximalSubtreesWherePrivate<T>(ITree<T> mock, Predicate<T> predicate)
    {
        foreach (var c in mock.Children)
        {
            if (IsValidSubTree(c, predicate))
            {
                yield return c;
            }
            else
            {
                foreach (var subtree in MaximalSubtreesWherePrivate(c, predicate))
                {
                    yield return subtree;
                }
            }
        }
    }

    public static string Nombre => "Alvaro Luis Gonzalez Brito";
    public static string Grupo => "C113";
    public static bool IsValidSubTree<T>(ITree<T> arbol, Predicate<T> predicate)
    {
        if (!predicate(arbol.Value))
        {
            return false;
        }
        foreach (var subarbol in arbol.Children)
        {
            if (!IsValidSubTree(subarbol, predicate))
            {
                return false;
            }
        }
        return true;
    }
}

class MockTree<T> : ITree<T>
{
    public T Value { private set; get; }
    public IEnumerable<ITree<T>> Children => children;
    private List<ITree<T>> children = new List<ITree<T>>();
    public MockTree(ITree<T> tree)
    {
        Value = default(T);
        children.Add(tree);
    }
}
