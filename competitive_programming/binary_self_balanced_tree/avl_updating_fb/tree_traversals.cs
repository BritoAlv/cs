namespace avlfb;
public partial class Node : Iprintable
{
    public static IEnumerable<Node> InOrder(Node root)
    {
        if (root.left != null)
        {
            foreach (var item in InOrder(root.left))
            {
                yield return item;
            }
        }
        yield return root;
        if (root.right != null)
        {
            foreach (var item in InOrder(root.right))
            {
                yield return item;
            }
        }
    }
    public static IEnumerable<Node> Pre_Order(Node root)
    {
        yield return root;
        if (root.left is not null)
        {
            foreach (var node in Pre_Order(root.left))
            {
                yield return node;
            }
        }
        if (root.right is not null)
        {
            foreach (var node in Pre_Order(root.right))
            {
                yield return node;
            }
        }
    }
    public static IEnumerable<Node> PostOrder(Node root)
    {
        if (root.left != null)
        {
            foreach (var item in PostOrder(root.left))
            {
                yield return item;
            }
        }
        if (root.right != null)
        {
            foreach (var item in PostOrder(root.right))
            {
                yield return item;
            }
        }
        yield return root;
    }
}