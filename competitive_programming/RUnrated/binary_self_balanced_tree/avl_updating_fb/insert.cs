namespace avlfb;
public partial class Node : Iprintable
{
    public static Node insert_avl(int value, Node root)
    {
        Node current = Node.insert_bst(value, root);
        Node? parent = current.parent;

        /*
        while height at node parent increased keep going, this means we have to update its balance factor and determine if height increased at parent to decide if keep going or not.
        */

        while (parent != null)
        {
            /*
            notice that when we insert height of subtree tend to increase, we update balance factor and keep going but when we do rotations, balance factors are fixed, but height is restored to the original before insertion, in other words rotations decrease height. to be more concrete rotation  decrease height, because it was increased, it get decremented so restored to original.
            */
            if (current.is_left) // we are coming from the left subtree.
            {
                if (parent.balance_factor == '+') // it get's balanced so end
                {
                    parent.balance_factor = '.';
                    break;
                }
                else if (parent.balance_factor == '.') // decrease balance factor and height at that subtree increased so we need to keep going. because invariant is maintained.
                {
                    parent.balance_factor = '-';
                }
                else if (parent.balance_factor == '-') // decrease balance factor and height, so we apply rotations, but it turns out that them leave height of the sub_tree unchanged, so we can stop as long as we know how to rotate effectively.
                {
                    fix_insert_left_imbalance(parent);
                    break;
                }
            }
            else // we are coming from the right subtree. reverse process of the stuff explained before.
            {
                if (parent.balance_factor == '-')
                {
                    parent.balance_factor = '.';
                    break;
                }
                else if (parent.balance_factor == '.')
                {
                    parent.balance_factor = '+';
                }
                else if (parent.balance_factor == '+')
                {
                    fix_insert_right_imbalance(parent);
                    break;
                }
            }
            current = parent;
            parent = current.parent;
        }
        return Node.get_root(current);
    }
    /// <summary>
    /// Modify our tree by inserting a new node.
    /// </summary>
    /// <param name="valor"> value to insert. </param>
    /// <param name="root">  root of tree where insert value. </param>
    /// <returns> Return Inserted Node. </returns>
    public static Node insert_bst(int valor, Node root)
    {
        if (valor < root.value)
        {
            root.left_size += 1;
            if (root.left == null)
            {
                root.left = new Node(valor, root);
                return root.left;
            }
            else
            {
                return insert_bst(valor, root.left);
            }
        }
        else
        {
            root.right_size += 1;
            if (root.right == null)
            {
                root.right = new Node(valor, root);
                return root.right;
            }
            else
            {
                return insert_bst(valor, root.right);
            }
        }

    }
    public static Node fix_insert_left_imbalance(Node parent)
    {
        if (parent.left!.balance_factor == parent.balance_factor)
        {
            parent = Node.minus_minus_minus(parent); // minus minus rotations leave everything in .,  so everything is nice.
            parent.balance_factor = '.';
            parent.right!.balance_factor = '.';
        }
        else
        {
            int oldbf = parent.left.right!.balance_factor; // ++, - depends on state of third node involved that's why it gets saved.
            Node.plus_plus_plus(parent.left);
            parent = Node.minus_minus_minus(parent);
            parent.balance_factor = '.';
            if (oldbf == '-')
            {
                parent.left!.balance_factor = '.';
                parent.right!.balance_factor = '+';
            }
            else if (oldbf == '+')
            {
                parent.left!.balance_factor = '-';
                parent.right!.balance_factor = '.';
            }
            else if (oldbf == '.')
            {
                parent.left!.balance_factor = parent.right!.balance_factor = '.';
            }
        }
        return parent;
    }
    public static Node fix_insert_right_imbalance(Node parent)
    {
        if (parent.right!.balance_factor == parent.balance_factor)
        {
            parent = Node.plus_plus_plus(parent);
            parent.balance_factor = '.';
            parent.left!.balance_factor = '.';
        }
        else
        {
            int oldbf = parent.right.left!.balance_factor;
            Node.minus_minus_minus(parent.right);
            parent = Node.plus_plus_plus(parent);
            parent.balance_factor = '.';
            if (oldbf == '-')
            {
                parent.left!.balance_factor = '.';
                parent.right!.balance_factor = '+';
            }
            else if (oldbf == '+')
            {
                parent.left!.balance_factor = '-';
                parent.right!.balance_factor = '.';
            }
            else if (oldbf == '.')
            {
                parent.left!.balance_factor = parent.right!.balance_factor = '.';
            }
        }
        return parent;
    }
}