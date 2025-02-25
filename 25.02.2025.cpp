/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/
/*Создать систему для учета сотрудников с использованием виртуальных методов:
Базовый класс - Employee, свойства name - имя, salary - зарплата, метод - calculateBonus() - возвращает бонус сотрудника.
Наследники: 
Manager, доп свойство - numberOfSubordinates (количество подчиненных), 
calculateBonus - расчет бонуса на основе зарплаты и количества подчиненных.

Developer, доп свойство - numberOfProjects (количество проектов), 
calculateBonus - расчет бонуса на основе зарплаты и количества проектов.

Intern, доп свойство - internshipDuration (стажировка в месяцах), 
calculateBonus - фиксированный бонус, если стажировка больше 3х месяцев, иначе бонус = 0.
*/

#include <iostream>

class Employee
{
    protected:
     std::string name;
     int salary;
     public:
     virtual int calculateBonus()
     {
         int res = salary/10;
         return res;
     }
     Employee(std::string name, int salary)
     {
         this->name = name;
         this->salary = salary;
     }
     Employee()
     {
         this->name = "Unknown";
         this->salary = 0;
     }
};

class Manager : public Employee
{
    protected:
    int numberOfSubordinates;
     public:
    int calculateBonus() override 
     {
         int res = numberOfSubordinates+salary/10;
         return res;
     }
     Manager(std::string name, int salary, int numberOfSubordinates) : Employee(name, salary)
     {
         this->numberOfSubordinates = numberOfSubordinates;
     }
};

class Developer : public Employee
{
    protected:
    int numberOfProjects;
     public:
    int calculateBonus() override
     {
         int res = numberOfProjects * salary/2;
         return res;
     }
     Developer(std::string name, int salary, int numberOfProjects) : Employee(name, salary)
     {
         this->numberOfProjects = numberOfProjects;
     }
};

class Intern : public Employee
{
    protected:
    int internshipDuration;
     public:
    int calculateBonus() override
     {
         int res = internshipDuration + salary/2;
         return res;
     }
     Intern(std::string name, int salary, int internshipDuration) : Employee(name, salary)
     {
         this->internshipDuration = internshipDuration;
     }
     
};


int main()
{
    Intern intt("Andrew", 80000, 5050);
    Developer dev ("Dave", 92000, 19300);
    Employee emp("Deff", 50000);
    Manager manag("Mangg", 56000, 19);
    std::cout<<"Base salary = " << intt.calculateBonus() <<std::endl;
    
}
