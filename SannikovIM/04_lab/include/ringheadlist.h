#pragma once
#include "headlist.h"
template <typename T>
class TRingHeadList : public THeadList<T> {
public:
	TRingHeadList() : THeadList<T>() {
		this->pStop = this->pHead;
		this->pHead->pNext = this->pStop;
	}
	~TRingHeadList() {
		if (this->pFirst == nullptr || this->pFirst == this->pStop) {
			delete this->pHead;
			this->pHead = nullptr;
			return;
		}
		TNode<T>* tmp = this->pFirst;
		while (tmp != this->pStop) {
			TNode<T>* toDelete = tmp;
			tmp = tmp->pNext;
			delete toDelete;
		}
		delete this->pHead;
		this->pHead = nullptr;
		this->pFirst = nullptr;
		this->pStop = nullptr;
	}
	void InsertEnd(T key) {
		TList<T>::InsertEnd(key);
		this->pHead->pNext = this->pFirst;
	}
	void DeleteLast() {
		TList<T>::DeleteLast();
		this->pHead->pNext = this->pFirst;
	}

};
