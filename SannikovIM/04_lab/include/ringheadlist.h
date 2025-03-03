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
		this->pHead->pNext = this->pFirst;
		this->pFirst = this->pHead;
	}
	void InsertEnd(T key) {
		TNode<T>* tmp1 = new TNode<T>(key);
		if (pFirst == pStop) {
			this->pFirst = tmp1;
			//this->pStop = this->pHead;
			this->pFirst->pNext = this->pStop;
			return;
		}
		TNode<T>* tmp = this->pFirst;
		while (tmp->pNext != pStop) {
			tmp = tmp->pNext;
		}
		tmp1->pNext = this->pStop;
		tmp->pNext = tmp1;
		this->pHead->pNext = this->pFirst;

	}
	void DeleteLast() {
		if (pFirst == pStop)
			throw "List is empty";

		if (pFirst->pNext == pStop) {
			delete pFirst;
			pFirst = pStop;
			this->pHead->pNext = this->pFirst;
			return;
		}

		TNode<T>* tmp = pFirst;
		while (tmp->pNext != pLast) {
			tmp = tmp->pNext;
		}

		delete pLast;
		tmp->pNext = pStop;
		this->pLast = tmp;
	}
};
