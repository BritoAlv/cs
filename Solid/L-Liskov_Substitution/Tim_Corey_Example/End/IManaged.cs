public interface IManaged: IEmployee
{
    IManager Manager { get; set; }
    void AssignManager(IManager manager);
}
