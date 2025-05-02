internal class Program
{
    private static void Main(string[] args)
    {
        var positive = (List<int> array) =>
        {
            int countt = 0;
            for (int i = 0; i < array.Count; ++i)
            {
                if (array[i] < 0)
                {
                    array[i] = -1;
                    ++countt;
                }
            }
            List<int> result = new List<int>();
            for (int i = 0; i < array.Count; ++i)
            {
                if (array[i] != -1)
                {
                    result.Add(array[i]);
                }
            }
            return result;
        };

        var even = (List<int> array) =>
        {
            for (int i = 0; i < array.Count; ++i)
            {
                if(array[i] > 0)
                {
                    if (array[i] % 2 == 1)
                    {
                        array[i] = 1;
                    }
                }
                else
                {
                    if (array[i] % -2 == -1)
                    {
                        array[i] = 1;
                    }
                }
            }
            List<int> result = new List<int>();
            for (int i = 0; i < array.Count; ++i)
            {
                if (array[i] != 1)
                {
                    result.Add(array[i]);
                }
            }
            return result;
        };
        List<int> array = new List<int>() { 1 , -5, -23, 5, 312, 1};
        Console.WriteLine("Default list: ");
        printArray(array);
        //array = positive(array);
        array = even(array);
        Console.WriteLine("Updated list: ");
        printArray(array);

    }
    static void printArray(List<int> array)
    {
        
        for(int i = 0; i<array.Count; ++i)
        {
            Console.WriteLine(array[i]);
        }
    }
    
    
    
}
