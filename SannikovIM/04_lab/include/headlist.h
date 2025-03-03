#pragma once
#include "list.h"
template <typename T>
class THeadList : public TList<T> {
protected:
	TNode<T>* pHead;

public:
	THeadList(){
	//	this->pFirst = this->pStop;
		this->pHead = nullptr;
		
		//this->pHead->pNext = this->pFirst;
		
	}
	void SetHead(TNode<T>* q) {
		this->pHead = q;
		this->pHead->pNext = this->pFirst;
	}
	
};
