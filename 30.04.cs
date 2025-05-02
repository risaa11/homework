using System.IO;
using System.Runtime.CompilerServices;
using System.Text;
using static System.Net.Mime.MediaTypeNames;

internal class Program
{
    private static void Main(string[] args)
    {
        Console.OutputEncoding = Encoding.UTF8;
        string path1 = @"C:\Users\matve\Documents\Text1.txt";
        string path2 = @"C:\Users\matve\Documents\Text2.txt";
        string outputPath = @"C:\Users\matve\Documents\OUTPUT.txt";
        FileInfo test1 = new FileInfo(path1);
        FileInfo test2 = new FileInfo(path2);
        string[] arrayText1 = File.ReadAllLines(path1);
        string[] arrayText2 = File.ReadAllLines(path2);
        for (int i = 0; i < arrayText1.Length; i++)
        {
            arrayText1[i] += " - это строка файла Text1.txt";
        }
        for (int i = 0; i < arrayText2.Length; i++)
        {
            arrayText2[i] += " - это строка файла Text2.txt";
        }

        for(int i = 0; i<arrayText2.Length; i++)
        {
            arrayText1[arrayText1.Length - 1] += "\n";
            arrayText1[arrayText1.Length-1] += arrayText2[i];
        }
        File.WriteAllLines(outputPath, arrayText1);
        string[] arrayText3 = File.ReadAllLines(outputPath);
        int countt = 1; 
        for (int i = 0; i < arrayText3.Length; i++)
        {
            for(int j = 0; j < arrayText3[i].Length; j++)
            {
                if(arrayText3[i][j] == ' ' || arrayText3[i][j] == '\n')
                {
                    countt++;
                }
            }
        }
        Console.WriteLine($"В этом файле {countt} слов");
    }
}
