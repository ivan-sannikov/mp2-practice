#pragma once
#include "Table.h"
#include <iostream>

using namespace std;
template <typename TKey, typename TData>
class ScanTable{ //: public Table<TKey, TData>{
private:
    int maxSize;
    int currPos;
    int count;
    TabRecord<TKey, TData>** recs;
public:
    ScanTable(int maxSize);
};
