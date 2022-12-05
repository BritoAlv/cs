
/// <summary>
/// Mutable Class Rectangle
/// </summary>
public class Rectangle
{
    public int Length{ get; set; }
    public int Height { get; set; }

    public void Grow(int length, int height)
    {
        Length += length;
        Height += height;
    }
}
