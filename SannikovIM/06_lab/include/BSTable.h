#pragma once
#include "Table.h"
#include "BinarySearchTree.h"
template <typename TKey, typename TData>
class BSTable : public Table<TKey, TData>{
private:
    BinarySearchTree<TKey, TData>* pMap;
    TreeNode<TKey, TData>* pCurr;
public:
    BSTable(int maxSize);
    BSTable(const BSTable<TKey, TData>& table);
    ~BSTable();
    TabRecord<TKey, TData>* Find(TKey key);
    void Insert(TKey key, TData data);
    void Remove(TKey key);
    void Next();
    void Reset();
    TabRecord<TKey, TData>* GetCurrent() const;
};


template <typename TKey, typename TData>
BSTable<TKey, TData>::BSTable(int maxSize){
    this->maxSize = maxSize;
    this->count = 0;
    this->currPos = 0;
    this->pMap = new BinarySearchTree<TKey, TData>();
}
template <typename TKey, typename TData>
BSTable<TKey, TData>::BSTable(const BSTable<TKey, TData>& table){
    this->maxSize = table.maxSize;
    this->count = table.count;
    this->currPos = table.currPos;
    this->pMap = new BinarySearchTree<TKey, TData>*(table.pMap);
    
}
template <typename TKey, typename TData>
BSTable<TKey, TData>::~BSTable(){
    delete this->pMap;
}
template <typename TKey, typename TData>
TabRecord<TKey, TData>* BSTable<TKey, TData>::Find(TKey key){
    if(this->isEmpty()) return nullptr;
    TreeNode<TKey, TData>* b = this->pMap->Search(key, this->pMap->GetRoot());
    if(b == nullptr) return nullptr;
    TabRecord<TKey, TData>* a = new TabRecord<TKey, TData>(b->key, b->data);
    return a;
}
template <typename TKey, typename TData>
void BSTable<TKey, TData>::Insert(TKey key, TData data){
    if(this->isFull()) throw "error";
    this->pMap->Insert(key, data);
    this->count++;
}
template <typename TKey, typename TData>
void BSTable<TKey, TData>::Remove(TKey key){
    if(this->isEmpty()) throw "error";
    this->pMap->Remove(key);
}

template <typename TKey, typename TData>
void BSTable<TKey, TData>::Next(){
    if(!this->IsTabEnden()){
        this->currPos++;
        this->pCurr = pMap->SearchNext(pCurr->key, pCurr);
    }
}
template <typename TKey, typename TData>
void BSTable<TKey, TData>::Reset(){
    this->currPos = 0;
    this->pCurr = pMap->SearchMin(this->pMap->GetRoot());
}

template <typename TKey, typename TData>
TabRecord<TKey, TData>* BSTable<TKey, TData>::GetCurrent() const{
    
    return new TabRecord<TKey, TData>(this->pCurr->key, this->pCurr->data);
}
