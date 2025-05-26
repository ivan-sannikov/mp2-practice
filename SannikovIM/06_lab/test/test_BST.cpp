#include <gtest.h>
#include "BinarySearchTree.h"

TEST(BinarySearchTree, can_create_BST){
    try {
        BinarySearchTree<int, int> a;
    }
    catch (...) {
        ADD_FAILURE();
    }
}
TEST(BinarySearchTree, can_insert_and_find_in_BST){
    BinarySearchTree<int, int> a;
    a.Insert(1,1);
    EXPECT_EQ(1, a.Search(1, a.GetRoot())->data);
}
TEST(BinarySearchTree, can_remove_in_BST){
    BinarySearchTree<int, int> a;
    a.Insert(1, 1);
    a.Insert(2, 2);
    a.Remove(2);
    EXPECT_EQ(nullptr, a.Search(2, a.GetRoot()));
}
TEST(BinarySearchTree, can_searchmin_in_BST){
    BinarySearchTree<int, int> a;
    a.Insert(1, 1);
    a.Insert(3, 3);
    a.Insert(2, 2);
    EXPECT_EQ(1, a.SearchMin(a.GetRoot())->data);
}
TEST(BinarySearchTree, can_searchmax_in_BST){
    BinarySearchTree<int, int> a;
    a.Insert(1, 1);
    a.Insert(3, 3);
    a.Insert(2, 2);
    EXPECT_EQ(3, a.SearchMax(a.GetRoot())->data);
}
TEST(BinarySearchTree, can_searchnext_in_BST){
    BinarySearchTree<int, int> a;
    a.Insert(1, 1);
    a.Insert(3, 3);
    a.Insert(2, 2);
    EXPECT_EQ(3, a.SearchNext(2,a.Search(2, a.GetRoot()))->data);
}
TEST(BinarySearchTree, can_searchprev_in_BST){
    BinarySearchTree<int, int> a;
    a.Insert(1, 1);
    a.Insert(3, 3);
    a.Insert(2, 2);
    EXPECT_EQ(1, a.SearchPrev(2,a.Search(2, a.GetRoot()))->data);
}

