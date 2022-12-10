



/// <summary>
/// Immutable Rectangle 
/// </summary>
public class ImmutableRectangle
{
    public ImmutableRectangle(int length, int height)
    {
        Length = length;
        Height = height;
    }

    public int Length { get; }
    public int Height { get; }

    public ImmutableRectangle Grow(int length, int height) => new ImmutableRectangle(Length + length, Height + height);
}
