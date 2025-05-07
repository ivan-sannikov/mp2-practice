#include <gtest.h>
#include "ScanTable.h"

TEST(ScanTable, Create_ScanTable){
    ScanTable<int, int> a(10);
    ASSERT_NO_THROW(a);
}
