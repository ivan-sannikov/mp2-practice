#pragma once
#include "headlist.h"
template <typename T>
class TRingHeadList : public THeadList<T> {
public:
	TRingHeadList() {
		//this->pFirst = nullptr;
		this->pStop = this->pHead;
		//this->pStop->pNext = nullptr;
	}
	~TRingHeadList() {
		while (pFirst != pStop) {
			TNode<T>* tmp = pFirst;
			pFirst = pFirst->pNext;
			delete tmp;
		}
	}
	void SetHead(TNode<T>* q) {
		this->pHead = q;
		this->pStop = this->pHead;
		//this->pHead->pNext = this->pFirst;
		this->pFirst = this->pHead;
	}
	TNode<T>* GetHead() { return this->pHead; }
	void InsertEnd(T key) {
		TNode<T>* tmp1 = new TNode<T>(key);
		if (pFirst == pStop) {
			this->pFirst = tmp1;
			this->pFirst->pNext = this->pHead;
			return;
		}
		TNode<T>* tmp = this->pFirst;
		while (tmp->pNext != pStop) {
			tmp = tmp->pNext;
		}
		tmp1->pNext = this->pHead;
		tmp->pNext = tmp1;
		//this->pHead->pNext = this->pFirst;
		
		//cout << tmp1->pNext << endl;

	}
	void InsertFirst(T key) {
		TNode<T>* tmp1 = new TNode<T>(key);
		if (pFirst == pStop) {
			pFirst = tmp1;
			pFirst->pNext = this->pHead;
			
			return;
		}
		TNode<T>* tmp = this->pFirst;
		tmp1->pNext = tmp;
		this->pFirst = tmp1;
		
	}
	
};
