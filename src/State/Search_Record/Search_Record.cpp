/*
	Made by: Tristan Franssen
*/
#include "Search_Record.h"

#include <iostream>
#include <fstream>

#include "../../Tools/Files/Files.h"

// searches for record
Search_Record::Search_Record()
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

	// searches through file and shows it
	std::cout << file.Search("res/Records/Records.txt", Choice);

	// waits until user want's to continue
	std::cout << "Press enter to continue . . . ";
	std::cin.get();
	std::cin.get();

}