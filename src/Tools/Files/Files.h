/*
	Made by: Tristan Franssen
*/
#pragma once

#include <string>

class Files
{
public:

	// reads file
	std::string Read_File(std::string File_Location, int Lines);

	// writes to file
	void Write_To_File(std::string File_Location, std::string Data, bool Override);

	// searches through file for the data given to it
	std::string Search(std::string File_Location, std::string Number);

	// gets line of data
	int Find_End(int Start_Account);

};

