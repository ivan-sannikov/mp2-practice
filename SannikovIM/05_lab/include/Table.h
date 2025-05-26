#pragma once
#include "TabRecord.h"

template <typename TKey, typename TData>
class Table {
protected:
    int maxSize; // TODO: Table
    int currPos; // TODO: Table
    int count; // TODO: Table
public:
	virtual TabRecord<TKey, TData>* Find(TKey key) = 0;
	virtual void Insert(TKey key, TData data) = 0;
	virtual void Remove(TKey key) = 0;
    bool isFull() const;
    bool isEmpty() const;
	virtual TabRecord<TKey, TData>* GetCurrent() const = 0;
    bool IsTabEnden() const;
	virtual void Next() = 0;
	virtual void Reset() = 0;
};
template <typename TKey, typename TData>
bool Table<TKey, TData>::isFull() const {
    return count == maxSize;
}
template <typename TKey, typename TData>
bool Table<TKey, TData>::isEmpty() const {
    return count == 0;
}
template <typename TKey, typename TData>
bool Table<TKey, TData>::IsTabEnden() const {
    return this->maxSize == this->currPos;
}
