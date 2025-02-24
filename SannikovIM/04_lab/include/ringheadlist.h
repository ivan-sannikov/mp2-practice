#pragma once
#include "headlist.h"
template <typename T>
class TRingHeadList : public THeadList<T> {
public:
	TRingHeadList() {
		this->pFirst = nullptr;
		//this->pStop = new TNode<T>(T());
		//this->pStop->pNext = nullt
	}
};
