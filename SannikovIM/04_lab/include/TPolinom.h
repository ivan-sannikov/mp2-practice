#pragma once
#include "TMonom.h"
#include "list.h"
#include "ringheadlist.h"
#include <string>
#include <iostream>

using namespace std;
template <typename T>
class TPolinom{
private: 
    TRingHeadList<TMonom> polinomslist;
    //TList<TMonom> list;

    void SortPolinoms(){
		TRingHeadList<TMonom> list;
		while(this->polinomslist.GetFirst() != nullptr){
			TNode<TMonom>* tmp = polinomslist.GetFirst();
			TNode<TMonom>* tmpmin = polinomslist.GetFirst();
			
				while(tmp != nullptr){
					
					if(tmp->key.GetConvolution() < tmpmin->key.GetConvolution()){
						tmpmin = tmp;
					}
					tmp = tmp->pNext;
				}
			
			polinomslist.Delete(tmpmin->key);
			list.InsertAfter(list.GetFirst()->key, tmpmin->key);
			
		}
	polinomslist = list;
	TNode<TMonom>* tmp = list.GetFirst();
	while(tmp != nullptr){
		cout<<tmp->key.GetConvolution()<<endl;
		tmp = tmp->pNext;
	}
	}
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
		SortPolinoms();
       // TNode<TMonom>* a = polinomslist.GetFirst();
        
    }

	//bool operator==(TPolinom<T>& pol)
  
};
