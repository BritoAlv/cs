using filesystem;
namespace MatCom.Exam;

public class AFileSystem : IFileSystem
{
    public AFileSystem(AFolder root)
    {
        Root = root;
    }
    public AFolder Root { get; set; }
    public void Copy(string origin, string destination)
    {
        var destination_folder = (AFolder)GetFolder(destination);
        IFile? file = this.Root.FindFile(origin);
        if (file != null)
        {
            destination_folder.CopyFile((AFile)file);
            return;
        }
        IFolder? folder = this.Root.FindFolder(origin);
        if (folder != null)
        {
            destination_folder.CopyFolder(((AFolder)folder));
            return;
        }
        throw new Exception("No se pudo copiar");
    }
    public void Delete(string path)
    {
        if (path_dealer.is_valid_path(path))
        {
            int i = path.Length - 1;
            while (path[i] != '/')
            {
                i--;
            }
            IFolder? parent_folder;
            if (i == 0) 
            {
                parent_folder = this.Root;
            }
            else
            {
                parent_folder = this.Root.FindFolder(path.Substring(0, i));
            }
            if (parent_folder != null)
            {
                var parent = (AFolder)parent_folder;
                var file = this.Root.FindFile(path);
                if (file != null)
                {
                    parent.DeleteFile((AFile)file);
                    return;
                }
                var folder = this.Root.FindFolder(path);
                if (folder != null)
                {
                    parent.DeleteFolder((AFolder)folder);
                    return;
                }
            }
        }
        throw new Exception("No se pudo borrar");
        
    }
    public IEnumerable<IFile> Find(FileFilter filter)
    {
        var currentFolder = this.Root;
        foreach (var file in currentFolder.GetFiles())
        {
            if (filter(file))
                yield return file;
        }
        foreach (var folder in Root.GetFolders())
        {
            foreach (var file in GetRoot("/" + folder.Name).Find(filter))
            {
                yield return file;
            }
        }
    }
    public IFile GetFile(string path)
    {
        IFile? file = this.Root.FindFile(path);
        if (file == null)
        {
            throw new Exception("No se encontró el archivo");
        }
        return file;
    }
    public IFolder GetFolder(string path)
    {
        if (path == "/")
        {
            return this.Root;
        }
        IFolder? folder = this.Root.FindFolder(path);
        if (folder == null)
        {
            throw new Exception("No se encontró la carpeta");
        }
        return folder;
    }
    public IFileSystem GetRoot(string path)
    {
        return new AFileSystem((AFolder)GetFolder(path));
    }
    public void Move(string origin, string destination)
    {
        Copy(origin, destination);
        Delete(origin);
    }
}
