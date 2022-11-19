public class IceCreamMachine
{
    public void MakeIceCream(string flavor)
    {
        if(flavor == "cacao")
        {
            Console.WriteLine("Cacao ice-cream"); //logic to create cacao ice-cream
        }
        else if (flavor == "vanilla")
        {
            Console.WriteLine("Vanilla ice-cream"); //logic to create vanilla ice-cream
        }
        else if (flavor == "cacao-vanilla")
        {
            //copy & paste the cacao ice-cream logic
            Console.WriteLine("Cacao ice-cream");

            //copy & paste the vanilla ice-cream logic
            Console.WriteLine("Vanilla ice-cream");
        }
        else
        {
            throw new Exception("Flavor not supported");
        }
    }
}