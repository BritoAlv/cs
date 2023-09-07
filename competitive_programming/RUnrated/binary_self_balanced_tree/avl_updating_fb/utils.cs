namespace avlfb;
public partial class Node : Iprintable
{
    /// <summary>
    /// Compute Height Of Node.
    /// </summary>
    /// <param name="root"></param>
    /// <returns></returns>
    public static int get_height(Node root)
    {
        var left_height = root.left == null ? -1 : get_height(root.left);
        var right_height = root.right == null ? -1 : get_height(root.right);
        return 1 + Math.Max(left_height, right_height);
    }

    public IEnumerable<Iprintable> GetChildrenIprintables()
    {
        if (left != null)
        {
            yield return left;
        }
        if (right != null)
        {
            yield return right;
        }
    }
    /// <summary>
    /// 
    /// </summary>
    /// <param name="valor"></param>
    /// <param name="root"></param>
    /// <returns> null if value is not found, if its found return deepest node with that value. </returns>
    public static Node? find_bst(int valor, Node? root)
    {
        /*
        return deepest appearance of a node in the tree, if it doesn't appear return null.
        */
        if (root is null)
        {
            return null;
        }
        if (valor < root.value)
        {
            return Node.find_bst(valor, root.left);
        }
        if (valor > root.value)
        {
            return Node.find_bst(valor, root.right);
        }
        if (valor == root.value)
        {
            Node? other = find_bst(valor, root.right);
            if (other is null)
            {
                return root;
            }
            return other;
        }
        return null;
    }
    public static void IsInvariantMantained(Node root)
    {
        if (root.parent != null)
        {
            if (root.parent.left == root)
            {
                if (root.value >= root.parent.value)
                {
                    throw new Exception("");
                }
            }
            else
            {
                if (root.value < root.parent.value)
                {
                    throw new Exception("");
                }
            }
        }

        if (root.left != null)
        {
            IsInvariantMantained(root.left);
        }
        if (root.right != null)
        {
            IsInvariantMantained(root.right);
        }
    }
    public static bool contains_bst(int valor, Node root)
    {
        Node? a = Node.find_bst(valor, root);
        return a == null;
    }
    public string valor => Get_valor();
    public string Get_valor()
    {
        string result = value.ToString() + " ";
        result += " fb = ";
        result += balance_factor;
        if (this.is_left)
        {
            result += ", L";
        }
        if (this.is_right)
        {
            result += ", R";
        }
        result += " LH := " + this.left_size;
        result += " RH := " + this.right_size;
        return result;
    }
    public static Node get_root(Node node)
    {
        while (node.parent != null)
        {
            node = node.parent;
        }
        return node;
    }

    /// <summary>
    /// return the number of nodes in the tree that are less than k.
    /// </summary>
    /// <param name="actual_node"></param>
    /// <param name="k"></param>
    /// <returns></returns>
    public static int rank(Node actual_node, int k)
    {
        if (actual_node.value < k)
        {
            var first_result = 1 + actual_node.left_size;
            if (actual_node.right != null)
            {
                first_result += rank(actual_node.right, k);
            }
            return first_result;
        }
        else if (actual_node.value == k)
        {
            return actual_node.left_size;
        }
        else
        {
            if (actual_node.left is null)
            {
                return 0;
            }
            return rank(actual_node.left, k);
        }
    }

    /// <summary>
    /// return the (k+1)-th smallest element in a tree rooted at actual node.
    /// </summary>
    /// <param name="actual_node"></param>
    /// <param name="k"></param>
    /// <returns></returns>
    public static Node select(Node actual_node, int k)
    {
        if (actual_node.left_size == k)
        {
            return actual_node;
        }

        else if (actual_node.left_size < k)
        {
            if (actual_node.right == null)
            {
                throw new Exception("There are less than " + k + " elements ");
            }
            return select(actual_node.right, (k - actual_node.left_size-1));
        }
        else
        {
            if (actual_node.left == null)
            {
                throw new Exception("There are less than " + k + " elements ");
            }
            return select(actual_node.left, k);
        }
    }
}