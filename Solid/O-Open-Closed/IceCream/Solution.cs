/*
in this example each class implements their own ice cream.
*/
public interface IMakeIceCream
{
    void Make();
}

public class CacaoIceCream : IMakeIceCream
{
    private IMakeIceCream iceCreamMaker;

    public CacaoIceCream(IMakeIceCream iceCreamMaker = null)  //optional argument, another flavor isn't required
    {
        this.iceCreamMaker = iceCreamMaker;
    }

    public void Make()
    {
        if(iceCreamMaker != null) //if flavor passed in, make that first
        {
            iceCreamMaker.Make();
        }

        Console.WriteLine("Cacao ice-cream");
    }
}

public class VanillaIceCream : IMakeIceCream
{
    private IMakeIceCream iceCreamMaker;

    public VanillaIceCream(IMakeIceCream iceCreamMaker = null) //optional argument, another flavor isn't required
    {
        this.iceCreamMaker = iceCreamMaker;
    }

    public void Make()
    {
        if (iceCreamMaker != null) //if flavor passed in, make that first
        {
            iceCreamMaker.Make();
        }

        Console.WriteLine("Vanilla ice-cream");
    }
}