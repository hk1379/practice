#include <iostream>
#include <fstream>
#include <string>

using std::ifstream;
using std::ofstream;
using std::string;

class Helper{
public:
	//popup message
	void PopupMessage(const char* message)
	{
		std::cout << message << std::endl;
	}

	//creating a file
	void CreateAndInput(string username, string password)
	{
		//creating and opening a text file
		string fileName = username + ".txt";
		ofstream MyFile(fileName);

		//write to file
		MyFile << username;
		MyFile << '\n' + password;

		//close the file
		MyFile.close();
	}

	//helps to log in but the more useful function is below
	void LogIn(string username, string password)
	{
		//check files which are called "username + .txt"
		string fileName = username + ".txt";
		ifstream MyReadFile(fileName);

		//looping through file and reading file
		string myText;
		int counter = 0;

		while (getline(MyReadFile, myText)) {
			if (counter == 0)
			{
				if (myText == "")
				{
					std::cout << "File is Empty";
				}
				else if (myText == username)
				{
					std::cout << "username is correct";
				}
				else
				{
					std::cout << "username is incorrect";
				}
			}
			else if (counter == 1)
			{
				if (myText == password)
				{
					std::cout << " \npassword is correct";
				}
				else
				{
					std::cout << " \npassword is correct";
				}
			}

			counter++;
		}
	}

	//User log in
	void UserLogin()
	{
		//will be initialised from the user input
		string username;
		string password;

		//user input for login occurs here
		std::cout << "Type a Username:\n";
		std::cin >> username;

		std::cout << "Type a Password:\n";
		std::cin >> password;

		//registering a user is here
		LogIn(username, password);
	}

	//registering new user
	void Registration()
	{
		//will be initialised from the user input
		string username;
		string password;

		//user input for registration occurs here
		std::cout << "Type a Username:\n";
		std::cin >> username;

		std::cout << "Type a Password:\n";
		std::cin >> password;

		//registering a user is here
		CreateAndInput(username, password);
		PopupMessage("Registration complete");
	}
};