using System;
using System.Linq;
using System.Collections;
using System.Collections.Generic;

class Program
{
    static void Main()
    {
        var employees = new[]
        {
            new { Name = "Ivan", Department = "IT", Salary = 100000 },
            new { Name = "Petr", Department = "HR", Salary = 80000 },
            new { Name = "Alexey", Department = "IT", Salary = 120000 },
            new { Name = "Mary", Department = "HR", Salary = 75000 },
            new { Name = "Darya", Department = "IT", Salary = 95000 },
            new { Name = "Sergey", Department = "Finance", Salary = 110000 }
        };

        var result = employees
            .GroupBy(e => e.Department);

        double avgSalary = employees.Average(result => result.Salary);


        int itCount = 0;
        int hrCount = 0;
        int financeCount = 0;

        for (int i = 0; i < employees.Count(); i++)
        {
            switch (employees[i].Department)
            {
                case "IT":
                    itCount += employees[i].Salary;
                    break;
                case "HR":
                    hrCount += employees[i].Salary;
                    break;
                case "Finance":
                    financeCount += employees[i].Salary;
                    break;
            }
        }
        Console.Write($"The most value department = ");
        string resultt = (itCount > hrCount) ? (itCount > financeCount) ? "IT" : "FINANCE" : (hrCount > financeCount) ? "HR" : "FINANCE";
        Console.WriteLine(resultt );
    }
}
