#include <gtest.h>
#include "headlist.h"


TEST(THeadList, can_create_headlist) {
	ASSERT_NO_THROW(THeadList<int> l);
}

TEST(THeadList, can_sethead_and_gethead_in_headlist) {
	THeadList<int> l;
	l.SetHead(0);
	EXPECT_EQ(0, l.GetHead()->key);
	EXPECT_EQ(l.GetFirst(), l.GetHead()->pNext);
}

TEST(THeadList, can_insertedfirst_in_headlist) {
	THeadList<int> l;
	l.SetHead(0);
	l.InsertFirst(1);
	EXPECT_EQ(0, l.GetHead()->key);
	EXPECT_EQ(1, l.GetFirst()->key);
	EXPECT_EQ(l.GetFirst(), l.GetHead()->pNext);
}
TEST(THeadList, can_deletefirst_in_headlist) {
	THeadList<int> l;
	l.SetHead(0);
	l.InsertFirst(1);
	l.DeleteFirst();
	EXPECT_EQ(0, l.GetHead()->key);
	EXPECT_EQ(nullptr, l.GetFirst());
	EXPECT_EQ(l.GetFirst(), l.GetHead()->pNext);
}
TEST(THeadList, can_deletefirst_in_headlist_with_more_elements) {
	THeadList<int> l;
	l.SetHead(0);
	l.InsertFirst(1);
	l.InsertFirst(2);
	l.DeleteFirst();
	EXPECT_EQ(0, l.GetHead()->key);
	EXPECT_EQ(1, l.GetFirst()->key);
	EXPECT_EQ(l.GetFirst(), l.GetHead()->pNext);
}
