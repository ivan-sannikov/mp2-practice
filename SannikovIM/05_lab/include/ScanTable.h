#pragma once
#include "Table.h"
#include <iostream>

template <typename TKey, typename TData>
class ScanTable : public Table<TKey, TData> {
protected:
	int maxSize; // TODO: Table
	int currPos; // TODO: Table
	int count; // TODO: Table
	TabRecord<TKey, TData>** recs;
public:
	ScanTable(int maxSize);
	ScanTable(ScanTable<TKey, TData>& table);
	~ScanTable();
	virtual void Insert(TKey key, TData data);
	virtual void Remove(TKey key);
	virtual TabRecord<TKey, TData>* Find(TKey key);
	virtual bool isFull() const;
	virtual bool isEmpty() const;
	virtual TabRecord<TKey, TData>* GetCurrent() const;
	virtual bool IsTabEnden() const;
	virtual void Next();
	virtual void Reset();
	const ScanTable<TKey, TData>& operator=(const ScanTable<TKey, TData>& table);
	bool operator==(const ScanTable<TKey, TData>& table) const;
	bool operator!=(const ScanTable<TKey, TData>& table) const;
};

template <typename TKey, typename TData>

ScanTable<TKey, TData>::ScanTable(int maxSize) {
	this->maxSize = maxSize;
	this->recs = new TabRecord<TKey, TData>* [this->maxSize];
	
	for (int i = 0; i < this->maxSize; i++) {
		this->recs[i] = new TabRecord<TKey, TData>();
	}
	this->currPos = -1;
	this->count = 0;
}
template <typename TKey, typename TData>
ScanTable<TKey, TData>::~ScanTable() {
	for (int i = 0; i < count; i++) {
		delete recs[i];
	}
	delete[] recs;
}

template <typename TKey, typename TData>
ScanTable<TKey, TData>::ScanTable(ScanTable<TKey, TData>& table) {
	this->maxSize = table.maxSize;	
	this->currPos = table.currPos;
	this->count = table.count;
	this->recs = new TabRecord<TKey, TData>*[this->maxSize];
	for (int i = 0; i < this->count; i++) {
		this->recs[i] = new TabRecord<TKey, TData>(*(table.recs[i]));
	}	
}
template <typename TKey, typename TData>
void ScanTable<TKey, TData>::Insert(TKey key, TData data) {
	if (isFull()) throw "list is full.";
	this->recs[count++] = new TabRecord<TKey, TData>(key, data);
}
template <typename TKey, typename TData>
TabRecord<TKey, TData>* ScanTable<TKey, TData>::Find(TKey key) {
	for (int i = 0; i < this->count; i++) {
		if (this->recs[i]->key == key) {
			currPos = i;
			return recs[i];
		}
	}
	return nullptr;
}
template <typename TKey, typename TData>
void ScanTable<TKey, TData>::Remove(TKey key) { // TODO: search + поставить последнюю запись на место удаляемой
	int j = 0;
	for (int i = 0; i < this->count; i++) {
		if (this->recs[i]->key != key) {
			if (i != j) {
				this->recs[j] = this->recs[i];
			}
			j++;
		}
	}
	this->count = j;
}
template <typename TKey, typename TData>
bool ScanTable<TKey, TData>::isFull() const {
	return count == maxSize;
}
template <typename TKey, typename TData>
bool ScanTable<TKey, TData>::isEmpty() const {
	return count == 0;
}
template <typename TKey, typename TData>
TabRecord<TKey, TData>* ScanTable<TKey, TData>::GetCurrent() const {
	if (isEmpty()) throw "error";
	return recs[this->currPos];
}
template <typename TKey, typename TData>
bool ScanTable<TKey, TData>::IsTabEnden() const {
	return currPos == count;
}
template <typename TKey, typename TData>
void ScanTable<TKey, TData>::Next() {
	if (IsTabEnden()) throw "error";
	this->currPos++;
}
template <typename TKey, typename TData>
void ScanTable<TKey, TData>::Reset() {
    if(this->isEmpty()) throw "error";
	currPos = 0;
}
template <typename TKey, typename TData>
const ScanTable<TKey, TData>& ScanTable<TKey, TData>::operator=(const ScanTable<TKey, TData>& table) { // TODO: copy
	if (this == &table) {
		return *this;
	}
	this->maxSize = table.maxSize;
	this->recs = new TabRecord<TKey, TData>* [this->maxSize];
	for (int i = 0; i < this->maxSize; i++) {
		this->recs[i] = table.recs[i];
	}
	this->count = table.count;
	this->currPos = table.currPos;
	return *this;
}
template <typename TKey, typename TData>
bool ScanTable<TKey, TData>::operator==(const ScanTable<TKey, TData>& table) const{
	if (table.count != this->count) return false;
	for (int i = 0; i < count; i++) {
		if (this->recs[i]->pData != table.recs[i]->pData || this->recs[i]->key != table.recs[i]->key) { // TODO: == для TabRecord
			return false;
		}
	}
	return true;
}
template <typename TKey, typename TData>
bool ScanTable<TKey, TData>::operator!=(const ScanTable<TKey, TData>& table) const {
	return !(*this == table);
}







