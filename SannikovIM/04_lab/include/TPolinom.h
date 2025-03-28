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
    void CheckPolinoms(double coeff, int degree) {
        TMonom t(coeff, degree);
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
        this->id_pol = other.id_pol;
        TRingHeadList<TMonom> l(other.polinomslist);
        this->polinomslist = l;
        return *this;
    }


    void DiffX() {
        TNode<TMonom>* tmp = this->polinomslist.GetFirst();
        TRingHeadList<TMonom> list;
        this->polinomslist.reset();
        string id_pol1 = "";
        while (!this->polinomslist.isended()) {
            int sv = tmp->key.GetDegree();
            int x = sv / 100;
            int y = sv / 10 % 10;
            int z = sv % 100 % 10;
            double value = tmp->key.GetCoeff();
            if (x != 0) {
                value *= x; x--;
                TMonom t(value, x * 100 + y * 10 + z);
                list.InsertEnd(t);
                string s;
                stringstream str;
                str << value;
                s = str.str() + compileMonom(x, y, z);
                if (list.GetFirst() != nullptr) {
                    if (value > 0) {
                        id_pol1 += "+" + s;
                    }
                }
                else {
                    id_pol1 += s;
                }
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
            CheckPolinoms(tmp1->key.GetCoeff(), tmp1->key.GetDegree());
            tmp1 = tmp1->pNext;
            list.next();
        }
        this->id_pol = id_pol1;
        SortPolinoms();
        
    }

    void DiffY() {
        TNode<TMonom>* tmp = this->polinomslist.GetFirst();
        TRingHeadList<TMonom> list;
        string id_pol1 = "";
        this->polinomslist.reset();
        while (!this->polinomslist.isended()) {
            int sv = tmp->key.GetDegree();
            int x = sv / 100;
            int y = sv / 10 % 10;
            int z = sv % 100 % 10;
            double value = tmp->key.GetCoeff();
            if (y != 0) {
                value *= y; y--;
                TMonom t(value, x * 100 + y * 10 + z);
                list.InsertEnd(t);
                string s;
                stringstream str;
                str << value;
                s = str.str() + compileMonom(x, y, z);
                if (list.GetFirst() != nullptr) {
                    if (value > 0) {
                        id_pol1 += "+" + s;
                    }
                }
                else {
                    id_pol1 += s;
                }
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
            CheckPolinoms(tmp1->key.GetCoeff(), tmp1->key.GetDegree());
            tmp1 = tmp1->pNext;
            list.next();
        }
        this->id_pol = id_pol1;
        SortPolinoms();

    }

    void DiffZ() {
        TNode<TMonom>* tmp = this->polinomslist.GetFirst();
        TRingHeadList<TMonom> list;
        string id_pol1 = "";
        this->polinomslist.reset();
        while (!this->polinomslist.isended()) {
            int sv = tmp->key.GetDegree();
            int x = sv / 100;
            int y = sv / 10 % 10;
            int z = sv % 100 % 10;
            double value = tmp->key.GetCoeff();
            if (z != 0) {
                value *= z; z--;
                TMonom t(value, x * 100 + y * 10 + z);
                list.InsertEnd(t);
                string s;
                stringstream str;
                str << value;
                s = str.str() + compileMonom(x, y, z);
                if (list.GetFirst() != nullptr) {
                    if (value > 0) {
                        id_pol1 += "+" + s;
                    }
                }
                else {
                    id_pol1 += s;
                }
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
            CheckPolinoms(tmp1->key.GetCoeff(), tmp1->key.GetDegree());
            tmp1 = tmp1->pNext;
            list.next();
        }
        this->id_pol = id_pol1;
        SortPolinoms();
    }

    TPolinom operator+(const TMonom& mon) {
        TNode<TMonom>* a = this->polinomslist.Search(mon);
        if (!this->polinomslist.isended()) {
            TMonom t(a->key.GetCoeff(), a->key.GetDegree());
            TMonom t1 = t+mon;
            this->polinomslist.InsertEnd(t1);
            this->polinomslist.Delete(mon);
        }
        else {
            this->polinomslist.InsertEnd(mon);
        }
        SortPolinoms();
        return *this;
    }

    TPolinom operator+(const TPolinom& pol) {
        TNode<TMonom>* tmp = pol.polinomslist.GetFirst();
        TPolinom p = pol;
        p.polinomslist.reset();
        while (!p.polinomslist.isended()) {
            TNode<TMonom>* a = this->polinomslist.Search(tmp->key);
            if (!this->polinomslist.isended()) {
                TMonom t(a->key.GetCoeff(), a->key.GetDegree());
                TMonom t1 = t + tmp->key;
                this->polinomslist.InsertEnd(t1);
                this->polinomslist.Delete(tmp->key);
            }
            else {
                if (tmp->key.GetCoeff() != 0) { this->polinomslist.InsertEnd(tmp->key); }
            }
            tmp = tmp->pNext;
            p.polinomslist.next();
        }
        SortPolinoms();
        return *this;
    }

    TPolinom operator-(const TMonom& mon) {
        TNode<TMonom>* a = this->polinomslist.Search(mon);
        if (!this->polinomslist.isended()) {
            TMonom t(a->key.GetCoeff(), a->key.GetDegree());
            TMonom t1 = t - mon;
            if (t1.GetCoeff() != 0) { this->polinomslist.InsertEnd(t1); }
            this->polinomslist.Delete(mon);
        }
        else {
            TMonom t((-1)*mon.GetCoeff(), mon.GetDegree());
            if (t.GetCoeff() != 0) { this->polinomslist.InsertEnd(t); }
        }
        SortPolinoms();
        return *this;
    }

    TPolinom operator-(const TPolinom& pol) {
        TPolinom p = pol;
        return *this + (p * (-1.0));
    }

    TPolinom operator*(double scalar) {
        TNode<TMonom>* tmp = this->polinomslist.GetFirst();
        TRingHeadList<TMonom> list;
        this->polinomslist.reset();
        while (!this->polinomslist.isended()) {
            double b = tmp->key.GetCoeff() * scalar;
            TMonom t(b, tmp->key.GetDegree());
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
            CheckPolinoms(tmp1->key.GetCoeff(), tmp1->key.GetDegree());
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
            double b = tmp->key.GetCoeff() * monom.GetCoeff();
            double c = tmp->key.GetDegree() + monom.GetDegree();
            TMonom t(b,c);
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
            CheckPolinoms(tmp1->key.GetCoeff(), tmp1->key.GetDegree());
            tmp1 = tmp1->pNext;
            list.next();
        }
        SortPolinoms();
        return *this;

    }

    TPolinom operator*(const TPolinom& pol) {
        TNode<TMonom>* tmp = this->polinomslist.GetFirst();
        TNode<TMonom>* tmp1 = pol.polinomslist.GetFirst();
        TPolinom p2 = pol;
        p2.polinomslist.reset();
        TPolinom p1;
        TPolinom p;
        p = *this;
        p1 = p * tmp1->key;
        tmp1 = tmp1->pNext;
        p2.polinomslist.next();
        while (!p2.polinomslist.isended()) {
            p = *this;
            p = p * tmp1->key;
            p1 =p1+p;
            tmp1 = tmp1->pNext;
            p2.polinomslist.next();
        }
        *this = p1;
        SortPolinoms();
        return *this;
    }

    double operator()(double x, double y, double z) { // TODO: x, y, z
        TList<double> num;
        TNode<TMonom>* tmp = this->polinomslist.GetFirst();
        double res = 0;
        this->polinomslist.reset();
        while (!this->polinomslist.isended()) {
      
            res += tmp->key.operator()(x,y,z);
            tmp = tmp->pNext;
            this->polinomslist.next();
        }
        return res;
    }
    /*
    friend ostream& operator<<(ostream& ostr, const TPolinom& pol)
    {
        ostr << endl;
        TNode<TMonom>* tmp = pol.polinomslist.GetFirst();
        TPolinom p = pol;
        string s;
        p.polinomslist.reset();
        while (!p.polinomslist.isended()) {
            if (tmp != p.polinomslist.GetFirst()) {
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
    */
};
