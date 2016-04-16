
#ifndef MENUCONTROLLER_H
#define MENUCONTROLLER_H
#include <string>
#include <iostream>

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
			while (menuChoice == 0) {
				while (std::cout << "Please choose one of the following:\n1. Enter a new customer record\n2. Search for a particular customer record\n3. Show all records\n4. Exit program\n" && !(std::cin >> menuChoice)) {
					std::cin.clear(); //clear bad input flag
					std::cin.ignore(1000, '\n'); //discard input
					std::cout << "Please enter 1, 2, 3, or 4." << std::endl;
					menuChoice = 0;
				}
				if (menuChoice > 4 || menuChoice <= 0) {
					std::cout << "Please enter 1, 2, 3, or 4." << std::endl;
					menuChoice = 0;
				}
			}
			std::cin.clear(); //clear bad input flag
			std::cin.ignore(1000, '\n'); //discard input
			std::cout << std::endl;

			switch (menuChoice)
			{
				case 1:
					break;
				case 2:
					break;
				case 3:
					break;
				case 4:
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
