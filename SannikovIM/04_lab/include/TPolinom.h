#pragma once
#include "TMonom.h"
#include "list.h"
#include "ringheadlist.h"
#include <string>
#include <iostream>
#include <cmath>

using namespace std;
template <typename T>
class TPolinom{
private: 
    TRingHeadList<TMonom> polinomslist;

    //TList<TMonom> list;

    void SortPolinoms() {
        TRingHeadList<TMonom> list;
        list.SetHead(this->polinomslist.GetHead());
        while (this->polinomslist.GetFirst() != this->polinomslist.GetStop()) {
            TNode<TMonom>* tmp = this->polinomslist.GetFirst();
            TNode<TMonom>* tmpmin = this->polinomslist.GetFirst();

            while (tmp != polinomslist.GetStop()) {

                if (tmp->key.GetConvolution() < tmpmin->key.GetConvolution()) {
                    tmpmin = tmp;
                }
                tmp = tmp->pNext;
            }
            list.InsertFirst(tmpmin->key);
            this->polinomslist.Delete(tmpmin->key);


        }
        while (list.GetFirst() != list.GetStop()) {
            TNode<TMonom>* tmp = list.GetFirst();
 
            this->polinomslist.InsertEnd(tmp->key);
            list.DeleteFirst();
        }
    }
    string compileMonom(int x, int y, int z) {
        string s;
        switch (x) {
        case 1:
            s += "x";
            break;

        case 0:
            break;
        default:
            s += ("x^" + to_string(x));
            break;
        }
        switch(y){
        case 1:
            s += "y";
            break;

        case 0:
            break;
        default:
            s += ("y^" + to_string(y));
            break;
        }
        switch (z) {
        case 1:
            s += "z";
            break;

        case 0:
            break;
        default:
            s += ("z^" + to_string(z));
            break;
        }
        return s;
    }
	
public:
    TPolinom(string polinom){
        TMonom t1("0z^-1");
        TNode<TMonom>* q = new TNode<TMonom>(t1);

        this->polinomslist.SetHead(q);
        int len = strlen(polinom.c_str());
        int i = 0;
        string monom = "";
        while(i<len){
            if((polinom[i] == '+' || polinom[i] == '-') && i != 0){
                TMonom t(monom);
                TNode<TMonom>* tmp = this->polinomslist.GetFirst();
              //  tmp->pNext = this->polinomslist.GetFirst()->pNext;
                if(tmp != polinomslist.GetStop()){
                    while (tmp->key.GetConvolution() != t.GetConvolution() && tmp->pNext != polinomslist.GetStop())
                    {
                        tmp = tmp->pNext;
                    }
                    if (tmp->key.GetConvolution() != t.GetConvolution() && tmp->pNext == polinomslist.GetStop()) tmp = polinomslist.GetStop();
                    if (tmp == polinomslist.GetStop()) this->polinomslist.InsertEnd(t);
                    else {
                        double a = tmp->key.GetValue();
                        polinomslist.Delete(tmp->key);
                        stringstream str;
                        str <<(double)(a + t.GetValue());
                        TMonom t1(str.str() + t.GetMonomConv());
                        polinomslist.InsertEnd(t1);

                    }
                }
                else {
                    this->polinomslist.InsertEnd(t);
                    //this->polinomslist.InsertEnd(this->polinomslist.GetStop()->key);
                }
                monom = "";
            }
            monom += polinom[i];
            i++;
        }
        TMonom t(monom);
        this->polinomslist.InsertEnd(t);
	SortPolinoms();
      
        TNode<TMonom>* a = polinomslist.GetFirst();
        
    }
    TPolinom(TRingHeadList<TMonom> list) {
        while (list.GetFirst() != nullptr) {
            TNode<TMonom>* tmp = list.GetFirst();
            polinomslist.InsertEnd(tmp->key);
            list.DeleteFirst();
        }
        SortPolinoms();
    }
    TRingHeadList<TMonom>& GetList() {
        return polinomslist;
    }

    bool operator==(TPolinom<T>& pol) const {
        cout << polinomslist.GetStop()->key.GetValue() << endl;
        TNode<TMonom>* tmpthis = this->polinomslist.GetFirst();
        TNode<TMonom>* tmppol = pol.GetList().GetFirst();
        while (tmpthis != polinomslist.GetStop() && tmppol != polinomslist.GetStop()) {
            if (tmpthis->key.GetConvolution() != tmppol->key.GetConvolution()) return 0;
            if (tmpthis->key.GetValue() != tmppol->key.GetValue()) return 0;
            tmpthis = tmpthis->pNext;
            tmppol = tmppol->pNext;
        }
        if ((tmpthis == polinomslist.GetStop() && tmppol != polinomslist.GetStop()) || (tmpthis != polinomslist.GetStop() && tmppol == polinomslist.GetStop())) return 0;
        return 1;
    }
    bool operator!=(TPolinom<T>& pol) const {
        return !(*this == pol);
    }
    TPolinom& operator=(TPolinom<T>& pol) {
        if (this == &pol) return *this;
         this->polinomslist.~TRingHeadList();
        TNode<TMonom>* tmp = pol.GetList().GetFirst();
        while (tmp != pol.GetList().GetStop()) {
            polinomslist.InsertEnd(tmp->key);
            tmp = tmp->pNext;
        }
        return *this;
    }
    void Diff() {
        TNode<TMonom>* tmp = this->polinomslist.GetFirst();
        TRingHeadList<TMonom> list;
        list.SetHead(this->polinomslist.GetHead());
        while (tmp != this->polinomslist.GetStop()) {
            int sv = tmp->key.GetConvolution();
            int x = sv / 100;
            int y = sv / 10 % 10;
            int z = sv % 100 % 10;
            double value = tmp->key.GetValue();

            if (x != 0) {
                value *= x; x--;


                stringstream str;
                str << value;
                string s = str.str();
                TMonom t(s + compileMonom(x, y, z));
                list.InsertEnd(t);
                x = sv / 100;
            }
            if (y != 0) {
                value *= y; y--;

                stringstream str;
                str << value;
                string s = str.str();
                TMonom t(s + compileMonom(x, y, z));
                list.InsertEnd(t);
                y = sv / 10 % 10;
            }
            if (z != 0) {
                value *= z; z--;
                stringstream str;
                str << value;
                string s = str.str();
                TMonom t(s + compileMonom(x, y, z));
                list.InsertEnd(t);
            }

          //  list.Delete(tmp->key);
            tmp = tmp->pNext;
        }
        this->polinomslist.~TRingHeadList();
        TNode<TMonom>* tmp1 = list.GetFirst();
        while (tmp1 != list.GetStop()) {
            polinomslist.InsertEnd(tmp1->key);
            tmp1 = tmp1->pNext;
        }
        SortPolinoms();
        
    }
    TPolinom operator+(TPolinom& pol) {
        TNode<TMonom>* tmp = pol.GetList().GetFirst();
        while (tmp != pol.GetList().GetStop()  ) {
            TNode<TMonom>* a = this->polinomslist.Search(tmp->key);
            if (a != polinomslist.GetStop()) {
                stringstream str;
                double b = a->key.GetValue() + tmp->key.GetValue();
                str << b;
                string s = str.str() + a->key.GetMonomConv();
                TMonom t(s);
                this->polinomslist.InsertEnd(t);
                this->polinomslist.Delete(tmp->key);
            }
            else {
                this->polinomslist.InsertEnd(tmp->key);
            }
            tmp = tmp->pNext;
        }
        SortPolinoms();
        return *this;
    }
    TPolinom operator-(TPolinom& pol) {
        TNode<TMonom>* tmp = pol.GetList().GetFirst();

        while (tmp != pol.GetList().GetStop()) {
            TNode<TMonom>* a = this->polinomslist.Search(tmp->key);
            if (a != polinomslist.GetStop()) {
                stringstream str;
                double b = a->key.GetValue() - tmp->key.GetValue();
                str << b;
                string s = str.str() + a->key.GetMonomConv();
                TMonom t(s);
                if (b != 0) {
                    this->polinomslist.InsertEnd(t);
                }
                this->polinomslist.Delete(tmp->key);
            }
            else {
                stringstream str;
                double b = -1 * tmp->key.GetValue();
                str << b;
                string s = str.str() + tmp->key.GetMonomConv();
                TMonom t(s);
                this->polinomslist.InsertEnd(t);
              //  this->polinomslist.Delete(tmp->key);
            }
           
            tmp = tmp->pNext;
           
          
        }
        SortPolinoms();
        return *this;
    }
    double operator()(double* operands) {
        TList<double> num;
        TNode<TMonom>* tmp = this->polinomslist.GetFirst();
        double res = 0;
        cout << "222" << endl;
        while (tmp != this->polinomslist.GetStop()) {
            int sv = tmp->key.GetConvolution();
            int x = sv / 100;
            int y = sv / 10 % 10;
            int z = sv % 100 % 10;
            double value = tmp->key.GetValue();
            res += value * pow(operands[0], x) * pow(operands[1], y) * pow(operands[2], z);
            tmp = tmp->pNext;
        }
        return res;
    }
    friend ostream& operator<<(ostream& ostr, TPolinom<T>& pol)
    {
        ostr << endl;
        TNode<TMonom>* tmp = pol.GetList().GetFirst();
        string s;
    
        TNode<TMonom>* g = pol.GetList().GetStop();
        while (tmp != pol.GetList().GetStop()) {
            if (tmp != pol.GetList().GetFirst()) {
                if (tmp->key.GetValue() > 0) {
                    s += ("+" + tmp->key.GetMonom());
                }
                else {
                    s += tmp->key.GetMonom();
                }
            }
            else {
                s += tmp->key.GetMonom();
            }
            tmp = tmp->pNext;
        }
        ostr << s;
        ostr << endl;
        return ostr;
    }

};
