// ННГУ, ИИТММ, Курс "Алгоритмы и структуры данных"
//
// Copyright (c) Сысоев А.В.
//
// Тестирование матриц

#include <iostream>
#include "TMonom.h"
#include "TPolinom.h"
#include "ScanTable.h"
#include "SortedTable.h"
#include "ArrayHashTable.h"
#include "ListHashTable.h"
using namespace std;
void PolinomOperation(TPolinom polinom1) {
	char flag = 'n';
	bool isNew = 0;
	string pol;
	while (flag != 'y' && flag != 'Y') {
		isNew = 0;
		cout << "Choose:" << endl;
		cout << "1) +" << endl;
		cout << "2) -" << endl;
		cout << "3) *" << endl;
		cout << "4) Diff" << endl;
		cout << "5) Change Polinom" << endl;
		cout << "6) Calculate Polinom" << endl;
		cout << "7) Exit" << endl;
		int n;
		int a;
		cin >> n;
		switch (n) {
		case 1:
			cout << "Choose:" << endl;
			cout << "1) + Scalar" << endl;
			cout << "2) + Monom" << endl;
			cout << "3) + Polinom" << endl;
			cout << "4) Exit" << endl;
			cin >> a;
			switch (a) {
			case 1:
			{
				cout << "Scalar:\n" << endl;
				double x;
				cin >> x;
				polinom1 = polinom1 + x;
				cout << polinom1 << endl << endl;
				break;
			}
			case 2:
			{
				cout << "Monom:\n" << endl;
				string d;
				cin >> d;
				TMonom m(d);
				polinom1 = polinom1 + m;
				cout << polinom1 << endl << endl;
				break;
			}
			case 3:
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
			cout << "1) - Scalar" << endl;
			cout << "2) - Monom" << endl;
			cout << "3) - Polinom" << endl;
			cout << "4) Exit" << endl;
			cin >> a;
			switch (a) {
			case 1:
			{
				cout << "Scalar:\n" << endl;
				double x;
				cin >> x;
				polinom1 = polinom1 - x;
				cout << polinom1 << endl << endl;
				break;
			}
			case 2:
			{
				cout << "Monom:\n" << endl;
				string d;
				cin >> d;
				TMonom m(d);
				polinom1 = polinom1 - m;
				cout << polinom1 << endl << endl;
				break;
			}
			case 3:
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
				TPolinom p = polinom1.DiffX();
				cout << p << endl << endl;
				break;
			}
			case 2:
			{
				TPolinom p = polinom1.DiffY();
				cout << p << endl << endl;
				break;
			}
			case 3:
			{
				TPolinom p = polinom1.DiffZ();
				cout << p << endl << endl;
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
		{
			double x, y, z;
			cout << "X = ";
			cin >> x;
			cout << "Y = ";
			cin >> y;
			cout << "Z = ";
			cin >> z;
			cout << "Result: " << polinom1(x, y, z) << endl;
		}
		break;
		case 7:
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


int main() {
	int sz;
	try {
		cout << "Enter table's size: " << endl;
		cin >> sz;
	}
	catch (const char* error_message) {
		return 0;
	}
	ScanTable<string, TPolinom> scanTable(sz);
	SortedTable<string, TPolinom> sortedTable(sz);
	ArrayHashTable<string, TPolinom> arrayHashTable(sz, 5);
	ListHashTable<string, TPolinom> listHashTable(sz);
	//setlocale(LC_ALL, "Russian");
	char flag = 'n';
	bool isNew = 0;

	//cout << "Enter Polinom:\n" << endl;
	//string pol;
	//cin >> pol;
	//TPolinom polinom1(pol);
	while (flag != 'y' && flag != 'Y') {
		int id;
		//cout << endl << polinom1 << endl << endl;
		cout << "Choose table:" << endl;
		cout << "1) Scan Table" << endl;
		cout << "2) Sorted Table" << endl;
		cout << "3) Array Hash Table" << endl;
		cout << "4) List Hash Table" << endl;
		isNew = 0;
		/*cout << "Choose:" << endl;
		cout << "1) +" << endl;
		cout << "2) -" << endl;
		cout << "3) *" << endl;
		cout << "4) Diff" << endl;
		cout << "5) Change Polinom" << endl;
		cout << "6) Calculate Polinom" << endl;
		cout << "7) Exit" << endl;*/
		int n;
		int a;
		cin >> n;
		switch (n) {
		case 1:
			cout << "Choose:" << endl;
			cout << "1) Insert" << endl;
			cout << "2) Get" << endl;
			cout << "3) Remove" << endl;
			cout << "4) See Table" << endl;
			cout << "5) Exit" << endl;
			cin >> a;
			switch (a) {
			case 1:
			{

				cout << "Enter Polinom:\n" << endl;
				string polin;
				cin >> polin;
				TPolinom pol(polin);
				scanTable.Insert(pol.GetIdPol(), pol);
				break;
			}
			case 2:
			{
				cout << "Enter Polinom:\n" << endl;
				string polin;
				cin >> polin;
				TPolinom pol(polin);
				TabRecord<string, TPolinom>* s = scanTable.Find(pol.GetIdPol());
				if (s == nullptr) {
					cout << "Not find" << endl;
					break;
				}
				PolinomOperation(s->pData);
				break;
			}
			case 3:
			{

				cout << "Enter Polinom:\n" << endl;
				string polin;
				cin >> polin;
				TPolinom pol(polin);
				scanTable.Remove(pol.GetIdPol());
				break;
			}
			case 4:
			{
				scanTable.Reset();
				cout << "\n" << endl;
					while (!scanTable.IsTabEnden()) {
						cout << scanTable.GetCurrent()->pData.GetIdPol() << endl;
						scanTable.Next();
					}
				cout << "\n" << endl;
				break;
			}
			default:
				break;

			}
			break;

		case 2:
			cout << "Choose:" << endl;
			cout << "1) Insert" << endl;
			cout << "2) Get" << endl;
			cout << "3) Remove" << endl;
			cout << "4) See Table" << endl;
			cout << "5) Exit" << endl;
			cin >> a;
			switch (a) {
			case 1:
			{

				cout << "Enter Polinom:\n" << endl;
				string polin;
				cin >> polin;
				TPolinom pol(polin);
				sortedTable.Insert(pol.GetIdPol(), pol);
				break;
			}
			case 2:
			{
				cout << "Enter Polinom:\n" << endl;
				string polin;
				cin >> polin;
				TPolinom pol(polin);
				TabRecord<string, TPolinom>* s = sortedTable.Find(pol.GetIdPol());
				if (s == nullptr) {
					cout << "Not find" << endl;
					break;
				}
				PolinomOperation(s->pData);
				break;
			}
			case 3:
			{

				cout << "Enter Polinom:\n" << endl;
				string polin;
				cin >> polin;
				TPolinom pol(polin);
				sortedTable.Remove(pol.GetIdPol());
				break;
			}
			case 4:
			{
				sortedTable.Reset();
				cout << "\n" << endl;
				while (!sortedTable.IsTabEnden()) {
					cout << sortedTable.GetCurrent()->pData.GetIdPol() << endl;
					sortedTable.Next();
				}
				cout << "\n" << endl;
				break;
			}
			default:
				break;

			}
			break;
		case 3:
			cout << "Choose:" << endl;
			cout << "1) Insert" << endl;
			cout << "2) Get" << endl;
			cout << "3) Remove" << endl;
			cout << "4) See Table" << endl;
			cout << "5) Exit" << endl;
			cin >> a;
			switch (a) {
			case 1:
			{

				cout << "Enter Polinom:\n" << endl;
				string polin;
				cin >> polin;
				TPolinom pol(polin);
				arrayHashTable.Insert(pol.GetIdPol(), pol);
				break;
			}
			case 2:
			{
				cout << "Enter Polinom:\n" << endl;
				string polin;
				cin >> polin;
				TPolinom pol(polin);
				TabRecord<string, TPolinom>* s = arrayHashTable.Find(pol.GetIdPol());
				if (s == nullptr) {
					cout << "Not find" << endl;
					break;
				}
				PolinomOperation(s->pData);
				break;
			}
			case 3:
			{

				cout << "Enter Polinom:\n" << endl;
				string polin;
				cin >> polin;
				TPolinom pol(polin);
				scanTable.Remove(pol.GetIdPol());
				break;
			}
			case 4:
			{
				arrayHashTable.Reset();
				cout << "\n" << endl;
				while (!arrayHashTable.IsTabEnden()) {
					cout << arrayHashTable.GetCurrent()->pData.GetIdPol() << endl;
					arrayHashTable.Next();
				}
				cout << "\n" << endl;
				break;
			}
			default:
				break;

			}
			break;
		case 4:
			cout << "Choose:" << endl;
			cout << "1) Insert" << endl;
			cout << "2) Get" << endl;
			cout << "3) Remove" << endl;
			cout << "4) See Table" << endl;
			cout << "5) Exit" << endl;
			cin >> a;
			switch (a) {
			case 1:
			{

				cout << "Enter Polinom:\n" << endl;
				string polin;
				cin >> polin;
				TPolinom pol(polin);
				listHashTable.Insert(pol.GetIdPol(), pol);
				break;
			}
			case 2:
			{
				cout << "Enter Polinom:\n" << endl;
				string polin;
				cin >> polin;
				TPolinom pol(polin);
				TabRecord<string, TPolinom>* s = listHashTable.Find(pol.GetIdPol());
				if (s == nullptr) {
					cout << "Not find" << endl;
					break;
				}
				PolinomOperation(s->pData);
				break;
			}
			case 3:
			{

				cout << "Enter Polinom:\n" << endl;
				string polin;
				cin >> polin;
				TPolinom pol(polin);
				listHashTable.Remove(pol.GetIdPol());
				break;
			}
			case 4:
			{
				listHashTable.Reset();
				cout << "\n" << endl;
				while (!listHashTable.IsTabEnden()) {
					cout << listHashTable.GetCurrent()->pData.GetIdPol() << endl;
					listHashTable.Next();
				}
				cout << "\n" << endl;
				break;
			}
			default:
				break;

			}
			break;


		}
	}
}
