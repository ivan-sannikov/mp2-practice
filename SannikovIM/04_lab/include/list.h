#pragma once

#include <algorithm>
template <typename T>
struct TNode {
	T key;
	TNode* pNext;
	TNode(): key(new T()), pNext(nullptr){}
	TNode(T k) : key(k), pNext(nullptr) {}
};
template <typename T>
class TList {
protected:
	TNode<T>* pFirst;
	TNode<T>* pCurr;
	TNode<T>* pPrev;
	TNode<T>* pLast;
	TNode<T>* pStop = nullptr;
public:
	
	TList() :pFirst(nullptr) {}
	TList(const TList& other) : pFirst(pStop) {
		if (other.pFirst == pStop) {
			return;
		}
		pFirst = new TNode<T>(other.pFirst->key);
		TNode<T>* tmp = pFirst;
		TNode<T>* curr = other.pFirst->pNext;
		while (curr != pStop) {
			tmp->pNext = new TNode<T>(curr->key);
			tmp = tmp->pNext;
			curr = curr->pNext;
		}
	}
	~TList() {
		while (pFirst != pStop) {
			TNode<T>* tmp = pFirst;
			pFirst = pFirst->pNext;
			delete tmp;
		}
	}
	TNode<T>* Search(T key) { // TODO: pPrev è pCurr
		if (this->pFirst == pStop) throw "First element is null";
		this->pCurr = this->pFirst;
		this->pPrev = this->pStop;
		while (this->pCurr != pStop && this->pCurr->key != key) { 
			this->pPrev = this->pCurr;
			this->pCurr = this->pCurr->pNext;
		}
		return pCurr;
	}
	void InsertEnd(T key) { 
		TNode<T>* tmp1 = new TNode<T>(key);
		if (pFirst == pStop) {
			this->pFirst = tmp1;
			this->pFirst->pNext = this->pStop; 
			this->pLast = pFirst;// TODO: pLast = pFirst
			return;
		}
		 // TODO: pLast->pNext = tmp1; pLast = tmp1; pLast->pNext = pStop;
		this->pLast->pNext = tmp1;
		this->pLast = tmp1;
		this->pLast->pNext = pStop;
	}
	void InsertBefore(T searchKey, T key) {
		TNode<T>* tmp1 = new TNode<T>(key);
		if (pFirst == pStop) {
			pFirst = tmp1;
			return;
		}
	
		TNode<T>* tmp = Search(searchKey); // TODO: search pPrev è pCurr
		if (tmp == this->pFirst) {
			this->InsertFirst(key);
			return;
		}
		this->pPrev->pNext = tmp1;
		tmp1->pNext = this->pCurr;

	}
	void InsertAfter(T searchKey, T key) { 
		TNode<T>* tmp1 = new TNode<T>(key);
		if (pFirst == pStop) {
			pFirst = tmp1;
			return;
		}
		TNode<T>* tmp = Search(searchKey);  // TODO: search pCurr
		if (tmp == this->pLast) {
			this->InsertEnd(key);
			return;
		}
		tmp1->pNext = tmp->pNext;
		tmp->pNext = tmp1;

	}
	void InsertFirst(T key) {
		TNode<T>* tmp1 = new TNode<T>(key);
		if (pFirst == pStop) {
			this->pFirst = tmp1;
			this->pLast = this->pFirst;// TODO: pLast = pFist
			return;
		}
		tmp1->pNext = this->pFirst;
		this->pFirst = tmp1;
	}
	TNode<T>* GetFirst() const { return this->pFirst;}
	TNode<T>* GetStop() const { return this->pStop; } // TODO: remove

	void DeleteLast() {
		if (pFirst == pStop)
			throw "List is empty";

		if (pFirst->pNext == pStop) {
			delete pFirst;
			pFirst = pStop;
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
	void DeleteFirst() {
		if (pFirst == pStop)
			throw "List is empty"; // TODO: throw

		if (pFirst->pNext == pStop) {
			delete pFirst;
			pFirst = pLast = pStop;
			return;
		}

		TNode<T>* tmp = pFirst->pNext;
		delete pFirst;
		this->pFirst = tmp;
	}
	void Delete(T key) {
		if (this->pFirst == pStop) throw "First element is null";
		if (this->pFirst->pNext == pStop) {
			this->pFirst = pStop; return;
		}
		TNode<T>* tmp = Search(key);
		//if (tmp1 == pStop) { this->DeleteFirst(); return; } // TODO: ???
		this->pPrev -> pNext = tmp->pNext;
		delete tmp;
		
	}

};


