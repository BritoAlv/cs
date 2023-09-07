/*
AVL Implementation that doesn't store height or balance factors, compute whenever needed, this is the worse implementation.
*/

namespace avlvivo;

public class Node : Iprintable
{
    public int value;
    public int balance_factor
    {
        get
        {
            var left = this.left == null ? -1 : this.left.height;
            var right = this.right == null ? -1 : this.right.height;
            return right - left;
        }
    }
    int height
    {
        get
        {
            var left = this.left == null ? -1 : this.left.height;
            var right = this.right == null ? -1 : this.right.height;
            return 1 + Math.Max(left, right);
        }
    }
    Node? parent;
    Node? _left = null;
    Node? _right = null;
    Node? left
    {
        get
        {
            return _left;
        }
        set
        {
            _left = value;
            if (value != null)
            {
                value.parent = this;
            }
        }
    }
    Node? right
    {
        get
        {
            return _right;
        }
        set
        {
            _right = value;
            if (value != null)
            {
                value.parent = this;
            }
        }
    }
    bool is_left
    {
        get
        {
            return parent == null ? false : parent.value > value;
        }
    }
    bool is_right
    {
        get
        {
            return parent == null ? false : parent.value <= value;
        }
    }
    public string valor => Get_valor();
    public string Get_valor()
    {
        string result = value.ToString() + " ";
        result += " fb = ";
        string fb = "";
        if (balance_factor <= -2)
        {
            fb = "--";
        }
        if (balance_factor == -1)
        {
            fb = "-";
        }
        if (balance_factor == 0)
        {
            fb = ".";
        }
        if (balance_factor == 1)
        {
            fb = "+";
        }
        if (balance_factor >= 2)
        {
            fb = "++";
        }
        result += fb;
        if (this.is_left)
        {
            result += ", L";
        }
        if (this.is_right)
        {
            result += ", R";
        }
        return result + ", Height = " + this.height;
    }
    public Node(int value, Node? parent = null)
    {
        this.value = value;
        this.parent = parent;
    }
    public static IEnumerable<Node> get_nodes(Node root)
    {
        yield return root;
        if (root.left is not null)
        {
            foreach (var node in get_nodes(root.left))
            {
                yield return node;
            }
        }
        if (root.right is not null)
        {
            foreach (var node in get_nodes(root.right))
            {
                yield return node;
            }
        }
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
    /*
    find in-order successor of a node, if it's himself return him.
    */
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
    /*
    Goal of this is to delete a requested value from the node, it is not restricted to return anything, but because i want to use it after to implement an avl, the returned node will be where the re-balancing should start.
    */
    public static Node delete_bst(int valor, Node root)
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
        ///////////////////////////
        /// Node Is In The Tree. ( our node should have at least left child, right child //or parent)
        ///////////////////////////
        Node parent = to_be_deleted.parent!;
        ///////////////////////////
        /// Node Doesn't have left child.
        //////////////////////////
        if (to_be_deleted.left == null)
        {
            if (to_be_deleted.is_left)
            {
                parent.left = to_be_deleted.right;
            }

            else if (to_be_deleted.is_right)
            {
                parent.right = to_be_deleted.right;
            }
            else
            {
                to_be_deleted.right!.parent = null;
                parent = to_be_deleted.right;
            }
            return parent;
        }
        /////////////
        /// Node is a leaf
        ////////////
        if (to_be_deleted.right == null)
        {
            if (to_be_deleted.is_left)
            {
                parent.left = to_be_deleted.left;
            }
            else if (to_be_deleted.is_right)
            {
                parent.right = to_be_deleted.left;
            }
            else
            {
                to_be_deleted.left!.parent = null;
                parent = to_be_deleted.left;
            }
            return parent;
        }
        Node successor = menor_mayor(to_be_deleted);
        int new_value = successor.value;
        Node c = Node.delete_bst(new_value, successor);
        to_be_deleted.value = new_value;
        return c;
    }
    private static bool contains_bst(int valor, Node root)
    {
        Node? a = Node.find_bst(valor, root);
        return a == null;
    }
    public static Node insert_bst(int valor, Node root)
    {
        /*
        return inserted node.
        */
        if (valor < root.value)
        {
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
        if (root.right == null)
        {
            root.right = new Node(valor, root);
            return root.right;
        }
        return insert_bst(valor, root.right);
    }
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

    /*
    Rotations will be done in a node with ++, -- (i mean it's unbalanced), rooted here.
    */
    public static Node plus_plus_plus(Node node)
    {
        Node? parent = node.parent;
        Node right_child = node.right!;
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
    public static Node get_root(Node node)
    {
        while (node.parent != null)
        {
            node = node.parent;
        }
        return node;
    }
    public static Node minus_minus_minus(Node node)
    {
        Node? parent = node.parent;
        Node left_child = node.left!;
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
    public static Node plus_plus_minus(Node node)
    {
        Node resulting = minus_minus_minus(node.right!);
        if (resulting.parent == null)
        {
            return resulting;
        }
        return plus_plus_plus(resulting.parent);
    }
    public static Node minus_minus_plus(Node node)
    {
        Node resulting = plus_plus_plus(node.left!);
        if (resulting.parent == null)
        {
            return resulting;
        }
        return minus_minus_minus(resulting.parent!);
    }
    public static Node minus_minus_dot(Node node)
    {
        return minus_minus_minus(node);
    }
    public static Node plus_plus_dot(Node node)
    {
        return plus_plus_plus(node);
    }
    public static Node rotation_switcher(Node node)
    {
        if (node.balance_factor <= -2 && node.left!.balance_factor == -1)
        {
            return Node.minus_minus_minus(node);
        }
        else if (node.balance_factor <= -2 && node.left!.balance_factor == 0)
        {
            return Node.minus_minus_dot(node);
        }
        else if (node.balance_factor <= -2 && node.left!.balance_factor == 1)
        {
            return Node.minus_minus_plus(node);
        }

        else if (node.balance_factor >= 2 && node.right!.balance_factor == -1)
        {
            return Node.plus_plus_minus(node);
        }
        else if (node.balance_factor >= 2 && node.right!.balance_factor == 0)
        {
            return Node.plus_plus_dot(node);
        }
        else if (node.balance_factor >= 2 && node.right!.balance_factor == 1)
        {
            return Node.plus_plus_plus(node);
        }
        else
        {
            return node;
        }

    }
    public static Node delete_avl(int valor, Node root)
    {
        Node parent_deleted = Node.delete_bst(valor, root);
        if (parent_deleted.balance_factor == -1 || parent_deleted.balance_factor == 1)
        {
            return Node.get_root(parent_deleted);
        }
        Node current = parent_deleted;
        while (current != null)
        {
            if (current.balance_factor == 0)
            {
                current = current.parent;
                continue;
            }

            if (current.balance_factor >= 2 || current.balance_factor <= -2)
            {
                current = Node.rotation_switcher(current);
                continue;
            }

            if (current.balance_factor == -1 || current.balance_factor == 1)
            {
                return Node.get_root(current);
            }
        }
        return Node.get_root(parent_deleted);
    }
    public static Node insert_avl(int valor, Node root)
    {
        Node inserted = Node.insert_bst(valor, root);
        Node? current = inserted.parent;
        if (current == null)
        {
            return Node.get_root(root);
        }
        if (current.balance_factor == 0)
        {
            return Node.get_root(inserted);
        }
        else
        {
            while (current != null)
            {
                if (current.balance_factor == 0)
                {
                    return Node.get_root(current);
                }
                if (current.balance_factor == -1 || current.balance_factor == 1)
                {
                    current = current.parent;
                    continue;
                }
                else
                {
                    current = Node.rotation_switcher(current);
                    return Node.get_root(current);
                }
            }
        }
        return Node.get_root(inserted);
    }
}