#include <iostream>  

class Processor
{
private:
	int ggrc;
public:
	void setGgrc(int ggrc)
	{
		this->ggrc = ggrc;
	}
	int GetGgrc()
	{
		return this->ggrc;
	}
	Processor(int ggrc)
	{
		this->ggrc = ggrc;
	}
	Processor()
	{
		this->ggrc = 0;
	}

}; //jkl  
class Ram
{
private:
	int spaceRam;
public:
	void setspaceRam(int spaceRam)
	{
		this->spaceRam = spaceRam;
	}
	int GetSpaceRam()
	{
		return this->spaceRam;
	}
	Ram(int spaceRam)
	{
		this->spaceRam = spaceRam;
	}
	Ram()
	{
		this->spaceRam = 0;
	}
};
class diskSpace
{
private:
	int spaceVal;
public:
	void setspaceVal(int spaceVal)
	{
		this->spaceVal = spaceVal;
	}
	int GetSpaceVal()
	{
		return this->spaceVal;
	}
	diskSpace(int spaceVal)
	{
		this->spaceVal = spaceVal;
	}
	diskSpace()
	{
		this->spaceVal = 0;
	}
};
class Display
{
private:
	int brightness;
public:
	void setbrightness(int brightness)
	{
		this->brightness = brightness;
	}
	int GetBrightness()
	{
		return this->brightness;
	}
	Display(int brightness)
	{
		this->brightness = brightness;
	}
	Display()
	{
		this->brightness = 0;
	}


};

class SmartPhone : public Display, public Processor, public Ram, public diskSpace
{
private:
	int salary = 0;
	std::string logo;
	bool checkReady = false;


public:

	void phoneTech(Display disp, Processor proc, Ram ram, diskSpace diskSpace)
	{
		checkReady = true;
	}

	SmartPhone(std::string logo, int salary, int ggrc, int spaceRam, int spaceVal, int brightness) :Display(brightness), Processor(ggrc), Ram(spaceRam), diskSpace(spaceVal)
	{
		this->logo = logo;
		this->salary = salary;
	}

	void PrintAll(SmartPhone phone)
	{
		if (checkReady)
			std::cout << "SmartPhone - " << phone.logo << "\nSalary phone = " << phone.salary << " rub\nProcessor = " << phone.Processor::GetGgrc() << " ggc\nDisplay = " << phone.Display::GetBrightness() << phone.salary << " neet\nRam = " << phone.Ram::GetSpaceRam() << " ggb\nDiskSpace = " << phone.diskSpace::GetSpaceVal() << std::endl;
		else
			std::cout << "SmartPhone - " << phone.logo << "\nSalary phone = " << phone.salary << std::endl;
	}
};

int main()
{
	Display* disp = new Display(3000);
	Processor* proc = new Processor(4000);
	Ram* ram = new Ram(8000);
	diskSpace* space = new diskSpace(256);
	SmartPhone* Galaxy = new SmartPhone("Samsung Galaxy", 80000, 4000, 16000, 512, 3000);
	Galaxy->phoneTech(*disp, *proc, *ram, *space);
	Galaxy->PrintAll(*Galaxy);
}
