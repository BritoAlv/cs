using System;
using System.Collections.Generic;
using Xunit;
public class JacktheOrderStatisticRipper
{
    [Theory]
    [InlineData(8, 3, 7, 4, 6, 9, 10, 1, 5, 2)]
    public void test_discrete_second_smallest(params int[] X)
    {
        Assert.Equal(X.Order().ToArray()[1], recursive_get_second_smallest(X.ToList()));
        Assert.Equal(X.Order().ToArray()[1], simulate_tournament(X));
    }

    [Theory]
    [InlineData(100, 50)]
    [InlineData(16, 31)]
    public void test_second_smallest(int size, int iterations)
    {
        while (iterations > 0)
        {
            int[] x = new int[size];
            for (int i = 1; i <= size; i++)
            {
                x[i - 1] = i;
            }
            int[] y = new int[x.Length];
            x = Shuffle<int>(x).ToArray();
            Array.Copy(x, y, x.Length);
            Assert.Equal(x.Order().ToArray()[1], recursive_get_second_smallest(x.ToList()));
            Assert.Equal(x.Order().ToArray()[1], simulate_tournament(x));
            iterations--;
        }
    }

    public static IList<T> Shuffle<T>(IList<T> list)
    {
        Random rng = new Random();
        int n = list.Count;
        while (n > 1)
        {
            n--;
            int k = rng.Next(n + 1);
            T value = list[k];
            list[k] = list[n];
            list[n] = value;
        }
        return list;
    }
    public static int recursive_get_second_smallest(IList<int> x)
    {
        if (x.Count == 2)
        {
            return x.Max();
        }
        else
        {
            List<int> smallest_half = new List<int>(x.Count / 2 % 2 == 0 ? x.Count / 2 : x.Count / 2 + 1);
            int index_min = -1;
            for (int i = 0; i <= x.Count - 2; i += 2)
            {
                if (x[i] < x[i + 1])
                {
                    smallest_half.Add(x[i]);
                    if (index_min < 0 || x[i + 1] < x[index_min])
                    {
                        index_min = i + 1;
                    }
                }
                else
                {
                    smallest_half.Add(x[i + 1]);
                    if (index_min < 0 || x[i] < x[index_min])
                    {
                        index_min = i;
                    }
                }
            }
            if (x.Count % 2 == 1)
            {
                smallest_half.Add(x[x.Count - 1]);
            }
            int second_smallest = recursive_get_second_smallest(smallest_half); // notice that it's imposible that this returns the smallest element in the array.
            if (second_smallest < x[index_min])
            {
                return second_smallest;
            }
            return x[index_min];
        }
    }

    public static int simulate_tournament(int[] x)
    {
        Queue<TournamentNode> cola = new Queue<TournamentNode>();
        foreach (var element in x)
        {
            cola.Enqueue(new TournamentNode(element));
        }
        while (cola.Count > 1) // Notice that each iteration half the number of elements in the cola.
        {
            var first = cola.Dequeue();
            var second = cola.Dequeue();
            if (first.Value < second.Value)
            {
                first.defeated.Add(second.Value);
                cola.Enqueue(first);
            }
            else
            {
                second.defeated.Add(first.Value);
                cola.Enqueue(second);
            }
        }
        return cola.Dequeue().defeated.Min()!;
    }
}

public class TournamentNode
{
    /*
    simulate the tournament needs O(n) space, to store defeated values, notice that every element belongs to at most one defeated list, due to the fact that the tournament is direct elimination.
    */
    public TournamentNode(int value)
    {
        Value = value;
    }
    public List<int> defeated = new List<int>();
    public int Value { get; }
}