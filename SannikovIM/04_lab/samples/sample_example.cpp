// ННГУ, ИИТММ, Курс "Алгоритмы и структуры данных"
//
// Copyright (c) Сысоев А.В.
//
// Тестирование матриц

#include <iostream>
#include "TMonom.h"
#include "TPolinom.h"


using namespace std;

int main() {
	//setlocale(LC_ALL, "Russian");
	char flag = 'n';
	bool isNew = 0;
	cout << "Enter Polinom:\n" << endl;
	string pol;
	cin >> pol;
	TPolinom polinom1(pol);
	while (flag != 'y' && flag != 'Y') {
		cout << endl << polinom1 << endl << endl;
		isNew = 0;
		cout << "Choose:" << endl;
		cout << "1) +" << endl;
		cout << "2) -" << endl;
		cout << "3) *" << endl;
		cout << "4) Diff" << endl;
		cout << "5) Change Polinom" << endl;
		cout << "6) Exit" << endl;
		int n;
		int a;
		cin >> n;
		switch (n) {
		case 1:
			cout << "Choose:" << endl;
			cout << "1) + Monom" << endl;
			cout << "2) + Polinom" << endl;
			cout << "3) Exit" << endl;
			cin >> a;
			switch (a) {
			case 1:
			{
				cout << "Monom:\n" << endl;
				string d;
				cin >> d;
				TMonom m(d);
				polinom1 = polinom1 + m;
				cout << polinom1 << endl << endl;
				break;
			}
			case 2:
			{
				cout << "Polinom:\n" << endl;
				cin >> pol;
				TPolinom polinom2(pol);
				polinom1 = polinom1 + polinom2;
				cout << polinom1 << endl << endl;
				break;
			}
			default:
				break;

			}
			break;

		case 2:
			cout << "Choose:" << endl;
			cout << "1) - Monom" << endl;
			cout << "2) - Polinom" << endl;
			cout << "3) Exit" << endl;
			cin >> a;
			switch (a) {
			case 1:
			{
				cout << "Monom:\n" << endl;
				string d;
				cin >> d;
				TMonom m(d);
				polinom1 = polinom1 - m;
				cout << polinom1 << endl << endl;
				break;
			}
			case 2:
			{
				cout << "Polinom:\n" << endl;
				cin >> pol;
				TPolinom polinom2(pol);
				polinom1 = polinom1 - polinom2;
				cout << polinom1 << endl << endl;
				break;
			}
			default:
				break;

			}
			break;
		case 3:
			cout << "Choose:" << endl;
			cout << "1) * Integer" << endl;
			cout << "2) * Monom" << endl;
			cout << "3) * Polinom" << endl;
			cout << "4) Exit" << endl;
			cin >> a;
			switch (a) {
			case 1: {
				cout << "Integer:\n" << endl;
				int d;
				cin >> d;

				polinom1 = polinom1 * d;
				cout << polinom1 << endl << endl;
				break;
			}
			case 2:
			{
				cout << "Monom\n" << endl;
				string d;
				cin >> d;
				TMonom m(d);
				polinom1 = polinom1 * m;
				cout << polinom1 << endl << endl;
				break;
			}
			case 3:
			{
				cout << "Polinom:\n" << endl;
				cin >> pol;
				TPolinom polinom2(pol);
				polinom1 = polinom1 * polinom2;
				cout << polinom1 << endl << endl;
				break;
			}
			default:
				break;

			}
			break;
		case 4:
			cout << "Choose:" << endl;
			cout << "1) X" << endl;
			cout << "2) Y" << endl;
			cout << "3) Z" << endl;
			cout << "4) Exit" << endl;
			cin >> a;
			switch (a) {
			case 1: {
				polinom1.DiffX();
				cout << polinom1 << endl << endl;
				break;
			}
			case 2:
			{
				polinom1.DiffY();
				cout << polinom1 << endl << endl;
				break;
			}
			case 3:
			{
				polinom1.DiffZ();
				cout << polinom1 << endl << endl;
				break;
			}
			default:
				break;

			}
			break;

		case 5: {
			cout << "Enter new Polinom:\n" << endl;
			cin >> pol;
			TPolinom polinom2(pol);
			polinom1 = polinom2;
			isNew = 1;
		}
			  break;
		case 6:
			isNew = 1;
			flag = 'y';
			break;
		}
		if (isNew == 0) {
			cout << "Exit?" << endl;
			cout << "(Yes - y, No - n): ";
			cin >> flag;
		}
	}
}
