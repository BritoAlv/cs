namespace avlfb;
public partial class Node : Iprintable
{
    public static Node delete_avl(int valor, Node root)
    {
        if (root.parent == null && root.left == null && root.right == null)
        {
            throw new Exception("Tree cannot be empty");
        }
        Node? to_be_deleted = Node.find_bst(valor, root); // find the node that it's going to be deleted.
        if (to_be_deleted == null)
        {
            return root;
        }

        /*
        Next two cases are easy to handle and do not affect balance factor.
        */
        /*
        delete root in case only has left child.
        */
        if (to_be_deleted.parent == null && to_be_deleted.right == null)
        {
            to_be_deleted.left!.parent = null;
            return to_be_deleted.left;
        }

        /*
        delete root in case only has right child
        */

        if (to_be_deleted.parent == null && to_be_deleted.left == null)
        {
            to_be_deleted.right!.parent = null;
            return to_be_deleted.right;
        }
        /*
        Notice that at this point every node that's going to be deleted have parent, because worst case is root but it has right child, so in-order successor have parent. 
        */

        /*
        invariant with delete operations is that height of that subtree decreased.
        */
        Node current;
        Node? parent;

        if (to_be_deleted.right == null && to_be_deleted.left == null)
        {
            /*
            dealing with leaf. this means that node doesn't have child, so once we delete it we decrease the height of that subtree because it doesn't have child.
            */
            current = to_be_deleted;

            update_size_children(current); // because it's going to be deleted I have to decrease size in 1 of all the parents.
            parent = current.parent;
            do_balancing(current); // we call do_balancing once we know invariant is active, i.e ,  
            if (to_be_deleted.is_left)
            {
                to_be_deleted.parent!.left = null;
            }
            else
            {
                to_be_deleted.parent!.right = null;
            }
        }
        /*
        PERFORM DELETE IN NODES THAT DOESN'T HAVE RIGHT CHILD.
        */
        else if (to_be_deleted.right == null)
        {
            update_size_children(to_be_deleted); // because it's going to be deleted I have to decrease size in 1 of all the parents.
            parent = to_be_deleted.parent!;
            if (to_be_deleted.is_left)
            {
                to_be_deleted.parent!.left = to_be_deleted.left;
                current = parent.left!;
            }
            else
            {
                to_be_deleted.parent!.right = to_be_deleted.left;
                current = parent.right!;
            }
            do_balancing(current);
        }
        /*
        PERFORM DELETE IN NODES THAT HAVE RIGHT CHILD.
        */
        else
        {
            Node successor = menor_mayor(to_be_deleted);
            int new_value = successor.value;
            /*
            in this case will do deletion and update balance factor of parent manually, rest of the job will be done by the while.
            */
            update_size_children(successor);
            Node? succesor_child = successor.right;
            if (succesor_child is null)
            {
                do_balancing(successor);
            }
            else
            {
                do_balancing(succesor_child);
            }
            parent = successor.parent!;
            if (successor.is_right)
            {
                parent.right = succesor_child;
            }
            else
            {
                parent.left = succesor_child;
            }
            /*
            swap values.
            */
            to_be_deleted.value = new_value;
            return Node.get_root(parent);
        }
        return Node.get_root(current);
    }

    private static void update_size_children(Node current)
    {
        /*
        decrease size of parent as long as we can.
        */
        while (current.parent != null)
        {
            if (current.is_left)
            {
                current.parent.left_size -= 1;
            }
            if (current.is_right)
            {
                current.parent.right_size -= 1;
            }
            current = current.parent;
        }
    }
    private static void do_balancing(Node current)
    {
        /*
        do_balancing will work as the invariant that the height of the subtree where is current decreased so the balance factor of parent may change, so we need to update it, and check if invariant is still maintained. recall that the invariant here is decrease and rotations balance the factors but decrease heights so this makes intuitive that after rotations we get more not balanced nodes.
        */
        Node? parent = current.parent;
        while (parent != null)
        {
            if (current.is_left) // we are coming from the left.
            {
                if (parent.balance_factor == '-') // this means we are coming from the left and this is the path that determines height, this means that once we fix balance factor invariant is maintained, so while should continue, the logic is that if we delete a node from the left of the parent and parent is -, this means that height of this parent will get balanced, but the height of the subtree rooted at parent decreased, so we have to update the balance factor of the parent with the same logic.
                {
                    parent.balance_factor = '.';
                }
                else if (parent.balance_factor == '.') // it get balanced but height don't decrease, so we stop the while because invariant is not maintained.
                {
                    parent.balance_factor = '+';
                    break;
                }
                else if (parent.balance_factor == '+') // let's recap what's going on, our parent balance factor gets to be ++, so we need to solve unbalancing, and check if height decreased this will be if after solving the unbalancing it ends up being . ( ++ +, or ++ -), recall that now can appear the rotation (++,.), this one after solved can end up being parent a "-", and this will keep everything up fine so we can stop without affecting anything.
                {
                    parent = fix_delete_right_imbalance(parent);
                    if (parent.balance_factor == '-')
                    {
                        break;
                    }
                }
            }
            else
            {
                if (parent.balance_factor == '+')
                {
                    parent.balance_factor = '.';
                }
                else if (parent.balance_factor == '.')
                {
                    parent.balance_factor = '-';
                    break;
                }
                else if (parent.balance_factor == '-')
                {
                    parent = fix_delete_left_imbalance(parent); // (--) -
                    if (parent.balance_factor == '+')
                    {
                        break;
                    }
                }
            }
            current = parent;
            parent = current.parent;
        }
    }
    private static Node fix_delete_left_imbalance(Node parent)
    {
        var bf = parent.left!.balance_factor;
        if (bf == '-')
        {
            parent = Node.minus_minus_minus(parent);
            parent.balance_factor = '.';
            parent.right!.balance_factor = '.';
        }
        else if (bf == '.')
        {
            parent = Node.minus_minus_minus(parent);
            parent.balance_factor = '+';
            parent.right!.balance_factor = '-';
        }
        else if (bf == '+')
        {
            int oldbf = parent.left!.right!.balance_factor;
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
                parent.left!.balance_factor = '.';
                parent.right!.balance_factor = '.';
            }
        }
        return parent;
    }
    private static Node fix_delete_right_imbalance(Node parent)
    {
        var bf = parent.right!.balance_factor;
        if (bf == '+')
        {
            parent = Node.plus_plus_plus(parent);
            parent.balance_factor = '.';
            parent.left!.balance_factor = '.';
        }
        else if (bf == '.')
        {
            parent = Node.plus_plus_plus(parent);
            parent.balance_factor = '-';
            parent.left!.balance_factor = '+';
        }

        else if (bf == '-')
        {
            int oldbf = parent.right!.left!.balance_factor;
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
                parent.left!.balance_factor = '.';
                parent.right!.balance_factor = '.';
            }
        }
        return parent;
    }
    public static Node menor_mayor(Node root)
    {
        if (root.right == null)
        {
            return root;
        }
        Node start = root.right; // this is not null because ?
        while (start.left != null)
        {
            start = start.left;
        }
        return start;
    }
}