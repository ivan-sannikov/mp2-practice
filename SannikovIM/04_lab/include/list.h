#pragma once

#include <algorithm>
template <typename T>
struct TNode {
	T key;
	TNode* pNext;
	TNode(): key(), pNext(nullptr){}
	TNode(T k) : key(k), pNext(nullptr) {}
};
template <typename T>
class TList {
protected:
	TNode<T>* pFirst;
	mutable TNode<T>* pCurr = pStop;
	mutable TNode<T>* pPrev;
	TNode<T>* pLast;
	TNode<T>* pStop = nullptr;
public:
	
	TList() : pFirst(nullptr) {}
	TList(const TList& other) : pFirst(pStop) {
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
		}
	}
	~TList() {
		while (pFirst != nullptr) {
			TNode<T>* tmp = pFirst;
			pFirst = pFirst->pNext;
			delete tmp;
		}
	}
	TNode<T>* Search(T key) {
		if (this->pFirst == pStop) return nullptr;
		this->pCurr = this->pFirst;
		this->pPrev = this->pStop;
		while (this->pCurr != pStop && this->pCurr->key != key) { 
			this->pPrev = this->pCurr;
			this->pCurr = this->pCurr->pNext;
		}
		return pCurr;
	}
	virtual void InsertEnd(T key) { 
		if (pFirst == nullptr) {
			this->InsertFirst(key);
			return;
		}
		TNode<T>* tmp1 = new TNode<T>(key);
		this->pLast->pNext = tmp1;
		this->pLast = tmp1;
		this->pLast->pNext = pStop;
	}
	void InsertBefore(T searchKey, T key) {
		TNode<T>* tmp = Search(searchKey); // TODO: search pPrev è pCurr
		if (tmp == nullptr)
		{
			throw ""; // TODO
		}
		if (tmp == this->pFirst) {
			this->InsertFirst(key);
			return;
		}
		TNode<T>* tmp1 = new TNode<T>(key);
		this->pPrev->pNext = tmp1;
		tmp1->pNext = this->pCurr;
	}
	void InsertAfter(T searchKey, T key) { 
		TNode<T>* tmp = Search(searchKey); 
		if (tmp == nullptr)
		{
			throw ""; // TODO
		}
		if (tmp == this->pLast) {
			this->InsertEnd(key);
			return;
		}
		TNode<T>* tmp1 = new TNode<T>(key);
		tmp1->pNext = pCurr->pNext;
		pCurr->pNext = tmp1;

	}
	virtual void InsertFirst(T key) {
		TNode<T>* tmp1 = new TNode<T>(key);
		if (pFirst == nullptr) {
			this->pFirst = tmp1;
			this->pFirst->pNext = this->pStop;
			this->pLast = this->pFirst;
			this->reset();
			return;
		}
		tmp1->pNext = this->pFirst;
		this->pFirst = tmp1;
	}
	TNode<T>* GetFirst() const {
		if (pFirst == nullptr) {
			return nullptr;
		}
		return pFirst;
	}


	// TODO: reset(), getcurr(), next(), isended()

	virtual void DeleteLast() {
		if (pFirst == nullptr)
			throw "List is empty";

		if (pFirst->pNext == pStop) {
			delete pFirst;
			pFirst = nullptr;
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
	virtual void DeleteFirst() {
		if (pFirst == nullptr)
			throw "List is empty";

		if (pFirst->pNext == pStop) {
			delete pFirst;
			pFirst = pLast = nullptr;
			return;
		}

		TNode<T>* tmp = pFirst->pNext;
		delete pFirst;
		this->pFirst = tmp;
	}
	void Delete(T key) {
		if (this->pFirst == nullptr) throw "List is empty";
		TNode<T>* tmp = Search(key);
		if (tmp == nullptr)
		{
			throw "This item is not on the list"; // TODO
		}
		if (pCurr == pFirst)
		{
			DeleteFirst();
			return;
		}
		if (pCurr == pLast)
		{
			DeleteLast();
			return;
		}
		this->pPrev->pNext = pCurr->pNext;
		delete pCurr;
	}
	void reset() const {
		if (this->pFirst == nullptr) {
			this->pCurr = this->pStop;
			return;
		}
		this->pCurr = this->pFirst;
		this->pPrev = nullptr;
	}
	TNode<T>* getcurr() { return this->pCurr; }
	void next() const {
		this->pCurr = this->pCurr->pNext;
		if (this->pPrev != nullptr) {
			this->pPrev = this->pPrev->pNext;
		}
	}
	bool isended() const {
		return (pCurr == pStop);
	}

};


