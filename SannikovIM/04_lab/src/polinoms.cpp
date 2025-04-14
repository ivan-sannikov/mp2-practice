#include "TPolinom.h"


void TPolinom::GetPolinom() {
    TPolinom pol = *this;
    pol.monoms.reset();
    TNode<TMonom>* tmp = pol.monoms.GetFirst();
    string id_pol1 = "";
    while (!pol.monoms.isended()) {
        int sv = tmp->key.GetDegree();
        int x = sv / 100;
        int y = sv / 10 % 10;
        int z = sv % 100 % 10;
        double value = tmp->key.GetCoeff();
        string s;
        stringstream str;
        str << value;
        s = str.str() + compileMonom(x, y, z);
        if (id_pol1 != "") {
            if (value > 0) {
                id_pol1 += "+" + s;
            }else if(value<0){
                id_pol1 += s;
            }
        }
        else {
            id_pol1 += s;
        }


        tmp = tmp->pNext;
        pol.monoms.next();
    }
    this->id_pol = id_pol1;
}



void TPolinom::InsertInList(TMonom& m1){
    TNode<TMonom>* searchDegree = this->monoms.Search(m1);
    if(searchDegree == nullptr){
        this->monoms.reset();
        int degr = 0;
        while(!this->monoms.isended()){
            degr = this->monoms.getcurr()->key.GetDegree();
            if(m1.GetDegree() > degr && m1.GetDegree()<this->monoms.getcurr()->pNext->key.GetDegree()){
                this->monoms.InsertAfter(this->monoms.getcurr()->key, m1);
                return;
            }
            this->monoms.next();
        }
        if(degr == 0){
            this->monoms.InsertEnd(m1);
            return;
        }
        if(m1.GetDegree() > degr){
            this->monoms.InsertFirst(m1);
            return;
        }
        if(m1.GetDegree() < degr){
            this->monoms.InsertEnd(m1);
            return;
        }
    }else{
        TMonom m2(searchDegree->key.GetCoeff()+m1.GetCoeff(), m1.GetDegree());
        TMonom m3(searchDegree->pNext->key);
        if(m3.GetDegree() <= 0) {
            this->monoms.Delete(searchDegree->key);
            this->monoms.InsertEnd(m2);
            return;
        }
        this->monoms.Delete(searchDegree->key);
        this->monoms.InsertAfter(m3, m2);
    }
    
}
    string TPolinom::compileMonom(int x, int y, int z) {
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
        switch (y) {
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
    TPolinom::TPolinom(){}
    TPolinom::TPolinom(const string& polinom) {
        this->id_pol = polinom;
        int len = strlen(polinom.c_str());
        int i = 0;
        string monom = "";
        while (i < len) {
            if ((polinom[i] == '+' || polinom[i] == '-') && i != 0) {
                TMonom m1(monom);
                InsertInList(m1);
                monom = "";
            }
            monom += polinom[i];
            i++;
        }
        TMonom m1(monom);
        InsertInList(m1);
    }
    TPolinom::TPolinom(const TPolinom& other) {
        this->id_pol = other.id_pol;
        TRingHeadList<TMonom> l(other.monoms);
        this->monoms = l;
    }
    bool TPolinom::operator==(const TPolinom& other) const {
        return (this->monoms == other.monoms) && (this->id_pol == other.id_pol);
    }

    bool TPolinom::operator!=(const TPolinom& pol) const {
        return !(*this == pol);
    }

    const TPolinom& TPolinom::operator=(const TPolinom& other) {
        if (this == &other) {
            return *this;
        }
        this->id_pol = other.id_pol;
        TRingHeadList<TMonom> l(other.monoms);
        this->monoms = l;
        return *this;
    }


    TPolinom TPolinom::DiffX() {

        this->monoms.reset();
        string id_pol1 = "";
        while (!this->monoms.isended()) {
            int sv = monoms.getcurr()->key.GetDegree();
            int x = sv / 100;
            int y = sv / 10 % 10;
            int z = sv % 100 % 10;
            double value = monoms.getcurr()->key.GetCoeff();
            if (x != 0) {
                value *= x; x--;
                string s;
                stringstream str;
                str << value;
                s = str.str() + compileMonom(x, y, z);
                if (id_pol1 != "") {
                    if (value > 0) {
                        id_pol1 += "+" + s;
                    }
                }
                else {
                    id_pol1 += s;
                }
            }
            this->monoms.next();
        }
        TPolinom p(id_pol1);
        return p;

    }

    TPolinom TPolinom::DiffY() {
        string id_pol1 = "";
        this->monoms.reset();
        while (!this->monoms.isended()) {
            int sv = monoms.getcurr()->key.GetDegree();
            int x = sv / 100;
            int y = sv / 10 % 10;
            int z = sv % 100 % 10;
            double value = monoms.getcurr()->key.GetCoeff();
            if (y != 0) {
                value *= y; y--;
                TMonom t(value, x * 100 + y * 10 + z);
                string s;
                stringstream str;
                str << value;
                s = str.str() + compileMonom(x, y, z);
                if (id_pol1 != "") {
                    if (value > 0) {
                        id_pol1 += "+" + s;
                    }
                }
                else {
                    id_pol1 += s;
                }
            }
            this->monoms.next();
        }
        TPolinom p(id_pol1);
        return p;

    }

    TPolinom TPolinom::DiffZ() {
        string id_pol1 = "";
        this->monoms.reset();
        while (!this->monoms.isended()) {
            int sv = monoms.getcurr()->key.GetDegree();
            int x = sv / 100;
            int y = sv / 10 % 10;
            int z = sv % 100 % 10;
            double value = monoms.getcurr()->key.GetCoeff();
            if (z != 0) {
                value *= z; z--;
                TMonom t(value, x * 100 + y * 10 + z);
                string s;
                stringstream str;
                str << value;
                s = str.str() + compileMonom(x, y, z);
                if (id_pol1 != "") {
                    if (value > 0) {
                        id_pol1 += "+" + s;
                    }
                }
                else {
                    id_pol1 += s;
                }
            }
            this->monoms.next();

        }
        TPolinom p(id_pol1);
        return p;
    }
TPolinom TPolinom::operator+(const double scalar) {
    TMonom m1(scalar, 0);
    TPolinom p(*this);
    p.InsertInList(m1);
    p.GetPolinom();
    return p;
}
TPolinom TPolinom::operator+(const TMonom& mon) {
    TMonom m1(mon);
    TPolinom p(*this);
    p.InsertInList(m1);
    p.GetPolinom();
    return p; 
}

TPolinom TPolinom::operator+(const TPolinom& pol) {
    TPolinom p(pol);
    TPolinom p1(*this);
    p.monoms.reset();
    while (!p.monoms.isended()) {
        p1.InsertInList(p.monoms.getcurr()->key);
        p.monoms.next();
    }
    p1.GetPolinom(); 
    return p1; 
}
TPolinom TPolinom::operator-(const double scalar) {
    TMonom m1(scalar,0);
    TPolinom p1 = *this + (m1 * (-1.0));
    return p1;
}
    TPolinom TPolinom::operator-(const TMonom& mon) {
        TMonom m1 = mon;
        TPolinom p1 = *this + (m1 * (-1.0));
        return p1;
    }

TPolinom TPolinom::operator-(const TPolinom& pol) {
    TPolinom p(pol);
    TPolinom p1 = *this + (p * (-1.0));
    return p1;
}

TPolinom TPolinom::operator*(double scalar) {
    if (scalar == 0) {
        TPolinom p("0");
        return p;
    }
    TPolinom p;
    this->monoms.reset();
    while (!this->monoms.isended()) {
        p.InsertInList(monoms.getcurr()->key * scalar);
        this->monoms.next();
    }
    p.GetPolinom();
    return p;

}
TPolinom TPolinom::operator*(const TMonom& monom) {
    
    TPolinom p;
    this->monoms.reset();
    while (!this->monoms.isended()) {
        p.InsertInList(monoms.getcurr()->key * monom);
        this->monoms.next();
    }
    p.GetPolinom();
    return p;

}

TPolinom TPolinom::operator*(const TPolinom& pol) {
    TPolinom p2(pol);
    p2.monoms.reset();

    TPolinom p1;
    while (!p2.monoms.isended()) {
        TPolinom p(*this);
        p.monoms.reset();

        p = p * p2.monoms.getcurr()->key;
        p1 = p1 + p;
        p1 = p;
        p2.monoms.next();
    }

    p1.GetPolinom();
    return p1;
}

double TPolinom::operator()(double x, double y, double z) const {
    double res = 0;
    TPolinom p(*this);
    p.monoms.reset();
    while (!p.monoms.isended()) {
        res += p.monoms.getcurr()->key(x, y, z);
        p.monoms.next();
    }
    return res;
}
    
ostream& operator<<(ostream& ostr, const TPolinom& pol)
{
    ostr << endl;
    TNode<TMonom>* tmp = pol.monoms.GetFirst();
    TPolinom p = pol;
    p.GetPolinom();
    ostr << p.id_pol;
    ostr << endl;
    return ostr;
}
    
