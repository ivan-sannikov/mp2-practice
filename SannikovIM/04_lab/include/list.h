#pragma once

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
	TNode<T>* Search(T key) {
		if (this->pFirst == pStop) throw "First element is null";
		TNode<T>* tmp = pFirst;
		while (tmp != pStop && tmp->key != key) { 
			tmp = tmp->pNext;
		}
		return tmp;

	}
	void InsertEnd(T key) { 
		TNode<T>* tmp1 = new TNode<T>(key);
		if (pFirst == pStop) {
			pFirst = tmp1;
			return;
		}
		TNode<T>* tmp = this->pFirst;
		while (tmp->pNext != pStop) {
			tmp = tmp->pNext;
		}
		tmp->pNext = tmp1;

	}
	void InsertBefore(T searchKey, T key) {
		TNode<T>* tmp1 = new TNode<T>(key);
		if (pFirst == pStop) {
			pFirst = tmp1;
			return;
		}
		TNode<T>* tmp = this->pFirst;
		while (tmp->pNext != pStop && tmp->pNext->key != searchKey) { 
			tmp = tmp->pNext;
		}
		TNode<T>* findElem = tmp->pNext;
		tmp->pNext = tmp1;
		tmp1->pNext = findElem;

	}
	void InsertAfter(T searchKey, T key) { 
		TNode<T>* tmp1 = new TNode<T>(key);
		if (pFirst == pStop) {
			pFirst = tmp1;
			return;
		}
		TNode<T>* tmp = this->pFirst;
		while (tmp != pStop && tmp->key != searchKey) { 
			tmp = tmp->pNext;
		}
		TNode<T>* findElem = tmp->pNext;
		tmp->pNext = tmp1;
		tmp1->pNext = findElem;

	}
	void InsertFirst(T key) {
		TNode<T>* tmp1 = new TNode<T>(key);
		if (pFirst == pStop) {
			pFirst = tmp1;
			return;
		}
		TNode<T>* tmp = this->pFirst;
		tmp1->pNext = tmp;
		this->pFirst = tmp1;

	}
	TNode<T>* GetLast() const {
		if (pFirst == pStop) return pStop;
		TNode<T>* tmp = pFirst;

		while (tmp->pNext != pStop) {
			tmp = tmp->pNext;
		}
		return tmp;

	}
	TNode<T>* GetFirst() const { return this->pFirst;}
	TNode<T>* GetStop() const { return this->pStop; }

	void DeleteLast() {
		if (pFirst == pStop)
			throw "List is empty";

		if (pFirst->pNext == pStop) {
			delete pFirst;
			pFirst = pStop;
			return;
		}

		TNode<T>* tmp = pFirst;
		while (tmp->pNext->pNext != pStop) {
			tmp = tmp->pNext;
		}

		delete tmp->pNext;
		tmp->pNext = pStop;
	}
	void DeleteFirst() {
		if (pFirst == pStop)
			return ;

		if (pFirst->pNext == pStop) {
			delete pFirst;
			pFirst = pStop;
			return;
		}

		TNode<T>* tmp = pFirst->pNext;
		delete pFirst;
		this->pFirst = tmp;
	}
	void Delete(T key) {
		if (this->pFirst == pStop) throw "First element is null";
		//cout << (this->pFirst->pNext == pStop) << endl;
		if (this->pFirst->pNext == pStop) {
			this->pFirst = pStop; return;
		}
		TNode<T>* tmp = pFirst;
		TNode<T>* tmp1 = nullptr;
		while (tmp != pStop && tmp->key != key) {
			tmp1 = tmp;
			tmp = tmp->pNext;
		}
		if (tmp1 == nullptr) { this->DeleteFirst(); return; }
		tmp1->pNext = tmp->pNext;
		delete tmp;
		
	}

};


