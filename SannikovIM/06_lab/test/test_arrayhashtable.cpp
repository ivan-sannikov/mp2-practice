#include <gtest.h>
#include "ArrayHashTable.h"

TEST(ArrayHashTable, can_make_arrayhashtable) {
    ArrayHashTable<int, int> a(10, 2);
    ASSERT_NO_THROW(a);
}
TEST(ArrayHashTable, can_inser_and_find_in_arrayhashtable) {
    ArrayHashTable<int, int> a(10, 2);
    a.Insert(1, 1);
    EXPECT_EQ(1, a.Find(1)->pData);
}
TEST(ArrayHashTable, can_inser_and_find_with_colision_in_arrayhashtable) {
    ArrayHashTable<int, int> a(10, 2);
    a.Insert(1, 1);
    a.Insert(11, 11);
    EXPECT_EQ(11, a.Find(11)->pData);
}
