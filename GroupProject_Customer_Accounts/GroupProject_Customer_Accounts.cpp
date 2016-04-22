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
	//Stub code to test AccountOperations.set/getFnameLName()
	//comment out or delete when completed
	//JohnMRobertM_AccountOperations accountOps;
	//accountOps.setFnameLname();
	//std::cout << "Get validated fNameLName: " << accountOps.getFnameLname() << std::endl;

	/*methods set/getAddress works as expected*/
	//Stub code to test AccountOperationss.set/getAddress()
	//comment out or delete when completed
	//JohnMRobertM_AccountOperations accountOps;
	//accountOps.setAddress();
	//system("cls");
	//std::cout << accountOps.getAddress() << std::endl;

	/*methods set/getAddress2 works as expected*/
	//Stub code to test AccountOperationss.set/getAddress2()
	//comment out or delete when completed
	//JohnMRobertM_AccountOperations accountOps;
	//accountOps.setAddressLine2();
	//system("cls");
	//std::cout << accountOps.getAddressLine2() << std::endl;

	/*methods set/getPhoneNumber works as expected*/
	//Stub code to test AccountOperationss.set/getPhoneNumber()
	//comment out or delete when completed
	//JohnMRobertM_AccountOperations accountOps;
	//accountOps.setPhoneNumber();
	//system("cls");
	//std::cout << accountOps.getPhoneNumber() << std::endl;

	//start main controller, shows menu
	menuController = new MenuController();
	system("pause");
    return 0;
}

