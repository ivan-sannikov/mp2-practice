#pragma once
#include "headlist.h"
template <typename T>
class TRingHeadList : public THeadList<T>() {
public:
	THeadList() : this->pFirst(nullptr) {
		pStop.pNext = this->pHead;
	}
};