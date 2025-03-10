#pragma once
#include "headlist.h"
template <typename T>
class TRingHeadList : public THeadList<T> {
public:
	TRingHeadList() : THeadList<T>() {
		this->pStop = this->pHead;
		this->pHead->pNext = this->pStop;
	}
	/*ingHeadList(const TRingHeadList& other) : THeadList<T>() {
		this->pStop = this->pHead;
		TNode<T>* current = other.pFirst;
		while (current != other.pStop) {
			this->InsertEnd(current->key);
			current = current->pNext;
		}
	}*/

	void InsertEnd(T key) {
		TList<T>::InsertEnd(key);
		this->pHead->pNext = this->pFirst;
	}
	void DeleteLast() {
		TList<T>::DeleteLast();
		this->pHead->pNext = this->pFirst;
	}
	/*
	void Delete(T& key) {
		if (this->pFirst == this->pStop) {
			throw "List is empty"; 
		}
		TNode<T>* tmp = Search(key);
		if (tmp == this->pStop) {
			throw "Element not found"; 
		}
		if (this->pPrev == this->pStop) { 
			this->pFirst = this->pFirst->pNext;
			this->pHead->pNext = this->pFirst;
		}
		else { 
			this->pPrev->pNext = tmp->pNext;
		}
		if (tmp == pLast) {
			this->pLast = this->pPrev;
			this->pPrev->pNext = this->pStop;
		}
		delete tmp;
	}
	*/
};
