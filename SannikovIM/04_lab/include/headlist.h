#pragma once
#include "list.h"
template <typename T>
class THeadList : public TList<T> {
protected:
	TNode<T>* pHead;
public:
	THeadList(){
		this->pFirst = this->pStop;
		this->pHead = new TNode<T>(T());
		this->pHead->pNext = this->pFirst;
		
	}
};
