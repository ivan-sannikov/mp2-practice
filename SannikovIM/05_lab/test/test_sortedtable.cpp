#include <gtest.h>
#include "SortedTable.h"
using namespace std;

TEST(SortedTable, can_make_scantable) {
    SortedTable<int, int> a(10);
    ASSERT_NO_THROW(a);
}
TEST(SortedTable, can_make_sortedtable_default_from_scantable) {
    ScanTable<int, int> a(3);
    ScanTable<int, int> b(3);
    a.Insert(1, 1);
    a.Insert(2, 1);
    a.Insert(3, 1);
    b.Insert(3, 1);
    b.Insert(1, 1);
    b.Insert(2, 1);
    SortedTable<int, int> c(b);
    EXPECT_EQ(c.GetCurrent()->key, a.GetCurrent()->key);
}
TEST(SortedTable, can_make_sortedtable_bublesort_from_scantable) {
    ScanTable<int, int> a(3);
    ScanTable<int, int> b(3);
    a.Insert(1, 1);
    a.Insert(2, 1);
    a.Insert(3, 1);
    b.Insert(3, 1);
    b.Insert(1, 1);
    b.Insert(2, 1);
    SortedTable<int, int> c(b,1);
    EXPECT_EQ(c.GetCurrent()->key, a.GetCurrent()->key);
}
TEST(SortedTable, can_make_sortedtable_selectionsort_from_scantable) {
    ScanTable<int, int> a(3);
    ScanTable<int, int> b(3);
    a.Insert(1, 1);
    a.Insert(2, 1);
    a.Insert(3, 1);
    b.Insert(3, 1);
    b.Insert(1, 1);
    b.Insert(2, 1);
    SortedTable<int, int> c(b, 2);
    EXPECT_EQ(c.GetCurrent()->key, a.GetCurrent()->key);
}
TEST(SortedTable, can_make_sortedtable_insertsort_from_scantable) {
    ScanTable<int, int> a(3);
    ScanTable<int, int> b(3);
    a.Insert(1, 1);
    a.Insert(2, 1);
    a.Insert(3, 1);
    b.Insert(3, 1);
    b.Insert(1, 1);
    b.Insert(2, 1);
    SortedTable<int, int> c(b, 3);
    EXPECT_EQ(c.GetCurrent()->key, a.GetCurrent()->key);
}
TEST(SortedTable, can_make_sortedtable_mergesort_from_scantable) {
    ScanTable<int, int> a(3);
    ScanTable<int, int> b(3);
    a.Insert(1, 1);
    a.Insert(2, 1);
    a.Insert(3, 1);
    b.Insert(3, 1);
    b.Insert(1, 1);
    b.Insert(2, 1);
    SortedTable<int, int> c(b, 4);
    EXPECT_EQ(c.GetCurrent()->key, a.GetCurrent()->key);
}
TEST(SortedTable, can_make_sortedtable_quicksort_from_scantable) {
    ScanTable<int, int> a(3);
    ScanTable<int, int> b(3);
    a.Insert(1, 1);
    a.Insert(2, 1);
    a.Insert(3, 1);
    b.Insert(3, 1);
    b.Insert(1, 1);
    b.Insert(2, 1);
    SortedTable<int, int> c(b, 0);
    EXPECT_EQ(c.GetCurrent()->key, a.GetCurrent()->key);
}
TEST(SortedTable, can_find_in_sortedtable) {
    SortedTable<int, int> a(10);
    a.Insert(1, 1);
    a.Insert(2, 1);
    a.Insert(3, 8);
    EXPECT_EQ(a.Find(3)->pData, 8);
}
TEST(SortedTable, can_insert_in_sortedtable) {
    SortedTable<int, int> a(10);
    a.Insert(1, 1);
    a.Insert(2, 1);
    a.Insert(4, 1);
    a.Insert(3, 1);
    a.Reset();
    a.Next();
    a.Next();
    EXPECT_EQ(a.GetCurrent()->key, 3);
}
TEST(SortedTable, can_remove_from_sortedtable) {
    SortedTable<int, int> a(10);
    a.Insert(1, 1);
    a.Insert(2, 1);
    a.Insert(4, 1);
    a.Insert(3, 1);
    a.Remove(3);
    EXPECT_EQ(a.Find(3), nullptr);
}
TEST(SortedTable, can_equate_sortedtable) {
    SortedTable<int, int> a(10);
    a.Insert(1, 1);
    a.Insert(2, 1);
    a.Insert(4, 1);
    a.Insert(3, 1);
    SortedTable<int, int> b(20);
    b.Insert(1, 1);
    b.Insert(4, 1);
    b.Insert(3, 1);
    b.Insert(2, 1);
    ASSERT_TRUE(a == b);
}
