using System.Net;
using System.Drawing;
using System.Drawing.Imaging;
using System.Windows.Forms;

internal class Program
{
    private static void Main(string[] args)
    {
        //List<string> urls = setLink();
        Console.WriteLine("Do you want to convert an image to an icon?\nYes/No");
        bool iconCheck = false;
        string temp = Console.ReadLine();
        if(temp == "Yes")
            iconCheck = true;
        else
            iconCheck = false;

        List<string> urls = new List<string>();
        urls.Add("https://sun9-41.userapi.com/impg/HT0Rf_8xqdfbkkct9Wp_s0kFWm0diyvn_YFcKw/Sb0prNfMwwU.jpg?size=850x1519&quality=95&sign=d00708327383aff82c2119b59b560241&type=album");
        urls.Add("https://sun9-33.userapi.com/impg/cBNDkoRg8lOUWPYRpga8iE4NXPc_j1TMXy_L4A/DYFB10V1aCs.jpg?size=527x1200&quality=95&sign=1642997e1ab77a05dd2c5e94938b7905&type=album");
        
        string dir = @"C:\Downloads";
        List<string> names = new List<string>();
        List<Thread> threads = new List<Thread>();
        for(int i = 0; i<urls.Count; ++i)
        {
            string url = urls[i];
            threads.Add(new Thread(() => downloadImage(dir, url)));
        }

        for (int i = 0; i < threads.Count; i++)
        {
            threads[i].Start();
        }
        for (int i = 0; i < threads.Count; i++)
        {
            threads[i].Join();
        }
        if (iconCheck)
        {
            for (int i = 0; i < urls.Count; ++i)
            {
                string url = urls[i];
                threads[i] = new Thread(() => usingImage(dir, url));
            }

            for (int i = 0; i < threads.Count; i++)
            {
                threads[i].Start();
            }
            for (int i = 0; i < threads.Count; ++i)
            {
                threads[i].Join();
            }
        }
        Console.WriteLine("Program so closed");
        
    }

    private static List<string> setLink()
    {
        string temp = "";
        List<string> urls = new List<string>();
        do
        {
            Console.Clear();
            Console.WriteLine("Input Image link...\nIf thats all, input a word <<stop>>");
            Console.Write("Current link: ");
            for(int i = 0; i<urls.Count; ++i)
            {
                Console.WriteLine(urls[i]);
            }
            temp = Console.ReadLine();

            if (temp == "stop" || temp == "Stop")
                break;
            else
                urls.Add(temp);

        } while (true);
        return urls;
    }
    public static void usingImage(string dir, string url)
    {
        Image image = Image.FromFile(dir + @$"\{Path.GetFileName(new Uri(url).LocalPath)}");
        Console.WriteLine($"Original size: {image.Width}*{image.Height}");
        int newWidth = 64;
        int newHeight = 64;
        using (Bitmap resizingImage = new Bitmap(newWidth, newHeight))
        {
            using (Graphics g = Graphics.FromImage(resizingImage))
            {
                g.InterpolationMode = System.Drawing.Drawing2D.InterpolationMode.HighQualityBicubic;
                g.DrawImage(image, 0, 0, newWidth, newHeight);

                resizingImage.Save(@"C:\\Downloads\Icon_" + Path.GetFileName(new Uri(url).LocalPath), ImageFormat.Png);
                Console.WriteLine("Image saved in Icon_" + Path.GetFileName(new Uri(url).LocalPath), ImageFormat.Png);
            }
        }
    }
    public static void downloadImage(string dir, string url)
    {
        String fileName = Path.GetFileName(new Uri(url).LocalPath);
        String savePath = Path.Combine(dir, fileName);

        Console.WriteLine($"Downloading file {fileName}");

        using (WebClient client = new WebClient())
        {
            client.DownloadFile(url, savePath);
        }
        Console.WriteLine("Downloading complete");
    }
}
