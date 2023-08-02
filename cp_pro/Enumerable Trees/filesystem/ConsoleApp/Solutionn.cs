using System.Text;
using filesystem;
namespace MatCom.Exam;
public class Exam
{
    public static IFileSystem CreateFileSystem()
    {
        return new AFileSystem(new AFolder(""));
    }
    public static string Nombre => "Alvaro Luis Gonzalez Brito";
    public static string Grupo => "C113";
}
