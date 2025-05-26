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
    cout << "Choose table:\n1) Scan Table\n2) Sorted Table\n3) Array Hash Table" << endl;
    int f;
    cin>>f;
    switch(f){
        case 1:{
            cout<<s1;
            cout<<"Enter Polinom"<<endl;
            string s;
            cin>>s;
            TPolinom a(s);
            while(s1.Find(a.GetIdPol()) == nullptr){
                a = TPolinom(s);
                cout<<"Can't find this polinom\nEnter Polinom"<<endl;
                cin>>s;
            }
            return a;
            break;
        }
        case 2:{
            cout<<s2;
            cout<<"Enter Polinom"<<endl;
            string s;
            cin>>s;
            TPolinom a(s);
            while(s2.Find(a.GetIdPol()) == nullptr){
                a = TPolinom(s);
                cout<<"Can't find this polinom\nEnter Polinom"<<endl;
                cin>>s;
            }
            return a;
            break;
        }
        case 3:{
            cout<<s3;
            cout<<"Enter Polinom"<<endl;
            string s;
            cin>>s;
            TPolinom a(s);
            while(s3.Find(a.GetIdPol()) == nullptr){
                a = TPolinom(s);
                cout<<"Can't find this polinom \nEnter Polinom"<<endl;
                cin>>s;
            }
            return a;
            break;
        }
        default:{
            cout<<"Incorrect operationon\n"<<endl;
        }
    }
}

void SavePolinom(TPolinom polinom1, TPolinom polinom2, ScanTable<string, TPolinom>& s1, SortedTable<string, TPolinom>& s2, ArrayHashTable<string, TPolinom>& s3, int flag1){
    char yy;
    char yyn;
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
    
}
void PolinomOperation(TPolinom polinom1, ScanTable<string, TPolinom>& s1, SortedTable<string, TPolinom>& s2, ArrayHashTable<string, TPolinom>& s3, int flag1) {
	char flag = 'n';
	bool isNew = 0;
	string pol;
	while (flag != 'y' && flag != 'Y') {
		isNew = 0;
		cout << "Choose:\n1) +\n2) -\n3) *\n4) Diff\n5) Change Polinom\n6) Calculate Polinom\n7) Exit" << endl;
		int n;
		int a;
		cin >> n;
        switch (n) {
            case 1:
                cout << "Choose:\n1) + Scalar\n2) + Monom\n3) + Polinom\n4) Exit" << endl;
                cin >> a;
                switch (a) {
                    case 1:
                    {
                        cout << "Scalar:\n" << endl;
                        double x;
                        cin >> x;
                        TPolinom polinom2 = polinom1 + x;
                        cout << polinom2 << endl << endl;
                        SavePolinom(polinom1, polinom2, s1, s2, s3, flag1);
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
                        SavePolinom(polinom1, polinom2, s1, s2, s3, flag1);
                        break;
                        
                    }
                    case 3:
                    {
                        TPolinom polinom3 = GetPolinomFromTable(s1, s2, s3);
                        TPolinom polinom2 = polinom1 + polinom3;
                        cout << polinom2 << endl << endl;
                        SavePolinom(polinom1, polinom2, s1, s2, s3, flag1);
                        break;
                        
                    }
                    default:
                        break;
                        
                }
                break;
        

		case 2:
            cout << "Choose:\n1) - Scalar\n2) - Monom\n3) - Polinom\n4) Exit" << endl;
			cin >> a;
                switch (a) {
                    case 1:
                    {
                        cout << "Scalar:\n" << endl;
                        double x;
                        cin >> x;
                        TPolinom polinom2 = polinom1 - x;
                        cout << polinom2 << endl << endl;
                        SavePolinom(polinom1, polinom2, s1, s2, s3, flag1);
                        break;
                        
                    }
                    case 2:
                    {
                        cout << "Monom:\n" << endl;
                        string d;
                        cin >> d;
                        TMonom m(d);
                        TPolinom polinom2 = polinom1 - m;
                        cout << polinom2 << endl << endl;
                        SavePolinom(polinom1, polinom2, s1, s2, s3, flag1);
                        break;
                        
                    }
                    case 3:
                    {
                        TPolinom polinom3 = GetPolinomFromTable(s1, s2, s3);
                        TPolinom polinom2 = polinom1 - polinom3;
                        cout << polinom2 << endl << endl;
                        SavePolinom(polinom1, polinom2, s1, s2, s3, flag1);
                        break;
                        
                    }
                    default:
                        break;
                        
                        
                       
                }
                break;
		case 3:
                cout << "Choose:\n1) * Scalar\n2) * Monom\n3) * Polinom\n4) Exit" << endl;
			cin >> a;
                switch (a) {
                    case 1: {
                        cout << "Integer:\n" << endl;
                        int d;
                        cin >> d;
                        TPolinom polinom2 = polinom1 * d;
                        cout << polinom2 << endl << endl;
                        SavePolinom(polinom1, polinom2, s1, s2, s3, flag1);
                        break;
                        
                    }
                    case 2:
                    {
                        cout << "Monom\n" << endl;
                        string d;
                        cin >> d;
                        TMonom m(d);
                        TPolinom polinom2 = polinom1 * m;
                        cout << polinom2 << endl << endl;
                        SavePolinom(polinom1, polinom2, s1, s2, s3, flag1);
                        break;
                        
                    }
                    case 3:
                    {
                        TPolinom polinom3 = GetPolinomFromTable(s1, s2, s3);
                        TPolinom polinom2 = polinom1 * polinom3;
                        cout << polinom2 << endl << endl;
                        SavePolinom(polinom1, polinom2, s1, s2, s3, flag1);
                        break;
                        
                    }
                    default:
                        break;
                        
                        
                        
                }
                break;
		case 4:
			cout << "Choose:\n1) X\n2) Y\n3) Z\n4) Exit" << endl;
			cin >> a;
                switch (a) {
                    case 1: {
                        TPolinom polinom2 = polinom1.DiffX();
                        cout << polinom2 << endl << endl;
                        SavePolinom(polinom1, polinom2, s1, s2, s3, flag1);
                        break;
                        
                    }
                    case 2:
                    {
                        TPolinom polinom2 = polinom1.DiffY();
                        cout << polinom2 << endl << endl;
                        SavePolinom(polinom1, polinom2, s1, s2, s3, flag1);
                        break;
                        
                    }
                    case 3:
                    {
                        TPolinom polinom2 = polinom1.DiffZ();
                        cout << polinom2 << endl << endl;
                        SavePolinom(polinom1, polinom2, s1, s2, s3, flag1);
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
			cout << "Exit?\n(Yes - y, No - n):" << endl;
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
		return 1;
	}
	ScanTable<string, TPolinom> scanTable(sz);
	SortedTable<string, TPolinom> sortedTable(sz);
	ArrayHashTable<string, TPolinom> arrayHashTable(sz, 5);
	char flag = 'n';
	bool isNew = 0;
	while (flag != 'y' && flag != 'Y') {
		int id;
		cout << "Choose table:\n1) Scan Table\n2) Sorted Table\n3) Array Hash Table\n4) All Tables\n5) Exit" << endl;
		isNew = 0;
		int n;
		int a;
		cin >> n;
		switch (n) {
		case 1:
			cout << "Choose:\n1) Insert\n2) Get\n3) Remove\n4) See Table\n5) Exit" << endl;
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
                cout<<scanTable;
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
                cout<<scanTable;
				break;
			}
			default:
				break;

			}
			break;

		case 2:
            cout << "Choose:\n1) Insert\n2) Get\n3) Remove\n4) See Table\n5) Exit" << endl;
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
                cout<<sortedTable;
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
                cout<<sortedTable;
				break;
			}
			default:
				break;

			}
			break;
		case 3:
			cout << "Choose:\n1) Insert\n2) Get\n3) Remove\n4) See Table\n5) Exit" << endl;
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
                cout<<arrayHashTable;
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
                cout<<arrayHashTable;
				break;
			}
			default:
				break;

			}
			break;
        case 4:
                cout << "Choose:\n1) Insert\n2) Remove\n3) See Table\n4) Exit" << endl;
                cin >> a;
                switch (a) {
                case 1:
                {

                    cout << "Enter Polinom:\n" << endl;
                    string polin;
                    cin >> polin;
                    TPolinom pol(polin);
                    scanTable.Insert(pol.GetIdPol(), pol);
                    sortedTable.Insert(pol.GetIdPol(), pol);
                    arrayHashTable.Insert(pol.GetIdPol(), pol);
                    
                    break;
                }
                
                case 2:
                {
                    cout<<"Scan Table:"<<scanTable<<"Sorted Table:"<<sortedTable<<"Array Hash Table:"<<arrayHashTable<<"\n";
                    cout << "Enter Polinom:\n" << endl;
                    string polin;
                    cin >> polin;
                    TPolinom pol(polin);
                    scanTable.Remove(pol.GetIdPol());
                    sortedTable.Remove(pol.GetIdPol());
                    arrayHashTable.Remove(pol.GetIdPol());
                    break;
                }
                case 3:
                {
                    cout<<"Scan Table:"<<scanTable<<"Sorted Table:"<<sortedTable<<"Array Hash Table:"<<arrayHashTable;
                    break;
                }
                default:
                    break;

                }
                break;
		case 5:
			flag = 'y';
			break;


		}
	}
	return 0;
}
