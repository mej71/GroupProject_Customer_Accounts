#pragma once

#ifndef JohnMRobertM_AccountOperations_H
#define JohnMRobertM_AccountOperations_H

#include <string>
#include <iostream>

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

public:

	//Mutators associated with customerRecord struct
	//all mutators provide i/O and validation
	
	void setFnameLname()
	{
		char fName[50];
		char lName[50];
		int flag;// serves as error accumaltor. 0 meaning zero errors
		int index;//element position
		bool allAlpha;//flag: allAlpha is true if isalpha == true, false otherwise

		//clear the screen for clarity
		system("cls");

		do
		{
			
			flag = 0;// serves as error accumaltor for outer do while loop. 0 meaning zero errors

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
			

		} while (flag != 0);
		
		//For testing comment out or delete when complete
		//if (flag == 0)
			//std::cout << "fName: " << fName << " lName: " << lName << " are valid!\n";

		//add to struct piece by piece
		record.fNameLname = fName;
		record.fNameLname += " ";
		record.fNameLname += lName;
	
	}

	void setAddress()
	{
		std::string address;
		std::string accept;
		bool flag = false;//flag for empty string / incorrect string true string is empty/incorrect false otherwise
		//clear the screen for clarity
		system("cls");
		 
		do
		{

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

			} while (flag);

			do
			{
				std::cout << std::endl << "Please verify the above is correct" << std::endl;
				std::cout << "Enter y for yes or n for no: ";
				std::cin >> accept;
			} while (accept.compare("y") != 0 && accept.compare("Y") != 0 && accept.compare("n") != 0 && accept.compare("N") != 0);

			if (accept.compare("n") == 0 || accept.compare("N") == 0)
			{
				flag = true;
				std::cin.get();
				system("cls");//clear the screen for clarity
			}	
		} while (flag);

		//add to struct
		record.address = address;
	
	}

	void setPhoneNumber()
	{
	
	}

	void setAccountBalance()
	{
	
	}

	void setLastPaymentDate()
	{
	
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

	void getPhoneNumber()
	{

	}

	void getAccountBalance()
	{

	}

	void getLastPaymentDate()
	{

	}

};
#endif
