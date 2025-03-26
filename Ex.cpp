#include <iostream>

using namespace std;

class Conclusion
{
public:
	virtual void print() = 0;
};

class Vehicle : public Conclusion
{
protected:
	int weight;
	std::string material;
public:
	Vehicle()
	{
		this->weight = 0;
		this->material = "No material";
	}
	Vehicle(int weight, std::string material)
	{
		this->weight = weight;
		this->material = material;
	}
	int getWeight()
	{
		return this->weight;
	}
	void setWeight(int weight)
	{
		this->weight = weight;
	}
	std::string getMaterial()
	{
		return this->material;
	}
	void setMaterial(int material)
	{
		this->material = material;
	}
	void print() override
	{
		std::cout << "This weight = " << this->weight << "\nThis material" << this->material << std::endl;
	}
	friend ostream& operator<<(ostream& torrent, Vehicle& d) {
		torrent << "This weight = " << d.weight << "\nThis material" << d.material << std::endl;
	}
};

class Car : public Vehicle
{
protected:
	int horsepower;
	int length;
	int width;
public:
	Car() : Vehicle()
	{
		this->horsepower = 0;
		this->length = 0;
		this->width = 0;
	}
	Car(int weight, std::string material) : Vehicle(weight, material)
	{
		this->horsepower = 0;
		this->length = 0;
		this->width = 0;
	}
	Car(int horsepower, int length, int width, int weight, std::string material) : Vehicle (weight, material)
	{
		this->horsepower = horsepower;
		this->length = length;
		this->width = width;
	}
	int getHorsepower()
	{
		return this->horsepower;
	}
	int getLength()
	{
		return this->length;
	}
	int getWidth()
	{
		return this->width;
	}
	void setHorsepower(int horsepower)
	{
		this->horsepower = horsepower;
	}
	void setLength(int length)
	{
		this->length = length;
	}
	void setWidth(int width)
	{
		this->width = width;
	}
	void print() override
	{
		Vehicle::print();
		std::cout << "This horsepower = " << this->horsepower << "\nThis length" << this->length << "\nThis width" << this->width << std::endl;
	}
	friend ostream& operator<<(ostream& torrent, Car& d) {
		torrent << "This weight = " << d.weight << "\nThis material" << d.material << std::endl;
		torrent << "This horsepower = " << d.horsepower << "\nThis length" << d.length << "\nThis width" << d.width << std::endl;
		return torrent;
	}
};

class Train : public Vehicle
{
protected:
	int numberOfWagons;
	int maxSpeed;
	std::string type;
public:
	Train() : Vehicle()
	{
		this->numberOfWagons = 0;
		this->maxSpeed = 0;
		this->type = "No type";
	}
	Train(int weight, std::string material) : Vehicle(weight, material)
	{
		this->numberOfWagons = 0;
		this->maxSpeed = 0;
		this->type = "No type";
	}
	Train(int maxSpeed, int numberOfWagons, std::string type, int weight, std::string material) : Vehicle(weight, material)
	{
		this->maxSpeed = maxSpeed;
		this->numberOfWagons = numberOfWagons;
		this->type = type;
	}
	int getNumberOfWagons()
	{
		return this->numberOfWagons;
	}
	int getMaxSpeed()
	{
		return this->maxSpeed;
	}
	std::string getType()
	{
		return this->type;
	}
	void setNumberOfWagons(int numberOfWagons)
	{
		this->numberOfWagons = numberOfWagons;
	}
	void setMaxSpeed(int maxSpeed)
	{
		this->maxSpeed = maxSpeed;
	}
	void setType(std::string type)
	{
		this->type = type;
	}
	void print() override
	{
		Vehicle::print();
		std::cout << "This numberOfWagons = " << this->numberOfWagons << "\nThis maxSpeed" << this->maxSpeed << "\nThis type" << this->type << std::endl;
	}
	friend ostream& operator<<(ostream& torrent, Train& d) {
		torrent << "This weight = " << d.weight << "\nThis material" << d.material << std::endl;
		torrent << "This numberOfWagons = " << d.numberOfWagons << "\nThis maxSpeed" << d.maxSpeed << "\nThis type" << d.type << std::endl;\
		return torrent;
	}
};

class Express : public Train
{
protected:
	std::string movementPlan;
public:
	Express() : Train()
	{
		this->movementPlan = "No plan";
	}
	Express(int weight, std::string material) : Train(weight, material)
	{
		this->movementPlan = "No plan";

	}
	Express(int maxSpeed, int numberOfWagons, std::string type, int weight, std::string material) : Train( maxSpeed,  numberOfWagons,  type,  weight,  material)
	{
		this->movementPlan = "No plan";
	}
	Express(int maxSpeed, int numberOfWagons, std::string type, int weight, std::string material, std::string movementPlan) : Train(maxSpeed, numberOfWagons, type, weight, material)
	{
		this->movementPlan = movementPlan;
	}
	std::string getMovementPlan()
	{
		return this->movementPlan;
	}
	void setMovementPlan(std::string movementPlan)
	{
		this->movementPlan = movementPlan;
	}
	void print() override
	{
		Vehicle::print();
		Train::print();
		std::cout<< "\nThis movementPlan = " << this->movementPlan << std::endl;
	}
	friend ostream& operator<<(ostream& torrent, Express& d) {
		torrent << "This weight = " << d.weight << "\nThis material" << d.material << std::endl;
		torrent << "This numberOfWagons = " << d.numberOfWagons << "\nThis maxSpeed" << d.maxSpeed << "\nThis type" << d.type << std::endl;
		torrent << "This movementPlan = " << d.movementPlan << std::endl;
		return torrent;
	}
};

int main()
{
	Express expressTest(99, 33, "So small(((", 50, "Ironn", "Left, right, straight");
	std::cout << expressTest;
}
