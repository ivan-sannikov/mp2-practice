#pragma once
#include "TreeNode.h"
template <typename TKey, typename TData>
class BinarySearchTree{
protected:
    TreeNode<TKey, TData>* root;
public:
    BinarySearchTree();
    BinarySearchTree(const BinarySearchTree<TKey, TData>& BSTree);
    ~BinarySearchTree();
    TreeNode<TKey, TData>* Search(TKey key, TreeNode<TKey, TData>* node);
    TreeNode<TKey, TData>* SearchMin(TreeNode<TKey, TData>* node);
    TreeNode<TKey, TData>* SearchMax(TreeNode<TKey, TData>* node);
    TreeNode<TKey, TData>* SearchNext(TKey key, TreeNode<TKey, TData>* node);
    TreeNode<TKey, TData>* SearchPrev(TKey key, TreeNode<TKey, TData>* node);
    void Insert(TKey key, TData data);
    void Remove(TKey key);
    const BinarySearchTree<TKey, TData>& operator=(const BinarySearchTree<TKey, TData>& BStree);
    TreeNode<TKey, TData>* GetRoot() const {return root;}
    
};
template <typename TKey, typename TData>
BinarySearchTree<TKey, TData>::BinarySearchTree(){
    this->root = nullptr;
}
template <typename TKey, typename TData>
BinarySearchTree<TKey, TData>::~BinarySearchTree(){
    delete root;
}

template <typename TKey, typename TData>
BinarySearchTree<TKey, TData>::BinarySearchTree(const BinarySearchTree<TKey, TData>& BSTree){
    this->root = new TreeNode<TKey, TData>*(BSTree.GetRoot()->key, BSTree.GetRoot()->data);
}
template <typename TKey, typename TData>
TreeNode<TKey, TData>* BinarySearchTree<TKey, TData>::Search(TKey key, TreeNode<TKey, TData>* node){
    while(node != nullptr && node->key != key){
        if(node->key > key) node = node->pLeft;
        else node = node->pRight;
    }
    return node;
}

template <typename TKey, typename TData>
TreeNode<TKey, TData>* BinarySearchTree<TKey, TData>::SearchMin(TreeNode<TKey, TData>* node){
    if(node == nullptr) throw "error";
    while(node->pLeft != nullptr) node = node->pLeft;
    return node;
}
template <typename TKey, typename TData>
TreeNode<TKey, TData>* BinarySearchTree<TKey, TData>::SearchMax(TreeNode<TKey, TData>* node){
    if(node == nullptr) throw "error";
    while(node->pRight != nullptr) node = node->pRight;
    return node;
}
template <typename TKey, typename TData>
TreeNode<TKey, TData>* BinarySearchTree<TKey, TData>::SearchNext(TKey key, TreeNode<TKey, TData>* node){
    if(node == nullptr) throw "error";
    if(node->pRight != nullptr) return SearchMin(node->pRight);
    TreeNode<TKey, TData> *p = node->pParrent;
    while(p != nullptr && p->pRight == node){
        node = p;
        p = node->pParrent;
    }
    return p;
}
template <typename TKey, typename TData>
TreeNode<TKey, TData>* BinarySearchTree<TKey, TData>::SearchPrev(TKey key, TreeNode<TKey, TData>* node){
    if(node == nullptr) throw "error";
    if(node->pLeft != nullptr) return SearchMax(node->pLeft);
    TreeNode<TKey, TData> *p = node->pParrent;
    while(p != nullptr && p->pLeft == node){
        node = p;
        p = node->pParrent;
    }
    return p;
}
template <typename TKey, typename TData>
void BinarySearchTree<TKey, TData>::Insert(TKey key, TData data){
    TreeNode<TKey, TData>* node = new TreeNode<TKey, TData>(key, data);
    if(this->root == nullptr){
        this->root = node;
        return;
    }
    TreeNode<TKey, TData>* x = this->root;
    TreeNode<TKey, TData>* y = nullptr;
    while(x != nullptr){
        y = x;
        if(x->key<node->key) x = x->pRight;
        else x = x->pLeft;
    }
    node->pParrent = y;
    if(node->key < y->key) y->pLeft = node;
    else y->pRight = node;
}
template <typename TKey, typename TData>
void BinarySearchTree<TKey, TData>::Remove(TKey key){
    TreeNode<TKey, TData>* z = this->Search(key, this->root);
    if(z == nullptr) throw "error";
    if(z->pRight == nullptr && z->pLeft == nullptr){
        if(z->pParrent->pLeft == z)
            z->pParrent->pLeft == nullptr;
        else
            z->pParrent->pRight = nullptr;
        delete z;
        return;
    }
    if(z->pRight == nullptr && z->pLeft != nullptr){
        if(z->pParrent->pLeft == z)
            z->pParrent->pLeft == z->pLeft;
        else
            z->pParrent->pRight = z->pLeft;
        z->pLeft->pParrent = z->pParrent;
        delete z;
        return;
    }
    if(z->pRight != nullptr && z->pLeft == nullptr){
        if(z->pParrent->pLeft == z)
            z->pParrent->pLeft == z->pRight;
        else
            z->pParrent->pRight = z->pParrent;
        delete z;
        return;
    }
    TreeNode<TKey, TData>* y = this->Search(z->key, this->root);
    if(y->pRight == nullptr)
        y->pRight->pParrent = y->pParrent;
    if(y->pParrent->pLeft == y)
        y->pParrent->pLeft = y->pRight;
    else
        y->pParrent->pRight = y->pRight;
    y->pLeft = z->pLeft;
    y->pRight = z->pRight;
    z->pLeft->pParrent = y;
    z->pRight->pParrent = y;
    delete z;
}

template <typename TKey, typename TData>
const BinarySearchTree<TKey, TData>& BinarySearchTree<TKey, TData>::operator=(const BinarySearchTree<TKey, TData>& BStree){
    if(BStree == *this) return *this;
    this->root = new TreeNode<TKey, TData>*(BStree.GetRoot()->key, BStree.GetRoot()->data);
    return *this;
}
