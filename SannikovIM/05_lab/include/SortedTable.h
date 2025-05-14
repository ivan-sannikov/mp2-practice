#pragma once
#include "ScanTable.h"
#include <iostream>

template <typename TKey, typename TData>
class SortedTable : public ScanTable<TKey, TData> {
private:
	int binarySearch(TKey key);
	void BubleSort();
	void QuickSort(int low, int high);
	void SelectionSort();
	void InsertSort();
    void merge(int left, int mid, int right);
    void MergeSort(int left, int right);
    int partition(int low, int high);
    
public:
	SortedTable(int maxSize);
	SortedTable(ScanTable<TKey, TData>& table);
	void Insert(TKey key, TData data);
	void Remove(TKey key);
	TabRecord<TKey, TData>* Find(TKey key);
};



template <typename TKey, typename TData>
void SortedTable<TKey, TData>::BubleSort() {
	for(int i = 0; i<this->count;i++){
		for(int j = i; j< this->count; j++){
			if (this->recs[i]->key > this->recs[j]->key) {
				TabRecord<TKey, TData>* tmp = this->recs[i];
				this->recs[i] = this->recs[j];
				this->recs[j] = tmp;
			}
		}
	}

}
template <typename TKey, typename TData>
int  SortedTable<TKey, TData>::binarySearch(TKey key) {
	int low = 0;
	int high = this->count-1;
	while (low <= high) {
		int mid = ((high - low) / 2) + low;
		if (this->recs[mid]->key == key) {
			return mid;
		}
		if (this->recs[mid]->key > key)
			high = mid - 1;
		if (this->recs[mid]->key < key)
			low = mid + 1;
	}
	return low;
}

template <typename TKey, typename TData>
void SortedTable<TKey, TData>::SelectionSort() {
	for (int i = 0; i < this->count - 1; i++) {
		int min_id = i;
		for (int j = i + 1; j < this->count; j++) {
			if (this->recs[j]->key < this->recs[min_id]->key)
				min_id = j;
		}
		TabRecord<TKey, TData>* tmp = this->recs[i];
		this->recs[i] = this->recs[min_id];
		this->recs[min_id] = tmp;
	}
}
template <typename TKey, typename TData>
void SortedTable<TKey, TData>::InsertSort() {
	for (int i = 1; i < this->count; i++) {
		TabRecord<TKey, TData>* key = this->recs[i];
		int j = i - 1;
		while (j >= 0 && this->recs[j]->key > key->key) {
			this->recs[j + 1] = this->recs[j];
			j = j - 1;
		}
		this->recs[j + 1] = key;
	}
}
template <typename TKey, typename TData>
void SortedTable<TKey, TData>::merge(int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;
    TabRecord<TKey, TData>** recs1;
    TabRecord<TKey, TData>** recs2;
    recs1 = new TabRecord<TKey, TData>* [n1];
    recs2 = new TabRecord<TKey, TData>* [n2];
    for (int i = 0; i < n1; i++)
        recs1[i] = this->recs[left + i];
    for (int j = 0; j < n2; j++)
        recs2[j] = this->recs[mid + 1 + j];

    int i = 0, j = 0;
    int k = left;
    while (i < n1 && j < n2) {
        if (recs1[i]->key <= recs2[j]->key) {
            this->recs[k] = recs1[i];
            i++;
        }
        else {
            this->recs[k] = recs2[j];
            j++;
        }
        k++;
    }
    while (i < n1) {
        this->recs[k] = recs1[i];
        i++;
        k++;
    }
    while (j < n2) {
        this->recs[k] = recs2[j];
        j++;
        k++;
    }
}
template <typename TKey, typename TData>
void SortedTable<TKey, TData>::MergeSort(int left, int right) {
    if (left >= right)
           return;

    int mid = left + (right - left) / 2;
    MergeSort(left, mid);
    MergeSort(mid + 1, right);
    merge(left, mid, right);
}
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
SortedTable<TKey, TData>::SortedTable(int maxSize) : ScanTable<TKey, TData>(maxSize) {
	static_assert(std::is_arithmetic<TKey>::value, "error");
}

template <typename TKey, typename TData>
SortedTable<TKey, TData>::SortedTable(ScanTable<TKey, TData>& table) : ScanTable<TKey, TData>(table) {
	QuickSort(0, this->count-1);
}

template <typename TKey, typename TData>
void SortedTable<TKey, TData>::Insert(TKey key, TData data) {
    if(this->count == 0){
        this->recs[0] = new TabRecord<TKey, TData>(key, data);
        this->count++;
        return;
    }
	int tmp = this->binarySearch(key);
	int i = 0;
   
	TabRecord<TKey, TData>** recs1;
    recs1 = new TabRecord<TKey, TData>* [this->maxSize];
	while(i<this->count+1){
        if(i == tmp){
            recs1[i] = new TabRecord<TKey, TData>(key, data);
            i++;
            
            continue;
        }
		recs1[i] = this->recs[i];
		i++;
	}
    for(int i = 0; i < this->count; i++){
        this->recs[i] = recs1[i];
    }
    this->recs[this->count] = recs1[this->count];
	this->count++;
}
template <typename TKey, typename TData>
TabRecord<TKey, TData>* SortedTable<TKey, TData>::Find(TKey key) {
	int low = 0;
	int high = this->count - 1;
	while (low <= high) {
		int mid = ((high - low) / 2) + low;
		if (this->recs[mid]->key == key) {
			return this->recs[mid];
		}
		if (this->recs[mid]->key > key)
			high = mid - 1;
		if (this->recs[mid]->key < key)
			low = mid + 1;

	}
	return nullptr;
}
template <typename TKey, typename TData>
void SortedTable<TKey, TData>::Remove(TKey key) {
	if (key > this->maxSize) throw "error";
	this->recs[key] = nullptr;
}

