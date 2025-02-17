#pragma once
#include "list.h"
template <typename T>
class THeadList : public TList<T>() {
protected:
	TNode<T>* pHead;
public:
	THeadList(): pFirst(nullptr) {
		pHead = new TNode<int>(0);
		pHead.pNext = this->pFirst;
	}
};