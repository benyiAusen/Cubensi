#include <fstream>
#include <iostream>
#include <locale>
#include <random>
#include <sstream>
#include <string>
#include <vector>

std::random_device rd; 
std::mt19937 eng(rd()); 
std::uniform_int_distribution<int> dis(0, 4);
std::vector<std::string> dict = {"U","D","L","R","F"};
std::string use_advanced_notation = "n";
std::string destination = "c";
int perms = 15;
const int p_max = 400;

inline void scramble(bool &_an, bool &_ds, int &perms)
{
	if (_an == true)
	{
		dis = std::uniform_int_distribution<int>(0, 8);
		dict.push_back("M");
		dict.push_back("E");
		dict.push_back("S");
		dict.push_back("B");
	}

	if (_ds == false)
	{
		std::string pause; 
		std::cout << "Algoritmo generado por Cubensi 1.0:\n";
		for (int i = 0; i < perms; ++i)
		{
			std::cout << dict[dis(eng)];
			if (i < perms - 1)
			{
				std::cout << ", ";
			}
		}
		std::getline(std::cin, pause);
	}

	else
	{
		std::ofstream gen;
		gen.open("algoritmo.txt");
		gen << "Algoritmo generado por Cubensi 1.0:\n";
		for (int i = 0; i < perms; ++i)
		{
			gen << dict[dis(eng)];
			if (i < perms - 1)
			{
				gen << ", ";
			}
		}
		gen.close();
	}
}
int main()
{
	setlocale(LC_ALL, "SPANISH");
	std::string input;
	std::cout << "\n";
	std::cout << "          LLLLL  L   L  LLL   LLLLL  L   L  LLLLL  L           /   /|\n"
			     "          L      L   L  L  L  L      LL  L  L      L          /___/ |\n"
			     "          L      L   L  LLL   LLLLL  L L L  LLLLL  L          |LLL| |\n"
			 	 "          L      L   L  L  L  L      L  LL      L  L          |LLL| /\n"
			 	 "          LLLLL  LLLLL  LLL   LLLLL  L   L  LLLLL  L          |LLL|/ \n          versión 1.0 y weá\n";
	
	std::cout << "\n¿Cuántas permutaciones quieres? ";
	std::getline(std::cin, input);
	std::stringstream(input) >> perms;
	std::cout << "\n¿Quieres los movimientos avanzados M/E/S/B? (S/N) ";
	std::getline(std::cin, input);
	std::stringstream(input) >> use_advanced_notation;
	std::cout << "\n¿Quieres dejar el algoritmo en un archivo o en la consola? (A/C) ";
	std::getline(std::cin, input);
	std::stringstream(input) >> destination;

	if (perms > p_max)
	{
		perms = p_max;
	}

	else if (perms < 0)
	{
		perms = abs(perms);
	}

	bool _an, _ds;
	switch (use_advanced_notation.at(0))
	{
	case 's':
	case 'S':
		_an = true;
		break;
	case 'n':
	case 'N':
	default:
		_an = false;
		break;
	}
	switch (destination.at(0))
	{
	case 'a':
	case 'A':
		_ds = true;
		break;
	case 'c':
	case 'C':
	default:
		_ds = false;
		break;
	}
	scramble(_an, _ds, perms);
	return 0;
}
