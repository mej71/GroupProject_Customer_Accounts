// GroupProject_Customer_Accounts.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include "MenuController.h";
#include "JohnMRobertM_AccountOperations.h";


void showWelcomeMessage() {
	std::cout << "Welcome to the Customer Accounts Information program, developed by Jem Milam and Robert Munshower." << std::endl;
}


int main()
{
	std::string runAgain = "Y";
	MenuController *menuController;
	showWelcomeMessage();
	
	/*methods set/getFnameLname works as expected*/
	//Stub code to test AccountOperations.getFnameLName()
	//comment out or delete when completed
	//JohnMRobertM_AccountOperations accountOps;
	//accountOps.setFnameLname();
	//std::cout << "Get validated fNameLName: " << accountOps.getFnameLname() << std::endl;

	//start main controller, shows menu
	menuController = new MenuController();
	system("pause");
    return 0;
}

