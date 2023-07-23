public class id_element<U> : IComparable<id_element<U>> where U : IComparable
{
    public int id;
    public U val;

    public id_element(int id, U val)
    {
        this.id = id;
        this.val = val;
    }

    public int CompareTo(id_element<U> other)
    {
        return this.val.CompareTo(other.val);
    }


}
