#pragma once
#include "Table.h"
#include <string>

template <typename TKey>
int DH(const TKey& key, int maxSize) {
	return key % maxSize;
}

template <>
int DH<std::string>(const std::string& key, int maxSize) {
	int hash = 0;
	for (char ch : key) {
		hash = (hash * 31 + ch) % maxSize;
	}
	return hash;
}

template <typename TKey, typename TData>
class HashTable : public Table<TKey,TData>{
protected:
	int h(const TKey& k) { return DH(k, maxSize); }
	int maxSize;
	int currPos;
	int count;
	
public:
	bool isFull() const; // TODO: будет в базовом классе
	bool isEmpty() const; // TODO: будет в базовом классе
	virtual bool IsTabEnden(); // TODO: будет в базовом классе
};
template <typename TKey, typename TData>
bool HashTable<TKey, TData>::isFull() const {
	return count == maxSize;
}
template <typename TKey, typename TData>
bool HashTable<TKey, TData>::isEmpty() const {
	return count == 0;
}
template <typename TKey, typename TData>
bool HashTable<TKey, TData>::IsTabEnden() {
	return this->maxSize == this->currPos;
}
