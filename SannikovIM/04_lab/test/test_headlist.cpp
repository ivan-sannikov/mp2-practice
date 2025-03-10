#include <gtest.h>
#include "headlist.h"


TEST(THeadList, can_create_headlist) {
	ASSERT_NO_THROW(THeadList<int> l);
}

TEST(THeadList, can_insertedfirst_in_headlist) {
	THeadList<int> l;
	l.InsertFirst(1);
	EXPECT_EQ(1, l.GetFirst()->key);

}
TEST(THeadList, can_deletefirst_in_headlist) {
	THeadList<int> l;
	l.InsertFirst(1);
	l.DeleteFirst();
	EXPECT_EQ(nullptr, l.GetFirst());
}
TEST(THeadList, can_deletefirst_in_headlist_with_more_elements) {
	THeadList<int> l;
	l.InsertFirst(1);
	l.InsertFirst(2);
	l.DeleteFirst();
	EXPECT_EQ(1, l.GetFirst()->key);
}
