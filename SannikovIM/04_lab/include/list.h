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
	TNode<T>* pCurr = pStop;
	TNode<T>* pPrev;
	TNode<T>* pLast;
	TNode<T>* pStop = nullptr;
public:
	TList() : pFirst(nullptr), pLast(this->pFirst) {}
	TList(const TList& other) : pFirst(nullptr) {
		if (other.pFirst == nullptr) {
			return;
		}
		this->pFirst = new TNode<T>(other.pFirst->key); // TODO: copy()
		TNode<T>* tmp = this->pFirst;
		TNode<T>* curr = other.pFirst->pNext;
		while (curr != other.pStop) {
			tmp->pNext = new TNode<T>(curr->key);
			tmp = tmp->pNext;
			curr = curr->pNext;
		}
		this->pLast = tmp;
		this->pLast->pNext = pStop;
	}
	~TList() {
		while (this->pFirst != nullptr) { // TODO: clear()
			TNode<T>* tmp = this->pFirst;
			this->pFirst = this->pFirst->pNext;
			delete tmp;
		}
	}
	const TList& operator=(const TList& other) {
		if (this == &other) return *this;
		while (this->pFirst != nullptr) {  // TODO: clear()
			TNode<T>* tmp = this->pFirst;
			this->pFirst = this->pFirst->pNext;
			delete tmp;
		}
		if (other.pFirst != nullptr) { // TODO: copy()
			this->pFirst = new TNode<T>(other.pFirst->key);
			TNode<T>* tmp = this->pFirst;
			TNode<T>* curr = other.pFirst->pNext;
			while (curr != nullptr) {
				tmp->pNext = new TNode<T>(curr->key);
				tmp = tmp->pNext;
				curr = curr->pNext;
			}
			this->pLast = tmp;
		}
		else {
			this->pFirst = nullptr;
			this->pLast = nullptr;
		}

		return *this;

	}
	TNode<T>* Search(T key) {
		if (this->pFirst == nullptr) return nullptr;
		this->pCurr = this->pFirst;
		this->pPrev = nullptr;
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
		TNode<T>* tmp = Search(searchKey);
		if (tmp == nullptr)
		{
			throw "Can't find";
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
			throw "Can't Find";
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
	virtual void DeleteLast() {
		if (pFirst == nullptr)
			throw "List is empty";

		if (pFirst->pNext == pStop) {
			DeleteFirst();
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
			throw "This item is not on the list";
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
	void reset() {
		if (this->pFirst == nullptr) {
			this->pCurr = this->pStop;
			return;
		}
		this->pCurr = this->pFirst;
		this->pPrev = nullptr;
	}
	TNode<T>* getcurr() const { return this->pCurr; }
	void next() {
		this->pPrev = this->pCurr;
		this->pCurr = this->pCurr->pNext;
	}
	bool isended() const {
		return (pCurr == pStop);
	}
	bool operator==(const TList<T>& other) const {
		//if (this->pLast != other.pLast) return 0;
		TNode<T>* tmp = this->pFirst;
		TNode<T>* oth = other.pFirst;
		while (tmp != this->pStop && oth != other.pStop) {
			if (oth->key != tmp->key) return 0;
			tmp = tmp->pNext;
			oth = oth->pNext;
		}
		if (oth == nullptr && tmp == nullptr) return 1;
		return 0;
	}
	bool operator!=(const TList<T>& other) const {
		return !(*this == other);
	}
};


