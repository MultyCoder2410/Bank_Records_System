/*
	Made by: Tristan Franssen
*/
#include "Menu.h"

#include <iostream>

#include "../State/Add_Record/Add_Record.h"
#include "../State/Show_Record/Show_Record.h"
#include "../State/Search_Record/Search_Record.h"
#include "../State/Update_Record/Update_Record.h"
#include "../State/Delete_Record/Delete_Record.h"
#include "../Tools/CLR_SCR.h"

// makes menu
Menu::Menu()
{

	while (true)
	{
		// shows menu
		std::cout << "***Acount Information System***\n\n";

		std::cout << "   1.Add record to file\n";
		std::cout << "   2.Show record from file\n";
		std::cout << "   3.Search record from file\n";
		std::cout << "   4.Update record\n";
		std::cout << "   5.Delete record\n";
		std::cout << "   6.Quit\n\n";

		std::cout << "Enter your choice: ";

		// stores input
		std::string Input;
		// gets input from user
		std::cin >> Input;

		// starts state
		Start_State(Input);
	}

}

// looks what state to start
void Menu::Start_State(std::string Choice)
{

	// looks what state to start
	if (Choice == "1")
	{

		// clears screen
		CLR_SCR;

		// adds record
		Add_Record add_record;

		// clears screen
		CLR_SCR;

	}
	else if (Choice == "2")
	{
		
		// clears screen
		CLR_SCR;

		// makes show record object and shows records
		Show_Record show_record;

		// clears screen
		CLR_SCR;

	}
	else if (Choice == "3")
	{

		// clears screen
		CLR_SCR;

		// makes record object and shows records
		Search_Record search_record;

		// clears screen
		CLR_SCR;

	}
	else if (Choice == "4")
	{

		// clears screen
		CLR_SCR;

		// makes and runs update records
		Update_Record update_record;

		// clears screen
		CLR_SCR;

	}
	else if (Choice == "5")
	{

		// clears screen
		CLR_SCR;

		// makes and runs delete records
		Delete_Record delete_record;

		// clears screen
		CLR_SCR;

	}
	else if (Choice == "6")
	{

		// closes program
		exit(0);

	}
	else
	{

		// clears screen
		CLR_SCR;

		// tells user invalid input
		std::cout << "\nInvalid input try again . . .";
		std::cin.get();
		std::cin.get();

		// clears screen
		CLR_SCR;

	}

}
