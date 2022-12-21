using System.Collections.Generic;
public class Category : ICategory
{
    private Dictionary<string, ICategory> subCategories;
    private Dictionary<string, Product> products;
    public Category(string name)
    {
        this.subCategories = new Dictionary<string, ICategory>();
        this.products = new Dictionary<string, Product>();
        this.Name = name;
        this.Parent = this;
    }
    public Category(string name, ICategory parent) : this(name)
    {
        this.Parent = parent;
    }
    public string Name { get; }
    public IEnumerable<ICategory> Subcategories => subCategories.Values;
    public IEnumerable<IProduct> Products => products.Values.Where(x => x.Count > 0);
    public ICategory Parent { get; }
    public ICategory CreateSubcategory(string name)
    {
        if (this.subCategories.ContainsKey(name))
        {
            throw new ArgumentException("ya existe esta categoría");
        }
        var cat = new Category(name, this);
        subCategories[name] = cat;
        return cat;
    }
    public static IEnumerable<IProduct> GetAllProducts(ICategory A)
    {
        foreach (var product in A.Products)
        {
            yield return product;
        }
        foreach (var sub in A.Subcategories)
        {
            foreach (var product in GetAllProducts(sub))
            {
                yield return product;
            }
        }
    }
    public void UpdateProduct(string product, int change)
    {
        int count = products.ContainsKey(product) ? products[product].Count : 0;
        count += change;
        if (count >= 0)
        {
            if (products.ContainsKey(product))
            {
                products[product].Count = count;
                return;
            }
            else
            {
                products[product] = new Product(product, change, this);
                return;
            }
        }
        else
        {
            throw new ArgumentException("La cantidad de un producto debe ser >=0");
        }
    }
}
