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
