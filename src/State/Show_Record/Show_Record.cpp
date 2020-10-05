/*
	Made by: Tristan Franssen
*/
#include "Show_Record.h"

#include <iostream>

#include "../../Tools/Files/Files.h"

// gets all records
Show_Record::Show_Record()
{

	// makes file object
	Files file;

	// gets amount of lines
	int Lines = std::stoi(file.Read_File("res/Lines.txt", 1));

	// gets file info
	std::string Records = file.Read_File("res/Records/Records.txt", Lines);

	// shows records
	std::cout << Records;

	// waits until user wants to continue
	std::cout << "\nPress Enter to continue . . . ";
	std::cin.get();
	std::cin.get();

}
