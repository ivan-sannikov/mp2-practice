#include <gtest.h>
#include "list.h"



TEST(TList, can_create_list) {
	ASSERT_NO_THROW(TList<int> l);
}

TEST(TList, can_insertfirst_and_getfirst_node_in_list) {

	TList<int> l;
	l.InsertFirst(1);
	TNode<int>* a = l.GetFirst();
	EXPECT_EQ(1, a->key);
}
TEST(TList, can_insertend_and_getlast_node_in_list) {

	TList<int> l;
	l.InsertFirst(1);
	l.InsertEnd(2);
	TNode<int>* a = l.GetFirst();
	EXPECT_EQ(2,a->pNext->key);
}
TEST(TList, can_deletefirst_node_in_list) {

	TList<int> l;
	l.InsertFirst(1);
	l.InsertFirst(2);
	l.DeleteFirst();
	EXPECT_EQ(1, l.GetFirst()->key);
}
TEST(TList, can_deletelast_node_in_list) {

	TList<int> l;
	l.InsertFirst(1);
	l.InsertFirst(2);
	l.DeleteLast();
	EXPECT_EQ(2, l.GetFirst()->key);
}

TEST(TList, can_insertbefore_in_list) {

	TList<int> l;
	l.InsertEnd(1);
	l.InsertEnd(2);
	l.InsertBefore(1, 3);
	TNode<int>* a = l.GetFirst();
	EXPECT_EQ(3, l.GetFirst()->key);
}
TEST(TList, can_insertafter_in_list) {

	TList<int> l;
	l.InsertEnd(1);
	l.InsertEnd(2);
	l.InsertAfter(1, 3);
	TNode<int>* a = l.GetFirst();
	EXPECT_EQ(3, a->pNext->key);
}

TEST(TList, can_search_in_list) {

	TList<int> l;
	l.InsertEnd(1);
	l.InsertEnd(2);
	l.InsertEnd(3);
	TNode<int>* a = new TNode<int>(2);
	EXPECT_EQ(l.Search(2)->key, a->key);
}

TEST(TList, can_delete_in_list) {

	TList<int> l;
	l.InsertEnd(1);
	l.InsertEnd(2);
	l.InsertEnd(3);
	l.Delete(2);
	EXPECT_EQ(l.GetFirst()->key, 1);
	EXPECT_EQ(l.GetFirst()->pNext->key, 3);
}



