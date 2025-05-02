using System;
using System.Threading;

internal class Program
{
    private static void Main(string[] args)
    {
        Console.OutputEncoding = System.Text.Encoding.UTF8;
        Console.WriteLine("Hello, World!");
        string path1 = @"C:\Users\matve\Downloads\ДЗ_30.04.txt";
        string path2 = @"C:\Users\matve\Downloads\ДЗ_28.04.txt";
        string path3 = @"C:\Users\matve\Downloads\ДЗ.txt";
        threadCreate(path1, path2, path3);
    }
    private static void threadCreate(params string[] pathes)
    {

        string[] words = new string[3];
        words[0] = "Написать";
        words[1] = "Решить";
        words[2] = "все";
        List<Thread> threads = new List<Thread>();
        foreach (string path in pathes)
        {
            string currentPath = path;
            threads.Add(new Thread(() => searchWord(currentPath, words)));
        }
        for (int i = 0; i < threads.Count; i++)
        {
            threads[i].Start();
        }
        foreach (var thread in threads)
        {
            thread.Join();
        }
    }
    static void searchWord(string path, string[] words )
    {
        string tempWord = "";
        FileInfo text = new FileInfo(path);
        string[] Text = File.ReadAllLines(text.FullName);
        for (int i = 0; i < Text.Length; i++) {
            for (int j = 0; j < Text[i].Length; j++)
            {
                if (Text[i][j] == ' ')
                {
                    for (int k = 0; k < words.Length; k++)
                    {
                        if (tempWord == words[k])
                        {
                            Console.WriteLine($"Found a word {tempWord}");
                        }
                    }
                        tempWord = "";
                }
                else
                    tempWord += Text[i][j];
            }
        }
    }
    
}
