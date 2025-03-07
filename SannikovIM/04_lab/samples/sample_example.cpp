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
	//TMonom<int> s("-3x");
	//cout<<s.GetValue()<< "  "<<s.GetConvolution()<<endl;
	//TPolinom<int> s("3x^2y^3z^2+3x^2y^3z^2-2x^3y^2z^3-5x^3y^2z^3+3x^2y^3z^2+2z");
	//TPolinom<int> s1("3x^2y^3z^2");
	//s1 = s;
	TPolinom s("3x^2y^3z^2-4xyz+2z+1");
	//TPolinom<int> s("4xyz+2z");
	//TPolinom<int> s1("1z+2y^2");
	//s.Diff();
	TMonom m("3z");
	//TPolinom<int> s("2z+2x");
	///TPolinom<int> s1("3z+2x");
	s = s - m;
	cout << s << endl;
	double a[] = { 1,2,3 };
	//cout << to_string(s1(a)) << endl;
	
}
