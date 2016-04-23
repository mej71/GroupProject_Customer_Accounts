// GroupProject_Customer_Accounts.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include "MenuController.h";
#include "JohnMRobertM_AccountOperations.h";


void showWelcomeMessage() {
	std::cout << "Welcome to the Customer Accounts Information program"
		<< std::endl << "Developed by Jem Milam and Robert Munshower." << std::endl << std::endl;
}


int main()
{
	std::string runAgain = "Y";
	MenuController *menuController;
	showWelcomeMessage();
	

	//start main controller, shows menu
	menuController = new MenuController();
	system("pause");
    return 0;
}

