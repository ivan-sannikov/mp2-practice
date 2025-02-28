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

  /*  int partition(vector<int>& vec, int low, int high) {
        int pivot = vec[high];
        int i = (low - 1);
        for (int j = low; j <= high - 1; j++) {
            if (vec[j] <= pivot) {
                i++;
                swap(vec[i], vec[j]);
            }
        }
        swap(vec[i + 1], vec[high]);
        return (i + 1);
    }

    void quickSort(vector<int>& vec, int low, int high) {
        if (low < high) {
            int pi = partition(vec, low, high);
            quickSort(vec, low, pi - 1);
            quickSort(vec, pi + 1, high);
        }
    }*/
public:
    TPolinom(string polinom){
    
        int len = strlen(polinom.c_str());
        int i = 0;
        string monom = "";
        while(i<len){
            if((polinom[i] == '+' || polinom[i] == '-') && i != 0){
                TMonom t(monom);
                TNode<TMonom>* tmp = polinomslist.GetFirst();
                if(tmp != nullptr){
                    while (tmp->key.GetConvolution() != t.GetConvolution() && tmp->pNext != nullptr)
                    {
                        tmp = tmp->pNext;
                    }
                    if (tmp->key.GetConvolution() != t.GetConvolution() && tmp->pNext == nullptr) tmp = nullptr;
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
                }
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