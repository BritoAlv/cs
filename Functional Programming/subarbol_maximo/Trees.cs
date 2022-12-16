public interface ITree<T> : IPrintable
{
    T Value { get; }
    IEnumerable<ITree<T>> Children { get; }
}
public delegate bool Predicate<T>(T item);
