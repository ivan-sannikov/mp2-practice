#pragma once
#include "list.h"

template <typename T>
class THeadList : public TList<T> {
protected:
	TNode<T>* pHead;
public:
	THeadList() : TList<T>() {
		this->pHead = nullptr;
		
	}
	void SetHead(T key) {
		this->pHead = new TNode<T>(key);
		this->pHead->pNext = this->pFirst;
	}
	TNode<T>* GetHead() { return this->pHead; }
	void InsertFirst(T key) {
		TNode<T>* tmp1 = new TNode<T>(key);
		if (pFirst == pStop) {
			this->pFirst = tmp1;
			this->pLast = this->pFirst;
			this->pHead->pNext = this->pFirst;
			return;
		}
		tmp1->pNext = this->pFirst;
		this->pFirst = tmp1;
		this->pHead->pNext = this->pFirst;
	}
	void DeleteFirst() {
		if (pFirst == pStop)
			throw "List is empty"; // TODO: throw

		if (pFirst->pNext == pStop) {
			delete pFirst;
			pFirst = pLast = pStop;
			this->pHead->pNext = this->pFirst;
			return;
		}

		TNode<T>* tmp = pFirst->pNext;
		delete pFirst;
		this->pFirst = tmp;
		this->pHead->pNext = this->pFirst;
	}

	
};
