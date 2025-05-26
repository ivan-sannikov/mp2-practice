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
	int h(const TKey& k) { return DH(k, this->maxSize); }
};

