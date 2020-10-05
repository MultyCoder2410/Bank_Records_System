/*
	Made by: Tristan Franssen
*/
#include "Add_Record.h"

#include <iostream>
#include <string>

#include "../../Tools/Files/Files.h"

// adds record
Add_Record::Add_Record()
{

	// stores account number
	std::string Account[6];

	// stores answer and add's it to array
	std::string Answer;

	// adds nice line
	Account[0] += "------------------------------------------";
	Account[0] += "\n";

	// asks user to put in account number and makes it look nice
	std::cout << "Enter account number: ";
	Account[1] += "Account number: ";
	std::cin >> Answer;
	Account[1] += Answer;
	Account[1] += "\n";

	// asks for first name and makes it look nice
	std::cout << "Enter first name: ";
	Account[2] += "First name: ";
	std::cin >> Answer;
	Account[2] += Answer;
	Account[2] += "\n";

	// asks for last name and makes it look nice
	std::cout << "Enter last name: ";
	Account[3] += "Last name: ";
	std::cin >> Answer;
	Account[3] += Answer;
	Account[3] += "\n";

	// asks for balance and makes it look nice
	std::cout << "Enter balance: ";
	Account[4] += "Current balance: ";
	std::cin >> Answer;
	Account[4] += Answer;
	Account[4] += "\n";

	// adds nice line
	Account[5] += "------------------------------------------";
	Account[5] += "\n";

	// makes files object
	Files file;

	// looks if account number is already in use
	if (file.Search("res/Records/Records.txt", Answer) == "")
	{

		// makes a new file and writes to file
		for (int i = 0; i < 6; i++)
		{
			file.Write_To_File("res/Records/Records.txt", Account[i], false);
		}

		// gets amount of linse
		int Lines = std::stoi(file.Read_File("res/Lines.txt", 1));
		// adds to amount of lines
		Lines += 6;
		// writes lines to file
		file.Write_To_File("res/Lines.txt", std::to_string(Lines), true);

	}
	else
	{

		// tells user that number is already in use
		std::cout << "\n\nAccount number already in use. Please try again . . .";
		std::cin.get();
		std::cin.get();

	}

}
