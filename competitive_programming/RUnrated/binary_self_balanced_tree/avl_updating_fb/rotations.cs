namespace avlfb;
public partial class Node : Iprintable
{

    /// <summary>
    ///            (A) (h+3)                   
    ///          /   \
    ///    (h) (D)   (B) (h+2)     =>  ....       
    ///             /  \
    ///        (h)(E)   (C) (h+1)
    /// </summary>
    /// <param name="node">Node should be the one with balance factor ++, so that it's right child have balance factor = +</param>
    /// <returns>this will return its right child. (because it's ends up at the root, and node will be at its left. </returns>
    public static Node plus_plus_plus(Node node)
    {
        Node? parent = node.parent;
        Node right_child = node.right!;

        node.right_size = right_child.left_size;
        right_child.left_size += 1 + node.left_size;

        if (parent != null)
        {
            if (node.is_left)
            {
                parent.left = right_child;
            }
            if (node.is_right)
            {
                parent.right = right_child;
            }
        }
        right_child.parent = parent;
        node.right = right_child.left;
        right_child.left = node;
        return right_child;
    }
    /// <summary>
    ///            (A) (h+3)                   
    ///          /   \
    ///   (h+2)(B)   (D) (h)    =>  ....       
    ///       /  \
    ///  (h)(E)  (C) (h+1)
    /// </summary>
    /// <param name="node">Node should be the one with balance factor --, so that it's left child have balance factor = -</param>
    /// <returns>this will return its left child. (because it's ends up at the root, and node will be at its right. </returns>
    public static Node minus_minus_minus(Node node)
    {
        Node? parent = node.parent;
        Node left_child = node.left!;

        node.left_size = left_child.right_size;
        left_child.right_size += 1 + node.right_size;
        
        if (parent != null)
        {
            if (node.is_left)
            {
                parent.left = left_child;
            }
            if (node.is_right)
            {
                parent.right = left_child;
            }
        }
        left_child.parent = parent;
        node.left = left_child.right;
        left_child.right = node;
        return left_child;
    }
}