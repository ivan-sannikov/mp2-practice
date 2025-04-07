#pragma once

#include <cstring>
#include <iostream>
#include <string>
#include <sstream>

using namespace std;

class TMonom{ 
private:
	int degree;
	double coeff;
	double GetConvolution(const string& pMem);

public:
	TMonom();
	TMonom(const string& pMem);
	TMonom(const TMonom& mon);
	TMonom(const double coeff, const int degree);
	bool operator==(const TMonom& m);
	bool operator!=(const TMonom& m);

	bool operator>(const TMonom& m);
	bool operator<(const TMonom& m);
	bool operator>=(const TMonom& m);
	bool operator<=(const TMonom& m);

	TMonom operator+(const TMonom& m);
	TMonom operator-(const TMonom& m);
	TMonom operator*(const TMonom& m);
	double operator()(double x, double y, double z);
	int GetDegree() const;
	double GetCoeff() const;

};
