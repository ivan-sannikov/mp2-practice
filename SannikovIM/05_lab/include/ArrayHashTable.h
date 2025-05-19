#pragma once
#include "HashTable.h"

template <typename TKey, typename TData>
class ArrayHashTable : public HashTable<TKey, TData>{
private:
    TabRecord<TKey, TData>** recs;
    TabRecord<TKey, TData>* pMark;
    int freePos;
    int hashStep;
    unsigned long GetNextPos(unsigned long ind) {
        return(ind + this->hashStep) % this->maxSize;
    }
public:
    ArrayHashTable(int maxSize, int hashStep);
    ArrayHashTable(const ArrayHashTable& h);
    ~ArrayHashTable();
    TabRecord<TKey, TData>* Find(TKey key);
    void Insert(TKey key, TData data);
    void Remove(TKey key);
    TabRecord<TKey, TData>* GetCurrent();
 //   bool IsTabEnden();
    void Next();
    void Reset();
    ArrayHashTable<TKey, TData>& operator=(const ArrayHashTable<TKey, TData>& other);
    bool operator==(const ArrayHashTable<TKey, TData>& other) const;
    bool operator!=(const ArrayHashTable<TKey, TData>& other) const;
};
template <typename TKey, typename TData>
ArrayHashTable<TKey, TData>::ArrayHashTable(int maxSize, int hashStep) {
    this->maxSize = maxSize;
    this->hashStep = hashStep;
    this->recs = new TabRecord<TKey, TData>* [this->maxSize];
    for (int i = 0; i < this->maxSize; i++) {
        this->recs[i] = nullptr;
    }
    this->pMark = new TabRecord<TKey, TData>();
    this->freePos = -1;
    this->count = 0;
}
template <typename TKey, typename TData>
ArrayHashTable<TKey, TData>::ArrayHashTable(const ArrayHashTable<TKey, TData>& h) {
    this->maxSize = h.maxSize;
    this->hashStep = h.hashStep;
    this->pMark = h.pMark;
    this->recs = new TabRecord<TKey, TData>* [this->maxSize];
    for (int i = 0; i < this->maxSize; i++) {
        if (h.recs[i] == nullptr) continue;
        if (h.recs[i] == h.pMark) {
            this->recs[i] = this->pMark;
        }
        else {
            this->recs[i] = new TabRecord<TKey, TData>(h.recs[i]->key, h.recs[i]->pData);
        }
    }
    this->freePos = h.freePos;
}
template <typename TKey, typename TData>
ArrayHashTable<TKey, TData>::~ArrayHashTable() {
    for (int i = 0; i < this->maxSize; i++) {
        if (this->recs[i] != nullptr && this->recs[i] != this->pMark) {
            delete this->recs[i];
        }
    }
    delete[] this->recs;
    delete this->pMark;
}
template <typename TKey, typename TData>
TabRecord<TKey, TData>* ArrayHashTable<TKey, TData>::Find(TKey key) {
    TabRecord<TKey, TData>* res = nullptr;
    this->currPos = this->h(key);
    this->freePos = -1;
    for (int i = 0; i < this->maxSize; i++) {
        if (this->recs[this->currPos] == nullptr) break;
        if (this->recs[this->currPos]->key == key) {
            res = this->recs[this->currPos];
            break;
        }
        if (this->recs[this->currPos] == this->pMark) {
            if (this->freePos == -1) {
                this->freePos = this->currPos;
            }
            this->currPos = this->GetNextPos(this->currPos);
        }
    }
    return res;
}
template <typename TKey, typename TData>
void ArrayHashTable<TKey, TData>::Remove(TKey key) {
    TabRecord<TKey, TData>* res = this->Find(key);
    if (res == nullptr) throw "error";
    delete res;
    this->count--;
}
template <typename TKey, typename TData>
void ArrayHashTable<TKey, TData>::Insert(TKey key, TData data) {
    if (this->isFull()) throw "error";
    TabRecord<TKey, TData>* res = this->Find(key);
    if (res != nullptr) throw "error";
    if (res == nullptr) {
        if (this->freePos == -1) {
            this->recs[this->currPos] = new TabRecord<TKey, TData>(key, data);
        }
        else {
            this->recs[this->freePos] = new TabRecord<TKey, TData>(key, data);
        }
    }
    this->count++;
}
template <typename TKey, typename TData>
void ArrayHashTable<TKey, TData>::Reset() {
    this->currPos = 0;
    while (!this->IsTabEnden()) {
        if (this->recs[this->currPos] != nullptr && this->recs[this->currPos] != this->pMark) break;
        this->currPos++;
    }
}
template <typename TKey, typename TData>
void ArrayHashTable<TKey, TData>::Next() {
    this->currPos++;
    while (!this->IsTabEnden()) {
        if (this->recs[this->currPos] != nullptr && this->recs[this->currPos] != this->pMark) break;
        this->currPos++;
    }
}
template <typename TKey, typename TData>
TabRecord<TKey, TData>* ArrayHashTable<TKey, TData>::GetCurrent() {
    if (isEmpty()) throw "error";
    return this->recs[this->currPos];
}
template <typename TKey, typename TData>
ArrayHashTable<TKey, TData>& ArrayHashTable<TKey, TData>::operator=(const ArrayHashTable<TKey, TData>& other) {
    if (this == &other) return *this;
    this->maxSize = other.maxSize;
    this->hashStep = other.hashStep;
    this->count = other.count;
    this->currPos = other.currPos;
    this->freePos = other.freePos;
    this->pMark = new TabRecord<TKey, TData>();
    this->recs = new TabRecord<TKey, TData>* [this->maxSize];
    for (int i = 0; i < this->maxSize; i++) {
        if (other.recs[i] == nullptr) {
            this->recs[i] = nullptr;
        }
        else if (other.recs[i] == other.pMark) {
            this->recs[i] = this->pMark;
        }
        else {
            this->recs[i] = new TabRecord<TKey, TData>(*other.recs[i]);
        }
    }
    return *this;
}
template <typename TKey, typename TData>
bool ArrayHashTable<TKey, TData>::operator==(const ArrayHashTable<TKey, TData>& other) const {
    if (this->hashStep != other.hashStep || this->count != other.count) {
        return false;
    }
    for (int i = 0; i < this->maxSize; i++) {
        if (this->recs[i] == nullptr && other.recs[i] == nullptr) {
            continue;
        }
        if ((this->recs[i] == nullptr) != (other.recs[i] == nullptr)) {
            return false;
        }
        if ((this->recs[i] == this->pMark && other.recs[i] != other.pMark) ||
            (this->recs[i] != this->pMark && other.recs[i] == other.pMark)) {
            return false;
        }
        if (this->recs[i] != this->pMark && this->recs[i] != nullptr && 
            other.recs[i] != other.pMark && other.recs[i] != nullptr) {
            if (this->recs[i]->key != other.recs[i]->key ||
                this->recs[i]->data != other.recs[i]->data) {
                return false;
            }
        }
    }

    return true;
}
template <typename TKey, typename TData>
bool ArrayHashTable<TKey, TData>::operator!=(const ArrayHashTable<TKey, TData>& other) const {
    return !(*this == other);
}