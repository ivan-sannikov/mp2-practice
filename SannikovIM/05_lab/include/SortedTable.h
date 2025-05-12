#pragma once
#include "ScanTable.h"


template <typename TKey, typename TData>
class SortedTable : public ScanTable<TKey, TData> {
private:
	TabRecord<TKey, TData>* binarySearch(TKey key);
	void BubleSort();
	void QuickSort();
	void SelectionSort();
	void InsertSort();
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
				TabRecord<TKey, TData>* tmp = recs[i];
				this->recs[i] = this->recs[j];
				this->recs[j] = tmp;
			}
		}
	}

}
template <typename TKey, typename TData>
TabRecord<TKey, TData>*  SortedTable<TKey, TData>::binarySearch(TKey key) {
	int low = 0;
	int high = this->count-1;
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
void SortedTable<TKey, TData>::SelectionSort() {
	for (int i = 0; i < this->count - 1; i++) {
		int min_id = i;
		for (int j = i + 1; j < this->count; j++) {
			if (this->recs[j]->key < this->recs[min_id]->key)
				min_id = j;
		}
		TabRecord<TKey, TData>* tmp = recs[i];
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
SortedTable<TKey, TData>::SortedTable(int maxSize) : ScanTable<TKey, TData>(maxSize) {
	static_assert(std::is_arithmetic<TKey>::value, "error");
}

template <typename TKey, typename TData>
SortedTable<TKey, TData>::SortedTable(ScanTable<TKey, TData>& table) : ScanTable<TKey, TData>(table) {
	InsertSort();
}

template <typename TKey, typename TData>
void SortedTable<TKey, TData>::Insert(TKey key, TData data) {
	TabRecord<TKey, TData>* tmp = this->binarySearch(key);
	int i = 0;

	while(i<this->count+1)
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
	recs[key] = nullptr;
}

