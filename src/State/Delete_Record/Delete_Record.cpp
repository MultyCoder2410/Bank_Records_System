/*
	Made by: Tristan Franssen
*/
#include "Delete_Record.h"

#include <iostream>
#include <string>

#include "../../Tools/Files/Files.h"
#include "../../Tools/CLR_SCR.h"

// deletes records
Delete_Record::Delete_Record()
{

	// keeps doing this until user wants to leave
	while (true)
	{

		// makes files object
		Files file;

		// stores users choice
		std::string Choice;

		// stores amount of accounts
		int count = std::stoi(file.Read_File("res/Lines.txt", 1));

		// calculates amount of accounts
		count /= 6;

		// tells user amount of accounts
		std::cout << "There are " << count << " accounts\n";

		// lets user input choice
		std::cout << "Enter record number: ";
		std::cin >> Choice;

		// tells user that this is current data
		std::cout << "\nRecord has following data\n";

		// searches through file and shows it
		std::cout << file.Search("res/Records/Records.txt", Choice);

		// stores input
		std::string Delete;

		// asks if sure you want to delete it
		std::cout << "\n\nAre you sure you want to delete this record!";
		std::cout << "\n\tY/N\n";
		std::cin >> Delete;

		// looks if you want to delete it
		if (Delete == "Y" || Delete == "y")
		{

			// stores old file
			std::string Old_File = file.Read_File("res/Records/Records.txt", count * 6);

			// gets start of account
			const size_t Account_Start = Old_File.find(Choice) - 59;
			// gets end of account
			const size_t Account_End = file.Find_End(Account_Start);

			// Deletes account
			Old_File.erase(Account_Start, Account_End);

			// gets amount of linse
			int Lines = std::stoi(file.Read_File("res/Lines.txt", 1));
			// adds to amount of lines
			Lines -= 6;
			// writes lines to file
			file.Write_To_File("res/Lines.txt", std::to_string(Lines), true);

			// writes to file
			file.Write_To_File("res/Records/Records.txt", Old_File, true);

			// breaks loop
			break;

		}
		else if (Delete == "N" || Delete == "n")
		{

			// breaks loop
			break;

		}
		else
		{

			// tells user it is not a valid answer
			std::cout << "This is a unvalid option. Please try again!";
			std::cin.get();
			std::cin.get();

		}

		// clears screen
		CLR_SCR;

	}
	
}
