#pragma once
template <typename TKey, typename TData>
struct TreeNode{
    TKey key;
    TData data;
    TreeNode<TKey, TData>* pRight;
    TreeNode<TKey, TData>* pLeft;
    TreeNode<TKey, TData>* pParrent;
    TreeNode(TKey key, TData data) : key(key), data(data){}
    TreeNode(){}
};
