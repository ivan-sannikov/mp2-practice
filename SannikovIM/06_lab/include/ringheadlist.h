#pragma once

#include "headlist.h"

template <typename TKey>
class TRingHeadList : public THeadList<TKey> {
public:
	TRingHeadList() : THeadList<TKey>() {
		this->pStop = this->pHead;
		this->pHead->pNext = this->pStop;
	}
	TRingHeadList(const TRingHeadList& other) :THeadList<TKey>(other){
		this->pStop = this->pHead;
		this->pLast->pNext = this->pStop;
	}
	virtual void InsertEnd(TKey key) {
		TList<TKey>::InsertEnd(key);
		this->pLast->pNext = this->pStop;
	}
	~TRingHeadList() {
		// Разрываем кольцо перед удалением pHead
		if (this->pLast != nullptr) {
			this->pLast->pNext = nullptr;  // Иначе delete в ~TList() пойдёт по кольцу
		}
		// pHead удалится в ~THeadList()
	}
	virtual void DeleteLast() {
		TList<TKey>::DeleteLast();
		this->pLast->pNext = this->pStop;
	}
	const TRingHeadList& operator=(const TRingHeadList& other) {
		this->pStop = nullptr;
		THeadList<TKey>::operator=(other);
		this->pStop = this->pHead;
		this->pLast->pNext = this->pStop;
		return *this;
	}
};
