#include <iostream>
#include "Helper.cpp"

using std::string;

int main()
{
	//instantiating helper class
	Helper helper;

	//input from user
	int input;
	helper.PopupMessage("Choose from the below two options:");
	helper.PopupMessage("1. Register");
	helper.PopupMessage("2. Login\n");
	std::cin >> input;

	//logic to either start registration process or login process
	switch (input)
	{
	default:
		break;
	case 1:
		helper.Registration();
		break;
	case 2:
		helper.UserLogin();
		break;
	}
}