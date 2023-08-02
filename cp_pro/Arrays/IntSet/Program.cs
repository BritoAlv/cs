public class Set{
    public static Set Difference(Set a, Set b){
        // los elementos de a que no estan en b.
        Set c = Intersection(a,b);
        bool q = a.belongss(0) && (!b.belongss(0));
        int[] cc = new int[a.elements_of_set.Length];
        for (int i = 0; i < a.elements_of_set.Length; i++)
        {
            if(!(c.elements_of_set.Contains(a.elements_of_set[i]))){
                 cc[i] = a.elements_of_set[i];
            }
        }
        cc = fix_zeroes(cc,q);
        Set aaa = new Set(cc);
        return aaa;

    }
    public bool Incluye(Set a){
        foreach (int elemento in a.elements_of_set)
        {
            if(!(this.elements_of_set.Contains(elemento)))
            {
                return false;
            }
        }
        return true;
    }
    public int Cardinal(){
        return this.elements_of_set.Length;
    }
    public static int[] fix_zeroes(int[] a, bool add_zero){
        a = a.Where(c => !(c==0)).ToArray();
        if(add_zero){
        int[] answer = new int[a.Length+1];
        for (int i = 0; i < a.Length; i++)
        {
            answer[i] = a[i];
        }

        answer[a.Length] = 0; a = answer;}
        return a;
    }

    public static Set Intersection(Set a, Set b)
    {
        bool c = a.belongss(0) && b.belongss(0);
        int[] answer = new int[a.Cardinal()];
        for (int i = 0; i < a.Cardinal(); i++)
        {
            if(b.elements_of_set.Contains(a.elements_of_set[i])){
                answer[i] = a.elements_of_set[i];
            }
        }
        answer = remove_repeated(answer);
        answer = fix_zeroes(answer, c);
        Set ca = new Set(answer);
        return ca;
        

    }
    public static int[] remove_repeated(int[] a) 
    // given an int[] return another int without repeated elements
    // and if int[] contains 0, return it at the last position.
    {
        bool b = a.Contains(0);
        int[] answer = new int[a.Length];
        for (int i = 0; i < a.Length; i++)
        {
            if(!(answer.Contains(a[i]))){answer[i] = a[i];}
        }
        answer = fix_zeroes(answer,b);
        return answer;
    }
    public int[] elements_of_set;
    public Set(int[] a){
        elements_of_set = Set.remove_repeated(a);
    }
    public bool belongss(int x){
        if (this.elements_of_set.Contains(x)){return true;}
        return false;
    }
    public static Set Union(Set c, Set d){
        Set Unionn(int[] a, int[] b){
        int[] result = new int[a.Length + b.Length];
        for (int i = 0; i < a.Length; i++)
        {
            result[i] = a[i];
        }
        for (int i = a.Length; i < a.Length + b.Length; i++)
        {
            result[i] = b[i-a.Length];
        } 
        return new Set(Set.remove_repeated(result));
    }
    return Unionn(c.elements_of_set, d.elements_of_set);
    }

}
public class Program{
    public static void Main(){
        int[] a = new int[5] {1,1,3,0,4};
        Set b = new Set(a);
        int[] c = new int[4] {1,2,3,0};
        Set d = new Set(c);
        Console.WriteLine(b.Incluye(d));
        Set union = Set.Union(b,d);
        Set inter = Set.Intersection(b,d);
        Set diff = Set.Difference(b,d);
        foreach (var item in union.elements_of_set)
        {
            Console.Write(item + " ");
        }
        Console.WriteLine("POTASIO");
        foreach (var item in inter.elements_of_set)
        {
            Console.Write(item + " ");
        }        
        Console.WriteLine("POTASIO");
        foreach (var item in diff.elements_of_set)
        {
            Console.Write(item + " ");
        }                
    }
}