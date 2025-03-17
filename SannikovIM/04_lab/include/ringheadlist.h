#pragma once
#include "headlist.h"
template <typename T>
class TRingHeadList : public THeadList<T> {
public:
	TRingHeadList() : THeadList<T>() {
		this->pStop = this->pHead;
		this->pHead->pNext = this->pStop;
	}
	TRingHeadList(const TRingHeadList& other) : THeadList<T>(other) {
		/*
		THeadList

		if (other.pFirst == pStop) {
			return;
		}
		pFirst = new TNode<T>(other.pFirst->key);
		TNode<T>* tmp = pFirst;
		TNode<T>* curr = other.pFirst->pNext;
		while (curr != other.pStop) {
			tmp->pNext = new TNode<T>(curr->key);
			tmp = tmp->pNext;
			curr = curr->pNext;
			this->pLast = tmp;
		}
		this->pHead = other.pHead;
		this->pHead->pNext = this->pFirst;
		this->pLast = tmp;
		this->pStop = this->pHead;*/
		this->pStop = this->pHead;
		this->pLast->pNext = this->pStop;
		
	}
	~TRingHeadList() {
		if (this->pFirst == nullptr || this->pFirst == this->pStop) {
			delete this->pHead;
			this->pHead = nullptr;
			return;
		}
		TNode<T>* tmp = pFirst;
		while (tmp != nullptr) {
			TNode<T>* del = tmp;
			tmp = tmp->pNext;
			delete del;
		}
		delete this->pHead;
		delete this->pStop;
	}
	void InsertEnd(T key) {
		TList<T>::InsertEnd(key);
		this->pHead->pNext = this->pFirst;
		
	}
	void DeleteLast() {
		TList<T>::DeleteLast();
		this->pHead->pNext = this->pFirst;
	}
	TRingHeadList& operator=(const TRingHeadList& other) {
		TList<T>::operator=(other);
		this->pStop = this->pHead;
		this->pLast->pNext = this->pStop;
	}
};
