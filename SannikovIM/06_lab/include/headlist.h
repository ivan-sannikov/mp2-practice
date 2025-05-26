#pragma once

#include "list.h"

template <typename TKey>
class THeadList : public TList<TKey> {
protected:
	TNode<TKey>* pHead;
public:
	THeadList() : TList<TKey>() {
		this->pHead = new TNode<TKey>();
		this->pHead->pNext = this->pFirst;
	}
	THeadList(const THeadList& other) :TList<TKey>(other) {
		this->pHead = new TNode<TKey>();
		this->pHead->pNext = this->pFirst;
	}
	~THeadList() {
		delete this->pHead;
		
	}
	virtual void InsertFirst(TKey key) {
		TList<TKey>::InsertFirst(key);
		this->pHead->pNext = this->pFirst;
	}
	virtual void DeleteFirst() {
		TList<TKey>::DeleteFirst();
		this->pHead->pNext = this->pFirst;
	}
	const THeadList& operator=(const THeadList& other) {
		//delete pHead;
		this->pHead = nullptr;
		TList<TKey>::operator=(other);
		this->pHead = new TNode<TKey>();
		this->pHead->pNext = this->pFirst;
		return *this;
	}
	
};
/*


*/