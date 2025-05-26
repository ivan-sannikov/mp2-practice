#pragma once
#include "Table.h"
#include <iostream>

using namespace std;

template <typename TKey, typename TData>
class ScanTable : public Table<TKey, TData> {
private:
    void copy(const ScanTable<TKey, TData>& h);
protected:
	TabRecord<TKey, TData>** recs;
public:
	ScanTable(int maxSize);
	ScanTable(const ScanTable<TKey, TData>& table);
	~ScanTable();
	virtual void Insert(TKey key, TData data);
	virtual void Remove(TKey key);
	virtual TabRecord<TKey, TData>* Find(TKey key);
	virtual TabRecord<TKey, TData>* GetCurrent() const;
	virtual void Next();
	virtual void Reset();
	const ScanTable<TKey, TData>& operator=(const ScanTable<TKey, TData>& table);
	bool operator==(const ScanTable<TKey, TData>& table) const;
	bool operator!=(const ScanTable<TKey, TData>& table) const;
    friend ostream& operator<<(ostream& ostr, const ScanTable<TKey, TData>& table){
        for (int i = 0; i < table.count; i++) {
            ostr << table.recs[i]->pData;
        }
        ostr<<endl;
        return ostr;
    }
};


template <typename TKey, typename TData>
void ScanTable<TKey, TData>::copy(const ScanTable<TKey, TData>& table){
    this->maxSize = table.maxSize;
    this->currPos = table.currPos;
    this->count = table.count;
    this->recs = new TabRecord<TKey, TData>*[this->maxSize];
    for (int i = 0; i < this->count; i++) {
        this->recs[i] = new TabRecord<TKey, TData>(*(table.recs[i]));
    }
}

template <typename TKey, typename TData>

ScanTable<TKey, TData>::ScanTable(int maxSize) {
	this->maxSize = maxSize;
	this->recs = new TabRecord<TKey, TData>* [this->maxSize];
	
	for (int i = 0; i < this->maxSize; i++) {
		this->recs[i] = new TabRecord<TKey, TData>();
	}
	this->currPos = 0;
	this->count = 0;
}
template <typename TKey, typename TData>
ScanTable<TKey, TData>::~ScanTable() {
	for (int i = 0; i < this->count; i++) {
		delete recs[i];
	}
	delete[] recs;
}

template <typename TKey, typename TData>
ScanTable<TKey, TData>::ScanTable(const ScanTable<TKey, TData>& table) {
    copy(table);
}
template <typename TKey, typename TData>
void ScanTable<TKey, TData>::Insert(TKey key, TData data) {
	if (this->isFull()) throw "list is full.";
	this->recs[this->count++] = new TabRecord<TKey, TData>(key, data);
}
template <typename TKey, typename TData>
TabRecord<TKey, TData>* ScanTable<TKey, TData>::Find(TKey key) {
	for (int i = 0; i < this->count; i++) {
		if (this->recs[i]->key == key) {
            this->currPos = i;
			return recs[i];
		}
	}
	return nullptr;
}
template <typename TKey, typename TData>
void ScanTable<TKey, TData>::Remove(TKey key) {
    this->Find(key);
    this->recs[this->currPos] = new TabRecord<TKey, TData>(*(this->recs[this->count-1]));
    this->count--;
}
template <typename TKey, typename TData>
TabRecord<TKey, TData>* ScanTable<TKey, TData>::GetCurrent() const {
	if (this->isEmpty()) throw "error";
	return recs[this->currPos];
}
template <typename TKey, typename TData>
void ScanTable<TKey, TData>::Next() {
	if (this->IsTabEnden()) throw "error";
	this->currPos++;
}
template <typename TKey, typename TData>
void ScanTable<TKey, TData>::Reset() {
    if(this->isEmpty()) throw "error";
    this->currPos = 0;
}
template <typename TKey, typename TData>
const ScanTable<TKey, TData>& ScanTable<TKey, TData>::operator=(const ScanTable<TKey, TData>& table) { 
	if (this == &table) {
		return *this;
	}
    copy(table);
	return *this;
}
template <typename TKey, typename TData>
bool ScanTable<TKey, TData>::operator==(const ScanTable<TKey, TData>& table) const{
	if (table.count != this->count) return false;
	for (int i = 0; i < this->count; i++) {
		if (*this->recs[i] != *table.recs[i]) {
			return false;
		}
	}
	return true;
}
template <typename TKey, typename TData>
bool ScanTable<TKey, TData>::operator!=(const ScanTable<TKey, TData>& table) const {
	return !(*this == table);
}

