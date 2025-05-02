using System.ComponentModel;

internal class Program
{
    private static void Main(string[] args)
    {
        int[] array = new int[5] { 1, 4, 3, 2, 4 };
        Console.WriteLine("Default list: ");
        printArray(array);

        DoOperation(array, Add);
        Console.WriteLine("Edited list: ");
        printArray(array);
    }
    static void printArray(int[] array)
    {
        for (int i = 0; i < array.Length; i++)
        {
            Console.WriteLine(array[i]);
        }
    }
    static int[] DoOperation(int[] n, Func<int[], int[]> operation) => operation(n);
    static Func<int[], int[]> Add = n =>
    {
        for(int i = 0; i<n.Length; ++i)
        {
            ++n[i];
        }
        return n;
    }; 
}
