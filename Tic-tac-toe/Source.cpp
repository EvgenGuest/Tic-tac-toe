//Персональный шаблон проекта С++
#include <iostream>
#include <fstream>
#include <string>
#include <conio.h>
#include <windows.h>
#include "Source.h"

using namespace std;

const int rows = 3, colums = 3;
char field[rows][colums] = {
	{' ', ' ', ' '},
	{' ', ' ', ' '},
	{' ', ' ', ' '}
};
int turn = 1;

void set_value(int X, int Y, char sym, bool& cor) {
	if (field[X][Y] == ' ') {
		field[X][Y] = sym;
		cor = true;
	}
}

void goX0(char symX0) {
	if (symX0 != 'X' && symX0 != '0')
		throw invalid_argument("not X or 0");

	char sym;
	bool correct = false;
	do {
		sym = _getch();
		switch (sym) {
		case 'Q': case 'q': set_value(0, 0, symX0, correct); break;
		case 'W': case 'w': set_value(0, 1, symX0, correct); break;
		case 'E': case 'e': set_value(0, 2, symX0, correct); break;
		case 'A': case 'a': set_value(1, 0, symX0, correct); break;
		case 'S': case 's': set_value(1, 1, symX0, correct); break;
		case 'D': case 'd': set_value(1, 2, symX0, correct); break;
		case 'Z': case 'z': set_value(2, 0, symX0, correct); break;
		case 'X': case 'x': set_value(2, 1, symX0, correct); break;
		case 'C': case 'c': set_value(2, 2, symX0, correct); break;
		default: correct = false;
		}
	} while (!correct);
	turn == 1 ? turn = 2 : turn = 1;
}

 /*
void go0() {
	char sym;
	bool correct = false;
	do {
		sym = _getch();
		switch (sym) {
		case 'Q': case 'q': set_value(0, 0, '0', correct); break;
		case 'W': case 'w': set_value(0, 1, '0', correct); break;
		case 'E': case 'e': set_value(0, 2, '0', correct); break;
		case 'A': case 'a': set_value(1, 0, '0', correct); break;
		case 'S': case 's': set_value(1, 1, '0', correct); break;
		case 'D': case 'd': set_value(1, 2, '0', correct); break;
		case 'Z': case 'z': set_value(2, 0, '0', correct); break;
		case 'X': case 'x': set_value(2, 1, '0', correct); break;
		case 'C': case 'c': set_value(2, 2, '0', correct); break;
		defualt: correct = false;
		}
	} while (!correct);
	turn = 2;
}
*/

/*void players(int turn) {
	int count = 0;
	while (count <= 8) {
		if (turn == 1) {
			goX();
			turn++;
			count++;
		}
		else {
			go0();
			turn--;
			count++;
		}
	}
}*/

/*
bool check_victory() {

}
bool check_victory();
*/

void save();
void load() {

};

bool file_exists(string path);

void print_map() {
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++)
			cout << field[i][j];
		cout << endl;
	}
}


int main() {
	setlocale(LC_ALL, "Russian");
	//int n;
	/*SYSTEMTIME date;
	GetSystemTime(&date);
	cout << "# date: " << date.wDay << "." << date.wMonth << "." << date.wYear << " " << (date.wHour + 5) << ":" << date.wMinute << endl;
	*/
	
	do {
	switch(turn) {
	case 1: goX0('X'); system("cls"); break;
	case 2: goX0('0'); system("cls"); break;
	}
	print_map();
	} while (turn != 0);

	//Задача

	return 0;
}
