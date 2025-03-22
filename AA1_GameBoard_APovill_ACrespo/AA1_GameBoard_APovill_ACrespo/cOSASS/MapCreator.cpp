#include <iostream>
#include <cstdio>
#include <fstream>
#include "Header.h"
using namespace std;

void InitializeRowsCols(int& rows, int& cols)
{
	int aux, i = 0;
	ifstream SetupFile("Initialize.txt");
	if (SetupFile.is_open())
	{
		while (SetupFile >> aux)
		{
			if (i == 0)
				rows = aux;
			else
				cols = aux;
			i++;
		}
		cout << "Cols: " << cols << " Rows: " << rows << endl;
	}
	else
		cout << "Unable to open file";
}

void InitializeMap(mapElem**& map, int& rows, int& cols, int& pinchos, int& gems)
{
	map = new mapElem* [rows];
	for (int i = 0; i < cols; ++i) {
		map[i] = new mapElem[cols];
	}

	int totalSquares = rows * cols;
	pinchos = totalSquares / 10;
	gems = totalSquares / 4;

	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			if (j == 0 || j == cols - 1 || i == 0 || i == rows - 1)
			{
				map[i][j] = PARED;
			}
			else
			{
				map[i][j] = LIBRE;
			}	
		}
	}

	for (int i = 0; i < pinchos; i++)
	{
		int b, a;
		do
		{
			a = RandomRange(1, rows - 2);
			b = RandomRange(1, cols - 2);
		} while (map[a][b] != LIBRE);
		map[a][b] = PINCHO;
	}

	for (int i = 0; i < gems; i++)
	{
		int b, a;
		do
		{
			a = RandomRange(1, rows - 1);
			b = RandomRange(1, cols - 1);
		} while (map[a][b] != LIBRE);
		map[a][b] = GEMA;
	}
}

int RandomRange(int min, int max)
{
	return (rand() + min) % max;
}

void DrawMap(mapElem** map, int rows, int cols)
{
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			switch (map[i][j])
			{
			case PINCHO:
				cout << " M ";
				break;
			case GEMA:
				cout << " G ";
				break;
			case PARED:
				cout << " [ ";
				break;
			case LIBRE:
				cout << "   ";
				break;
			default:
				break;
			}
		}
		cout << endl;
	}
}

void DeleteMap(mapElem** map, int rows)
{
	for (int i = 0; i < rows; i++)
	{
		delete[] map[i];
	}
	delete[] map;
	map = nullptr;
}

void main()
{
	srand(time(NULL));
	int rows, cols, pinchos_num, gems_num;
	InitializeRowsCols(rows, cols);
	mapElem** map = new mapElem * [rows];
	InitializeMap(map, rows, cols, pinchos_num, gems_num);
	DrawMap(map, rows, cols);
	DeleteMap(map, rows);
}
