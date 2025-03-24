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
		}
		~TRingHeadList() {
			this->pStop = nullptr;
			if (this->pLast != nullptr) {
				this->pLast->pNext = this->pStop;
			}
		}
		virtual void InsertEnd(T key) {
			TList<T>::InsertEnd(key);
			if (this->pFirst) {
				this->pHead->pNext = this->pFirst;
			}
		}

		virtual void DeleteLast() {
			TList<T>::DeleteLast();
			if (this->pFirst) {
				this->pHead->pNext = this->pFirst;
			}
		}
		TRingHeadList& operator=(const TRingHeadList& other) {
			THeadList<T>::operator=(other);
			this->pStop = this->pHead;
			this->pLast->pNext = this->pStop;
			return *this;
		}
	};
