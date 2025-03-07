#include <gtest.h>
#include "TPolinom.h"


TEST(TPolinom, can_create_polinom) {
	ASSERT_NO_THROW(TPolinom p("11z+2x"));
}
TEST(TPolinom, can_create_polinom_without_parametrs) {
	ASSERT_NO_THROW(TPolinom p);
}
TEST(TPolinom, can_create_copy_polinom) {
	TPolinom p("1z+2x");
	ASSERT_NO_THROW(TPolinom p1(p));
 }
TEST(TPolinom, copied_polinom_is_equal_to_source_one) {
	TPolinom p("1z+2x");
	TPolinom p1(p);
	TPolinom p2(p);
	EXPECT_EQ(p2, p1);
}
TEST(TPolinom, can_create_polinom_as_tringheadlist) {
	TRingHeadList<TMonom> s;
	TMonom m("0z^-1");
	TMonom m1("2z");
	TMonom m2("1y");
	s.SetHead(m);
	s.InsertFirst(m1);
	s.InsertFirst(m2);
	ASSERT_NO_THROW(TPolinom p(s));
}
TEST(TPolinom, can_compare_polinom) {
	TPolinom p("1z+2x");
	TPolinom p1("1z+2x");
	EXPECT_EQ(p, p1);
}
TEST(TPolinom, can_equate_polinoms) {
	TPolinom p("1z+2x");
	TPolinom p1("2z+2x");
	p = p1;
	EXPECT_EQ(p, p1);
}
TEST(TPolinom, can_sum_polinoms) {
	TPolinom p("1z+2x");
	TPolinom p1("1z");
	TPolinom p2("2z+2x");
	p = p+p1;
	EXPECT_EQ(p2, p);
}
TEST(TPolinom, can_sub_polinoms) {
	TPolinom p("1z-1x");
	TPolinom p1("1z+3x");
	TPolinom p2("2z+2x");
	p2 = p2 - p1;
	EXPECT_EQ(p2, p);
}
TEST(TPolinom, can_multiply_polinoms) {
	TPolinom p("1z+2x");
	TPolinom p1("1z+3x");
	TPolinom p2("6x^2+5xz+z^2");
	p = p * p1;
 	EXPECT_EQ(p2, p);
}
TEST(TPolinom, can_sum_polinom_and_monom) {
	TPolinom p("1z+2x");
	TMonom p1("1z");
	TPolinom p2("2z+2x");
	p = p + p1;
	EXPECT_EQ(p2, p);
}
TEST(TPolinom, can_sub_polinom_and_monom) {
	TPolinom p("1z+2x");
	TMonom p1("1z");
	TPolinom p2("2z+2x");
	p = p2 - p1;
	EXPECT_EQ(p2, p);
}
TEST(TPolinom, can_multiply_polinom_and_monom) {
	TPolinom p("1z+2x");
	TMonom p1("2z");
	TPolinom p2("2z^2+4zx");
	p = p * p1;
	EXPECT_EQ(p2, p);
}
TEST(TPolinom, can_multiply_polinom_and_scalar) {
	TPolinom p("1z+2x");
	TPolinom p2("8z + 16x");
	p = p * 8;
	EXPECT_EQ(p2, p);
}