/// <summary>
/// You should implement this interface in your BinaryTree class:
/// </summary>
public interface IPrintable
{
    /// <summary>
    /// Given a node of the tree return in an IEnumerable its children.
    /// </summary> 
    IEnumerable<IPrintable> GetChildrenIprintables();

    /// <summary>
    /// what will be printed for that node.
    /// </summary>
    string valor { get; }
}
