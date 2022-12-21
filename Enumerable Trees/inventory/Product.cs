public class Product : IProduct
{
    private int _count;
    public string Name{ get; }
    public int Count
    {
        get
        {
            return _count;
        }
        set
        {
            if (value < 0)
            {
                throw new ArgumentException("No puede haber un producto con <0 cantidad");
            }
            _count = value;
        }
    }
    public ICategory Parent { get; }
    public Product(string name, int count, ICategory parent)
    {
        Name = name;
        _count = count;
        Parent = parent;
    }
}