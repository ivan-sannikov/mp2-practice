#pragma once
#include "Table.h"
#include <string>

template <typename TKey>
int DefaultHash(const TKey& key, int maxSize) {
	return static_cast<unsigned long>(key) % maxSize;
}
template <>
int DefaultHash<std::string>(const std::string& key, int maxSize) {
	unsigned long hash = 0;
	for (char ch : key) {
		hash = (hash * 31 + ch) % maxSize;
	}
	return hash;
}

template <typename TKey, typename TData>
class HashTable : public Table<TKey,TData>{
protected:
	int h(const TKey& k) { return DefaultHash(k, maxSize); }
	int maxSize;
	int currPos;
	int count;
	
public:
	virtual TabRecord<TKey, TData>* Find(TKey key) = 0;
	virtual void Insert(TKey key, TData data) = 0;
	virtual void Remove(TKey key) = 0;
	bool isFull() const;
	bool isEmpty() const;
	TabRecord<TKey, TData>* GetCurrent() = 0;
	virtual bool IsTabEnden();
	virtual void Next() = 0;
	virtual void Reset() = 0;

	
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
