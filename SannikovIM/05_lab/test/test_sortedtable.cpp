#include <gtest.h>
#include "SortedTable.h"
using namespace std;

TEST(SortedTable, can_make_scantable) {
    SortedTable<int, int> a(10);
    ASSERT_NO_THROW(a);
}