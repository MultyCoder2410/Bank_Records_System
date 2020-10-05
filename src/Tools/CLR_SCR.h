/*
	Made by: Tristan Franssen
*/
#pragma once

#if defined(_WIN32)
	#define CLR_SCR system("cls")
#else
	#define CLR_SCR system("clear")
#endif