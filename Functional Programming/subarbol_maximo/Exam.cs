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
