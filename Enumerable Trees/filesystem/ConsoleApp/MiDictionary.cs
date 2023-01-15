namespace MatCom.Exam;

public class MiDictionary<T> : IMyColection<T> where T : IDeable
{
    public MiDictionary()
    {
        Backend_Dictionary = new Dictionary<string, T>();
    }

    public IEnumerable<T> Items => Backend_Dictionary.Values;

    public Dictionary<string, T> Backend_Dictionary { get; private set; }

    public void Add(T item)
    {
        Backend_Dictionary[item.Id] = item;
    }

    public bool Contains(T item)
    {
        return Backend_Dictionary.ContainsKey(item.Id);
    }

    public void Remove(T item)
    {
        Backend_Dictionary.Remove(item.Id);
    }
}