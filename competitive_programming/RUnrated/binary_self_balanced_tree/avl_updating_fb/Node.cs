/*
AVL Implementation that doesn't store height,  store only balance factor and updating it in real-time.
*/
namespace avlfb;
public partial class Node : Iprintable
{
    public Node(int value, Node? parent = null)
    {
        this.value = value;
        this.parent = parent;
        this.left_size = 0;
        this.right_size = 0;
    }
    public int value;
    public char balance_factor = '.';
    int left_size;
    int right_size;
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
}