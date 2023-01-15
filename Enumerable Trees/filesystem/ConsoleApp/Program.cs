using filesystem;
using MatCom.Exam;
public class Test
{
    public static void Main()
    {
        IFileSystem a = Exam.CreateFileSystem();
        IFolder root = a.GetFolder("/");
        root.CreateFolder("Downloads");
        root.CreateFile("temp.dll", 20);

    }
}