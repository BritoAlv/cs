public class Porgram{
    public static void Main(){
    int n1 = 10;
    int[] i1 = { 0, 0, 3 };
    int[] d1 = { 5, 5, 3 };
    int[] regalos1 = EjecutaInstrucciones(n1, i1, d1);
    foreach (var item in regalos1)
    {
        Console.Write(item + " ");
    }
    }
    public static int[] EjecutaInstrucciones(int n, int[] i, int[] d){
        int[] get_circular_array(int a, int b){
            int[] result = new int[1] {1};
            if (a == b){result = new int[1] {a};}
            else if (a > b)
            {
            result = new int[n-a+b+1];
            for (int k = a; k < n ; k++)
            {
                result[k-a] = k;
            }
            for (int k = 0; k <= b; k++)
            {
                result[n-a+k] = k;
            }
            }
            else if (a < b){
                result = new int[b-a+1];
                for (int l = a; l < result.Length; l++)
                {
                    result[l-a] = l;
                }
            }
            return result;
            
        }

        int[] pos_gifts = new int[n];
        for (int m = 0; m < n; m++)
        {
            pos_gifts[m] = m+1;
        }
        for (int l = 0; l < i.Length; l++)
        {
            int[] exchange = get_circular_array(i[l], d[l]);
            gifts_exchange(exchange);
        }
        void gifts_exchange(int[] a){
            int i = 0;
            int j = a.Length-1;
            while(i<j)
            {
               int temp = pos_gifts[a[i]];
               pos_gifts[a[i]] = pos_gifts[a[j]];
               pos_gifts[a[j]] = temp; 
               i = i+1;
               j = j-1;
            }
        }
        return pos_gifts;
    }   
}