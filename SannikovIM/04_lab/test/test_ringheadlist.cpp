#include <gtest.h>
#include "ringheadlist.h"


TEST(TRingHeadList, can_create_ringheadlist) {
	ASSERT_NO_THROW(TRingHeadList<int> l);
}
TEST(TRingHeadList, can_insertend_one_element_in_ringheadlist) {
	TRingHeadList<int> l;
	l.InsertEnd(1);
	EXPECT_EQ(1, l.GetFirst()->key);
}
TEST(TRingHeadList, can_insertend_more_elements_in_ringheadlist) {
	TRingHeadList<int> l;
	l.InsertEnd(1);
	l.InsertEnd(2);
	EXPECT_EQ(2, l.GetFirst()->pNext->key);
}
