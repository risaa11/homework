using System;
using System.Collections.Generic;
using System.Threading;
internal class Program
{
    private static void Main(string[] args)
    {
        Console.OutputEncoding = System.Text.Encoding.UTF8;
        const int size = 10;
        int[] array = new int[size] { 1,3,4,5,8,7,6,5,4,3};
        Console.WriteLine("Изначальный список: ");
        for(int i = 0; i<array.Length; ++i)
        {
            Console.WriteLine(array[i]);
        }
        Thread sort = new Thread(() => Sort(array));
        Thread checker = new Thread(() => Checker(array));
        sort.Start();
        checker.Start();
        Console.WriteLine("Программа завершила работу");
    }
    private static void Sort(int[] array)
    {
        int temp = 0;
        for(int i = 0; i<array.Length; ++i)
        {
            for(int j = i+1; j<array.Length; ++j)
            {
                if (array[i] > array[j])
                {
                    temp = array[i];
                    array[i] = array[j];
                    array[j] = temp;
                    Thread.Sleep(100);
                }
            }
        }
    }

    private static void Checker(int[] array)
    {
        int[] dubl = new int[array.Length];

        for (int i = 0; i < array.Length; ++i)
        {
            dubl[i] = array[i];
        }

        do
        {

            for (int i = 0; i<array.Length; ++i)
            {
                if (array[i] != dubl[i])
                {
                    Console.WriteLine("Список изменился\nНовый список: ");
                    for(int j = 0; j<array.Length; ++j)
                    {
                        Console.WriteLine(array[j]);
                    }
                }
            }
            for (int i = 0; i < array.Length; ++i)
            {
                dubl[i] = array[i];
            }
            Thread.Sleep(50);
        } while (true);
    }
}
