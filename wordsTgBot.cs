using System;
using System.Collections.Generic;
using System.Diagnostics.Eventing.Reader;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using Telegram.Bot;
using Telegram.Bot.Polling;
using Telegram.Bot.Types;
using Telegram.Bot.Types.Enums;
using Telegram.Bot.Types.ReplyMarkups;

namespace TelegammBotCore
{

    internal class BotCore
    {
        User me;
        TelegramBotClient bot;
        public BotCore(TelegramBotClient b)
        {
            bot = b;
            me = bot.GetMe().Result;
            bot.DeleteWebhook();          // you may comment this line if you find it unnecessary
            bot.DropPendingUpdates();

            bot.OnError += OnError;
            bot.OnMessage += OnMessage;
            bot.OnUpdate += OnUpdate;

        }
        public void Start(CancellationTokenSource cts)
        {
            Console.WriteLine($"@{me.Username} is running... Press Escape to terminate");
            while (Console.ReadKey(true).Key != ConsoleKey.Escape) ;
            cts.Cancel(); // stop the bot            
        }

        List<string> usedWords = new List<string>();
        List<string> words = new List<string>();
        bool addWordCheck = false;
        bool inGameCheck = false;
        int haveWord = -1;
        int currentWord = -1;
        bool losecheck = false;
        bool bott = false;
        string lastWord = "No game detected";

        async Task OnMessage(Message msg, UpdateType type)
        {
            if(msg.Text == "/end")
            {
                bot.SendMessage(msg.Chat, "Вы проиграли!!!", parseMode: ParseMode.Html, linkPreviewOptions: true, replyMarkup: new ReplyKeyboardRemove());
                usedWords.Clear();
                words.Clear();
                addWordCheck = false;
                inGameCheck = false;
                haveWord = -1;
                currentWord = -1;
            }
            if (inGameCheck)
                wordGame(msg);

            if (addWordCheck)
            {
                words.Add(msg.Text);
                haveWord++;
                await bot.SendMessage(msg.Chat, $"<b><u>Слово {msg.Text} было добавлено</u></b>", parseMode: ParseMode.Html, linkPreviewOptions: true, replyMarkup: new ReplyKeyboardRemove());

                string listWord = "В данный момент есть слова: ";
                for(int i = 0; i<words.Count; ++i)
                {
                    listWord += $" | {words[i]} | ";
                }
                await bot.SendMessage(msg.Chat, $"{listWord}");
                addWordCheck = false;
            }

            if (msg.Text is not { } text)
                Console.WriteLine($"Received a message of type {msg.Type}");
            else if (text.StartsWith('/'))
            {
                var space = text.IndexOf(' ');
                if (space < 0) space = text.Length;
                var command = text[..space].ToLower();
                if (command.LastIndexOf('@') is > 0 and int at) // it's a targeted command
                    if (command[(at + 1)..].Equals(me.Username, StringComparison.OrdinalIgnoreCase))
                        command = command[..at];
                    else
                        return; // command was not targeted at me
                await OnCommand(command, text[space..].TrimStart(), msg);
            }
            else
                await OnTextMessage(msg);
        }
        async Task OnError(Exception exception, HandleErrorSource source)
        {
            Console.WriteLine(exception);
        }
        async Task OnUpdate(Update update)
        {

            Console.WriteLine($"Received unhandled update {update.Type}"); 
        }

        async void wordGame(Message msg)
        {
            
            

            Random rand = new Random();
            bool niceCheckWord = false;
            char lastSymb;
            char firstSymb;
            int queue = 0;
            List<string> activeWord = new List<string>();
            int iterCol = 0;
            bool realityCheck = false;

            


            if (msg.Text != "/game")
            {
                for (int i = 0; i < words.Count; ++i)
                {
                    if (msg.Text == words[i])
                    {
                        realityCheck = false;
                        break;
                    }
                    else
                    {
                        realityCheck = true;
                    }
                   
                }
                usedWords.Add(msg.Text);
                ++currentWord;
            }
            if(realityCheck)
            {
                await bot.SendMessage(msg.Chat, "Вы проиграли!!! Назвали не то слово", parseMode: ParseMode.Html, linkPreviewOptions: true, replyMarkup: new ReplyKeyboardRemove());
                bott = true;
                lastWord = usedWords[usedWords.Count - 2];
                usedWords.Clear();
                words.Clear();
                addWordCheck = false;
                inGameCheck = false;
                haveWord = -1;
                currentWord = -1;
                losecheck = true;
            }
            if (currentWord > 0 && !losecheck)
            {
                string wordList = "Были названы слова: ";
                for(int i = 0; i<usedWords.Count; ++i)
                    wordList += $"{usedWords[i]} | ";
                await bot.SendMessage(msg.Chat, $"{wordList}");
                lastSymb = usedWords[usedWords.Count-2][usedWords[usedWords.Count-2].Length-1];

                
                firstSymb = usedWords[usedWords.Count - 1][0];


                if (lastSymb != firstSymb)
                {
                    await bot.SendMessage(msg.Chat, " <b><u>Вы проиграли! Было названо слово, которое начинается не с той буквы, которой закончилось предыдущие. Прочитайте правила командой /? и возвращайтесь!!</u></b>", parseMode: ParseMode.Html, linkPreviewOptions: true, replyMarkup: new ReplyKeyboardRemove());
                    bott = true;
                    lastWord = usedWords[usedWords.Count - 2];
                    usedWords.Clear();
                    words.Clear();
                    addWordCheck = false;
                    inGameCheck = false;
                    haveWord = -1;
                    currentWord = -1;
                    losecheck = true;
                }
                if (!losecheck)
                {
                    bool checkActiveWord = false;

                    for (int i = 0; i < words.Count; ++i)
                    {
                        if (lastSymb == words[i][0])
                        {
                            activeWord.Add(words[i]);
                            checkActiveWord = true;
                        }
                    }
                    if (checkActiveWord)
                    {
                        string listActive = "Список возможных слов для ответа бота: ";

                        for (int i = 0; i < activeWord.Count; ++i)
                        {
                            listActive += $" | {activeWord[i]} | ";
                        }
                        await bot.SendMessage(msg.Chat, $"{listActive}");
                    }
                    else
                    {
                        await bot.SendMessage(msg.Chat, $"Нету вариантов ответить, вы победили!!", parseMode: ParseMode.Html, linkPreviewOptions: true, replyMarkup: new ReplyKeyboardRemove());
                        bott = false;
                        lastWord = usedWords[usedWords.Count - 1];
                        usedWords.Clear();
                        words.Clear();
                        addWordCheck = false;
                        inGameCheck = false;
                        haveWord = -1;
                        currentWord = -1;
                        losecheck = true;
                    }
                }
                if (!losecheck)
                {
                    for (int i = 0; i < usedWords.Count; ++i)
                    {
                        queue = rand.Next(activeWord.Count);
                        if (activeWord[queue] == usedWords[i])
                        {
                            i = 0;
                            queue = rand.Next(activeWord.Count);
                            iterCol++;
                            if (iterCol >= activeWord.Count)
                            {
                                await bot.SendMessage(msg.Chat, "Вы победили!!! ", parseMode: ParseMode.Html, linkPreviewOptions: true, replyMarkup: new ReplyKeyboardRemove());
                                lastWord = usedWords[usedWords.Count - 1];
                                bott = false;
                                usedWords.Clear();
                                words.Clear();
                                addWordCheck = false;
                                inGameCheck = false;
                                haveWord = -1;
                                currentWord = -1;
                                losecheck = true;
                                break;
                            }
                        }

                    }

                    usedWords.Add(activeWord[queue]);
                    

                }
            }
            else
            {
                queue = rand.Next(words.Count);
                usedWords.Add(words[queue]);
                await bot.SendMessage(msg.Chat, $"Первое слово выпало");
            }

            if (!losecheck)
            {
                currentWord++;

                await bot.SendMessage(msg.Chat, $"Бот называет слово: {usedWords[currentWord]}");
            }
            else
                losecheck = false;
        }

        async Task OnCommand(string command, string args, Message msg)
        {
            Console.WriteLine($"Received command: {command} {args}");
            switch (command)
            {
                case "/start":
                    await bot.SendMessage(msg.Chat, """
                <b><u>Bot menu</u></b>:
                
                /?              - game rules
                /game           - go game!!
                /add            - add word in list
                /end            - you can lose game
                /best           - best player in last match
                """, parseMode: ParseMode.Html, linkPreviewOptions: true,
                        replyMarkup: new ReplyKeyboardRemove()); // also remove keyboard to clean-up things
                    break;
                case "/?":
                    await bot.SendMessage(msg.Chat, " <b><u>Правила: игроки по очереди называют слова. Игрок называет слово, которое\r\nначинается на букву которой закончилось слово предыдущего игрока. Выигрывает\r\nтот, кто называет последнее слово из Словаря.\r\n</u></b> ", parseMode: ParseMode.Html, linkPreviewOptions: true,
                        replyMarkup: new ReplyKeyboardRemove());
                    break;
                case "/add":
                    await bot.SendMessage(msg.Chat, " <b><u>Введите слово, которое хотите добавить: </u></b> ", parseMode: ParseMode.Html, linkPreviewOptions: true, replyMarkup: new ReplyKeyboardRemove());
                    addWordCheck = true;
                    break;
                case "/game":
                    if(words.Count==0)
                    {
                        await bot.SendMessage(msg.Chat, " <b><u>Вы не добавили слова!!!</u></b>", parseMode: ParseMode.Html, linkPreviewOptions: true, replyMarkup: new ReplyKeyboardRemove());
                    }
                    else {
                        await bot.SendMessage(msg.Chat, " <b><u>Удачной игры!!!</u></b>", parseMode: ParseMode.Html, linkPreviewOptions: true, replyMarkup: new ReplyKeyboardRemove());
                        inGameCheck = true;
                        wordGame(msg);
                    }
                    break;
                case "/best":
                    if (lastWord != "No game detected")
                    {
                        if(bott)
                            await bot.SendMessage(msg.Chat, $" <b><u>Лучший игрок в последней игре - бот. Его слово - {lastWord} </u></b>", parseMode: ParseMode.Html, linkPreviewOptions: true, replyMarkup: new ReplyKeyboardRemove());
                        else
                            await bot.SendMessage(msg.Chat, $" <b><u>Лучший игрок в последней игре - игрок. Его слово - {lastWord} </u></b>", parseMode: ParseMode.Html, linkPreviewOptions: true, replyMarkup: new ReplyKeyboardRemove());

                    }
                    else
                    {
                        await bot.SendMessage(msg.Chat, $" <b><u> {lastWord} </u></b>", parseMode: ParseMode.Html, linkPreviewOptions: true, replyMarkup: new ReplyKeyboardRemove());
                    }
                    break;

            }
        }

        async Task OnTextMessage(Message msg) // received a text message that is not a command
        {
            Console.WriteLine($"Received text '{msg.Text}' in {msg.Chat}");
        }
    }
}
