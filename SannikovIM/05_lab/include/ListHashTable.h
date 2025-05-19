#pragma once
#include "HashTable.h"
#include "list.h" 
template <typename TKey, typename TData>
class ListHashTable : public HashTable<TKey, TData> {
private:
    TList<TabRecord<TKey, TData>>** recs;

public:
    ListHashTable(int maxSize);
    ListHashTable(const ListHashTable& h);  
    ~ListHashTable();
    void Insert(TKey key, TData data);
    void Remove(TKey key);
    TabRecord<TKey, TData>* Find(TKey key);
  //  bool IsTabEnden();
    void Reset();
    void Next();
    TabRecord<TKey, TData>* GetCurrent();
    ListHashTable<TKey, TData>& operator=(const ListHashTable<TKey, TData>& h);
    bool operator==(const ListHashTable<TKey, TData>& h) const;
    bool operator!=(const ListHashTable<TKey, TData>& h) const;
};

template <typename TKey, typename TData>
ListHashTable<TKey, TData>::ListHashTable(int maxSize) {
    this->maxSize = maxSize;
    this->count = 0;
    this->currPos = -1;
    this->recs = new TList<TabRecord<TKey, TData>>*[maxSize];
    for (int i = 0; i < this->maxSize; i++) {
        this->recs[i] = nullptr;
    }
}
template <typename TKey, typename TData>
ListHashTable<TKey, TData>::ListHashTable(const ListHashTable& h) {
    this->maxSize = h.maxSize;
    this->count = h.count;
    this->currPos = h.currPos;
    this->recs = new TList<TabRecord<TKey, TData>>* [h.maxSize];
    for (int i = 0; i < this->maxSize; i++) {
        this->recs[i] = h.recs[i];
    }
}
template <typename TKey, typename TData>
ListHashTable<TKey, TData>::~ListHashTable() {
    delete[] recs;
}

template <typename TKey, typename TData>
TabRecord<TKey, TData>* ListHashTable<TKey, TData>::Find(TKey key) {
    int index = this->h(key);
    TList<TabRecord<TKey, TData>>* list = recs[index];
    if (list == nullptr) return nullptr;
    list->reset();
    while (!list->isended()) {
        if (list->getcurr()->key.key == key) {
            return new TabRecord<TKey, TData>(list->getcurr()->key);
        }
        list->next();
    }
    return nullptr;
}
template <typename TKey, typename TData>
void ListHashTable<TKey, TData>::Insert(TKey key, TData data) {
    if (this->isFull()) throw "error";
    int pos = h(key);
    TabRecord<TKey, TData> a(key, data);
    if (recs[pos] == nullptr) {
        TList<TabRecord<TKey, TData>>* b = new TList<TabRecord<TKey, TData>>();
        b->InsertFirst(a);
        this->recs[pos] = b;
    }
    else {
        recs[pos]->InsertEnd(a);
    }
    this->count++;
}
template <typename TKey, typename TData>
void ListHashTable<TKey, TData>::Remove(TKey key) {
    if (this->isEmpty()) throw "Table is empty";

    int pos = this->h(key);
    if (recs[pos] == nullptr) throw "No list at this hash index";

    TabRecord<TKey, TData>* temp = Find(key);
    recs[pos]->Delete(*temp); 
    this->count--;
}
template <typename TKey, typename TData>
void ListHashTable<TKey, TData>::Reset() {
    this->currPos = 0;
    for (int i = 0; i < this->maxSize; i++) {
        if (this->recs[i] != nullptr) recs[i]->reset();
    }
    while (!this->IsTabEnden()) {
        if (this->recs[this->currPos] != nullptr) break;
        this->currPos++;
    }
}
template <typename TKey, typename TData>
void ListHashTable<TKey, TData>::Next() {
    if (!this->recs[this->currPos]->isended()) {
        this->recs[this->currPos]->next();
        if(!this->recs[this->currPos]->isended()) return;
    }
    this->currPos++;
    while (!this->IsTabEnden()) {
        if (this->recs[this->currPos] != nullptr) break;
        this->currPos++;
    }
}
template <typename TKey, typename TData>
TabRecord<TKey, TData>* ListHashTable<TKey, TData>::GetCurrent() {
    if (isEmpty()) throw "error";
    return new TabRecord<TKey, TData>(this->recs[this->currPos]->getcurr()->key);
}
template <typename TKey, typename TData>
bool ListHashTable<TKey, TData>::operator==(const ListHashTable<TKey, TData>& h) const {
    if (this->count != h.count) return false;
    ListHashTable<TKey, TData> b(h);
    ListHashTable<TKey, TData> c(*this);
    c.Reset();
    b.Reset();
    
    while (!c.IsTabEnden() && !b.IsTabEnden()) {
        if (c.GetCurrent() != b.GetCurrent()) return false;
        c.Next();
        b.Next();
    }
    if (c.IsTabEnden() != b.IsTabEnden()) return false;
    return true;
}
template <typename TKey, typename TData>
bool ListHashTable<TKey, TData>::operator!=(const ListHashTable<TKey, TData>& h) const {
    return !(*this == h);
}
template <typename TKey, typename TData>
ListHashTable<TKey, TData>& ListHashTable<TKey, TData>::operator=(const ListHashTable<TKey, TData>& h) {
    if (*this == other) return *this;
    this->maxSize = h.maxSize;
    this->count = h.count;
    this->currPos = h.currPos;
    this->recs = new TList<TabRecord<TKey, TData>>* [h.maxSize];
    for (int i = 0; i < this->maxSize; i++) {
        this->recs[i] = h.recs[i];
    }
}