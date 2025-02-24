#pragma once
#include "TMonom.h"
#include "ringheadlist.h"
#include <string>
#include <iostream>

using namespace std;
template <typename T>
class TPolinom{
private: 
    TRingHeadList<TMonom> polinomslist;
    TList<TMonom> list;
public:
    TPolinom(string polinom){
        int len = strlen(polinom.c_str());
        int i = 0;
        string monom = "";
        while(i<len){
            if((polinom[i] == '+' || polinom[i] == '-') && i != 0){
                TMonom t(monom);
                this->polinomslist.InsertEnd(t);
                monom = "";
            }
            monom += polinom[i];
            i++;
        }
        TMonom t(monom);
        this->polinomslist.InsertEnd(t);
        TNode<TMonom>* a = polinomslist.GetFirst();
       
    }
  
};