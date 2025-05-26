#include <gtest.h>
#include "BSTable.h"

TEST(BSTable, can_create_BSTable){
    try {
        BSTable<int, int> a(10);
    }
    catch (...) {
        ADD_FAILURE();
    }
}
TEST(BSTable, can_insert_and_find_in_BSTable){
    BSTable<int, int> a(10);
    a.Insert(1,1);
    EXPECT_EQ(1, a.Find(1)->pData);
}
TEST(BSTable, can_remove_in_BSTable){
    BSTable<int, int> a(10);
    a.Insert(1,1);
    a.Insert(2,2);
    a.Remove(2);
    EXPECT_EQ(nullptr, a.Find(2));
}
TEST(BSTable, can_navigation_in_BSTable){
    BSTable<int, int> a(10);
    a.Insert(3, 3);
    a.Insert(1, 1);
    a.Insert(2, 2);
    a.Insert(4, 4);
    a.Reset();
    a.Next();
    a.Next();
    EXPECT_EQ(3, a.GetCurrent()->pData);
}

