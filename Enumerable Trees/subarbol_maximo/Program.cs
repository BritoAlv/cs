public class Test
{
    public static void Main()
    {
        Random random = new Random();
        RandomLazyTree<int> arbol_lazy = new RandomLazyTree<int>(random, x => TestValueGenerators.APrimeWithProb(x, 0.8f), 5, 2);
        arbol_lazy.print(arbol_lazy, Exam.MaximalSubtreesWhere(arbol_lazy, x => TestPredicates.IsPrime(x)));

        // arbol_infinito.print_infinite_tree(arbol_infinito, x => x%2 == 0); 
    }
}