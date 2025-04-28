#pragma once

#include "headlist.h"

template <typename T>
class TRingHeadList : public THeadList<T> {
public:
	TRingHeadList() : THeadList<T>() {
		this->pStop = this->pHead;
		this->pHead->pNext = this->pStop;
	}
	TRingHeadList(const TRingHeadList& other) :THeadList<T>(other){
		this->pStop = this->pHead;
		this->pLast->pNext = this->pStop;
	}
	virtual void InsertEnd(T key) {
		TList<T>::InsertEnd(key);
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
		TList<T>::DeleteLast();
		this->pLast->pNext = this->pStop;
	}
	const TRingHeadList& operator=(const TRingHeadList& other) {
		this->pStop = nullptr;
		THeadList<T>::operator=(other);
		this->pStop = this->pHead;
		this->pLast->pNext = this->pStop;
		return *this;
	}
};
