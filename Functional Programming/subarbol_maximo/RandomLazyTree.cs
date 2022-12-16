/// <summary>
/// A lazy random tree, how does it work ?
/// </summary>
/// <typeparam name="T"></typeparam>
public class RandomLazyTree<T> : ITree<T>
{
    protected Random _random; // has a random
    protected Func<Random, T> _generator; // a func to generate random values.
    public T Value { get; private set; } // its value
    public readonly int Height; // some Height
    public readonly int Width; // some Width
    protected List<RandomLazyTree<T>>? _children; // List to back-up Children
    /// <summary>
    /// this method is the hard stuff of the ITree method, because, if the list is
    /// null ( doesn't have children), we construct in that time its children in a 
    /// lazy way. This is, if the height is 0, it just doesn't have children, but an
    /// empty list to indicate that, in other case, we generate a 0 < k < width random
    /// number of new subtrees. In the list what we find is each subtree that has this node as
    /// parent.
    /// </summary>
    public virtual IEnumerable<ITree<T>> Children
    {
        get
        {
            if (_children is null)
            {
                _children = new List<RandomLazyTree<T>>();
                if (Height > 0)
                {
                    int k = Width;
                    while (k-- > 0)
                    {
                        _children.Add(new RandomLazyTree<T>(_random, _generator, Height - 1, Width));
                    }
                }
            }
            return _children;
        }
    }
    public string valor => Value.ToString();
    public RandomLazyTree(Random random, Func<Random, T> valueGenerator, int height, int width)
    {
        _random = random;
        _generator = valueGenerator;
        Value = valueGenerator(random);
        Height = height;
        Width = width;
        _children = null;
    }
    public IEnumerable<IPrintable> GetChildrenIprintables()
    {
        foreach (var child in Children)
        {
            yield return child;
        }
    }
    public virtual void print(RandomLazyTree<T> node, IEnumerable<ITree<T>> SubMaximalTrees, string indent = "", bool isLast = true, bool isMaximal = false)
    {
        // determine which shape use in dependence of it is the last or there are more children in its level.
        var marker = isLast ? "└───" : "├───";
        // print the corresponding indent for that level of depth in the tree.
        Console.Write(indent);
        // this line works because SubMaximalTree is aready computed, because is finite, how deal
        if (SubMaximalTrees.Contains(node))
        {
            isMaximal = true;
        }
        if (isMaximal)
        {
            Console.ForegroundColor = ConsoleColor.DarkBlue;
        }
        // print the marker.
        Console.Write(marker);
        // print what represents that node.
        Console.Write(node.valor);
        Console.ResetColor();
        // pass to the children nodes recursively.
        Console.WriteLine();
        // compute indent for children.
        indent += isLast ? "    " : "│   ";
        // call the method recursively.
        // LastOrDefault will fail if sequence is infinite.
        var lastChild = node.GetChildrenIprintables().LastOrDefault();
        foreach (var child in node.GetChildrenIprintables())
        {
            print((RandomLazyTree<T>)child, SubMaximalTrees, indent, child == lastChild, isMaximal); // false for infinite cases);
        }        
    }
}
