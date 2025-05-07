#include "ScanTable.h"

template <typename TKey, typename TData>

ScanTable(int maxSize){
    this->maxSize = maxSize;
    this->recs = new TabRecord<TKey, TData>*[this->maxSize];
    for(int i=0;i<this->maxSize;i++){
        this->recs[i] = new TabRecord<TKey, TData>();
    }
}
