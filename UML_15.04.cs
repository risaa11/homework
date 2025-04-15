using System;
using System.Threading;

    public enum Color
    {
        Red,
        Yellow,
        Green
    }

    public interface ITrafficLightState
    {
        void Handle(TrafficLight trafficLight);
        int Duration { get; }
        Color Color { get; }
    }

    public class RedState : ITrafficLightState
    {
        public void Handle(TrafficLight trafficLight)
        {
            trafficLight.SetState(new YellowState(new GreenState()));
        }

        public int Duration => 5000;
        public Color Color => Color.Red;
    }

    public class GreenState : ITrafficLightState
    {
        public void Handle(TrafficLight trafficLight)
        {
            trafficLight.SetState(new YellowState(new RedState()));
        }

        public int Duration => 10000;
        public Color Color => Color.Green;
    }

    public class YellowState : ITrafficLightState
    {
        private readonly ITrafficLightState _nextState;

        public YellowState(ITrafficLightState nextState)
        {
            _nextState = nextState;
        }

        public void Handle(TrafficLight trafficLight)
        {
            trafficLight.SetState(_nextState);
        }

        public int Duration => 2000;
        public Color Color => Color.Yellow;
    }

    public class TrafficLight
    {
        private ITrafficLightState _currentState;

        public TrafficLight(ITrafficLightState initialState)
        {
            _currentState = initialState;
            Notify();
        }

        public void ChangeState()
        {
            _currentState.Handle(this);
        }

        public void SetState(ITrafficLightState newState)
        {
            _currentState = newState;
            Notify();
        }

        public ITrafficLightState CurrentState => _currentState;

        private void Notify()
        {
            Console.WriteLine($"Текущий цвет светофора: {_currentState.Color}");
            switch (_currentState.Color)
            {
                case Color.Red:
                    Console.WriteLine("Водители: Стоять!");
                    Console.WriteLine("Пешеходы: Идти!");
                    break;
                case Color.Yellow:
                    Console.WriteLine("Водители: Приготовиться!");
                    Console.WriteLine("Пешеходы: Ждать!");
                    break;
                case Color.Green:
                    Console.WriteLine("Водители: Ехать!");
                    Console.WriteLine("Пешеходы: Стоять!");
                    break;
            }
            Console.WriteLine($"Состояние продлится {_currentState.Duration / 1000} секунд(ы)");
            Console.WriteLine();
        }
    }

    class Program
    {
        static void Main(string[] args)
        {
            TrafficLight trafficLight = new TrafficLight(new RedState());

            while (true)
            {
               Thread.Sleep(trafficLight.CurrentState.Duration);
                trafficLight.ChangeState();
            }
        }
    }
