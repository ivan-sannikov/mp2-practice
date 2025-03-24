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
    void CheckPolinoms(string monom) {
        TMonom t(monom);
        TNode<TMonom>* tmp = this->polinomslist.GetFirst();
        this->polinomslist.reset();
        if (!this->polinomslist.isended()) {
            while (tmp->key != t && !this->polinomslist.isended())
            {
                tmp = tmp->pNext;
                this->polinomslist.next();
            }
            if (this->polinomslist.isended()) this->polinomslist.InsertEnd(t);
            else {
                TMonom t1(t + tmp->key);
                this->polinomslist.InsertEnd(t1);
            }
        }
        else {
            this->polinomslist.InsertEnd(t);
        }
        this->polinomslist.reset();
    }

    void SortPolinoms() {
        TRingHeadList<TMonom> list;
        this->polinomslist.reset();
        while (!this->polinomslist.isended()) {
            TNode<TMonom>* tmp = this->polinomslist.GetFirst();
            TNode<TMonom>* tmpmin = this->polinomslist.GetFirst();

            while (!this->polinomslist.isended()) {
                if (tmp->key < tmpmin->key) {
                    tmpmin = tmp;
                }
                this->polinomslist.next();
                tmp = tmp->pNext;
            }
            list.InsertFirst(tmpmin->key);
            this->polinomslist.Delete(tmpmin->key);
            this->polinomslist.reset();


        }
        list.reset();
        while (!list.isended()) {
            TNode<TMonom>* tmp = list.GetFirst();
            this->polinomslist.InsertEnd(tmp->key);
            list.DeleteFirst();
            list.reset();
        }
    }
    /*
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
    */
	
public:
    TPolinom(){}
    TPolinom(const string& polinom){
        this->id_pol = polinom;
        int len = strlen(polinom.c_str());
        int i = 0;
        string monom = "";
        while(i<len){
            if((polinom[i] == '+' || polinom[i] == '-') && i != 0){
                CheckPolinoms(monom);
                monom = "";
            }
            monom += polinom[i];
            i++;
        }
        TMonom t(monom);
        this->polinomslist.InsertEnd(t);
	SortPolinoms();
        
    }   
    TPolinom(const TPolinom& other) {
        this->id_pol = other.id_pol;
        TRingHeadList<TMonom> l(other.polinomslist);
        this->polinomslist = l;
    }   
    bool operator==(const TPolinom& other) const {
        return (this->polinomslist == other.polinomslist) && (this->id_pol == other.id_pol);
    }
    
    bool operator!=(const TPolinom& pol) const {
        return !(*this == pol);
    }
    
    const TPolinom& operator=(const TPolinom& other) {
        if (this == &other) {
            return *this;
        }
        TRingHeadList<TMonom> l(other.polinomslist);
        this->polinomslist = l;
        return *this;
    }


    void DiffX() {
        TNode<TMonom>* tmp = this->polinomslist.GetFirst();
        TRingHeadList<TMonom> list;
        this->polinomslist.reset();
        while (!this->polinomslist.isended()) {
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
                
            }
            tmp = tmp->pNext;
            this->polinomslist.next();
        }
        this->polinomslist.reset();
        while (!this->polinomslist.isended()) {
            this->polinomslist.DeleteFirst();
            this->polinomslist.reset();
        }
        TNode<TMonom>* tmp1 = list.GetFirst();
        list.reset();
        while (!list.isended()) {
            CheckPolinoms(tmp1->key.GetMonom());
            tmp1 = tmp1->pNext;
            list.next();
        }
        SortPolinoms();
        
    }

    void DiffY() {
        TNode<TMonom>* tmp = this->polinomslist.GetFirst();
        TRingHeadList<TMonom> list;
        this->polinomslist.reset();
        while (!this->polinomslist.isended()) {
            int sv = tmp->key.GetConvolution();
            int x = sv / 100;
            int y = sv / 10 % 10;
            int z = sv % 100 % 10;
            
            double value = tmp->key.GetValue();
            if (y != 0) {
                value *= y; y--;
                stringstream str;
                str << value;
                string s = str.str();
                TMonom t(s + compileMonom(x, y, z));
                list.InsertEnd(t);
            }
            tmp = tmp->pNext;
            this->polinomslist.next();
        }
        this->polinomslist.reset();
        while (!this->polinomslist.isended()) {
            this->polinomslist.DeleteFirst();
            this->polinomslist.reset();
        }
        TNode<TMonom>* tmp1 = list.GetFirst();
        list.reset();
        while (!list.isended()) {
            CheckPolinoms(tmp1->key.GetMonom());
            tmp1 = tmp1->pNext;
            list.next();
        }
        SortPolinoms();

    }

    void DiffZ() {
        TNode<TMonom>* tmp = this->polinomslist.GetFirst();
        TRingHeadList<TMonom> list;
        this->polinomslist.reset();
        while (!this->polinomslist.isended()) {
            int sv = tmp->key.GetConvolution();
            int x = sv / 100;
            int y = sv / 10 % 10;
            int z = sv % 100 % 10;
            double value = tmp->key.GetValue();
            if (z != 0) {
                value *= z; z--;
                stringstream str;
                str << value;
                string s = str.str();
                TMonom t(s + compileMonom(x, y, z));
                list.InsertEnd(t);
            }
            tmp = tmp->pNext;
            this->polinomslist.next();

        }
        this->polinomslist.reset();
        while (!this->polinomslist.isended()) {
            this->polinomslist.DeleteFirst();
            this->polinomslist.reset();
        }
        TNode<TMonom>* tmp1 = list.GetFirst();
        list.reset();
        while (!list.isended()) {
            CheckPolinoms(tmp1->key.GetMonom());
            tmp1 = tmp1->pNext;
            list.next();
        }
        SortPolinoms();
    }

    TPolinom operator+(const TMonom& mon) {
        TNode<TMonom>* a = this->polinomslist.Search(mon);
        if (!this->polinomslist.isended()) {
            stringstream str;
            double b = a->key.GetValue() + mon.GetValue();
            str << b;
            string s = str.str() + mon.GetMonomConv();
            TMonom t(s);
            this->polinomslist.InsertEnd(t);
            this->polinomslist.Delete(mon);
        }
        else {
            this->polinomslist.InsertEnd(mon);
        }
        SortPolinoms();
        return *this;
    }

    TPolinom operator+(const TPolinom& pol) {
        TNode<TMonom>* tmp = pol.GetList().GetFirst();
        pol.polinomslist.reset();
        while (!pol.polinomslist.isended()) {
            TNode<TMonom>* a = this->polinomslist.Search(tmp->key);
            if (!this->polinomslist.isended()) {
                stringstream str;
                double b = a->key.GetValue() + tmp->key.GetValue();
                str << b;
                string s = str.str() + a->key.GetMonomConv();
                TMonom t(s);
                if (t.GetValue() != 0) { this->polinomslist.InsertEnd(t); }
                this->polinomslist.Delete(tmp->key);
            }
            else {
                if (tmp->key.GetValue() != 0) { this->polinomslist.InsertEnd(tmp->key); }
            }
            tmp = tmp->pNext;
            pol.polinomslist.next();
        }
        SortPolinoms();
        return *this;
    }

    TPolinom operator-(const TMonom& mon) {
        TNode<TMonom>* a = this->polinomslist.Search(mon);
        if (!this->polinomslist.isended()) {
            stringstream str;
            double b = a->key.GetValue() + ((-1)*mon.GetValue());
            str << b;
            string s = str.str() + mon.GetMonomConv();
            TMonom t(s);
            if (t.GetValue() != 0) { this->polinomslist.InsertEnd(t); }
            this->polinomslist.Delete(mon);
        }
        else {
            stringstream str;
            double b = ((-1) * mon.GetValue());
            str << b;
            string s = str.str() + mon.GetMonomConv();
            TMonom t(s);
            if (t.GetValue() != 0) { this->polinomslist.InsertEnd(t); }
        }
        SortPolinoms();
        return *this;
    }

    TPolinom operator-(const TPolinom& pol) {
        return *this + (pol * (-1.0));
    }

    TPolinom operator*(double scalar) {
        TNode<TMonom>* tmp = this->polinomslist.GetFirst();
        TRingHeadList<TMonom> list;
        this->polinomslist.reset();
        while (!this->polinomslist.isended()) {
            double b = tmp->key.GetValue() * scalar;
            stringstream str;
            str << b;
            string s = str.str() + tmp->key.GetMonomConv();
            TMonom t(s);
            list.InsertFirst(t);
            tmp = tmp->pNext;
            this->polinomslist.next();
        }
        this->polinomslist.reset();
        while (!this->polinomslist.isended()) {
            this->polinomslist.DeleteFirst();
            this->polinomslist.reset();
        }
        TNode<TMonom>* tmp1 = list.GetFirst();
        list.reset();
        while (!list.isended()) {
            CheckPolinoms(tmp1->key.GetMonom());
            tmp1 = tmp1->pNext;
            list.next();
        }
        SortPolinoms();
        return *this;

    }
    TPolinom operator*(const TMonom& monom) {
        TNode<TMonom>* tmp = this->polinomslist.GetFirst();
        TRingHeadList<TMonom> list;
        this->polinomslist.reset();
        while (!this->polinomslist.isended()) {
            double b = tmp->key.GetValue() * monom.GetValue();
            stringstream str;
            str << b;
            double c = tmp->key.GetConvolution() + monom.GetConvolution();
            if (b > 0) {
                string s = str.str() + tmp->key.GetMonomConv(c);
                if (tmp != this->polinomslist.GetFirst()) {
                    s = "+" + s;
                }
               
                TMonom t(s);
                list.InsertFirst(t);
            }
            if (b < 0) {
                string s = str.str() + tmp->key.GetMonomConv(c);
                TMonom t(s);
                list.InsertFirst(t);
            }
            tmp = tmp->pNext;
            this->polinomslist.next();
        }
        this->polinomslist.reset();
        while (!this->polinomslist.isended()) {
            this->polinomslist.DeleteFirst();
            this->polinomslist.reset();
        }
        TNode<TMonom>* tmp1 = list.GetFirst();
        list.reset();
        while (!list.isended()) {
            CheckPolinoms(tmp1->key.GetMonom());
            tmp1 = tmp1->pNext;
            list.next();
        }
        SortPolinoms();
        return *this;

    }

    TPolinom operator*(const TPolinom& pol) {
        TNode<TMonom>* tmp = this->polinomslist.GetFirst();
        TNode<TMonom>* tmp1 = pol.GetList().GetFirst();
        pol.polinomslist.reset();
        TPolinom p1;
        TPolinom p;
        p = *this;
        p1 = p * tmp1->key;
        tmp1 = tmp1->pNext;
        pol.polinomslist.next();
        while (!pol.polinomslist.isended()) {
            p = *this;
            p = p * tmp1->key;
            p1 =p1+p;
            tmp1 = tmp1->pNext;
            pol.polinomslist.next();
        }
        *this = p1;
        SortPolinoms();
        return *this;
    }

    double operator()(double* operands) { // TODO: x, y, z
        TList<double> num;
        TNode<TMonom>* tmp = this->polinomslist.GetFirst();
        double res = 0;
        this->polinomslist.reset();
        while (!this->polinomslist.isended()) {
            int sv = tmp->key.GetConvolution();
            int x = sv / 100;
            int y = sv / 10 % 10;
            int z = sv % 100 % 10;
            double value = tmp->key.GetValue();
            res += value * pow(operands[0], x) * pow(operands[1], y) * pow(operands[2], z);
            tmp = tmp->pNext;
            this->polinomslist.next();
        }
        return res;
    }

    friend ostream& operator<<(ostream& ostr, const TPolinom& pol)
    {
        ostr << endl;
        TNode<TMonom>* tmp = pol.GetList().GetFirst();
        string s;
        pol.polinomslist.reset();
        while (!pol.polinomslist.isended()) {
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
            pol.polinomslist.next();
        }
        ostr << s;
        ostr << endl;
        return ostr;
    }
};
