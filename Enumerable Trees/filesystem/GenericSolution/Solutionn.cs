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
public class AFolder : IFolder, IDeable
{
    private readonly string name;
    IMyColection<AFolder> subfolders{ get; }
    IMyColection<AFile> subfiles{ get; }
    public AFolder(string name)
    {
        this.name = name;
        subfolders = new MiList<AFolder>(); // injecting specific implementation
        subfiles = new MiDictionary<AFile>(); // injecting specific implementation.
    }

    public AFolder(string name, IEnumerable<AFile> files, IEnumerable<AFolder> folders) : this(name)
    {
        foreach (var file in files)
        {
            subfiles.Add(file);
        }
        foreach (var folder in folders)
        {
            subfolders.Add(folder);
        }
    }
    public AFolder Clone() => new AFolder(Name, subfiles.Items.Select(f => f.Clone()), subfolders.Items.Select(f => f.Clone()));
    public string Name => name;
    public string Id => name;
    public IFile CreateFile(string name, int size)
    {
        if (this.ContainFile(name))
        {
            throw new Exception("Archivo ya existe");
        }
        var new_file = new AFile(name, size);
        subfiles.Add(new_file);
        return new_file;
    }
    public IFolder CreateFolder(string name)
    {
        if (this.ContainFolder(name))
        {
            throw new Exception("Carpeta ya existe");
        }
        var new_folder = new AFolder(name);
        subfolders.Add(new_folder);
        return new_folder;
    }
    public void CopyFile(AFile file)
    {
        subfiles.Remove(file);
        subfiles.Add(new AFile(file.Name, file.Size));
    }
    public void CopyFolder(AFolder folder)
    {
        if (!this.ContainFolder(folder.name))
        {
            this.CreateFolder(folder.name);
        }
        foreach (var file in folder.subfiles.Items)
        {
            this.GetAFolder(folder.name)!.CopyFile(file);
        }
        foreach (var subfolder in folder.subfolders.Items)
        {
            this.GetAFolder(folder.name)!.CopyFolder(subfolder);
        }
    }
    public bool ContainFile(string name)
    {
        return subfiles.Items.Any(x => x.Id == name);
    }
    public bool ContainFolder(string name)
    {
        return subfolders.Items.Any(x => x.Id == name);
    }
    public void DeleteFile(AFile file)
    {
        this.subfiles.Remove(file);
    }
    public void DeleteFolder(AFolder folder)
    {
        this.subfolders.Remove(folder);
    }
    public IEnumerable<IFile> GetFiles()
    {
        return this.subfiles.Items.OrderBy(x => x.Name);
    }
    public IEnumerable<IFolder> GetFolders()
    {
        return this.subfolders.Items.OrderBy(x => x.Name);
    }
    public int TotalSize() => subfiles.Items.Sum(f => f.Size) + subfolders.Items.Sum(f => f.TotalSize());
    public AFolder? GetAFolder(string name)
    {
        if(ContainFolder(name))
        {
            return subfolders.get_by_name(name);
        }
        return null;
    }
    public AFile? GetAFile(string name)
    {
        if(ContainFile(name))
        {
            return subfiles.get_by_name(name);
        }
        return null;
    }
    public IFile? FindFile(string path)
    {
        if (path_dealer.is_valid_path(path))
        {
            var new_path = path.Substring(1);
            if (path.Count(x => x == '/') == 1)
            {
                return this.GetAFile(new_path);
            }
            else
            {
                var next_folder = "";
                int i = 0;
                while (new_path[i] != '/')
                {
                    next_folder = next_folder + new_path[i];
                    i++;
                }
                if (this.ContainFolder(next_folder))
                {
                    return this.GetAFolder(next_folder)!.FindFile(new_path.Substring(next_folder.Length));
                }
                return null;
            }
        }
        throw new Exception("Invalid File Path");
    }

    public IFolder? FindFolder(string path)
    {
        if (path_dealer.is_valid_path(path))
        {
            var new_path = path.Substring(1);
            if (path.Count(x => x == '/') == 1)
            {
                return this.GetAFolder(new_path);
            }
            else
            {
                var next_folder = "";
                int i = 0;
                while (new_path[i] != '/')
                {
                    next_folder = next_folder + new_path[i];
                    i++;
                }
                if (this.ContainFolder(next_folder))
                {
                    return this.subfolders.get_by_name(next_folder).FindFolder(new_path.Substring(next_folder.Length));
                }
                return null;
            }
        }
        throw new Exception("Invalid Folder Path");
    }
}

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


public static class path_dealer
{
    public static bool is_valid_path(string path)
    {
        if(!path.StartsWith("/"))
        {
            return false;
        }

        if (path.EndsWith("/") && path.Length > 1)
        {
            return false;
        }

        for (int i = 0; i < path.Length; i++)
        {
            if (path[i] == '/')
            {
                if (i+1 <= path.Length-1 && path[i+1] == '/' )
                {
                    return false;
                }
            }
        }
        return true;
    }    
}