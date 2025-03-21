#include <iostream>

using namespace std;

class SmartOven
{
public:
	bool Status = false;
public:
	SmartOven()
	{
		bool Status = false;
	}
	SmartOven(bool status)
	{
		this->Status = status;
	}
	void executeCommand(std::string change)
	{
		(change == "включить" || change == "Включить") ? this->Status = true : this->Status = false;
	}
	std::string checkStatus()
	{
		return (this->Status) ? "Духовка включена" : "Духовка выключена";
	}
};

class SmartTV
{
public:
	bool Status = false;
public:
	SmartTV()
	{
		bool Status = false;
	}
	SmartTV(bool status)
	{
		this->Status = status;
	}
	void executeCommand(std::string change)
	{
		(change == "включить" || change == "Включить") ? this->Status = true : this->Status = false;
	}
	std::string checkStatus()
	{
		return (this->Status) ? "Телевизор включен" : "Телевизор выключен";
	}
};

class SmartHome : public SmartTV, public SmartOven
{
public:
	void changeStatus(SmartOven& object, std::string change)
	{
		(change == "Включить" || change == "включить") ? object.Status = true : object.Status = false;
	}
	void changeStatus(SmartTV& object, std::string change)
	{
		(change == "Включить" || change == "включить") ? object.Status = true : object.Status = false;
	}
};

int main()
{
	setlocale(LC_ALL, "ru");
	SmartTV tv;
	SmartOven oven;
	std::cout << tv.checkStatus() << std::endl;
	std::cout << oven.checkStatus() << std::endl;
	SmartHome home;
	home.changeStatus(tv, "Включить");
	home.changeStatus(oven, "Включить");
	std::cout << tv.checkStatus() << std::endl;
	std::cout << oven.checkStatus() << std::endl;
	home.changeStatus(tv, "Выключить");
	home.changeStatus(oven, "Выключить");
	std::cout << tv.checkStatus() << std::endl;
	std::cout << oven.checkStatus() << std::endl;
}
