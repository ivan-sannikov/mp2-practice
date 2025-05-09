#include "ScanTable.h"
#include "TabRecord.h"

template <typename TKey, typename TData>

ScanTable<TKey, TData>::ScanTable(int maxSize){
    this->maxSize = maxSize;
    this->recs = new TabRecord<TKey, TData>*[this->maxSize];
    for(int i=0;i<this->maxSize;i++){
        this->recs[i] = new TabRecord<TKey, TData>();
    }
    this->count = 0;
}

template <typename TKey, typename TData>
ScanTable<TKey, TData>::ScanTable(ScanTable<TKey, TData>& table){
    this->maxSize = table.maxSize;
    this->recs = new TabRecord<TKey, TData>*[this->maxSize];
    for(int i = 0; i<this->maxSize;i++){
        this->recs[i] = table.recs[i];
    }
}
template <typename TKey, typename TData>
void ScanTable<TKey, TData>::Insert(TKey key, TData data){
    TabRecord<TKey,TData>* rec(key, data);
    this->recs[count++] = rec;
}
template <typename TKey, typename TData>
TabRecord<TKey, TData>* ScanTable<TKey, TData>::Find(TKey key){
    for(int i = 0;i<this->count;i++){
        if(this->recs[i]->key == key) return recs[i];
    }
    return nullptr;
}
template <typename TKey, typename TData>
void ScanTable<TKey, TData>::Remove() {

}
template <typename TKey, typename TData>
bool ScanTable<TKey, TData>::isFull() const {
    return true;

}