#include <iostream>

class Socks
{
private:
	std::string color;
	std::string size;
public:
	std::string GetColor()
	{
		return this->color;
	}
	std::string GetSize()
	{
		return this->size;
	}
	void SetSize(std::string size)
	{
		this->size = size;
	}
	void SetColor(std::string color)
	{
		this->color = color;
	}
	Socks()
	{
		this->color = "Black";
		this->size = "XL";
	}
	Socks(std::string color, std::string size)
	{
		this->color = color;
		this->size = size;
	}
};

class Shoes
{
private:
	std::string size;
	std::string color;
	std::string material;
public:
	Shoes()
	{
		this->size = "XL";
		this->color = "brown";
		this->material = "skin";
	}
	Shoes(std::string color, std::string size, std::string material)
	{
		this->color = color;
		this->size = size;
		this->material = material;
	}
	std::string GetColor()
	{
		return this->color;
	}
	std::string GetSize()
	{
		return this->size;
	}
	std::string GetMaterial()
	{
		return this->material;
	}
	void SetSize(std::string size)
	{
		this->size = size;
	}
	void SetColor(std::string color)
	{
		this->color = color;
	}
	void SetMaterial(std::string material)
	{
		this->material = material;
	}
};

class Sweater
{
private:
	std::string color;
	std::string size;
public:
	std::string GetColor()
	{
		return this->color;
	}
	std::string GetSize()
	{
		return this->size;
	}
	void SetSize(std::string size)
	{
		this->size = size;
	}
	void SetColor(std::string color)
	{
		this->color = color;
	}
	Sweater()
	{
		this->color = "Black";
		this->size = "XL";
	}
	Sweater(std::string color, std::string size)
	{
		this->color = color;
		this->size = size;
	}
};
