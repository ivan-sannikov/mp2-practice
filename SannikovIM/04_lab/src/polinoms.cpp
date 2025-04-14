#include "TPolinom.h"


    string TPolinom::GetPolinom(const TPolinom& p) {
        TPolinom pol = p;
        pol.monoms.reset();
        TNode<TMonom>* tmp = this->monoms.GetFirst();
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
                }else{
                    id_pol1 += s;
                }
            }
            else {
                id_pol1 += s;
            }


            tmp = tmp->pNext;
            pol.monoms.next();
        }
        return id_pol1;
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

        TNode<TMonom>* tmp = this->monoms.GetFirst();
        this->monoms.reset();
        string id_pol1 = "";
        while (!this->monoms.isended()) {
            int sv = tmp->key.GetDegree();
            int x = sv / 100;
            int y = sv / 10 % 10;
            int z = sv % 100 % 10;
            double value = tmp->key.GetCoeff();
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

            tmp = tmp->pNext;
            this->monoms.next();
        }
        TPolinom p(id_pol1);
        return p;

    }

    TPolinom TPolinom::DiffY() {
        TNode<TMonom>* tmp = this->monoms.GetFirst();
        string id_pol1 = "";
        this->monoms.reset();
        while (!this->monoms.isended()) {
            int sv = tmp->key.GetDegree();
            int x = sv / 100;
            int y = sv / 10 % 10;
            int z = sv % 100 % 10;
            double value = tmp->key.GetCoeff();
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
            tmp = tmp->pNext;
            this->monoms.next();
        }
        TPolinom p(id_pol1);
        return p;

    }

    TPolinom TPolinom::DiffZ() {
        TNode<TMonom>* tmp = this->monoms.GetFirst();
        string id_pol1 = "";
        this->monoms.reset();
        while (!this->monoms.isended()) {
            int sv = tmp->key.GetDegree();
            int x = sv / 100;
            int y = sv / 10 % 10;
            int z = sv % 100 % 10;
            double value = tmp->key.GetCoeff();
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
            tmp = tmp->pNext;
            this->monoms.next();

        }
        TPolinom p(id_pol1);
        return p;
    }
TPolinom TPolinom::operator+(const double scalar) {
    TMonom m1(scalar, 0);
    InsertInList(m1);
    this->id_pol = GetPolinom(*this);
    return *this;
}
    TPolinom TPolinom::operator+(const TMonom& mon) {
        TMonom m1 = mon;
        InsertInList(m1);
        this->id_pol = GetPolinom(*this);
        return *this;
    }

    TPolinom TPolinom::operator+(const TPolinom& pol) {
        TNode<TMonom>* tmp = pol.monoms.GetFirst();
        TPolinom p = pol;
        p.monoms.reset();
        while (!p.monoms.isended()) {
            InsertInList(tmp->key);
            tmp = tmp->pNext;
            p.monoms.next();
        }
        this->id_pol = GetPolinom(*this);
        return *this;
    }
TPolinom TPolinom::operator-(const double scalar) {
    TMonom m1(scalar,0);
    TPolinom p1 = *this + (m1 * (-1.0));
    *this = p1;
    this->id_pol = GetPolinom(*this);
    return *this;
}
    TPolinom TPolinom::operator-(const TMonom& mon) {
        TMonom m1 = mon;
        TPolinom p1 = *this + (m1 * (-1.0));
        *this = p1;
        this->id_pol = GetPolinom(*this);
        return *this;
    }

    TPolinom TPolinom::operator-(const TPolinom& pol) {
        TPolinom p = pol;
        TPolinom p1 = *this + (p * (-1.0));
        *this = p1;
        this->id_pol = GetPolinom(*this);
        return *this;
    }

    TPolinom TPolinom::operator*(double scalar) {
        TNode<TMonom>* tmp = this->monoms.GetFirst();
        TRingHeadList<TMonom> list;
        this->monoms.reset();
        while (!this->monoms.isended()) {
            double b = tmp->key.GetCoeff() * scalar;
            TMonom t(b, tmp->key.GetDegree());
            list.InsertFirst(t);
            tmp = tmp->pNext;
            this->monoms.next();
        }
        this->monoms.reset();
        while (!this->monoms.isended()) {
            this->monoms.DeleteFirst();
            this->monoms.reset();
        }
        TNode<TMonom>* tmp1 = list.GetFirst();
        list.reset();
        while (!list.isended()) {
            InsertInList(tmp1->key);
            tmp1 = tmp1->pNext;
            list.next();
        }
        this->id_pol = GetPolinom(*this);
        return *this;

    }
    TPolinom TPolinom::operator*(const TMonom& monom) {
        TNode<TMonom>* tmp = this->monoms.GetFirst();
        TRingHeadList<TMonom> list;
        this->monoms.reset();
        while (!this->monoms.isended()) {
            double b = tmp->key.GetCoeff() * monom.GetCoeff();
            double c = tmp->key.GetDegree() + monom.GetDegree();
            TMonom t(b, c);
            list.InsertFirst(t);
            tmp = tmp->pNext;
            this->monoms.next();
        }
        this->monoms.reset();
        while (!this->monoms.isended()) {
            this->monoms.DeleteFirst();
            this->monoms.reset();
        }
        TNode<TMonom>* tmp1 = list.GetFirst();
        list.reset();
        while (!list.isended()) {
            InsertInList(tmp1->key);
            tmp1 = tmp1->pNext;
            list.next();
        }
        this->id_pol = GetPolinom(*this);
        return *this;

    }

    TPolinom TPolinom::operator*(const TPolinom& pol) {
        TNode<TMonom>* tmp = this->monoms.GetFirst();
        TNode<TMonom>* tmp1 = pol.monoms.GetFirst();
        TPolinom p2 = pol;
        p2.monoms.reset();
        TPolinom p1;
        TPolinom p;
        p = *this;
        p1 = p * tmp1->key;
        tmp1 = tmp1->pNext;
        p2.monoms.next();
        while (!p2.monoms.isended()) {
            p = *this;
            p = p * tmp1->key;
            p1 = p1 + p;
            tmp1 = tmp1->pNext;
            p2.monoms.next();
        }

        this->monoms.reset();
        while (!this->monoms.isended()) {
            this->monoms.DeleteFirst();
            this->monoms.reset();
        }

        TNode<TMonom>* tmp2 = p1.monoms.GetFirst();
        p1.monoms.reset();
        while (!p1.monoms.isended()) {
            InsertInList(tmp2->key);
            tmp2 = tmp2->pNext;
            p1.monoms.next();
        }
        
        this->id_pol = GetPolinom(*this);
        return *this;
    }

    double TPolinom::operator()(double x, double y, double z) const { // TODO: x, y, z
        TNode<TMonom>* tmp = this->monoms.GetFirst();
        double res = 0;
        TPolinom p = *this;
        p.monoms.reset();
        while (!p.monoms.isended()) {

            res += tmp->key.operator()(x, y, z);
            tmp = tmp->pNext;
            p.monoms.next();
        }
        return res;
    }
    
    ostream& operator<<(ostream& ostr, const TPolinom& pol)
    {
        ostr << endl;
        TNode<TMonom>* tmp = pol.monoms.GetFirst();
        TPolinom p = pol;
        ostr << p.GetPolinom(p);
        ostr << endl;
        return ostr;
    }
    
