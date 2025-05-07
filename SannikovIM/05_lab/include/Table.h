#pragma once
#include "TabRecord.h"

template <typename TKey, typename TData>
class Table{
public:
    virtual TabRecord<TKey, TData> Find() = 0;
    virtual void Insert() = 0;
    virtual void Remove() = 0;
    virtual bool isFull() const = 0;
    virtual bool isEmpty() const = 0;
    virtual int GetCurrent() = 0;
    
};
