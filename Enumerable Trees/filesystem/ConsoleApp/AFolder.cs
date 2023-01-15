using filesystem;
namespace MatCom.Exam;

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
        AFolder destination_folder = this.GetAFolder(folder.name)!;
        foreach (var file in folder.subfiles.Items)
        {
            destination_folder.CopyFile(file);
        }
        foreach (var subfolder in folder.subfolders.Items)
        {
            destination_folder.CopyFolder(subfolder);
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
                var folder = this.GetAFolder(next_folder);
                if (folder != null)
                {
                    return folder.FindFile(new_path.Substring(next_folder.Length));
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
