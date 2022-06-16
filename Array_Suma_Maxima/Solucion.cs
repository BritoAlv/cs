namespace Weboo.Examen
{
    public static class Solucion
    {
        public static int[] SubarrayDeSumaMaxima(int[] numeros)
        {
 /* define a function that given an array and two index start and end
 return the array that starts at position i and ends at j.
 */
 int[] return_array(int start, int end, int[] a){
     int[] answer = new int[end-start+1];
     for (int i = start; i <= end; i++)
     {
         answer[i-start] = a[i];
     }
     return answer;
 }
 /* define a function that return sum of elements in an array
 starting at position i, ending in position j. (including it).
 */ 
    int sum_array(int start, int end, int[] a){
        int sum = 0;
        for (int i = start; i <= end; i++)
        {
            sum = sum + a[i];
        }
        return sum;
    }
    int starting = 0;
    int ending = numeros.Length-1;
    int answer = sum_array(0, numeros.Length-1, numeros);
    for (int i = 0; i < numeros.Length; i++)
    {
        for (int j = i; j < numeros.Length; j++)
        {
            int temp = sum_array(i,j, numeros);
            if(temp > answer){
                answer = temp;
                starting = i;
                ending = j;
            }
        }
    }
    return return_array(starting, ending, numeros);
        }
    }
}
