using filesystem;
namespace MatCom.Exam;

public class AFile : IFile, IDeable
{
    public AFile(string name, int size)
    {
        Name = name;
        Size = size;
    }
    public int Size { get; }
    public string Name { get; }
    public string Id => Name;
    public AFile Clone() => new AFile(this.Name, this.Size);
}
