#pragma once
#include "TabRecord.h"

template <typename TKey, typename TData>
class Table {
public:
	virtual TabRecord<TKey, TData>* Find(TKey key) = 0;
	virtual void Insert(TKey key, TData data) = 0;
	virtual void Remove(TKey key) = 0;
	virtual bool isFull() const = 0;
	virtual bool isEmpty() const = 0;
	virtual TabRecord<TKey, TData>* GetCurrent() = 0;
	virtual bool IsTabEnden() = 0;
	virtual void Next() = 0;
	virtual void Reset() = 0;


};