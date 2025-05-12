#pragma once
#include "HashTable.h"

template <typename TKey, typename TData>
class ArrayHashTable : public HashTable<TKey, TData>{
public:
    ArrayHashTable(int maxSize, int hashStep);
    ArrayHashTable(const ArrayHashTable& aht);
    TabRecord<TKey, TData>* Find(TKey key);
    void Insert(TKey key, TData data);
    void Remove(TKey key);
    bool isFull() const;
    bool isEmpty() const;
    TabRecord<TKey, TData>* GetCurrent();
    bool IsTabEnden();
    void Next();
    void Reset();
};