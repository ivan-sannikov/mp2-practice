#include <gtest.h>
#include "SortedTable.h"
using namespace std;

TEST(SortedTable, can_make_scantable) {
    SortedTable<int, int> a(10);
    ASSERT_NO_THROW(a);
}
TEST(SortedTable, can_make_sortedtable_from_scantable) {
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
TEST(SortedTable, can_find_in_sortedtable) {
    SortedTable<int, int> a(10);
    a.Insert(1, 1);
    a.Insert(2, 1);
    a.Insert(3, 8);
    EXPECT_EQ(a.Find(3)->pData, 8);
}
