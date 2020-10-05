/*
	Made by: Tristan Franssen
*/
#include "Update_Record.h"

#include <iostream>
#include <string>

#include "../../Tools/Files/Files.h"

// updates record
Update_Record::Update_Record()
{

	// makes files object
	Files file;

	// stores new account info
	std::string Account[4];

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

	// let's user know what to do
	std::cout << "\nEnter new data\n\n";

	// lets user put in new account info
	std::cout << "Enter account number: ";
	std::cin >> Account[0];
	std::cout << "Enter first name: ";
	std::cin >> Account[1];
	std::cout << "Enter last name: ";
	std::cin >> Account[2];
	std::cout << "Enter balance: ";
	std::cin >> Account[3];

	// stores old file
	std::string Old_File = file.Read_File("res/Records/Records.txt", count * 6);

	// gets start of account
	const size_t Account_Start = Old_File.find(Choice) - 59;
	// gets end of account
	const size_t Account_End = file.Find_End(Account_Start);

	// Deletes account
	Old_File.erase(Account_Start , Account_End);

	// adds to old file
	Old_File.append((char*)"------------------------------------------\nAccount number: ");
	Old_File.append((char*)Account[0].c_str());
	Old_File.append("\nFirst name: ");
	Old_File.append((char*)Account[1].c_str());
	Old_File.append("\nLast name: ");
	Old_File.append((char*)Account[2].c_str());
	Old_File.append((char*)"\nCurrent balance: ");
	Old_File.append((char*)Account[3].c_str());
	Old_File.append((char*)"\n------------------------------------------\n");

	// writes to file
	file.Write_To_File("res/Records/Records.txt", Old_File, true);

	// waits until user want's to continue
	std::cout << "Press enter to continue . . . ";
	std::cin.get();
	std::cin.get();

}
