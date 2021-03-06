// PPProjektKolokwium1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

struct pomiary
{
	string nazwa;
	string id;
	float pomiar;
};


void readFile(string fname, vector <pomiary> &tab, int size)
{
	short num = 0;
	string line;
	stringstream ss;
	float number;
	float x;
	int nr_linii = 1;
	
	ifstream file(fname);
	if (file.is_open())
	{
		while (getline(file, line))
		{
			switch (nr_linii)
			{
			case 1: tab[num].nazwa = line;  break;
			case 2: tab[num].id = line; break;
			case 3: x = 0;
				ss.clear();
				ss.str(line);
				while (!ss.eof())
				{
					ss >> number;
					tab[num].pomiar += number;

					x++;
				}
				tab[num].pomiar = tab[num].pomiar / x; break;
			}
			nr_linii++;
			if (nr_linii > 3)
			{
				nr_linii = 1;
				num++;
			}
		}
	}

	file.close();
}

void writeToFile(string fname, vector <pomiary> tab)
{
	ofstream file(fname);

	if (file.is_open())
	{
		for (int i = 0; i < tab.size(); i++)
		{
			file << tab[i].nazwa << endl;
			file << tab[i].id << endl;
			file << tab[i].pomiar << endl;
		}
	}

	file.close();
}


int main()

{
	vector <pomiary> tab(2);
	readFile("pomiary.txt", tab, 2);
	writeToFile("sredniapomiaru.txt", tab);
}