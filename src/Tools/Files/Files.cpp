/*
	Made by: Tristan Franssen
*/
#include "Files.h"

#include <iostream>
#include <fstream>

// reads file
std::string Files::Read_File(std::string File_Location, int Lines)
{

	// reads file
	std::ifstream Reader(File_Location, std::ios::binary);

	// looks if can open file
	if (!Reader)
	{

		// tells user can't open file
		std::cout << "Can't open file . . .\n";
		std::cin.get();
		std::cin.get();
		// exits
		exit(-1);

	}

	// stores file
	std::string File;
	// line storage
	std::string Line;

	// gets lines
	for (int i = 0; i < Lines; i++)
	{
		
		// gets line
		getline(Reader, Line);
		// gives line to file
		File += Line + '\n';

	}


	// closes file
	Reader.close();

	// returns file
	return File;

}

// writes to file
void Files::Write_To_File(std::string File_Location, std::string Data, bool Override)
{

	// makes writer
	std::ofstream Writer;

	// looks if you want to override the data
	if (Override)
	{

		// opens file with writer
		Writer.open(File_Location, std::ios::binary);

	}
	else
	{

		// opens file with writer
		Writer.open(File_Location, std::ios::binary|std::ios_base::app);

	}

	// looks if can open file
	if (!Writer)
	{

		// tells user can't open file
		std::cout << "Can't open file . . .\n";
		std::cin.get();
		std::cin.get();
		// exits
		exit(-1);

	}

	// writes to file
	Writer << Data;

	// closes writer
	Writer.close();

}


// searches through file for the data given to it
std::string Files::Search(std::string File_Location, std::string Number)
{

	// reads file
	std::ifstream Reader(File_Location, std::ios::binary);

	// looks if can open file
	if (!Reader)
	{

		// tells user can't open file
		std::cout << "Can't open file . . .\n";
		std::cin.get();
		std::cin.get();
		// exits
		exit(-1);

	}

	// stores account info
	std::string Account;
	// stores lines
	std::string Lines;


	// goes through all the lines
	while (getline(Reader, Lines))
	{

		// looks if account has been found else continues
		if (Lines == "Account number: " + Number)
		{

			// add's line to make it look nicer
			Account += "------------------------------------------\n";

			// gets current line
			Account += Lines + "\n";

			// gets all lines for account info
			for (int i = 0; i < 4; i++)
			{

				// gets line
				getline(Reader, Lines);

				// add's line to end result
				Account += Lines + "\n";

			}

			// stops loop
			break;

		}

	}

	// closes file
	Reader.close();

	// returns file
	return Account;

}

// gets line of data
int Files::Find_End(int Start_Account)
{

	// reads file
	std::ifstream Reader("res/Records/Records.txt", std::ios::binary);

	// looks if can open file
	if (!Reader)
	{

		// tells user can't open file
		std::cout << "Can't open file . . .\n";
		std::cin.get();
		std::cin.get();
		// exits
		exit(-1);

	}

	char Char;

	// counts amount of lines
	int Char_Amount = 0;

	// goes through all the lines
	while (Reader.get(Char))
	{
		
		// looks if account has been found else continues
		if (Char_Amount >= Start_Account + 43 && Char == '-')
		{

			break;

		}

		// adds to lines 
		Char_Amount++;

	}

	// closes file
	Reader.close();

	// returns file
	return Char_Amount + 43;

}