public interface IInventory
{
    ICategory Root { get; }
    ICategory GetCategory(params string[] categories);
    IProduct GetProduct(string name, params string[] categories);
    IEnumerable<IProduct> FindAll(Filter<IProduct> filter);
}
