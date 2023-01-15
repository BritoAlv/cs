namespace MatCom.Exam;
public class MiList<T> : IMyColection<T> where T: IDeable
{
    public MiList()
    {
        Backend_List = new List<T>();
    }
    public IEnumerable<T> Items => Backend_List;
    public List<T> Backend_List{ get; private set; }
    public void Add(T item)
    {
        Backend_List.Add(item);
    }
    public bool Contains(T item)
    {
        return Backend_List.Any(x => x.Id == item.Id);
    }
    public void Remove(T item)
    {
        List<T> result = new List<T>();
        foreach (var element in Backend_List)
        {
            if (element.Id != item.Id)
            {
                result.Add(element);
            }
        }
        Backend_List = result;
    }
}
