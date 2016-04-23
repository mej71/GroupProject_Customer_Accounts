
#ifndef MENUCONTROLLER_H
#define MENUCONTROLLER_H
#include <string>
#include <iostream>
#include "JohnMRobertM_AccountOperations.h"

class MenuController {

	private:
		int tempInt;
		int menuChoice;
		std::string tempStr;
		bool tempBool;
		bool exitProgram;


	public:
		MenuController() {
			tempInt = 0;
			menuChoice = 0;
			tempStr = "";
			tempBool = false;
			exitProgram = false;
			while (exitProgram ==  false) {
				showMenu();
			}
		}

		void showMenu() {
			//create instance of the account operations class, to handle our menu choices
			JohnMRobertM_AccountOperations operations;
			system("cls");//clear the screen for clarity
			while (menuChoice == 0) {
				while (std::cout << "Please choose one of the following:\n1. Enter a new customer record\n2. Search for a particular customer record\n3. Show all records\n4. Delete a record\n5. Modify a record\n6. Exit program\n" && !(std::cin >> menuChoice)) {
					std::cin.clear(); //clear bad input flag
					std::cin.ignore(1000, '\n'); //discard input
					std::cout << "Please enter 1, 2, 3, 4, 5, or 6." << std::endl;
					menuChoice = 0;
				}
				if (menuChoice > 6 || menuChoice <= 0) {
					std::cout << "Please enter 1, 2, 3, 4, 5, or 6." << std::endl;
					menuChoice = 0;
				}
			}
			std::cin.clear(); //clear bad input flag
			std::cin.ignore(1000, '\n'); //discard input
			std::cout << std::endl;

			switch (menuChoice)
			{
				case 1:
					//get user input, create the new record and write it to the file
					operations.createRecord();
					break;
				case 2:
					operations.findRecord();
					break;
				case 3:
                    operations.getAllRecords();
					break;
				case 4:
					operations.deleteRecord();
					break;
				case 5:

					break;
				case 6:
					exitProgram = true;
					break;
				default:
					break;
			}

			//reset variables
			tempInt = 0;
			menuChoice = 0;
			tempStr = "";
			tempBool = false;
		}

};
#endif
