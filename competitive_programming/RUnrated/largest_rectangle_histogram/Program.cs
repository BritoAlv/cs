using Xunit;
public class Test
{
    [Theory]
    [InlineData(3, 2, 1, 1)]
    [InlineData(16, 3, 6, 4, 6, 5)]
    public void test_slow_algorithm(params int[] heights)
    {
        Assert.Equal(heights[0], slow_algorithm(heights.Skip(1).ToArray()));
    }
    [Theory]
    [InlineData(2, 1, 1)]
    [InlineData(3, 2, 1, 1)]
    [InlineData(16, 3, 6, 4, 6, 5)]
    [InlineData(3, 2, 1, 4)]
    [InlineData(16, 4, 3, 5, 6, 7, 3, 4, 6, 5)]
    [InlineData(3, 2, 4, 2, 2, 4, 4)]
    [InlineData(32, 1, 2, 3, 2, 1, 1)]
    [InlineData(16, 3, 4, 2, 8, 90, 6, 5)]
    public void test_algorithm(params int[] heights)
    {
        Assert.Equal(slow_algorithm(heights), algorithm(heights));
    }

    public int slow_algorithm(int[] heights)
    {
        int max = heights[0];
        for (int i = 0; i < heights.Length; i++)
        {
            int aux = heights[i];
            max = Math.Max(max, aux);
            for (int j = i - 1; j >= 0; j--)
            {
                if (aux > heights[j])
                {
                    aux = heights[j];
                }
                max = Math.Max(max, aux * (i + 1 - j));
            }
        }
        return max;
    }
    public int algorithm(int[] heights)
    {
        /*
        this solution is linear because every height on the array is involved in the operations at most once, push, pope
        */
        int answer = heights[0]; // a valid answer to start with.
        Stack<(int, int)> stack = new Stack<(int, int)>(); // create an empty stack.
        for (int i = 0; i < heights.Length; i++) // loop through all the heights.
        {
            if (stack.Count == 0 || stack.Peek().Item1 <= heights[i])
            {
                stack.Push((heights[i], 0));
            }
            else
            {
                while (stack.Count > 0)
                {
                    var last_poped = stack.Pop();
                    var its_value = last_poped.Item2 + 1;
                    answer = Math.Max(answer, last_poped.Item1 * (its_value));
                    if (stack.Count > 0 && stack.Peek().Item1 > heights[i])
                    {
                        var pop = stack.Pop();
                        pop.Item2 += its_value;
                        stack.Push(pop);
                        continue;
                    }
                    stack.Push((heights[i], its_value));
                    break;
                }
            }
        }
        while (stack.Count > 0)
        {
            var last_poped = stack.Pop();
            var its_value = last_poped.Item2 + 1;
            answer = Math.Max(answer, last_poped.Item1 * (its_value));
            if (stack.Count > 0)
            {
                var pop = stack.Pop();
                pop.Item2 += its_value;
                stack.Push(pop);
            }
        }
        return answer;
    }
}