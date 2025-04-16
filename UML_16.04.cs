using System;
using System.Collections.Generic;

public class Pizza
{
    public string Dough { get; set; }
    public string Sauce { get; set; }
    public List<string> Toppings { get; set; } = new List<string>();

    public void Display()
    {
        Console.WriteLine($"Пицца: Тесто - {Dough}, Соус - {Sauce}");
        Console.WriteLine("Начинки: " + string.Join(", ", Toppings));
        Console.WriteLine();
    }
}

public interface IPizzaBuilder
{
    void SetDough();
    void SetSauce();
    void SetToppings();
    Pizza GetPizza();
    void Reset();
}

public class MargheritaPizzaBuilder : IPizzaBuilder
{
    private Pizza _pizza = new Pizza();

    public void Reset()
    {
        _pizza = new Pizza();
    }

    public void SetDough()
    {
        _pizza.Dough = "Тонкое тесто";
    }

    public void SetSauce()
    {
        _pizza.Sauce = "Томатный соус";
    }

    public void SetToppings()
    {
        _pizza.Toppings.Add("Моцарелла");
        _pizza.Toppings.Add("Свежие листья базилика");
        _pizza.Toppings.Add("Оливковое масло");
    }

    public Pizza GetPizza()
    {
        Pizza result = _pizza;
        Reset();
        return result;
    }
}
public class PepperoniPizzaBuilder : IPizzaBuilder
{
    private Pizza _pizza = new Pizza();

    public void Reset()
    {
        _pizza = new Pizza();
    }

    public void SetDough()
    {
        _pizza.Dough = "Традиционное тесто";
    }

    public void SetSauce()
    {
        _pizza.Sauce = "Острый томатный соус";
    }

    public void SetToppings()
    {
        _pizza.Toppings.Add("Моцарелла");
        _pizza.Toppings.Add("Пепперони");
        _pizza.Toppings.Add("Перец чили");
        _pizza.Toppings.Add("Лук");
    }

    public Pizza GetPizza()
    {
        Pizza result = _pizza;
        Reset();
        return result;
    }
}

public class PizzaDirector
{
    private IPizzaBuilder _builder;

    public PizzaDirector(IPizzaBuilder builder)
    {
        _builder = builder;
    }

    public void ChangeBuilder(IPizzaBuilder builder)
    {
        _builder = builder;
    }

    public Pizza MakePizza()
    {
        _builder.Reset();
        _builder.SetDough();
        _builder.SetSauce();
        _builder.SetToppings();
        return _builder.GetPizza();
    }
}

class Program
{
    static void Main(string[] args)
    {
        var margheritaBuilder = new MargheritaPizzaBuilder();
        var pepperoniBuilder = new PepperoniPizzaBuilder();

        var director = new PizzaDirector(margheritaBuilder);

        var margheritaPizza = director.MakePizza();
        margheritaPizza.Display();

        director.ChangeBuilder(pepperoniBuilder);
        var pepperoniPizza = director.MakePizza();
        pepperoniPizza.Display();

        var anotherMargherita = margheritaBuilder;
        anotherMargherita.SetDough();
        anotherMargherita.SetSauce();
        anotherMargherita.SetToppings();
        var directMargherita = anotherMargherita.GetPizza();
        directMargherita.Display();
    }
}
