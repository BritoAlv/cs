using System;
using System.Collections.Generic;
using Xunit;
public class JacktheOrderStatisticRipper
{
    [Theory]
    [InlineData(1, 2, 3, 5, 4, 0)]
    [InlineData(1, 3, 4, 5, 6)]
    public void test_minimum_maximum(params int[] X)
    {
        Assert.Equal((X.Min(), X.Max()), get_minimum_maximum(X));
    }
    public (int, int) get_minimum_maximum(int[] x)
    {
        if (x.Length == 0)
        {
            throw new Exception("Array cannot be empty");
        }
        int start = 1;
        var actual = (x[0], x[0]);
        if (x.Length % 2 == 0)
        {
            start++;
            if (x[0] > x[1])
            {
                actual.Item1 = x[1];
                actual.Item2 = x[0];
            }
            else
            {
                actual.Item2 = x[1];
            }
        }

        for (int i = start; i < x.Length; i += 2)
        {
            actual = update_answer(actual, x[i], x[i + 1]);
        }

        return actual;

        (int, int) update_answer((int, int) actual, int current1, int current2)
        {
            int smallest = current1;
            int greatest = current2;
            if (current1 > current2)
            {
                smallest = current2;
                greatest = current1;
            }
            if (smallest < actual.Item1)
            {
                actual.Item1 = smallest;
            }
            if (greatest > actual.Item2)
            {
                actual.Item2 = greatest;
            }
            return actual;
        }
    }
}