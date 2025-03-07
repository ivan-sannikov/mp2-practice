#include <gtest.h>
#include "ringheadlist.h"


TEST(TRingHeadList, can_create_ringheadlist) {
	ASSERT_NO_THROW(TRingHeadList<int> l);
}
TEST(TRingHeadList, can_sethead_and_gethead_in_ringheadlist) {
	TRingHeadList<int> l;
	l.SetHead(0);
	EXPECT_EQ(0, l.GetHead()->key);
	EXPECT_EQ(l.GetFirst(), l.GetHead()->pNext);
	EXPECT_EQ(l.GetHead(), l.GetFirst()->pNext);
}
TEST(TRingHeadList, can_insertend_one_element_in_ringheadlist) {
	TRingHeadList<int> l;
	l.SetHead(0);
	l.InsertEnd(1);
	EXPECT_EQ(0, l.GetHead()->key);
	EXPECT_EQ(1, l.GetLast()->key);
	EXPECT_EQ(1, l.GetFirst()->key);
	EXPECT_EQ(l.GetHead(), l.GetFirst()->pNext);
}
TEST(TRingHeadList, can_insertend_more_elements_in_ringheadlist) {
	TRingHeadList<int> l;
	l.SetHead(0);
	l.InsertEnd(1);
	l.InsertEnd(2);
	EXPECT_EQ(0, l.GetHead()->key);
	EXPECT_EQ(2, l.GetFirst()->pNext->key);
	EXPECT_EQ(l.GetHead(), l.GetFirst()->pNext->pNext);
}
