#include <gtest.h>
#include "ScanTable.h"

TEST(ScanTable, can_make_scantable) {
    try {
        ScanTable<int, int> a(10);
    }
    catch (...) {
        ADD_FAILURE();
    }
}
TEST(ScanTable, can_copy_scantable) {
    ScanTable<int, int> a(10);
    a.Insert(1, 1);
    ScanTable<int, int> b(a);
    EXPECT_EQ(a, b);
}
TEST(ScanTable, copy_scantable_from_not_one_link) {
    ScanTable<int, int> a(10);
    a.Insert(1, 1);
    ScanTable<int, int> b(a);
    a.Insert(2, 1);
    EXPECT_NE(a, b);
}
TEST(ScanTable, can_insert_and_find_scantable) {
    ScanTable<int, int> a(10);
    a.Insert(1, 1);
    TabRecord<int, int>* r = new TabRecord<int, int>(1, 1);
    EXPECT_EQ(a.Find(1)->pData,r->pData);
}
TEST(ScanTable, can_check_isFull_scantable) {
    ScanTable<int, int> a(1);
    a.Insert(1, 1);
    ASSERT_ANY_THROW(a.Insert(1, 1));
}
TEST(ScanTable, can_getcurrent_scantable) {
    ScanTable<int, int> a(10);
    a.Insert(1, 1);
    TabRecord<int, int>* r = new TabRecord<int, int>(1, 1);
    EXPECT_EQ(a.GetCurrent()->pData, r->pData);
}
TEST(ScanTable, can_work_equal_scantable) {
    ScanTable<int, int> a(10);
    a.Insert(1, 1);
    ScanTable<int, int> b(a);
    ASSERT_TRUE(a == b);
}
TEST(ScanTable, can_work_notequal_scantable) {
    ScanTable<int, int> a(10);
    a.Insert(1, 1);
    ScanTable<int, int> b(a);
    
    a.Insert(8, 1);
    ASSERT_TRUE(a != b);
}
TEST(ScanTable, can_new_scantable_isEmpty) {
    ScanTable<int, int> a(10);
    EXPECT_EQ(true, a.isEmpty());
}
TEST(ScanTable, can_scantable_isFull) {
    ScanTable<int, int> a(1);
    a.Insert(1, 1);
    EXPECT_EQ(true, a.isFull());
}
TEST(ScanTable, can_Remove_element_scantable) {
    ScanTable<int, int> a(1);
    a.Insert(1, 1);
    a.Remove(1);
    EXPECT_EQ(true, a.isEmpty());
}

TEST(ScanTable, ca1n_Remove_element_scantable) {
    ScanTable<int, int> a(1);
    a.Insert(1, 1);
    a.Remove(1);
    EXPECT_EQ(true, a.isEmpty());
}
