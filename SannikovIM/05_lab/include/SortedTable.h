#pragma once
#include "ScanTable.h"


template <typename TKey, typename TData>
class SortedTable : public ScanTable<TKey, TData> {
private:
	void BubleSort();
	void QuickSort();

public:
	SortedTable(int maxSize);
	void Insert(TKey key, TData data);
	void Remove(TKey key);
	TabRecord<TKey, TData>* Find(TKey key);
};

template <typename TKey, typename TData>

SortedTable<TKey, TData>::SortedTable(int maxSize) : ScanTable<TKey, TData>(maxSize) {
	static_assert(std::is_arithmetic<TKey>::value, "error");
}

template <typename TKey, typename TData>
void SortedTable<TKey, TData>::Insert(TKey key, TData data) {
	if (key > this->maxSize) throw "key is more then table size.";
	this->currPos++;
	this->recs[count++] = new TabRecord<TKey, TData>(key, data);
}
template <typename TKey, typename TData>
TabRecord<TKey, TData>* SortedTable<TKey, TData>::Find(TKey key) {
	if (key > this->maxSize) throw "error";
	return recs[key];
}
template <typename TKey, typename TData>
void SortedTable<TKey, TData>::Remove(TKey key) {
	if (key > this->maxSize) throw "error";
	recs[key] = nullptr;
}
