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
	setlocale(LC_ALL, "Russian");
	char flag = 'n';
	bool isNew = 0;
	cout << "Введите полином:\n" << endl;
	string pol;
	cin >> pol;
	TPolinom polinom1(pol);
	while (flag != 'y' && flag != 'Y') {
		cout << endl << polinom1 << endl << endl;
		isNew = 0;
		cout << "Выберите действие:" << endl;
		cout << "1) Сложение" << endl;
		cout << "2) Вычитание" << endl;
		cout << "3) Умножение" << endl;
		cout << "4) Дифференцирование" << endl;
		cout << "5) Поменять полином" << endl;
		cout << "6) Выйти" << endl;
		int n;
		int a;
		cin >> n;
		switch (n) {
		case 1:
			cout << "Выберите действие:" << endl;
			cout << "1) С мономом" << endl;
			cout << "2) С полиномом" << endl;
			cout << "3) Выйти" << endl;
			cin >> a;
			switch (a) {
			case 1:
			{
				cout << "Введите моном:\n" << endl;
				string d;
				cin >> d;
				TMonom m(d);
				polinom1 = polinom1 + m;
				cout << polinom1 << endl << endl;
				break;
			}
			case 2:
			{
				cout << "Введите полином:\n" << endl;
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
			cout << "Выберите действие:" << endl;
			cout << "1) С мономом" << endl;
			cout << "2) С полиномом" << endl;
			cout << "3) Выйти" << endl;
			cin >> a;
			switch (a) {
			case 1:
			{
				cout << "Введите моном:\n" << endl;
				string d;
				cin >> d;
				TMonom m(d);
				polinom1 = polinom1 - m;
				cout << polinom1 << endl << endl;
				break;
			}
			case 2:
			{
				cout << "Введите полином:\n" << endl;
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
			cout << "Выберите действие:" << endl;
			cout << "1) С скаляром" << endl;
			cout << "2) С мономом" << endl;
			cout << "3) С полиномом" << endl;
			cout << "4) Выйти" << endl;
			cin >> a;
			switch (a) {
			case 1: {
				cout << "Введите скаляр:\n" << endl;
				int d;
				cin >> d;

				polinom1 = polinom1 * d;
				cout << polinom1 << endl << endl;
				break;
			}
			case 2:
			{
				cout << "Введите моном:\n" << endl;
				string d;
				cin >> d;
				TMonom m(d);
				polinom1 = polinom1 * m;
				cout << polinom1 << endl << endl;
				break;
			}
			case 3:
			{
				cout << "Введите полином:\n" << endl;
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
			cout << "Выберите действие:" << endl;
			cout << "1) По x" << endl;
			cout << "2) По y" << endl;
			cout << "3) По z" << endl;
			cout << "4) Выйти" << endl;
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
			cout << "Введите новый полином:\n" << endl;
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
			cout << "Хотите выйти?" << endl;
			cout << "(Да - y, Нет - n): ";
			cin >> flag;
		}
	}
}
