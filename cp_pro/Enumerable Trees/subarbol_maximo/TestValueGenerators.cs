public static class TestValueGenerators
{
    public static int AnEvenWithProb(Random random, float prob)
    {
        return 2 * random.Next(0, 100) + (random.NextSingle() < prob ? 0 : 1);
    }
    public static int AnOddWithProb(Random random, float prob)
    {
        return AnEvenWithProb(random, 1.0f - prob);
    }
    public static int ASquareWithProb(Random random, float prob)
    {
        int x = random.Next(0, 100);
        return x * x + (random.NextSingle() < prob ? 0 : random.Next(0, 2 * x + 1));
    }
    static int[] primes = new int[]
    {
        2, 3, 5, 7, 11, 13, 17, 19, 23,
        29, 31, 37, 41, 43, 47, 53, 59,
        61, 67, 71, 73, 79, 83, 89, 97
    };
    public static int APrimeWithProb(Random random, float prob)
    {
        int x = primes[random.Next(0, primes.Length)];
        return x * (random.NextSingle() < prob ? 1 : random.Next(2, 100));
    }
}