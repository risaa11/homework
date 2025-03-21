#include <iostream>

class Admin
{
public:
	bool AdminStatus = false;
	Admin()
	{
		this->AdminStatus = false;
	}
	Admin(bool adminStatus)
	{
		this->AdminStatus = adminStatus;
	}
};

class Сommunity : public Admin
{
protected:
	std::string Name;
public:
	Сommunity()
	{
		this->Name = "Unreg";
	}
	Сommunity(std::string name)
	{
		this->Name = name;
	}
	void changeName(std::string name)
	{
		if(this->AdminStatus)
			this->Name = name;
	}
};

class Post : public Сommunity
{
protected:
	std::string Text;
	bool LikeStatus;
	std::string LikedPeople;
public:
	Post()
	{
		this->Text = "None text";
		this->LikeStatus = false;
		this->LikedPeople = " ";
	}
	Post(std::string text, bool likeStatus, std::string likedPeople)
	{
		this->Text = text;
		this->LikeStatus = false;
		this->LikedPeople = " ";
	}
	void changeLike(std::string peopleName)
	{
		if (this->AdminStatus)
		{
			if (!this->LikeStatus)
			{
				LikeStatus = true;
				this->LikedPeople = peopleName;
			}
			else
			{
				LikeStatus = false;
				this->LikedPeople = " ";
			}
		}
	}
	void changeText(std::string text)
	{
		if(this->AdminStatus)
		{
			this->Text = text;
		}
	}
};

class User : public Post
{
private:
	std::string Login;
	std::string Password;
public:
	User()
	{
		this->Login = "Annonimous";
		this->Password = "Annonimous";
	}
	User(std::string login, std::string password, bool adminStatus) 
	{
		this->Login = login;
		this->Password = password;
		this->AdminStatus = adminStatus;
	}
	void setLogin(std::string login)
	{
		if(AdminStatus)
			this->Login = login;
	}
	std::string getLogin()
	{
		if (this->AdminStatus)
			return this->Login;
	}

};
