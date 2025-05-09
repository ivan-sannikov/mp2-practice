#pragma once
#include "TabRecord.h"

template <typename TKey, typename TData>
class Table{
public:
    virtual TabRecord<TKey, TData>* Find(TKey key) = 0;
    virtual void Insert(TKey key, TData data) = 0;
    virtual void Remove() = 0;
    virtual bool isFull() const = 0;
   // virtual bool isEmpty() const = 0;
   // virtual int GetCurrent() = 0;
   // virtual bool IsTabEnden() = 0;
   // virtual bool Next() = 0;
///    virtual bool Reset() = 0;
    
    
};
