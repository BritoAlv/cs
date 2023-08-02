public class RandomInfiniteTree<T> : RandomLazyTree<T>
{
    public override IEnumerable<ITree<T>> Children
    {
        get
        {
            int i = 0;
            while (i < _children!.Count)
            {
                yield return _children[i++];
            }
            if (Height > 0)
            {
                while (true)
                {
                    var new_tree = new RandomLazyTree<T>(_random, _generator, Height - 1, 1);
                    lock (_children!)
                    {
                        _children.Add(new_tree);
                    }
                    yield return new_tree;
                }
            }
        }
    }
    public RandomInfiniteTree(Random random, Func<Random, T> valueGenerator, int height, int width) :
        base(random, valueGenerator, height, width)
    {
        _children = new List<RandomLazyTree<T>>();
    }
    public virtual void print_infinite_tree(RandomLazyTree<T> node, Predicate<T> predicate, string indent = "", bool isLast = true)
    {
        // determine which shape use in dependence of it is the last or there are more children in its level.
        var marker = isLast ? "└───" : "├───";
        // print the corresponding indent for that level of depth in the tree.
        Console.Write(indent);
        // print the marker.
        Console.Write(marker);
        // print what represents that node.
        Console.Write(node.Value.ToString());
        // pass to the children nodes recursively.
        Console.WriteLine();
        // compute indent for children.
        indent += isLast ? "    " : "│   ";
        // call the method recursively.
        // LastOrDefault will fail if sequence is infinite.
        foreach (var child in this.Children)
        {
            var aslazy = (RandomLazyTree<T>)child;
            print(aslazy, Exam.MaximalSubtreesWhere(aslazy, predicate), indent, false);
        }
    }
}