#pragma once
#include "ScanTable.h"
#include <iostream>

template <typename TKey, typename TData>
class SortedTable : public ScanTable<TKey, TData> {
private:
	void QuickSort(int low, int high);
    int partition(int low, int high);
    
public:
	SortedTable(int maxSize);
	SortedTable(ScanTable<TKey, TData>& table);
	void Insert(TKey key, TData data);
	void Remove(TKey key);
	TabRecord<TKey, TData>* Find(TKey key);
};
template <typename TKey, typename TData>
int SortedTable<TKey, TData>::partition(int low, int high) {
    int pivot = this->recs[high]->key;
    int i = (low - 1);
    for (int j = low; j <= high - 1; j++) {
        if (this->recs[j]->key <= pivot) {
            i++;
            TabRecord<TKey, TData>* tmp = this->recs[i];
            this->recs[i] = this->recs[j];
            this->recs[j] = tmp;
        }
    }
    TabRecord<TKey, TData>* tmp = this->recs[i+1];
    this->recs[i+1] = this->recs[high];
    this->recs[high] = tmp;
    return (i + 1);
}
template <typename TKey, typename TData>
void SortedTable<TKey, TData>::QuickSort(int low, int high) {
    if (low < high) {
        int pi = partition(low, high);
        QuickSort(low, pi - 1);
        QuickSort(pi + 1, high);
    }
}
template <typename TKey, typename TData>
SortedTable<TKey, TData>::SortedTable(int maxSize) : ScanTable<TKey, TData>(maxSize){}
template <typename TKey, typename TData>
SortedTable<TKey, TData>::SortedTable(ScanTable<TKey, TData>& table) : ScanTable<TKey, TData>(table) {
    QuickSort(0, this->count - 1);
}

template <typename TKey, typename TData>
void SortedTable<TKey, TData>::Insert(TKey key, TData data) {
    this->Find(key);
    if (this->currPos < this->count&& this->recs[this->currPos]->key == key) throw "error";
    for (int i = this->count; i > this->currPos; i--) {
        this->recs[i] = this->recs[i - 1];
    }
    this->recs[this->currPos] = new TabRecord<TKey, TData>(key, data);
    this->count++;
}
template <typename TKey, typename TData>
TabRecord<TKey, TData>* SortedTable<TKey, TData>::Find(TKey key) {
    if (this->isEmpty()) return nullptr;
	int low = 0;
	int high = this->count - 1;
	while (low <= high) {
		int mid = ((high - low) / 2) + low;
		if (this->recs[mid]->key == key) {
            this->currPos = mid;
			return this->recs[mid];
		}
		if (this->recs[mid]->key > key)
			high = mid - 1;
		if (this->recs[mid]->key < key)
			low = mid + 1;

	}
    this->currPos = low;
	return nullptr;
}
template <typename TKey, typename TData>
void SortedTable<TKey, TData>::Remove(TKey key) { 
    if (this->isEmpty()) throw "error";
    TabRecord<TKey, TData>* tmp = this->Find(key);
    if (tmp == nullptr) throw "error";
    for(int i = this->currPos; i<this->count-1;i++){
        this->recs[i] = this->recs[i+1];
    }
    this->count--;
}

