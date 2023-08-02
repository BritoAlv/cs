public interface ICategory
{
    string Name { get; }
    ICategory CreateSubcategory(string name);
    void UpdateProduct(string product, int count);
    IEnumerable<ICategory> Subcategories { get; }
    IEnumerable<IProduct> Products { get; }
    ICategory Parent { get; }
}
