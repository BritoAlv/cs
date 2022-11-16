public interface IShape
{
    double area();
}

public class Rectangle: IShape
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


/*
Squeare can not derive from Rectangle, becuase it does not behave
like a rectangle
*/
public class Square : IShape
{
    public double side{ get; set; }
    public Square(int side)
    {
        this.side = side;
    }

    public double area()
    {
        return side*side;
    }
}

public class test
{
    public static void Main()
    {
        Rectangle a = new Rectangle(3, 2);
        Console.WriteLine(a.area());

        Square b = new Square(3);
        Console.WriteLine(b.area());
    }
}