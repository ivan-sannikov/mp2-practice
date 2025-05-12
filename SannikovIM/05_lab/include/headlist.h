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
	THeadList(const THeadList& other) :TList<T>(other) {
		this->pHead = new TNode<T>();
		this->pHead->pNext = this->pFirst;
	}
	~THeadList() {
		delete this->pHead;
		
	}
	virtual void InsertFirst(T key) {
		TList<T>::InsertFirst(key);
		this->pHead->pNext = this->pFirst;
	}
	virtual void DeleteFirst() {
		TList<T>::DeleteFirst();
		this->pHead->pNext = this->pFirst;
	}
	const THeadList& operator=(const THeadList& other) {
		//delete pHead;
		this->pHead = nullptr;
		TList<T>::operator=(other);
		this->pHead = new TNode<T>();
		this->pHead->pNext = this->pFirst;
		return *this;
	}
	
};
/*


*/