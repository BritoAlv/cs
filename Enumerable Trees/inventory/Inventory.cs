using System.Linq;

public class Inventory : IInventory
{
    public Inventory(ICategory root)
    {
        Root = root;
    }
    public ICategory Root { get; }
    public IEnumerable<IProduct> FindAll(Filter<IProduct> filter) => Category.GetAllProducts(this.Root).Where(x => filter(x));
    public ICategory GetCategory(params string[] categories)
    {
        ICategory actual = this.Root;
        for (int i = 0; i < categories.Length; i++)
        {
            actual = find_subcategory(categories[i]);
        }
        return actual;
        ICategory find_subcategory(string name)
        {
            foreach (var subcategory in actual.Subcategories.Where(subcategory => subcategory.Name == name))
            {
                return subcategory;
            }

            throw new ArgumentException("No se encontró la categoría");
        }
    }
    public IProduct GetProduct(string name, params string[] categories)
    {
        foreach (var product in GetCategory(categories).Products.Where(product => product.Name == name))
        {
            return product;
        }

        throw new ArgumentException("No se encontró el producto");
    }
}
