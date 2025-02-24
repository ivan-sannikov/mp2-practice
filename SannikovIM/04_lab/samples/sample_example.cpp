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
	TPolinom<int> s("3x^2y^3z^2-2x^3y^2z^3");
}