#include <gtest.h>
#include "ListHashTable.h"

TEST(ListHashTable, can_create_listhashtable) {
    ListHashTable<int, int> a(10);
    ASSERT_NO_THROW(a);
}

TEST(ListHashTable, can_insert_and_find_listhashtable) {
    ListHashTable<int, int> a(10);
    a.Insert(1, 1);
    EXPECT_EQ(1, a.Find(1)->pData);
}
TEST(ListHashTable, can_copy_listhashtable) {
    ListHashTable<int, int> a(10);
    a.Insert(1, 1);
    ListHashTable<int, int> b(a);
    EXPECT_EQ(1, b.Find(1)->pData);
}
TEST(ListHashTable, can_copy_not_from_one_link_listhashtable) {
    ListHashTable<int, int> a(10);
    a.Insert(1, 1);
    ListHashTable<int, int> b(a);
    b.Insert(2, 2);
    EXPECT_NE(a, b);
}
TEST(ListHashTable, can_remove_from_listhashtable) {
    ListHashTable<int, int> a(10);
    a.Insert(1, 1);
    a.Insert(2, 2);
    a.Remove(2);
    EXPECT_EQ(nullptr, a.Find(2));
}
TEST(ListHashTable, check_isEmpty_listhashtable) {
    ListHashTable<int, int> a(10);
    a.Insert(1, 1);
    a.Remove(1);
    EXPECT_EQ(true, a.isEmpty());
}
TEST(ListHashTable, check_isFull_listhashtable) {
    ListHashTable<int, int> a(2);
    a.Insert(1, 1);
    a.Insert(2, 1);
    EXPECT_EQ(true, a.isFull());
}
TEST(ListHashTable, check_cant_insert_isFull_listhashtable) {
    ListHashTable<int, int> a(2);
    a.Insert(1, 1);
    a.Insert(2, 1);
    ASSERT_ANY_THROW(a.Insert(3, 1));
}
TEST(ListHashTable, check_normal_hash_listhashtable) {
    ListHashTable<int, int> a(2);
    a.Insert(1, 1);
    a.Insert(11, 11);
    a.Reset();
    a.Next();
    EXPECT_EQ(11, a.GetCurrent()->pData);
}
