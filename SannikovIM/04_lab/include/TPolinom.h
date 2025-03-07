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
        if (tmp != polinomslist.GetLast()->pNext) {
            while (tmp->key.GetConvolution() != t.GetConvolution() && tmp->pNext != polinomslist.GetLast()->pNext)
            {
                tmp = tmp->pNext;
            }
            if (tmp->key.GetConvolution() != t.GetConvolution() && tmp->pNext == polinomslist.GetLast()->pNext) tmp = polinomslist.GetLast()->pNext;
            if (tmp == polinomslist.GetLast()->pNext) this->polinomslist.InsertEnd(t);
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
    }

    void SortPolinoms() {
        TRingHeadList<TMonom> list;
        list.SetHead(this->polinomslist.GetHead()->key);
        while (this->polinomslist.GetFirst() != this->polinomslist.GetLast()->pNext) {
            TNode<TMonom>* tmp = this->polinomslist.GetFirst();
            TNode<TMonom>* tmpmin = this->polinomslist.GetFirst();

            while (tmp != polinomslist.GetLast()->pNext) {
                if (tmp->key.GetConvolution() < tmpmin->key.GetConvolution()) {
                    tmpmin = tmp;
                }
                tmp = tmp->pNext;
            }
            list.InsertFirst(tmpmin->key);
            this->polinomslist.Delete(tmpmin->key);


        }
        while (list.GetFirst() != list.GetLast()->pNext) {
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
        this->polinomslist.SetHead(t1);
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

    TPolinom() {
        TMonom t1("0z^-1");
        this->polinomslist.SetHead(t1);
    }

    TPolinom(TRingHeadList<TMonom>& list) {
        TMonom t1("0z^-1");
        this->polinomslist.SetHead(t1);
        TNode<TMonom>* tmp = list.GetFirst();
        while (tmp != list.GetLast()->pNext) {
            this->polinomslist.InsertEnd(tmp->key);
            tmp = tmp->pNext;
          
        }
        SortPolinoms();
    }

    TPolinom(const TPolinom& other) {
        
        TMonom zeroMonom(other.GetList().GetHead()->key.GetMonom());
        this->polinomslist.SetHead(zeroMonom);
        TNode<TMonom>* tmp = other.polinomslist.GetFirst();
        while (tmp != other.polinomslist.GetLast()->pNext) {
            this->polinomslist.InsertEnd(tmp->key);
            tmp = tmp->pNext;
        }
    }

    const TRingHeadList<TMonom>& GetList() const {
        return polinomslist;
    }

    bool operator==(const TPolinom& pol) const  {
        TNode<TMonom>* tmpthis = this->polinomslist.GetFirst();
        TNode<TMonom>* tmppol = pol.GetList().GetFirst();
        while (tmpthis != polinomslist.GetLast()->pNext && tmppol != polinomslist.GetLast()->pNext) {
            if (tmpthis->key.GetConvolution() != tmppol->key.GetConvolution()) return 0;
            //cout<< tmpthis->key.GetValue()<<
            if (tmpthis->key.GetValue() != tmppol->key.GetValue()) return 0;
            tmpthis = tmpthis->pNext;
            tmppol = tmppol->pNext;
        }
        if ((tmpthis == polinomslist.GetLast()->pNext && tmppol != pol.GetList().GetLast()->pNext) || (tmpthis != polinomslist.GetLast()->pNext && tmppol == pol.GetList().GetLast()->pNext)) return 0;
        return 1;
    }

    bool operator!=(const TPolinom& pol) const  {
        return !(*this == pol);
    }

    TPolinom& operator=(const TPolinom& pol) {
        if (this == &pol) {
            return *this;
        }
        while (this->polinomslist.GetFirst() != this->polinomslist.GetLast()->pNext) {
            this->polinomslist.DeleteFirst();
        }
        TNode<TMonom>* tmp = pol.GetList().GetFirst();
        while (tmp != pol.GetList().GetLast()->pNext) {
            this->polinomslist.InsertEnd(tmp->key);
            tmp = tmp->pNext;
        }
        return *this;
    }

    void DiffX() {
        TNode<TMonom>* tmp = this->polinomslist.GetFirst();
        TRingHeadList<TMonom> list;
        list.SetHead(this->polinomslist.GetHead()->key);
        while (tmp != this->polinomslist.GetLast()->pNext) {
            int sv = tmp->key.GetConvolution();
            int x = sv / 100;
            int y = sv / 10 % 10;
            int z = sv % 100 % 10;
            double value = tmp->key.GetValue();
            if (x != 0 || y != 0 || z != 0) {
            if (x != 0) {
                value *= x; x--;
            }
            
                stringstream str;
                str << value;
                string s = str.str();
                TMonom t(s + compileMonom(x, y, z));
                list.InsertEnd(t);
            }
            tmp = tmp->pNext;
        }
        while (this->polinomslist.GetFirst() != this->polinomslist.GetLast()->pNext) {
            this->polinomslist.DeleteFirst();
        }
        TNode<TMonom>* tmp1 = list.GetFirst();
        while (tmp1 != list.GetLast()->pNext) {
            CheckPolinoms(tmp1->key.GetMonom());
            tmp1 = tmp1->pNext;
        }
    //    CheckPolinoms();
        SortPolinoms();
        
    }

    void DiffY() {
        TNode<TMonom>* tmp = this->polinomslist.GetFirst();
        TRingHeadList<TMonom> list;
        list.SetHead(this->polinomslist.GetHead()->key);
        while (tmp != this->polinomslist.GetLast()->pNext) {
            int sv = tmp->key.GetConvolution();
            int x = sv / 100;
            int y = sv / 10 % 10;
            int z = sv % 100 % 10;
            
            double value = tmp->key.GetValue();
            if (x != 0 || y != 0 || z != 0) {
            if (y != 0) {
                value *= y; y--;
            }
            
                stringstream str;
                str << value;
                string s = str.str();
                TMonom t(s + compileMonom(x, y, z));
                list.InsertEnd(t);
            }
            tmp = tmp->pNext;
        }
        while (this->polinomslist.GetFirst() != this->polinomslist.GetLast()->pNext) {
            this->polinomslist.DeleteFirst();
        }
        TNode<TMonom>* tmp1 = list.GetFirst();
        while (tmp1 != list.GetLast()->pNext) {
            CheckPolinoms(tmp1->key.GetMonom());
            tmp1 = tmp1->pNext;
        }
        SortPolinoms();

    }

    void DiffZ() {
        TNode<TMonom>* tmp = this->polinomslist.GetFirst();
        TRingHeadList<TMonom> list;
        list.SetHead(this->polinomslist.GetHead()->key);
        while (tmp != this->polinomslist.GetLast()->pNext) {
            int sv = tmp->key.GetConvolution();
            int x = sv / 100;
            int y = sv / 10 % 10;
            int z = sv % 100 % 10;
            double value = tmp->key.GetValue();
            if (x != 0 || y != 0 || z != 0) {
            if (z != 0) {
                value *= z; z--;
                
            }
                stringstream str;
                str << value;
                string s = str.str();
                TMonom t(s + compileMonom(x, y, z));
                list.InsertEnd(t);
            }
            tmp = tmp->pNext;
        }
        while (this->polinomslist.GetFirst() != this->polinomslist.GetLast()->pNext) {
            this->polinomslist.DeleteFirst();
        }
        TNode<TMonom>* tmp1 = list.GetFirst();
        while (tmp1 != list.GetLast()->pNext) {
            CheckPolinoms(tmp1->key.GetMonom());
            tmp1 = tmp1->pNext;
        }
        SortPolinoms();
    }

    TPolinom operator+(TMonom& mon) {
        TNode<TMonom>* a = this->polinomslist.Search(mon);
        if (a != polinomslist.GetLast()->pNext) {
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
        while (tmp != pol.GetList().GetLast()->pNext) {
            TNode<TMonom>* a = this->polinomslist.Search(tmp->key);
            if (a != polinomslist.GetLast()->pNext) {
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

    TPolinom operator-(TMonom& mon) {
        TNode<TMonom>* a = this->polinomslist.Search(mon);
        if (a != polinomslist.GetLast()->pNext) {
            stringstream str;
            double b = a->key.GetValue() + ((-1)*mon.GetValue());
            str << b;
            string s = str.str() + mon.GetMonomConv();
            TMonom t(s);
            this->polinomslist.InsertEnd(t);
            this->polinomslist.Delete(mon);
        }
        else {
            stringstream str;
            double b = ((-1) * mon.GetValue());
            str << b;
            string s = str.str() + mon.GetMonomConv();
            TMonom t(s);
            this->polinomslist.InsertEnd(t);
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
        list.SetHead(this->polinomslist.GetHead()->key);
        while (tmp != this->polinomslist.GetLast()->pNext) {
            double b = tmp->key.GetValue() * scalar;
            stringstream str;
            str << b;
            string s = str.str() + tmp->key.GetMonomConv();
            TMonom t(s);
            list.InsertFirst(t);
            tmp = tmp->pNext;
        }
        while (this->polinomslist.GetFirst() != this->polinomslist.GetLast()->pNext) {
            this->polinomslist.DeleteFirst();
        }
        TNode<TMonom>* tmp1 = list.GetFirst();
        while (tmp1 != list.GetLast()->pNext) {
            CheckPolinoms(tmp1->key.GetMonom());
            tmp1 = tmp1->pNext;
        }
        SortPolinoms();
        return *this;

    }

    TPolinom operator*(TMonom& monom) {
        TNode<TMonom>* tmp = this->polinomslist.GetFirst();
        TRingHeadList<TMonom> list;
        list.SetHead(this->polinomslist.GetHead()->key.GetMonom());
        while (tmp != this->polinomslist.GetLast()->pNext) {
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
        }
        while (this->polinomslist.GetFirst() != this->polinomslist.GetLast()->pNext) {
            this->polinomslist.DeleteFirst();
        }
        TNode<TMonom>* tmp1 = list.GetFirst();
        while (tmp1 != list.GetLast()->pNext) {
            CheckPolinoms(tmp1->key.GetMonom());
            tmp1 = tmp1->pNext;
        }
        SortPolinoms();
        return *this;

    }

    TPolinom operator*(TPolinom& pol) {
        TNode<TMonom>* tmp = this->polinomslist.GetFirst();
        TNode<TMonom>* tmp1 = pol.GetList().GetFirst();
        TPolinom p1;
        TPolinom p;
        p = *this;
        p1 = p * tmp1->key;
        tmp1 = tmp1->pNext;
        while (tmp1 != pol.GetList().GetLast()->pNext) {
            p = *this;
            p = p * tmp1->key;
            p1 =p1+p;
            tmp1 = tmp1->pNext;
        }
        *this = p1;
        SortPolinoms();
        return *this;
    }

    double operator()(double* operands) {
        TList<double> num;
        TNode<TMonom>* tmp = this->polinomslist.GetFirst();
        double res = 0;
        cout << "222" << endl;
        while (tmp != this->polinomslist.GetLast()->pNext) {
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

    friend ostream& operator<<(ostream& ostr, TPolinom& pol)
    {
        ostr << endl;
        TNode<TMonom>* tmp = pol.GetList().GetFirst();
        string s;
    
        TNode<TMonom>* g = pol.GetList().GetLast()->pNext;
        while (tmp != pol.GetList().GetLast()->pNext) {
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
