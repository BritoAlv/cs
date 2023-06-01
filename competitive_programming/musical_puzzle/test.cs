using Xunit;
public static class tester
{
    [Theory]
    [InlineData(2, 4, "abab")]
    [InlineData(4, 7, "abacaba")]
    [InlineData(1, 6, "aaaaaa")]
    [InlineData(6, 7, "abcdefg")]
    [InlineData(4, 5, "babdd")]
    public static void test(int answer, int len, string melody)
    {
        Assert.Equal(answer, Problem.get_minimum_melodies(melody));
    }
}