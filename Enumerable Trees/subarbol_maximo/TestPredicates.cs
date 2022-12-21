public static class TestPredicates
{
    public static Predicate<int> IsEven = x => x % 2 == 0;
    public static Predicate<int> IsOdd = x => x % 2 == 1;
    public static Predicate<int> IsSquare = x =>
    {
        int sqrt = (int)Math.Sqrt(x);
        return sqrt * sqrt == x;
    };
    public static Predicate<int> IsPrime = x =>
    {
        int q = 2;

        while (q * q <= x)
        {
            if (x % q++ == 0)
                return false;
        }
        return true;
    };
}