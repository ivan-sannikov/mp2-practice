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
/*
    void TPolinom::CheckPolinoms(string monom) {
        TMonom t(monom);
        TNode<TMonom>* tmp = this->monoms.GetFirst();
        this->monoms.reset();
        if (!this->monoms.isended()) {
            while (tmp->key != t && !this->monoms.isended())
            {
                tmp = tmp->pNext;
                this->monoms.next();
            }
            if (this->monoms.isended()) this->monoms.InsertEnd(t);
            else {
                TMonom t1(t + tmp->key);
                this->monoms.InsertEnd(t1);
            }
        }
        else {
            this->monoms.InsertEnd(t);
        }
        this->monoms.reset();
    }
    void TPolinom::CheckPolinoms(double coeff, int degree) {
        TMonom t(coeff, degree);
        TNode<TMonom>* tmp = this->monoms.GetFirst();
        this->monoms.reset();
        if (!this->monoms.isended()) {
            while (tmp->key != t && !this->monoms.isended())
            {
                tmp = tmp->pNext;
                this->monoms.next();
            }
            if (this->monoms.isended()) this->monoms.InsertEnd(t);
            else {
                TMonom t1(t + tmp->key);
                this->monoms.InsertEnd(t1);
            }
        }
        else {
            this->monoms.InsertEnd(t);
        }
        this->monoms.reset();
    }

    void TPolinom::SortPolinoms() {
        TRingHeadList<TMonom> list;
        this->monoms.reset();
        while (!this->monoms.isended()) {
            TNode<TMonom>* tmp = this->monoms.GetFirst();
            TNode<TMonom>* tmpmin = this->monoms.GetFirst();

            while (!this->monoms.isended()) {
                if (tmp->key < tmpmin->key) {
                    tmpmin = tmp;
                }
                this->monoms.next();
                tmp = tmp->pNext;
            }
            list.InsertFirst(tmpmin->key);
            this->monoms.Delete(tmpmin->key);
            this->monoms.reset();


        }
        list.reset();
        while (!list.isended()) {
            TNode<TMonom>* tmp = list.GetFirst();
            this->monoms.InsertEnd(tmp->key);
            list.DeleteFirst();
            list.reset();
        }
    }
    */
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
                CheckPolinoms(monom);
                monom = "";
            }
            monom += polinom[i];
            i++;
        }
        TMonom t(monom);
        this->monoms.InsertEnd(t);
        SortPolinoms();

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
        TRingHeadList<TMonom> list;
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
                TMonom t(value, x * 100 + y * 10 + z);
                list.InsertEnd(t);
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

    TPolinom TPolinom::DiffY() {
        TNode<TMonom>* tmp = this->monoms.GetFirst();
        TRingHeadList<TMonom> list;
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
                list.InsertEnd(t);
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
        this->monoms.reset();
        while (!this->monoms.isended()) {
            this->monoms.DeleteFirst();
            this->monoms.reset();
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

    TPolinom TPolinom::DiffZ() {
        TNode<TMonom>* tmp = this->monoms.GetFirst();
        TRingHeadList<TMonom> list;
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
                list.InsertEnd(t);
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
        this->monoms.reset();
        while (!this->monoms.isended()) {
            this->monoms.DeleteFirst();
            this->monoms.reset();
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

    TPolinom TPolinom::operator+(const TMonom& mon) {
        TNode<TMonom>* a = this->monoms.Search(mon);
        if (!this->monoms.isended()) {
            TMonom t(a->key.GetCoeff(), a->key.GetDegree());
            TMonom t1 = t + mon;
            this->monoms.InsertEnd(t1);
            this->monoms.Delete(mon);
        }
        else {
            this->monoms.InsertEnd(mon);
        }
        SortPolinoms();
        this->id_pol = GetPolinom(*this);
        return *this;
    }

    TPolinom TPolinom::operator+(const TPolinom& pol) {
        TNode<TMonom>* tmp = pol.monoms.GetFirst();
        TPolinom p = pol;
        p.monoms.reset();
        while (!p.monoms.isended()) {
            TNode<TMonom>* a = this->monoms.Search(tmp->key);
            if (!this->monoms.isended()) {
                TMonom t(a->key.GetCoeff(), a->key.GetDegree());
                TMonom t1 = t + tmp->key;
                this->monoms.InsertEnd(t1);
                this->monoms.Delete(tmp->key);
            }
            else {
                if (tmp->key.GetCoeff() != 0) { this->monoms.InsertEnd(tmp->key); }
            }
            tmp = tmp->pNext;
            p.monoms.next();
        }
        SortPolinoms();
        this->id_pol = GetPolinom(*this);
        return *this;
    }

    TPolinom TPolinom::operator-(const TMonom& mon) {
        TNode<TMonom>* a = this->monoms.Search(mon);
        if (!this->monoms.isended()) {
            TMonom t(a->key.GetCoeff(), a->key.GetDegree());
            TMonom t1 = t - mon;
            if (t1.GetCoeff() != 0) { this->monoms.InsertEnd(t1); }
            this->monoms.Delete(mon);
        }
        else {
            TMonom t((-1) * mon.GetCoeff(), mon.GetDegree());
            if (t.GetCoeff() != 0) { this->monoms.InsertEnd(t); }
        }
        SortPolinoms();
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
            CheckPolinoms(tmp1->key.GetCoeff(), tmp1->key.GetDegree());
            tmp1 = tmp1->pNext;
            list.next();
        }
        SortPolinoms();
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
            CheckPolinoms(tmp1->key.GetCoeff(), tmp1->key.GetDegree());
            tmp1 = tmp1->pNext;
            list.next();
        }
        SortPolinoms();
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
            CheckPolinoms(tmp2->key.GetCoeff(), tmp2->key.GetDegree());
            tmp2 = tmp2->pNext;
            p1.monoms.next();
        }
        
        SortPolinoms();
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
    
