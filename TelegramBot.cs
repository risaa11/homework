using System;
using System.Collections.Generic;
using System.Linq;
using System.Reflection.Metadata.Ecma335;
using System.Runtime.CompilerServices;
using System.Security.Cryptography;
using System.Text;
using System.Text.Json.Serialization.Metadata;
using System.Threading.Tasks;
using Microsoft.VisualBasic;
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
           // bot.DeleteWebhook();          // you may comment this line if you find it unnecessary
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

        class Userrrr
        {
            public bool GameCheck = false;
            public int[] array = new int[12];
            public int[] dealerArray = new int[12];
            public int countt = 0;
            public int dealerCount = 0;
            public int checkCard = 0;
            public bool DeallerMode = false;
            public bool FirstDeallerCheck = true;
            public int DeallerScore = 0;
            public bool DeallerStay = false;
            public int score = 0;
            public bool stopGame = false;
            public bool idc = true;
            public CallbackQuery c = new CallbackQuery();
            public List<int> CardList = new List<int>();
            public List<int> SuitList = new List<int>();
            public List<int> dealerCardList = new List<int>();
            public List<int> dealerSuitList = new List<int>();
        }
         
         Message msgg = new Message();
        List<Userrrr> SelectUser = new List<Userrrr>();
        List<Message> UsersEveryTime = new List<Message>();

        int UsersCount = 0;
        int EveryTimeUser = -1;
        bool CreateUser = true;
        
        async Task OnMessage(Message msg, UpdateType type)
        {
            
            //await bot.SendMessage(msg.Chat, $"Проверка на присутствие на сервере.");
            for (int i = 0; i<UsersEveryTime.Count; ++i)
            {
                if (msg.Chat.Id == UsersEveryTime[i].Chat.Id)
                {
                   // await bot.SendMessage(msg.Chat, $"Ты уже есть на сервере.");
                    EveryTimeUser = i;
                    CreateUser = false;
                    UsersEveryTime[EveryTimeUser] = msg;
                    break;
                }
                else
                    CreateUser = true;
            }
            if(CreateUser)
            {
                await bot.SendMessage(msg.Chat, $"Регистрация на сервере. Твой Username - {msg.Chat.Username}");
                Userrrr r = new Userrrr();
                UsersEveryTime.Add(msg);
                SelectUser.Add(r);
                EveryTimeUser++;
                UsersCount++;
            }
            // await bot.SendMessage(msg.Chat, $"Теперь ты на сервере. Всего людей на сервере - {UsersCount}. Твой ID - {UsersEveryTime[EveryTimeUser].Chat.Id}");
            // await bot.SendMessage(msg.Chat, $"Текущий юзер - {EveryTimeUser} {UsersEveryTime[EveryTimeUser].Chat.Username}. Твой ID - {UsersEveryTime[EveryTimeUser].Chat.Id}");
            //  UserList();
            SelectUser[EveryTimeUser].c.Data = "";
            if (UsersEveryTime[EveryTimeUser].Text == "/black")
            {
                var inlineMarkup5 = new InlineKeyboardMarkup()
                            .AddButton("Взять карту", "Взять карту");
                await bot.SendMessage(UsersEveryTime[EveryTimeUser].Chat, "<b><u>Black menu</u></b>:", parseMode: ParseMode.Html, linkPreviewOptions: true,
                           replyMarkup: new ReplyKeyboardRemove());
                await bot.SendMessage(UsersEveryTime[EveryTimeUser].Chat, $"Hello, this is my BlackJack\nНажмите на кнопку <<Взять карту>> ", replyMarkup: inlineMarkup5);
                if (SelectUser[EveryTimeUser].FirstDeallerCheck)
                {
                    Random Card = new Random();
                    int tempDeal = Card.Next(1, 14);
                    SelectUser[EveryTimeUser].dealerArray[SelectUser[EveryTimeUser].dealerCount] = tempDeal;
                    SelectUser[EveryTimeUser].DeallerScore += SelectUser[EveryTimeUser].dealerArray[SelectUser[EveryTimeUser].dealerCount];
                    SelectUser[EveryTimeUser].dealerCardList.Add(tempDeal); 
                    tempDeal = Card.Next(1, 4);
                    SelectUser[EveryTimeUser].dealerSuitList.Add(tempDeal);
                    SelectUser[EveryTimeUser].dealerCount++;
                }

                SelectUser[EveryTimeUser].FirstDeallerCheck = false;
                SelectUser[EveryTimeUser].GameCheck = true;
            }
            if (SelectUser[EveryTimeUser].GameCheck)
                BlackJack();
            if (UsersEveryTime[EveryTimeUser].Text is not { } text)
                Console.WriteLine($"Received a message of type {UsersEveryTime[EveryTimeUser].Type}");
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
                await OnCommand(command, text[space..].TrimStart(), UsersEveryTime[EveryTimeUser]);
            }
            else
                await OnTextMessage(UsersEveryTime[EveryTimeUser]);
        }

        async void UserList()
        {
            string userList = "Люди на сервере: ";
            for(int i = 0; i<UsersEveryTime.Count; ++i)
            {
                userList += $" {UsersEveryTime[i].Chat.Username},";
            }
            await bot.SendMessage(UsersEveryTime[EveryTimeUser].Chat, $"{userList}");
        }
        async Task BlackJack()
        {
            if (SelectUser[EveryTimeUser].c.Data == "Оставить текущие карты")
                SelectUser[EveryTimeUser].DeallerMode = true;
            if (SelectUser[EveryTimeUser].c.Data == "stop")
                SelectUser[EveryTimeUser].stopGame = true;
            if(SelectUser[EveryTimeUser].DeallerMode)
            {
                do
                {
                    await bot.SendMessage(UsersEveryTime[EveryTimeUser].Chat, "<b><u>Black Dealer menu</u></b>:", parseMode: ParseMode.Html, linkPreviewOptions: true,
                           replyMarkup: new ReplyKeyboardRemove());
                    await bot.SendMessage(UsersEveryTime[EveryTimeUser].Chat, $"Dealer open next card");
                    Random Card = new Random();
                    int tempDeal = Card.Next(1, 14);
                    SelectUser[EveryTimeUser].dealerArray[SelectUser[EveryTimeUser].dealerCount] = tempDeal;
                    SelectUser[EveryTimeUser].DeallerScore += SelectUser[EveryTimeUser].dealerArray[SelectUser[EveryTimeUser].dealerCount];
                    SelectUser[EveryTimeUser].dealerCardList.Add(tempDeal);
                    tempDeal = Card.Next(1, 4);
                    SelectUser[EveryTimeUser].dealerSuitList.Add(tempDeal);
                    SelectUser[EveryTimeUser].dealerCount++;

                    string DealerCardstr = DefaultDeal();
                    var inlineMarkup3 = new InlineKeyboardMarkup()
                    .AddNewRow($"Dealer score = {SelectUser[EveryTimeUser].DeallerScore}")
                    .AddNewRow($"Your score = {SelectUser[EveryTimeUser].checkCard}")
                    .AddNewRow($"{DealerCardstr}");



                    await bot.SendMessage(UsersEveryTime[EveryTimeUser].Chat, "DealerScore: ", parseMode: ParseMode.Html, replyMarkup: inlineMarkup3);
                    if (SelectUser[EveryTimeUser].DeallerScore > 21)
                    {
                        await bot.SendMessage(UsersEveryTime[EveryTimeUser].Chat, "YOU WIN!!!!! ", parseMode: ParseMode.Html, replyMarkup: inlineMarkup3);
                        SelectUser[EveryTimeUser].stopGame = true;
                    }
                    else if(SelectUser[EveryTimeUser].DeallerScore > 16)
                    {
                        SelectUser[EveryTimeUser].DeallerStay = true;
                        if(SelectUser[EveryTimeUser].checkCard > SelectUser[EveryTimeUser].DeallerScore)
                        {
                            await bot.SendMessage(UsersEveryTime[EveryTimeUser].Chat, "YOU WIN!!!!! ");
                            SelectUser[EveryTimeUser].stopGame = true;
                        }    
                        else
                        {
                            await bot.SendMessage(UsersEveryTime[EveryTimeUser].Chat, "YOU ARE SO NOOB)0)!!!!!, DEALLER WIN!!! ");
                            SelectUser[EveryTimeUser].stopGame = true;
                        }
                    }
                    Thread.Sleep(1000);
                } while (SelectUser[EveryTimeUser].DeallerScore <= 21 && !SelectUser[EveryTimeUser].DeallerStay);

            }
            if (UsersEveryTime[EveryTimeUser].Text == "Взять карту" || SelectUser[EveryTimeUser].c.Data == "Взять карту")
            {
                
                await bot.SendMessage(UsersEveryTime[EveryTimeUser].Chat, $"Идет раздача карт");

                string setCard = razdacha();

                SelectUser[EveryTimeUser].checkCard += SelectUser[EveryTimeUser].array[SelectUser[EveryTimeUser].countt];
                
                string Poluchenie = $"<b><u>Bot menu</u></b>: ";

                string myCard = FullCard();


                var inlineMarkup2 = new InlineKeyboardMarkup()
                .AddNewRow(setCard)
                .AddNewRow($"{myCard}")
                .AddNewRow($"Кол-во карт:   {SelectUser[EveryTimeUser].countt + 1}")
                .AddNewRow($"Счет:   {SelectUser[EveryTimeUser].checkCard}")
                .AddButton("Взять карту   ", "Взять карту")
                .AddButton("Пас   ", "Оставить текущие карты")
                .AddButton("Выйти   ", "stop");

                for (int i = 0; i<= SelectUser[EveryTimeUser].countt; ++i)
                {
                    Poluchenie += $"|{SelectUser[EveryTimeUser].array[i]}|";
                }
                await bot.SendMessage(UsersEveryTime[EveryTimeUser].Chat, "<b><u>Black menu</u></b>:", parseMode: ParseMode.Html, linkPreviewOptions: true,
                        replyMarkup: new ReplyKeyboardRemove());
                await bot.SendMessage(UsersEveryTime[EveryTimeUser].Chat, "Справка: ", parseMode: ParseMode.Html, replyMarkup: inlineMarkup2);
                
                await bot.SendMessage(UsersEveryTime[EveryTimeUser].Chat, "<b><u>Black Dealer menu</u></b>:", parseMode: ParseMode.Html, linkPreviewOptions: true,
                        replyMarkup: new ReplyKeyboardRemove());
                string dealerCard = DefaultDeal();
                var inlineMarkup3 = new InlineKeyboardMarkup()
                .AddNewRow($"Dealer score = {SelectUser[EveryTimeUser].DeallerScore}")
                .AddNewRow($"{dealerCard}");

                await bot.SendMessage(UsersEveryTime[EveryTimeUser].Chat, "DealerScore: ", parseMode: ParseMode.Html, replyMarkup: inlineMarkup3);
                ++SelectUser[EveryTimeUser].countt;

                }
                if(SelectUser[EveryTimeUser].checkCard >21 || SelectUser[EveryTimeUser].stopGame)
                {
                    
                    var inlineMarkup4 = new InlineKeyboardMarkup()
                            .AddButton("Начать новую игру", "/black");
                    await bot.SendMessage(UsersEveryTime[EveryTimeUser].Chat, "<b><u>Black menu</u></b>:", parseMode: ParseMode.Html, linkPreviewOptions: true,
                               replyMarkup: new ReplyKeyboardRemove());
                    await bot.SendMessage(UsersEveryTime[EveryTimeUser].Chat, $"Game over. you lose. try again?", replyMarkup: inlineMarkup4);

                SelectUser[EveryTimeUser].GameCheck = false;
                SelectUser[EveryTimeUser].countt = 0;
                SelectUser[EveryTimeUser].dealerCount = 0;
                SelectUser[EveryTimeUser].checkCard = 0;
                SelectUser[EveryTimeUser].DeallerMode = false;
                SelectUser[EveryTimeUser].FirstDeallerCheck = true;
                SelectUser[EveryTimeUser].DeallerScore = 0;
                SelectUser[EveryTimeUser].DeallerStay = false;
                SelectUser[EveryTimeUser].score = 0;
                SelectUser[EveryTimeUser].CardList.Clear();
                SelectUser[EveryTimeUser].SuitList.Clear();
                for (int i = 0; i<12; ++i)
                    {
                    SelectUser[EveryTimeUser].array[i] = 0;
                    SelectUser[EveryTimeUser].dealerArray[i] = 0;
                    }
                SelectUser[EveryTimeUser].stopGame = false;

            }
        }


        string razdacha()
        {
            Thread.Sleep(1000);
            Random Card = new Random();
            bool cardCheck = false;
            int tempSuit = 0;
            int tempCard = 0;
            string setCard = "Новая карта ";
            do
            {
                cardCheck = false;
                tempCard = Card.Next(1, 14);
                SelectUser[EveryTimeUser].array[SelectUser[EveryTimeUser].countt] = tempCard;
                tempSuit = Card.Next(1, 4);
                for (int i = 0; i < SelectUser[EveryTimeUser].SuitList.Count; ++i)
                {
                    if (SelectUser[EveryTimeUser].array[SelectUser[EveryTimeUser].countt] == SelectUser[EveryTimeUser].CardList[i] && tempSuit == SelectUser[EveryTimeUser].SuitList[i])
                    {
                        cardCheck = true;
                        break;
                    }
                }
            } while (cardCheck);

            if (SelectUser[EveryTimeUser].checkCard == 1 && SelectUser[EveryTimeUser].checkCard + 11 <= 21)
                SelectUser[EveryTimeUser].array[SelectUser[EveryTimeUser].countt] += 11;
            SelectUser[EveryTimeUser].CardList.Add(SelectUser[EveryTimeUser].array[SelectUser[EveryTimeUser].countt]);
            SelectUser[EveryTimeUser].SuitList.Add(tempSuit);
            switch (SelectUser[EveryTimeUser].array[SelectUser[EveryTimeUser].countt])
            {
                case 11:
                    setCard += "| V";
                    SelectUser[EveryTimeUser].array[SelectUser[EveryTimeUser].countt] = 10;
                    break;
                case 12:
                    setCard += "| D";
                    SelectUser[EveryTimeUser].array[SelectUser[EveryTimeUser].countt] = 10;
                    break;
                case 13:
                    setCard += "| K";
                    SelectUser[EveryTimeUser].array[SelectUser[EveryTimeUser].countt] = 10;
                    break;
                case 1:
                    setCard += "| A";
                    break;
                default:
                    setCard += $"| {SelectUser[EveryTimeUser].array[SelectUser[EveryTimeUser].countt]}";
                    break;
            }
            switch (tempSuit)
            {
                case 1:
                    setCard += "♦️ |";
                    break;
                case 2:
                    setCard += "♥️ |";
                    break;
                case 3:
                    setCard += "♠️ |";
                    break;
                case 4:
                    setCard += "♣️ |";
                    break;
            }
            return setCard;
        }

        string FullCard()
        {
            
                string setCard = "Карты: ";

                for (int i = 0; i < SelectUser[EveryTimeUser].CardList.Count; ++i)
                {
                    switch (SelectUser[EveryTimeUser].CardList[i])
                    {
                        case 11:
                            setCard += "| V";
                            break;
                        case 12:
                            setCard += "| D";
                            break;
                        case 13:
                            setCard += "| K";
                            break;
                        case 1:
                            setCard += "| A";
                            break;
                        default:
                            setCard += $"| {SelectUser[EveryTimeUser].CardList[i]}";
                            break;
                    }
                    switch (SelectUser[EveryTimeUser].SuitList[i])
                    {
                        case 1:
                            setCard += "♦️ | ";
                            break;
                        case 2:
                            setCard += "♥️ | ";
                            break;
                        case 3:
                            setCard += "♠️ | ";
                            break;
                        case 4:
                            setCard += "♣️ | ";
                            break;
                    }

                }

                return setCard;
            
        }
        async Task OnError(Exception exception, HandleErrorSource source)
        {
            Console.WriteLine(exception);
        }
        async Task OnUpdate(Update update)
        {
            
            switch (update)
            {
                case { CallbackQuery: { } callbackQuery }: await OnCallbackQuery(callbackQuery); break;
                case { PollAnswer: { } pollAnswer }: await OnPollAnswer(pollAnswer); break;
                default: Console.WriteLine($"Received unhandled update {update.Type}"); break;
            };
        }
        
        async Task OnCommand(string command, string args, Message msg)
        {
            Console.WriteLine($"Received command: {command} {args}");
            switch (command)
            {
                case "/start":
                    await bot.SendMessage(msg.Chat, """
                <b><u>Bot menu</u></b>:
                /photo [url]    - send a photo <i>(optionally from an <a href="https://picsum.photos/310/200.jpg">url</a>)</i>
                /inline_buttons - send inline buttons
                /keyboard       - send keyboard buttons
                /remove         - remove keyboard buttons
                /poll           - send a poll
                /reaction       - send a reaction
                /black          - play to blackJack!!!
                """, parseMode: ParseMode.Html, linkPreviewOptions: true,
                        replyMarkup: new ReplyKeyboardRemove()); // also remove keyboard to clean-up things
                    var inlineMarkup2 = new InlineKeyboardMarkup()
                            .AddButton("Играть в блекджек!!", "/black");
                    await bot.SendMessage(msg.Chat, "Ты также можешь поиграть в блекджек!", replyMarkup: inlineMarkup2);
                    break;
                case "/photo":
                    if (args.StartsWith("http"))
                        await bot.SendPhoto(msg.Chat, args, caption: "Source: " + args);
                    else
                    {
                        await bot.SendChatAction(msg.Chat, ChatAction.UploadPhoto);
                        await Task.Delay(2000); // simulate a long task
                        await using var fileStream = new FileStream("bot.gif", FileMode.Open, FileAccess.Read);
                        await bot.SendPhoto(msg.Chat, fileStream, caption: "Read https://telegrambots.github.io/book/");
                    }
                    break;
                case "/inline_buttons":
                    var inlineMarkup = new InlineKeyboardMarkup()
                        .AddNewRow("1.1", "1.2", "1.3")
                        .AddNewRow()
                            .AddButton("WithCallbackData", "CallbackData")
                            .AddButton(InlineKeyboardButton.WithUrl("WithUrl", "https://github.com/TelegramBots/Telegram.Bot"));
                    await bot.SendMessage(msg.Chat, "Inline buttons:", replyMarkup: inlineMarkup);
                    break;
                case "/keyboard":
                    var replyMarkup = new ReplyKeyboardMarkup()
                        .AddNewRow("1.1", "1.2", "1.3")
                        .AddNewRow().AddButton("2.1").AddButton("2.2");
                    await bot.SendMessage(msg.Chat, "Keyboard buttons:", replyMarkup: replyMarkup);
                    break;
                case "/remove":
                    await bot.SendMessage(msg.Chat, "Removing keyboard", replyMarkup: new ReplyKeyboardRemove());
                    break;
                case "/poll":
                    await bot.SendPoll(msg.Chat, "Question", ["Option 0", "Option 1", "Option 2"], isAnonymous: false, allowsMultipleAnswers: true);
                    break;
                case "/reaction":
                    await bot.SetMessageReaction(msg.Chat, msg.Id, ["❤"], false);
                    break;
                case "/users":
                    UserList();
                    break;
            }
        }

        string DefaultDeal()
        {
            string defaultt = $"Карты диллера: ";
            for (int i = 0; i < SelectUser[EveryTimeUser].dealerSuitList.Count; i++)
            {
                switch (SelectUser[EveryTimeUser].dealerArray[i])
                {
                    case 11:
                        defaultt += "| V";
                        SelectUser[EveryTimeUser].dealerCardList[i] = 10;
                        SelectUser[EveryTimeUser].dealerArray[SelectUser[EveryTimeUser].dealerCount] = 10;
                        SelectUser[EveryTimeUser].dealerArray[i] = 10;
                        SelectUser[EveryTimeUser].DeallerScore -= 1;
                        break;
                    case 12:
                        defaultt += "| D";
                        SelectUser[EveryTimeUser].dealerCardList[i] = 10;
                        SelectUser[EveryTimeUser].dealerArray[SelectUser[EveryTimeUser].dealerCount] = 10;
                        SelectUser[EveryTimeUser].dealerArray[i] = 10;
                        SelectUser[EveryTimeUser].DeallerScore -= 2;
                        break;
                    case 13:
                        defaultt += "| K";
                        SelectUser[EveryTimeUser].dealerCardList[i] = 10;
                        SelectUser[EveryTimeUser].dealerArray[SelectUser[EveryTimeUser].dealerCount] = 10;
                        SelectUser[EveryTimeUser].dealerArray[i] = 10;
                        SelectUser[EveryTimeUser].DeallerScore -= 3;
                        break;
                    case 1:
                        defaultt += "| A";
                        if (SelectUser[EveryTimeUser].DeallerScore + 11 <= 21)
                            SelectUser[EveryTimeUser].DeallerScore += 11;
                        break;
                    default:
                        defaultt += $"| {SelectUser[EveryTimeUser].dealerArray[i]}";
                        break;
                }
                switch (SelectUser[EveryTimeUser].dealerSuitList[i])
                {
                    case 1:
                        defaultt += "♦️ |";
                        break;
                    case 2:
                        defaultt += "♥️ |";
                        break;
                    case 3:
                        defaultt += "♠️ |";
                        break;
                    case 4:
                        defaultt += "♣️ |";
                        break;
                }
            }
            return defaultt;
        }
        async Task OnTextMessage(Message msg) // received a text message that is not a command
        {
            
        }
        async Task OnCallbackQuery(CallbackQuery callbackQuery)
        {

            //await bot.SendMessage(msg.Chat, $"Проверка на присутствие на сервере.");
            for (int i = 0; i < UsersEveryTime.Count; ++i)
            {
                if (callbackQuery.Message.Chat.Id == UsersEveryTime[i].Chat.Id)
                {
                    // await bot.SendMessage(msg.Chat, $"Ты уже есть на сервере.");
                    EveryTimeUser = i;
                    CreateUser = false;
                    UsersEveryTime[EveryTimeUser] = callbackQuery.Message;
                    break;
                }
                else
                    CreateUser = true;
            }
            if (CreateUser)
            {
                await bot.SendMessage(callbackQuery.Message.Chat, $"Регистрация на сервере. Твой Username - {callbackQuery.Message.Chat.Username}");
                Userrrr r = new Userrrr();
                UsersEveryTime.Add(callbackQuery.Message);
                SelectUser.Add(r);
                EveryTimeUser++;
                UsersCount++;
            }
            // await bot.SendMessage(msg.Chat, $"Теперь ты на сервере. Всего людей на сервере - {UsersCount}. Твой ID - {UsersEveryTime[EveryTimeUser].Chat.Id}");
            // await bot.SendMessage(msg.Chat, $"Текущий юзер - {EveryTimeUser} {UsersEveryTime[EveryTimeUser].Chat.Username}. Твой ID - {UsersEveryTime[EveryTimeUser].Chat.Id}");
            // UserList();

            SelectUser[EveryTimeUser].c = callbackQuery;
            await bot.AnswerCallbackQuery(callbackQuery.Id, $"You selected {callbackQuery.Data}");

            if (SelectUser[EveryTimeUser].c.Data == "Взять карту" || SelectUser[EveryTimeUser].c.Data == "/black")
                if (UsersEveryTime[EveryTimeUser].Text == "/black" || SelectUser[EveryTimeUser].c.Data == "/black")
                {
                    var inlineMarkup5 = new InlineKeyboardMarkup()
                                .AddButton("Взять карту", "Взять карту");
                    await bot.SendMessage(UsersEveryTime[EveryTimeUser].Chat, "<b><u>Black menu</u></b>:", parseMode: ParseMode.Html, linkPreviewOptions: true,
                               replyMarkup: new ReplyKeyboardRemove());
                    await bot.SendMessage(UsersEveryTime[EveryTimeUser].Chat, $"Hello, this is my BlackJack\nНажмите на кнопку <<Взять карту>> ", replyMarkup: inlineMarkup5);
                    if (SelectUser[EveryTimeUser].FirstDeallerCheck)
                    {
                        Random Card = new Random();
                        int tempDeal = Card.Next(1, 14);
                        SelectUser[EveryTimeUser].dealerArray[SelectUser[EveryTimeUser].dealerCount] = tempDeal;
                        SelectUser[EveryTimeUser].DeallerScore += SelectUser[EveryTimeUser].dealerArray[SelectUser[EveryTimeUser].dealerCount];
                        SelectUser[EveryTimeUser].dealerCardList.Add(tempDeal);
                        tempDeal = Card.Next(1, 4);
                        SelectUser[EveryTimeUser].dealerSuitList.Add(tempDeal);
                        SelectUser[EveryTimeUser].dealerCount++;
                    }

                    SelectUser[EveryTimeUser].FirstDeallerCheck = false;
                    SelectUser[EveryTimeUser].GameCheck = true;
                }
            if (SelectUser[EveryTimeUser].GameCheck)
                BlackJack();

        }
        async Task OnPollAnswer(PollAnswer pollAnswer)
        {
            if (pollAnswer.User != null)
                await bot.SendMessage(pollAnswer.User.Id, $"You voted for option(s) id [{string.Join(',', pollAnswer.OptionIds)}]");
        }
        
    }
}
