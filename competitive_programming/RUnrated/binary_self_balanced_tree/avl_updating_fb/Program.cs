using System.Diagnostics;
using avlfb;
public class Test
{

    public static void Main()
    {
        Node a = new Node(1);
        for (int i = 2; i < 11; i++)
        {
            a  = Node.insert_avl(i,a);
        }
        print_tree.print(a);
        Console.WriteLine(Node.select(a, 9).value);
    }
}