#pragma once
#include "TMonom.h"
#include "list.h"
#include "ringheadlist.h"
#include <string>
#include <iostream>
#include <cmath>

using namespace std;
class TPolinom{
private: 
    TRingHeadList<TMonom> polinomslist;

    void CheckPolinoms(string monom) {
        TMonom t(monom);
        TNode<TMonom>* tmp = this->polinomslist.GetFirst();
        this->polinomslist.reset();
        if (!this->polinomslist.isended()) {
            while (tmp->key.GetConvolution() != t.GetConvolution() && !this->polinomslist.isended())
            {
                tmp = tmp->pNext;
                this->polinomslist.next();
            }
            if (this->polinomslist.isended()) this->polinomslist.InsertEnd(t);
            else {
                double a = tmp->key.GetValue();
                polinomslist.Delete(tmp->key);
                stringstream str;
                str << (double)(a + t.GetValue());
                if (a + t.GetValue() > 0) {
                    string s = str.str() + t.GetMonomConv();
                    if (tmp != polinomslist.GetFirst()) {
                        s = "+" + s;
                    }
                    TMonom t1(s);
                    polinomslist.InsertEnd(t1);
                }
                if (a + t.GetValue() < 0) {
                    string s = str.str() + t.GetMonomConv();
                    TMonom t1(s);
                    polinomslist.InsertEnd(t1);
                }

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
                if (tmp->key.GetConvolution() < tmpmin->key.GetConvolution()) {
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
    TPolinom(string polinom){
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
    ~TPolinom() {
        this->polinomslist.reset();
        while (!this->polinomslist.isended()) {
            this->polinomslist.DeleteFirst();
            this->polinomslist.reset();
        }
    }
    
    TPolinom(const TPolinom& other) {
        TRingHeadList<TMonom> l(other.polinomslist);
        this->polinomslist = l;
    }

    const TRingHeadList<TMonom>& GetList() const {
        return polinomslist;
    }
    
    bool operator==(const TPolinom& other) const {
        TPolinom p1(*this);
        TPolinom p2(other);
        p1.polinomslist.reset();
        p2.polinomslist.reset();
        TNode<TMonom>* tmpThis = p1.polinomslist.GetFirst();
        TNode<TMonom>* tmpOther = p2.polinomslist.GetFirst();

        while (!p1.polinomslist.isended() && !p2.polinomslist.isended()) {
            if (tmpThis->key != tmpOther->key) {
                return false;
            }
            tmpThis = tmpThis->pNext;
            tmpOther = tmpOther->pNext;
            p1.polinomslist.next();
            p2.polinomslist.next();
        }

        return p1.polinomslist.isended() && p2.polinomslist.isended();
    }
    
    bool operator!=(const TPolinom& pol) const {
        return !(*this == pol);
    }
    
    TPolinom& operator=(const TPolinom& other) {
        if (this == &other) {
            return *this;
        }
        TPolinom p1(other);
        this->polinomslist.reset();
        while (!this->polinomslist.isended()) {
            this->polinomslist.DeleteFirst();
            this->polinomslist.reset();
        }
        p1.polinomslist.reset();
        TNode<TMonom>* tmp = p1.polinomslist.GetFirst();
        while (!p1.polinomslist.isended()) {
            this->polinomslist.InsertEnd(tmp->key);
            tmp = tmp->pNext;
            p1.polinomslist.next();
        }

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

    TPolinom operator+(TMonom& mon) {
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

    TPolinom operator+(TPolinom& pol) {
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

    TPolinom operator-(TMonom& mon) {
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

    TPolinom operator-(TPolinom& pol) {
        return *this + (pol * -1);
    }

    TPolinom operator*(int scalar) {
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
    TPolinom operator*(TMonom& monom) {
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

    TPolinom operator*(TPolinom& pol) {
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

    double operator()(double* operands) {
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

    friend ostream& operator<<(ostream& ostr, TPolinom& pol)
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
