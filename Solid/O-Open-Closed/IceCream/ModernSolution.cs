/*  can’t inherit multiple classes. So for a two flavor combo, we have to duplicate some code
or extract the logic into a service if the code in the base class is updated, all class children
are impacted. Imagine the base class has some dependencies injected through a constructor, 
every time we add a new dependency, all children have to parse that parameter to the base constructor.
*/
public abstract class BaseIceCream
{
    public abstract void MakeIceCream();
}

public class CacaoIceCream : BaseIceCream
{
    public override void MakeIceCream()
    {
        Console.WriteLine("Cacao ice-cream");
    }
}

public class VanillaIceCream : BaseIceCream
{
    public override void MakeIceCream()
    {
        Console.WriteLine("Vanilla ice-cream");
    }
}

public class CacaoAndVanilla : CacaoIceCream
{
    public override void MakeIceCream()
    {
        base.MakeIceCream();
        Console.WriteLine("Vanilla ice-cream"); //duplicate vanilla logic because we can't iherit both cacao and vanilla
    }
}