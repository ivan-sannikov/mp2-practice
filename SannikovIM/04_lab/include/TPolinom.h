#pragma once

#include "TMonom.h"
#include "list.h"
#include "ringheadlist.h"
#include <string>
#include <iostream>
#include <cmath>

using namespace std;
class TPolinom{ // TODO: разделить объ€вление и реализацию
private: 
    TRingHeadList<TMonom> polinomslist;
    string id_pol;

    string GetPolinom(const TPolinom& p);
    void CheckPolinoms(string monom);
    void CheckPolinoms(double coeff, int degree);
    void SortPolinoms();
    string compileMonom(int x, int y, int z);
    
	
public:
    TPolinom();
    TPolinom(const string& polinom);
    TPolinom(const TPolinom& other);
    bool operator==(const TPolinom& other) const;
    bool operator!=(const TPolinom& pol) const;
    const TPolinom& operator=(const TPolinom& other);
    void DiffX();
    void DiffY();
    void DiffZ();
    TPolinom operator+(const TMonom& mon);
    TPolinom operator+(const TPolinom& pol);
    TPolinom operator-(const TMonom& mon);
    TPolinom operator-(const TPolinom& pol);
    TPolinom operator*(double scalar);
    TPolinom operator*(const TMonom& monom);
    TPolinom operator*(const TPolinom& pol);
    double operator()(double x, double y, double z);
    friend ostream& operator<<(ostream& ostr, const TPolinom& pol);

};
