// IProduct is in its worse immutable.
public interface IProduct
{
    string Name { get; }
    int Count { get; }
    ICategory Parent { get; }
}
public delegate bool Filter<T>(T item);
