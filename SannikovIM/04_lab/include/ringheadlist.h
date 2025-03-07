#pragma once
#include "headlist.h"
template <typename T>
class TRingHeadList : public THeadList<T> {
public:
	TRingHeadList() : THeadList<T>() {
		//this->pFirst = nullptr;
		this->pStop = this->pHead;
		//this->pStop->pNext = nullptr;
	}
	TRingHeadList(const TRingHeadList& other) : THeadList<T>() {
		this->pStop = this->pHead;

		// Копируем элементы из другого списка
		TNode<T>* current = other.pFirst;
		while (current != other.pStop) {
			this->InsertEnd(current->key);
			current = current->pNext;
		}
	}
	~TRingHeadList() {
		while (pFirst != pStop) {
			TNode<T>* tmp = pFirst;
			pFirst = pFirst->pNext;
			delete tmp;
		}
		delete pHead; 
	}
	  void SetHead(T key) {
		this->pHead = new TNode<T>(key);
		this->pStop = this->pHead;
		this->pFirst = this->pHead;
		this->pLast = this->pFirst;
		this->pHead->pNext = this->pFirst;
		

	}
	void InsertEnd(T key) {
		TNode<T>* tmp1 = new TNode<T>(key);
		if (pFirst == pStop) {
			this->pFirst = tmp1;
			this->pLast = tmp1;
			//this->pStop = this->pHead;
			this->pHead->pNext = this->pFirst;
			this->pFirst->pNext = this->pStop;
			return;
		}
		TNode<T>* tmp = this->pFirst;
		while (tmp->pNext != pStop) {
			tmp = tmp->pNext;
		}
		tmp1->pNext = this->pStop;
		tmp->pNext = tmp1;
		this->pLast = tmp1;
		///this->pHead->pNext = this->pFirst;

	}
	void DeleteLast() {
		if (pFirst == pStop)
			throw "List is empty";

		if (pFirst->pNext == pStop) {
			delete pFirst;
			pFirst = pStop;
			this->pHead->pNext = this->pFirst;
			return;
		}

		TNode<T>* tmp = pFirst;
		while (tmp->pNext != pLast) {
			tmp = tmp->pNext;
		}

		delete pLast;
		tmp->pNext = pStop;
		this->pLast = tmp;
	}
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
};
