#pragma once

#include <algorithm>

template <typename TKey>
struct TNode {
	TKey key;
	TNode* pNext;
	TNode(): key(), pNext(nullptr){}
	TNode(TKey k) : key(k), pNext(nullptr) {}
};

template <typename TKey>
class TList {
protected:
	TNode<TKey>* pFirst;
	TNode<TKey>* pCurr = pStop;
	TNode<TKey>* pPrev;
	TNode<TKey>* pLast;
	TNode<TKey>* pStop = nullptr;
private:
	void clear() {
		
		while (this->pFirst != nullptr) { 
			TNode<TKey>* tmp = this->pFirst;
			this->pFirst = this->pFirst->pNext;
			delete tmp;
		}
	}
	void copy(const TList& other) {
		this->pFirst = new TNode<TKey>(other.pFirst->key); 
		TNode<TKey>* tmp = this->pFirst;
		TNode<TKey>* curr = other.pFirst->pNext;
		while (curr != other.pStop) {
			tmp->pNext = new TNode<TKey>(curr->key);
			tmp = tmp->pNext;
			curr = curr->pNext;
		}
		this->pLast = tmp;
		this->pLast->pNext = pStop;
	}
public:
	TList() : pFirst(nullptr), pLast(this->pFirst) {}
	TList(const TList& other) : pFirst(nullptr) {
		if (other.pFirst == nullptr) {
			return;
		}
		copy(other);
	}
	~TList() {
		clear();
	}
	const TList& operator=(const TList& other) {
		if (this == &other) return *this;
		if (this->pLast != nullptr) { this->pLast->pNext = nullptr; }
		clear();
		if (other.pFirst != nullptr) { // TODO: copy()
			copy(other);
		}
		else {
			this->pFirst = nullptr;
			this->pLast = nullptr;
		}

		return *this;

	}
	TNode<TKey>* Search(TKey key) {
		if (this->pFirst == nullptr) return nullptr;
		this->pCurr = this->pFirst;
		this->pPrev = nullptr;
		while (this->pCurr != pStop && this->pCurr->key != key) { 
			this->pPrev = this->pCurr;
			this->pCurr = this->pCurr->pNext;
		}
        if(pCurr == pStop) pCurr = nullptr;
		return pCurr;
	}
	virtual void InsertEnd(TKey key) {
		if (pFirst == nullptr) {
			this->InsertFirst(key);
			return;
		}
		TNode<TKey>* tmp1 = new TNode<TKey>(key);
		this->pLast->pNext = tmp1;
		this->pLast = tmp1;
		this->pLast->pNext = pStop;
	}
	void InsertBefore(TKey searchKey, TKey key) {
		TNode<TKey>* tmp = Search(searchKey);
		if (tmp == nullptr)
		{
			throw "Can't find";
		}
		if (tmp == this->pFirst) {
			this->InsertFirst(key);
			return;
		}
		TNode<TKey>* tmp1 = new TNode<TKey>(key);
		this->pPrev->pNext = tmp1;
		tmp1->pNext = this->pCurr;
	}
	void InsertAfter(TKey searchKey, TKey key) {
		TNode<TKey>* tmp = Search(searchKey); 
		if (tmp == nullptr)
		{
			throw "Can't Find";
		}
		if (tmp == this->pLast) {
			this->InsertEnd(key);
			return;
		}
		TNode<TKey>* tmp1 = new TNode<TKey>(key);
		tmp1->pNext = pCurr->pNext;
		pCurr->pNext = tmp1;

	}
	virtual void InsertFirst(TKey key) {
		TNode<TKey>* tmp1 = new TNode<TKey>(key);
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
	TNode<TKey>* GetFirst() const {
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

		TNode<TKey>* tmp = pFirst;
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

		TNode<TKey>* tmp = pFirst->pNext;
		delete pFirst;
		this->pFirst = tmp;
	}
	void Delete(TKey key) {
		if (this->pFirst == nullptr) throw "List is empty";
		TNode<TKey>* tmp = Search(key);
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
	TNode<TKey>* getcurr() const { return this->pCurr; }
	void next() {
		this->pPrev = this->pCurr;
		this->pCurr = this->pCurr->pNext;
	}
	bool isended() const {
		return (pCurr == pStop);
	}
	bool operator==(const TList<TKey>& other) const {
		TNode<TKey>* tmp = this->pFirst;
		TNode<TKey>* oth = other.pFirst;
		while (tmp != this->pStop && oth != other.pStop) {
			if (oth->key != tmp->key) return 0;
			tmp = tmp->pNext;
			oth = oth->pNext;
		}
		if (oth == other.pStop && tmp == this->pStop) return 1;
		return 0;
	}
	bool operator!=(const TList<TKey>& other) const {
		return !(*this == other);
	}
};


