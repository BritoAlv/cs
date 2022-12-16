public class Test
{
    public static void Main()
    {
        Random random = new Random();
        RandomInfiniteTree<int> arbol = new RandomInfiniteTree<int>(random, x => TestValueGenerators.AnEvenWithProb(x, 0.5f), 4, 2);   
        arbol.print_infinite_tree(arbol);
    }
}