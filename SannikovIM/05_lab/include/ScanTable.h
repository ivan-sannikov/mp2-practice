#pragma once

#include "TabRecord.h"
#include "Table.h"

template <typename TKey, typename TData>
class ScanTable : public Table<TKey, TData>{
private:
    int maxSize;
    int currPos;
    int count;
    TabRecord<TKey, TData>** recs;
public:
    ScanTable();
    ScanTable(int maxSize);
    ScanTable(ScanTable<TKey, TData>& table);
    void Insert(TKey key, TData data);
    void Remove();
    TabRecord<TKey, TData>* Find(TKey key);
    bool isFull() const;
   // bool isEmpty() const;
   // int GetCurrent();
   // bool IsTabEnden();
  //  bool Next();
   // bool Reset();
};
