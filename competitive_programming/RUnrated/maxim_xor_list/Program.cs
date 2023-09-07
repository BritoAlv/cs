public class Test
{
    public static void Main()
    {
        Console.WriteLine(max_xor(new int[6] { 3, 10, 5, 25, 2, 8 }));
        Console.WriteLine(max_xor(new int[2] { 32, 16 }));
    }

    /*
    Complexity is n*max_bits.
    */
    public static int max_xor(int[] numbers, int max_bits = 8)
    {
        Trie trie = new Trie();
        int max = numbers[0] ^ numbers[1];
        string first = Convert.ToString(numbers[0], 2).PadLeft(max_bits, '0');
        trie.insert(first);
        for (int i = 1; i < numbers.Length; i++)
        {
            string binary = Convert.ToString(numbers[i], 2).PadLeft(max_bits, '0');
            int max_xor = trie.max_xor(binary);
            if (max_xor > max)
            {
                max = max_xor;
            }
            trie.insert(binary);
        }
        return max;
    }
}

public class Trie
{
    string? end = null;
    char? value = null;
    Dictionary<char, Trie> childs = new Dictionary<char, Trie>();
    public Trie()
    {
    }
    private Trie(char Value)
    {
        this.value = Value;
    }
    public void insert(string binary)
    {
        var actual = this;
        for (int i = 0; i < binary.Length; i++)
        {
            actual = actual.insert(binary, i);
        }
    }
    public int max_xor(string binary, int pointer = 0)
    {
        var actual = this;
        char[] answer = new char[binary.Length];
        while (!(actual.end == null))
        {
            char to_found = binary[pointer] == '1' ? '0' : '1';
            if (actual.childs.ContainsKey(to_found))
            {
                actual = actual.childs[to_found];
                answer[pointer] = '1';
            }
            else
            {
                actual = actual.childs[binary[pointer]];
                answer[pointer] = '0';
            }
            pointer++;
        }
        return Convert.ToInt32(answer.Aggregate("", (m, x) => m + x), 2);
    }

    private Trie insert(string binary, int pointer)
    {
        char to_insert = binary[pointer];
        if (!childs.ContainsKey(to_insert))
        {
            childs[to_insert] = new Trie(to_insert);
        }
        if (binary.Length - 1 == pointer)
        {
            childs[to_insert].end = binary;
        }
        return childs[to_insert];
    }
}