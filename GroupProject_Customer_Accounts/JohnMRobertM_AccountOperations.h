#pragma once

#ifndef JohnMRobertM_AccountOperations_H
#define JohnMRobertM_AccountOperations_H

#include <string>
#include <iostream>
#include <fstream>

/*
Class Author: Robert M. written for a collaborative Project between John Milman and Robert Munshower
Created: 04/20/16
Class:  JohnMRobertM_AccountOperations 
This class contains the logic and commands associated with:
1)Entering a new record into the file
2)Searching for a particular customer's record and displaying it
3)Searching for a particular customer's record and deleting it
4)Searching for a particular customer's record and changing it
5)Displaying the entire contents of the file containg all customer records
*/


class JohnMRobertM_AccountOperations {

private:
	//The structure to hold all componets of a customer record
	struct CustomerRecord
	{
		std::string fNameLname;
		std::string address;
		std::string cityStateZip;
		std::string phoneNumber;
		std::string accountBalance;
		std::string lastPaymentDate;
	};

	CustomerRecord record;//reference to the struct
	std::ofstream accountFile;

public:

	//Constructor
	JohnMRobertM_AccountOperations() {
		//creates file if it does not exist, opens it in append mode.
		accountFile.open("accounts.txt", std::fstream::out | std::fstream::app);
	}

	//calls all the input field methods, and the writes to the file
	void createRecord() {
		setFnameLname();
		setAddress();
		setAddressLine2();
		setPhoneNumber();
		setAccountBalance();
		setLastPaymentDate();
		addRecord();
	}

	//Add record to file
	void addRecord() {
		accountFile << record.fNameLname << "," << record.address << + "," << record.cityStateZip << "," << record.phoneNumber << "," << record.accountBalance << "," << record.lastPaymentDate << std::endl;
	}

	//Mutators associated with customerRecord struct
	//all mutators provide i/O and validation
	
	void setFnameLname()
	{
		char fName[50];
		char lName[50];
		int flag;// serves as error accumaltor. 0 meaning zero errors
		int index;//element position
		bool allAlpha;//flag: allAlpha is true if isalpha == true, false otherwise
		std::string accept;


		//clear the screen for clarity
		system("cls");

		do
		{
			
			flag = 0;// serves as error accumaltor for outer do while loop. 0 meaning zero errors
			accept = "";

			std::cout << "Please enter the customer's first name only followed by the return key.\n";
			std::cout << ": ";
			std::cin >> fName;

			std::cout << "Please enter the customer's last name only followed by the return key.\n";
			std::cout << ": ";
			std::cin >> lName;

			//validate alpha only
			index = 0;//element position
			allAlpha = true; //flag allAlpha is true if isalpha == true, false otherwise
			//check fname alpha
			while (index < strlen(fName))
			{
				if (!isalpha(fName[index]))
				{
					allAlpha = false;
				}
				index++;
			}
			index = 0; //reset index
			//check lName alpha
			while (index < (strlen(lName)))
			{
				if (!isalpha(lName[index]))
				{
					allAlpha = false;
				}
				index++;
			}
			//clear screen if errors retake input
			if (allAlpha == false )
				system("cls");
			
			//check allAlpha flag to write error
			if (allAlpha != true)
			{
				std::cout << "\aAlpha Error: First and last name must be alpha only.\n\n";
				flag++;
			}

			//validate length two characters min for fName and lName
			if (strlen(fName) < 2 || strlen(lName) < 2)
			{
				if(allAlpha == true)// clear screen for this error only if allApha has not done so
					system("cls");
				std::cout << "\aLength Error: First and last name should be at least two characters each.\n\n";
				flag++;
			}

			//verify
			if (flag == 0)
			{
				do
				{
					std::cout << std::endl << "Please verify the above is correct" << std::endl;
					std::cout << "Enter y for yes or n for no: ";
					std::cin >> accept;
				} while (accept.compare("y") != 0 && accept.compare("Y") != 0 && accept.compare("n") != 0 && accept.compare("N") != 0);
			}

			if (accept.compare("n") == 0 || accept.compare("N") == 0)
			{
				flag++;
				std::cin.get();//get newline char
				system("cls");//clear the screen for clarity
			}
			

		} while (flag != 0);
		

		//add to struct piece by piece
		record.fNameLname = fName;
		record.fNameLname += " ";
		record.fNameLname += lName;

		//Clear the input stream
		std::cin.ignore();
	
	}

	void setAddress()
	{
		std::string address;
		std::string accept;
		bool flag;//flag for empty string / incorrect string true string is empty/incorrect false otherwise
		//clear the screen for clarity
		system("cls");
		 
		do
		{
			//set flag
			flag = false;
			//set accept
			accept = "";

			do
			{
				std::cout << "Please enter the customer's street address" << std::endl << std::endl;
				std::getline(std::cin, address);
				
				if (address.empty())
				{
					flag = true;
					system("cls");//clear the screen for clarity
					std::cout << "\aEmpty Error: The address cannot be empty." << std::endl << std::endl;
				}
				else
					flag = false;
					//check for any punctuation
					for (int i = 0; i < address.length(); i++) {
						if (ispunct(address[i])) {
							flag = true;
						}
					}

			} while (flag);
			//verify
			do
			{
				std::cout << std::endl << "Please verify the above is correct" << std::endl;
				std::cout << "Enter y for yes or n for no: ";
				std::cin >> accept;
			} while (accept.compare("y") != 0 && accept.compare("Y") != 0 && accept.compare("n") != 0 && accept.compare("N") != 0);

			if (accept.compare("n") == 0 || accept.compare("N") == 0)
			{
				flag = true;
				std::cin.get();//get newline char
				system("cls");//clear the screen for clarity
			}	
		} while (flag);

		//add to struct
		record.address = address;

		//Clear the input stream
		std::cin.ignore();
	
	}

	void setAddressLine2()
	{
		std::string address2;
		std::string accept;
		bool flag;//flag for empty string / incorrect string true string is empty/incorrect false otherwise
		system("cls");//clear the screen for clarity

		do
		{
			//set accept
			accept = "";
			//set flag
			flag = false;
			do
			{
				std::cout << "Please enter the customer's City State and Zip separated by spaces only" << std::endl << std::endl;
				std::getline(std::cin, address2);

				if (address2.empty())
				{
					flag = true;
					system("cls");//clear the screen for clarity
					std::cout << "\aEmpty Error: The  *** address cannot be empty." << std::endl << std::endl;
				}
				else
					flag = false;
					//check for any punctuation
					for (int i = 0; i < address2.length(); i++) {
						if (ispunct(address2[i])) {
							flag = true;
						}
					}

			} while (flag);
			//verify
			do
			{
				std::cout << std::endl << "Please verify the above is correct" << std::endl;
				std::cout << "Enter y for yes or n for no: ";
				std::cin >> accept;
			} while (accept.compare("y") != 0 && accept.compare("Y") != 0 && accept.compare("n") != 0 && accept.compare("N") != 0);

			if (accept.compare("n") == 0 || accept.compare("N") == 0)
			{
				flag = true;
				std::cin.get();//get newline char
				system("cls");//clear the screen for clarity
			}
		} while (flag);

		//add to struct
		record.cityStateZip = address2;

		//Clear the input stream
		std::cin.ignore();
	}

	void setPhoneNumber()
	{
		char number[11];
		bool invalid;//flag for number. If number is invalid; invalid == true otherwise false 
		std::string accept;

		system("cls");//clear the screen for clarity
		do 
		{
			//set bool to false
			invalid = false;
			//set accept
			accept = "";

			std::cout << "Please enter the customer's contact number. Enter 10 digits only." << std::endl << std::endl;
			std::cin >> number;

			//check for alpha chars
			for (int index = 0; index < strlen(number); index++)
			{
				if (isalpha(number[index]) && invalid != true)
					invalid = true;
			}
			//check length
			if (strlen(number) != 10)
				invalid = true;

			//throw error
			if (invalid)
			{
				system("cls");//clear the screen for clarity
				std::cout << "\aPhone Number Error: Enter 10 digits only no spaces." << std::endl << std::endl;
			}
			//verify
			if (!invalid)
			{
				do
				{
					std::cout << std::endl << "Please verify the above is correct" << std::endl;
					std::cout << "Enter y for yes or n for no: ";
					std::cin >> accept;
				} while (accept.compare("y") != 0 && accept.compare("Y") != 0 && accept.compare("n") != 0 && accept.compare("N") != 0);
			}

			if (accept.compare("n") == 0 || accept.compare("N") == 0)
			{
				invalid = true;
				std::cin.get();//get newline char
				system("cls");//clear the screen for clarity
			}


		} while (invalid);

		//add to struct
		record.phoneNumber = number;
		//format the number in the struct
		record.phoneNumber.insert(0, "(");
		record.phoneNumber.insert(4, ")");
		record.phoneNumber.insert(8, "-");

		//Clear the input stream
		std::cin.ignore();
	
	}

	void setAccountBalance()
	{
		char number[100];
		bool invalid;//flag for number. If number is invalid; invalid == true otherwise false
		int decimal;
		std::string accept;

		system("cls");//clear the screen for clarity
		do
		{
			//set bool to false
			invalid = false;
			//set decimal
			decimal = 0;
			//set accept
			accept = "";

			std::cout << "Please enter the customer's total balance. Example: 567.00" << std::endl << std::endl;
			std::cin >> number;
			
			//check for all digit chars
			for (int index = 0; index < strlen(number); index++)
			{
				if (!isdigit(number[index]))
				{
					if (number[index] == '.')//if is digit false check if decimal '.'
					{
						decimal++;// increment decimal to one to indicate 1 decimal 
					}
					else if (!isdigit(number[index]) && number[index] != '.')
					{
						invalid = true;
					}
				}
			}

			//check that there are only two chars after decimal which were already checked to be digits
			//by checking the decimals position. Number must contain a min of 4 char digits ex 1.00
			std::string temp = number;
			if (temp.length() < 4)
			{
				invalid = true;
			}
			else if (temp.at((temp.length() - 3)) != '.')
				invalid = true;

			//throw error
			if (invalid || decimal != 1)//check if in valid true or too many decimals
			{
				system("cls");//clear the screen for clarity
				std::cout << "\aBalance Error: Balance must be a positive value with only 1 decimal place." << std::endl << std::endl;
			}
			//verify
			if (!invalid && decimal == 1)
			{
				do
				{
					std::cout << std::endl << "Please verify the above is correct" << std::endl;
					std::cout << "Enter y for yes or n for no: ";
					std::cin >> accept;
				} while (accept.compare("y") != 0 && accept.compare("Y") != 0 && accept.compare("n") != 0 && accept.compare("N") != 0);
			}

			if (accept.compare("n") == 0 || accept.compare("N") == 0)
			{
				invalid = true;
				decimal = 0;
				std::cin.get();//get newline char
				system("cls");//clear the screen for clarity
			}


		} while (invalid || decimal != 1);

		//add to struct
		record.accountBalance = number;

		//Clear the input stream
		std::cin.ignore();
	}

	void setLastPaymentDate()
	{
		char date[11];
		bool invalid;//flag for number. If number is invalid; invalid == true otherwise false 
		std::string accept;
		std::string temp;

		system("cls");//clear the screen for clarity
		do
		{
			//set bool to false
			invalid = false;
			//set accept
			accept = "";
			//set temp
			temp = "";

			std::cout << "Please enter the customer's last payment date. Example: 01/02/2016" << std::endl << std::endl;
			std::cin >> date;
			
			//check date format
			for (int index = 0; index < 10; index++)
			{
				if (index != 2 && index != 5)
				{
					if (!isdigit(date[index]))
						invalid = true;
				}
				else
				{
					if (date[index] != '/')
						invalid = true;
				}
			}
			
			temp = date;
			//check date values only if invalid is false
			if (!invalid)//because stoi will cause a run time error if non digit is encountered.
			{
				std::string mm = temp.substr(0, 2);
				std::string dd = temp.substr(3, 2);
				std::string yyyy = temp.substr(6, 4);

				try
				{
					if (stoi(mm) <= 0 || stoi(mm) > 12)
						invalid = true;
					if (stoi(dd) <= 0 || stoi(dd) > 31)
						invalid = true;
					if (stoi(yyyy) < 1999)
						invalid = true;
				}
				catch (const std::exception&)
				{
					invalid = true;
				}
				
			}


			//throw error
			if (invalid)//check if in valid true or too many decimals
			{
				system("cls");//clear the screen for clarity
				std::cout << "\aDate Error: Date format must match: MM/DD/YYYY" << std::endl
					<< "Year cannot be prior to 1999" << std::endl  << std::endl;
			}
			//verify
			if (!invalid)
			{
				do
				{
					std::cout << std::endl << "Please verify the above is correct" << std::endl;
					std::cout << "Enter y for yes or n for no: ";
					std::cin >> accept;
				} while (accept.compare("y") != 0 && accept.compare("Y") != 0 && accept.compare("n") != 0 && accept.compare("N") != 0);
			}

			if (accept.compare("n") == 0 || accept.compare("N") == 0)
			{
				invalid = true;
				std::cin.get();//get newline char
				system("cls");//clear the screen for clarity
			}




		} while (invalid);

		//add to struct
		record.lastPaymentDate = date;

		//Clear the input stream
		std::cin.ignore();
	
	}

	//Accessors associated with customerRecord struct
	std::string getFnameLname()
	{
		return record.fNameLname;
	}

	std::string getAddress()
	{
		return record.address;
	}

	std::string getAddressLine2()
	{
		return record.cityStateZip;
	}

	std::string getPhoneNumber()
	{
		return record.phoneNumber;
	}

	std::string getAccountBalance()
	{
		return record.accountBalance;
	}

	std::string getLastPaymentDate()
	{
		return record.lastPaymentDate;
	}

};
#endif
