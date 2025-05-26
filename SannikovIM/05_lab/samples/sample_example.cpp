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
using namespace std;

TPolinom GetPolinomFromTable(ScanTable<string, TPolinom>& s1, SortedTable<string, TPolinom>& s2, ArrayHashTable<string, TPolinom>& s3){
    cout << "Choose table:" << endl;
    cout << "1) Scan Table" << endl;
    cout << "2) Sorted Table" << endl;
    cout << "3) Array Hash Table" << endl;
    int f;
    cin>>f;
    switch(f){
        case 1:{
            s1.Reset();
            cout << "\n" << endl;
            while (!s1.IsTabEnden()) {
                cout << s1.GetCurrent()->pData.GetIdPol() << endl;
                s1.Next();
            }
            cout << "\n" << endl;
            cout<<"Enter Polinom"<<endl;
            string s;
            cin>>s;
            while(s1.Find(s) == nullptr){
                cout<<"Can't find this polinom"<<endl;
                cout<<"Enter Polinom"<<endl;
                cin>>s;
            }
            TPolinom a(s);
            return a;
            break;
        }
        case 2:{
            s2.Reset();
            cout << "\n" << endl;
            while (!s2.IsTabEnden()) {
                cout << s1.GetCurrent()->pData.GetIdPol() << endl;
                s2.Next();
            }
            cout<<"Enter Polinom"<<endl;
            string s;
            cin>>s;
            while(s2.Find(s) == nullptr){
                cout<<"Can't find this polinom \n"<<endl;
                cout<<"Enter Polinom"<<endl;
                cin>>s;
            }
            TPolinom a(s);
            return a;
            break;
        }
        case 3:{
            s3.Reset();
            cout << "\n" << endl;
            while (!s3.IsTabEnden()) {
                cout << s3.GetCurrent()->pData.GetIdPol() << endl;
                s3.Next();
            }
            cout<<"Enter Polinom"<<endl;
            string s;
            cin>>s;
            while(s3.Find(s) == nullptr){
                cout<<"Can't find this polinom \n"<<endl;
                cout<<"Enter Polinom"<<endl;
                cin>>s;
            }
            TPolinom a(s);
            return a;
            break;
        }
        default:{
            cout<<"Incorrect operationon\n"<<endl;
        }
    }
}


void PolinomOperation(TPolinom polinom1, ScanTable<string, TPolinom>& s1, SortedTable<string, TPolinom>& s2, ArrayHashTable<string, TPolinom>& s3, int flag1) {
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
		char yy;
		char yyn;
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
				TPolinom polinom2 = polinom1 + x;
				cout << polinom2 << endl << endl;
				cout << "Save?" << endl;
				cin >> yy;
				if (yy == 'y') {
					cout << "Save as new?" << endl;
					cin >> yyn;
					if (yyn == 'y') {
						switch (flag1) {
						case 1:
						{
							s1.Insert(polinom2.GetIdPol(), polinom2);
							break;
						}
						case 2:
						{
							s2.Insert(polinom2.GetIdPol(), polinom2);
							break;
						}
						case 3:
						{
							s3.Insert(polinom2.GetIdPol(), polinom2);
							break;
						}
						}
					}
					else if (yyn == 'n') {
						switch (flag1) {
						case 1:
						{
							s1.Remove(polinom1.GetIdPol());
							s1.Insert(polinom2.GetIdPol(), polinom2);
							break;
						}
						case 2:
						{
							s2.Remove(polinom1.GetIdPol());
							s2.Insert(polinom2.GetIdPol(), polinom2);
							break;
						}
						case 3:
						{
							s3.Remove(polinom1.GetIdPol());
							s3.Insert(polinom2.GetIdPol(), polinom2);
							break;
						}
						
						}
					}
				}
				break;
			}
			case 2:
			{
				cout << "Monom:\n" << endl;
				string d;
				cin >> d;
				TMonom m(d);
				TPolinom polinom2 = polinom1 + m;
				cout << polinom2 << endl << endl;
				cout << "Save?" << endl;
				cin >> yy;
				if (yy == 'y') {
					cout << "Save as new?" << endl;
					cin >> yyn;
					if (yyn == 'y') {
						switch (flag1) {
						case 1:
						{
							s1.Insert(polinom2.GetIdPol(), polinom2);
							break;
						}
						case 2:
						{
							s2.Insert(polinom2.GetIdPol(), polinom2);
							break;
						}
						case 3:
						{
							s3.Insert(polinom2.GetIdPol(), polinom2);
							break;
						}
						
						}
					}
					else if (yyn == 'n') {
						switch (flag1) {
						case 1:
						{
							s1.Remove(polinom1.GetIdPol());
							s1.Insert(polinom2.GetIdPol(), polinom2);
							break;
						}
						case 2:
						{
							s2.Remove(polinom1.GetIdPol());
							s2.Insert(polinom2.GetIdPol(), polinom2);
							break;
						}
						case 3:
						{
							s3.Remove(polinom1.GetIdPol());
							s3.Insert(polinom2.GetIdPol(), polinom2);
							break;
						}
						}
					}
					break;
				}
			}
			case 3:
			{
                TPolinom polinom3 = GetPolinomFromTable(s1, s2, s3);
				TPolinom polinom2 = polinom1 + polinom3;
				cout << polinom2 << endl << endl;
				cout << "Save?" << endl;
				cin >> yy;
				if (yy == 'y') {
					cout << "Save as new?" << endl;
					cin >> yyn;
					if (yyn == 'y') {
						switch (flag1) {
						case 1:
						{
							s1.Insert(polinom2.GetIdPol(), polinom2);
							break;
						}
						case 2:
						{
							s2.Insert(polinom2.GetIdPol(), polinom2);
							break;
						}
						case 3:
						{
							s3.Insert(polinom2.GetIdPol(), polinom2);
							break;
						}
						}
					}
					else if (yyn == 'n') {
						switch (flag1) {
						case 1:
						{
							s1.Remove(polinom1.GetIdPol());
							s1.Insert(polinom2.GetIdPol(), polinom2);
							break;
						}
						case 2:
						{
							s2.Remove(polinom1.GetIdPol());
							s2.Insert(polinom2.GetIdPol(), polinom2);
							break;
						}
						case 3:
						{
							s3.Remove(polinom1.GetIdPol());
							s3.Insert(polinom2.GetIdPol(), polinom2);
							break;
						}
						}
					}
					break;
				}

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
				TPolinom polinom2 = polinom1 - x;
				cout << polinom2 << endl << endl;
				cout << "Save?" << endl;
				cin >> yy;
				if (yy == 'y') {
					cout << "Save as new?" << endl;
					cin >> yyn;
					if (yyn == 'y') {
						switch (flag1) {
						case 1:
						{
							s1.Insert(polinom2.GetIdPol(), polinom2);
							break;
						}
						case 2:
						{
							s2.Insert(polinom2.GetIdPol(), polinom2);
							break;
						}
						case 3:
						{
							s3.Insert(polinom2.GetIdPol(), polinom2);
							break;
						}
						}
					}
					else if (yyn == 'n') {
						switch (flag1) {
						case 1:
						{
							s1.Remove(polinom1.GetIdPol());
							s1.Insert(polinom2.GetIdPol(), polinom2);
							break;
						}
						case 2:
						{
							s2.Remove(polinom1.GetIdPol());
							s2.Insert(polinom2.GetIdPol(), polinom2);
							break;
						}
						case 3:
						{
							s3.Remove(polinom1.GetIdPol());
							s3.Insert(polinom2.GetIdPol(), polinom2);
							break;
						}
						}
					}
					break;
				}
			}
			case 2:
			{
				cout << "Monom:\n" << endl;
				string d;
				cin >> d;
				TMonom m(d);
				TPolinom polinom2 = polinom1 - m;
				cout << polinom2 << endl << endl;
				cout << "Save?" << endl;
				cin >> yy;
				if (yy == 'y') {
					cout << "Save as new?" << endl;
					cin >> yyn;
					if (yyn == 'y') {
						switch (flag1) {
						case 1:
						{
							s1.Insert(polinom2.GetIdPol(), polinom2);
							break;
						}
						case 2:
						{
							s2.Insert(polinom2.GetIdPol(), polinom2);
							break;
						}
						case 3:
						{
							s3.Insert(polinom2.GetIdPol(), polinom2);
							break;
						}
						}
					}
					else if (yyn == 'n') {
						switch (flag1) {
						case 1:
						{
							s1.Remove(polinom1.GetIdPol());
							s1.Insert(polinom2.GetIdPol(), polinom2);
							break;
						}
						case 2:
						{
							s2.Remove(polinom1.GetIdPol());
							s2.Insert(polinom2.GetIdPol(), polinom2);
							break;
						}
						case 3:
						{
							s3.Remove(polinom1.GetIdPol());
							s3.Insert(polinom2.GetIdPol(), polinom2);
							break;
						}
						}
					}
					break;
				}
			}
			case 3:
			{
                TPolinom polinom3 = GetPolinomFromTable(s1, s2, s3);
				TPolinom polinom2 = polinom1 - polinom3;
				cout << polinom2 << endl << endl;
				cout << "Save?" << endl;
				cin >> yy;
				if (yy == 'y') {
					cout << "Save as new?" << endl;
					cin >> yyn;
					if (yyn == 'y') {
						switch (flag1) {
						case 1:
						{
							s1.Insert(polinom2.GetIdPol(), polinom2);
							break;
						}
						case 2:
						{
							s2.Insert(polinom2.GetIdPol(), polinom2);
							break;
						}
						case 3:
						{
							s3.Insert(polinom2.GetIdPol(), polinom2);
							break;
						}
						}
					}
					else if (yyn == 'n') {
						switch (flag1) {
						case 1:
						{
							s1.Remove(polinom1.GetIdPol());
							s1.Insert(polinom2.GetIdPol(), polinom2);
							break;
						}
						case 2:
						{
							s2.Remove(polinom1.GetIdPol());
							s2.Insert(polinom2.GetIdPol(), polinom2);
							break;
						}
						case 3:
						{
							s3.Remove(polinom1.GetIdPol());
							s3.Insert(polinom2.GetIdPol(), polinom2);
							break;
						}
						}
					}
					break;
				}
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

				TPolinom polinom2 = polinom1 * d;
				cout << polinom2 << endl << endl;
				cout << "Save?" << endl;
				cin >> yy;
				if (yy == 'y') {
					cout << "Save as new?" << endl;
					cin >> yyn;
					if (yyn == 'y') {
						switch (flag1) {
						case 1:
						{
							s1.Insert(polinom2.GetIdPol(), polinom2);
							break;
						}
						case 2:
						{
							s2.Insert(polinom2.GetIdPol(), polinom2);
							break;
						}
						case 3:
						{
							s3.Insert(polinom2.GetIdPol(), polinom2);
							break;
						}
						}
					}
					else if (yyn == 'n') {
						switch (flag1) {
						case 1:
						{
							s1.Remove(polinom1.GetIdPol());
							s1.Insert(polinom2.GetIdPol(), polinom2);
							break;
						}
						case 2:
						{
							s2.Remove(polinom1.GetIdPol());
							s2.Insert(polinom2.GetIdPol(), polinom2);
							break;
						}
						case 3:
						{
							s3.Remove(polinom1.GetIdPol());
							s3.Insert(polinom2.GetIdPol(), polinom2);
							break;
						}
						}
					}
					break;
				}
			}
			case 2:
			{
				cout << "Monom\n" << endl;
				string d;
				cin >> d;
				TMonom m(d);
				TPolinom polinom2 = polinom1 * m;
				cout << polinom2 << endl << endl;
				cout << "Save?" << endl;
				cin >> yy;
				if (yy == 'y') {
					cout << "Save as new?" << endl;
					cin >> yyn;
					if (yyn == 'y') {
						switch (flag1) {
						case 1:
						{
							s1.Insert(polinom2.GetIdPol(), polinom2);
							break;
						}
						case 2:
						{
							s2.Insert(polinom2.GetIdPol(), polinom2);
							break;
						}
						case 3:
						{
							s3.Insert(polinom2.GetIdPol(), polinom2);
							break;
						}
						}
					}
					else if (yyn == 'n') {
						switch (flag1) {
						case 1:
						{
							s1.Remove(polinom1.GetIdPol());
							s1.Insert(polinom2.GetIdPol(), polinom2);
							break;
						}
						case 2:
						{
							s2.Remove(polinom1.GetIdPol());
							s2.Insert(polinom2.GetIdPol(), polinom2);
							break;
						}
						case 3:
						{
							s3.Remove(polinom1.GetIdPol());
							s3.Insert(polinom2.GetIdPol(), polinom2);
							break;
						}
						}
					}
					break;
				}
			}
			case 3:
			{
                TPolinom polinom3 = GetPolinomFromTable(s1, s2, s3);
				TPolinom polinom2 = polinom1 * polinom3;
				cout << polinom2 << endl << endl;
				cout << "Save?" << endl;
				cin >> yy;
				if (yy == 'y') {
					cout << "Save as new?" << endl;
					cin >> yyn;
					if (yyn == 'y') {
						switch (flag1) {
						case 1:
						{
							s1.Insert(polinom2.GetIdPol(), polinom2);
							break;
						}
						case 2:
						{
							s2.Insert(polinom2.GetIdPol(), polinom2);
							break;
						}
						case 3:
						{
							s3.Insert(polinom2.GetIdPol(), polinom2);
							break;
						}
						}
					}
					else if (yyn == 'n') {
						switch (flag1) {
						case 1:
						{
							s1.Remove(polinom1.GetIdPol());
							s1.Insert(polinom2.GetIdPol(), polinom2);
							break;
						}
						case 2:
						{
							s2.Remove(polinom1.GetIdPol());
							s2.Insert(polinom2.GetIdPol(), polinom2);
							break;
						}
						case 3:
						{
							s3.Remove(polinom1.GetIdPol());
							s3.Insert(polinom2.GetIdPol(), polinom2);
							break;
						}
						}
					}
					break;
				}
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
				TPolinom polinom2 = polinom1.DiffX();
				cout << polinom2 << endl << endl;
				cout << "Save?" << endl;
				cin >> yy;
				if (yy == 'y') {
					cout << "Save as new?" << endl;
					cin >> yyn;
					if (yyn == 'y') {
						switch (flag1) {
						case 1:
						{
							s1.Insert(polinom2.GetIdPol(), polinom2);
							break;
						}
						case 2:
						{
							s2.Insert(polinom2.GetIdPol(), polinom2);
							break;
						}
						case 3:
						{
							s3.Insert(polinom2.GetIdPol(), polinom2);
							break;
						}
						}
					}
					else if (yyn == 'n') {
						switch (flag1) {
						case 1:
						{
							s1.Remove(polinom1.GetIdPol());
							s1.Insert(polinom2.GetIdPol(), polinom2);
							break;
						}
						case 2:
						{
							s2.Remove(polinom1.GetIdPol());
							s2.Insert(polinom2.GetIdPol(), polinom2);
							break;
						}
						case 3:
						{
							s3.Remove(polinom1.GetIdPol());
							s3.Insert(polinom2.GetIdPol(), polinom2);
							break;
						}
						}
					}
					break;
				}
			}
			case 2:
			{
				TPolinom polinom2 = polinom1.DiffY();
				cout << polinom2 << endl << endl;
				cout << "Save?" << endl;
				cin >> yy;
				if (yy == 'y') {
					cout << "Save as new?" << endl;
					cin >> yyn;
					if (yyn == 'y') {
						switch (flag1) {
						case 1:
						{
							s1.Insert(polinom2.GetIdPol(), polinom2);
							break;
						}
						case 2:
						{
							s2.Insert(polinom2.GetIdPol(), polinom2);
							break;
						}
						case 3:
						{
							s3.Insert(polinom2.GetIdPol(), polinom2);
							break;
						}
						}
					}
					else if (yyn == 'n') {
						switch (flag1) {
						case 1:
						{
							s1.Remove(polinom1.GetIdPol());
							s1.Insert(polinom2.GetIdPol(), polinom2);
							break;
						}
						case 2:
						{
							s2.Remove(polinom1.GetIdPol());
							s2.Insert(polinom2.GetIdPol(), polinom2);
							break;
						}
						case 3:
						{
							s3.Remove(polinom1.GetIdPol());
							s3.Insert(polinom2.GetIdPol(), polinom2);
							break;
						}
						}
					}
					break;
				}
			}
			case 3:
			{
				TPolinom polinom2 = polinom1.DiffZ();
				cout << polinom2 << endl << endl;
				cout << "Save?" << endl;
				cin >> yy;
				if (yy == 'y') {
					cout << "Save as new?" << endl;
					cin >> yyn;
					if (yyn == 'y') {
						switch (flag1) {
						case 1:
						{
							s1.Insert(polinom2.GetIdPol(), polinom2);
							break;
						}
						case 2:
						{
							s2.Insert(polinom2.GetIdPol(), polinom2);
							break;
						}
						case 3:
						{
							s3.Insert(polinom2.GetIdPol(), polinom2);
							break;
						}
						}
					}
					else if (yyn == 'n') {
						switch (flag1) {
						case 1:
						{
							s1.Remove(polinom1.GetIdPol());
							s1.Insert(polinom2.GetIdPol(), polinom2);
							break;
						}
						case 2:
						{
							s2.Remove(polinom1.GetIdPol());
							s2.Insert(polinom2.GetIdPol(), polinom2);
							break;
						}
						case 3:
						{
							s3.Remove(polinom1.GetIdPol());
							s3.Insert(polinom2.GetIdPol(), polinom2);
							break;
						}
						}
					}
					break;
				}
			}
			default:
				break;

			}
			break;

		case 5: {
			cout << "Enter new Polinom:\n" << endl;
			cin >> pol;
			TPolinom polinom2(pol);
			switch (flag1) {
			case 1:
			{
				s1.Remove(polinom1.GetIdPol());
				s1.Insert(polinom2.GetIdPol(), polinom2);
				break;
			}
			case 2:
			{
				s2.Remove(polinom1.GetIdPol());
				s2.Insert(polinom2.GetIdPol(), polinom2);
				break;
			}
			case 3:
			{
				s3.Remove(polinom1.GetIdPol());
				s3.Insert(polinom2.GetIdPol(), polinom2);
				break;
			}
			}
			return;
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
	//setlocale(LC_ALL, "Russian");
	char flag = 'n';
	bool isNew = 0;
	while (flag != 'y' && flag != 'Y') {
		int id;
		cout << "Choose table:" << endl;
		cout << "1) Scan Table" << endl;
		cout << "2) Sorted Table" << endl;
		cout << "3) Array Hash Table" << endl;
		cout << "4) Exit" << endl;
		isNew = 0;
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
				scanTable.Reset();
				cout << "\n" << endl;
				while (!scanTable.IsTabEnden()) {
					cout << scanTable.GetCurrent()->pData.GetIdPol() << endl;
					scanTable.Next();
				}
				cout << "\n" << endl;
				cout << "Enter Polinom:\n" << endl;
				string polin;
				cin >> polin;
				TPolinom pol(polin);
				TabRecord<string, TPolinom>* s = scanTable.Find(pol.GetIdPol());
				if (s == nullptr) {
					cout << "Not find" << endl;
					break;
				}
				PolinomOperation(s->pData, scanTable, sortedTable, arrayHashTable, 1);
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
				sortedTable.Reset();
				cout << "\n" << endl;
				while (!sortedTable.IsTabEnden()) {
					cout << sortedTable.GetCurrent()->pData.GetIdPol() << endl;
					sortedTable.Next();
				}
				cout << "\n" << endl;
				cout << "Enter Polinom:\n" << endl;
				string polin;
				cin >> polin;
				TPolinom pol(polin);
				TabRecord<string, TPolinom>* s = sortedTable.Find(pol.GetIdPol());
				if (s == nullptr) {
					cout << "Not find" << endl;
					break;
				}

				PolinomOperation(s->pData, scanTable, sortedTable, arrayHashTable, 2);
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
				arrayHashTable.Reset();
				cout << "\n" << endl;
				while (!arrayHashTable.IsTabEnden()) {
					cout << arrayHashTable.GetCurrent()->pData.GetIdPol() << endl;
					arrayHashTable.Next();
				}
				cout << "\n" << endl;
				cout << "Enter Polinom:\n" << endl;
				string polin;
				cin >> polin;
				TPolinom pol(polin);
				TabRecord<string, TPolinom>* s = arrayHashTable.Find(pol.GetIdPol());
				if (s == nullptr) {
					cout << "Not find" << endl;
					break;
				}
				
				PolinomOperation(s->pData, scanTable, sortedTable, arrayHashTable, 3);
				break;
			}
			case 3:
			{

				cout << "Enter Polinom:\n" << endl;
				string polin;
				cin >> polin;
				TPolinom pol(polin);
				arrayHashTable.Remove(pol.GetIdPol());
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
			flag = 'y';
			break;


		}
	}
	return 1;
}
