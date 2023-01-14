namespace MatCom.Exam;

public interface IMyColection<T> where T: IDeable
{
    void Add(T item);
    bool Contains(T item);
    void Remove(T item);
    IEnumerable<T> Items { get; }
    
    /// <summary>
    /// This method assumes that the required element exist in the collection.
    /// </summary>
    /// <param name="name"></param>
    /// <returns></returns>
    T get_by_name(string name)
    {
        return Items.First(x => x.Id == name);
    }
}

public interface IDeable
{
    string Id{ get; }
}