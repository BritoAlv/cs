namespace SeminarioConcurrencia;

/*

A monitor is a way of managing the locks, is a static primitive class ie is programmed directly in assembly to use atomic operations.

everything is due to assembly.

*/

public static partial class Program
{
    public static void Main()
    {
        TestCountDown();
    }    
}