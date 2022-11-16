public class Rectangle
{
    public int width;
    public int height;
    public virtual void set_width(int a)
    {
        width = a;
    }
    public virtual void set_heigth(int a)
    {
        height = a;
    }

    public virtual double area()
    {
        return width * height;
    }

    public Rectangle(int w, int h)
    {
        this.width = w;
        this.height = h;
    }
}

public class Square : Rectangle
{
    public override void set_heigth(int a)
    {
        base.set_heigth(a);
        this.width = a;
    }

    public override void set_width(int a)
    {
        base.set_width(a);
        this.height = a;
    }

    public Square(int w) : base(w, w) { }
}

public class test
{
    public static void Main()
    {
        Rectangle a = new Rectangle(3, 2);
        Console.WriteLine(a.area());


        Rectangle b = new Square(2);
        /*
        because i'm coding this I know b is really a square,
        but if someone doesn't and do this:
        */

        b.set_heigth(5);
        b.set_width(4);
        Console.WriteLine(b.area());
        /*
        expected area should be 20, but not it is 16, this is what
        Liskov substitution is all about, derived class should behave
        like father type without user knowing it, also use
        preconditions, postconditions, covarianza, contravarianza.
        */
    }
}