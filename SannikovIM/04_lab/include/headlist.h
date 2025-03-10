#pragma once
#include "list.h"

template <typename T>
class THeadList : public TList<T> {
protected:
	TNode<T>* pHead;
public:
	THeadList() : TList<T>() {
		this->pHead = new TNode<T>();
		this->pHead->pNext = this->pFirst;
	}
	~THeadList() {
	//	TList<T>::~TList();
		delete pHead;
	}
	virtual void InsertFirst(T key) {
		TList<T>::InsertFirst(key);
		this->pHead->pNext = this->pFirst;
	}
	virtual void DeleteFirst() {
		TList<T>::DeleteFirst();
		this->pHead->pNext = this->pFirst;
	}

	
};
