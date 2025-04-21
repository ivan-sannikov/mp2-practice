#include <gtest.h>
#include "TMonom.h"


TEST(TMonom, can_create_monom) {
	ASSERT_NO_THROW(TMonom("-3xyz"));
}
TEST(TMonom, getvalue_positive) {
	TMonom p("3x");
	double h = p.GetCoeff();
	EXPECT_EQ(3, h);
}
TEST(TMonom, getvalue_negative) {
	TMonom p("-3x");
	double h = p.GetCoeff();
	EXPECT_EQ(-3, h);
}
TEST(TMonom, getvalue_double) {
	TMonom p("-3.5x");
	double h = p.GetCoeff();
	EXPECT_EQ(-3.5, h);
}
TEST(TMonom, getconvolution_double) {
	TMonom p("-3.5x^2");
	int h = p.GetDegree();
	EXPECT_EQ(200, h);
}
TEST(TMonom, getconvolution_more) {
	TMonom p("-3.5x^2y^6z^7");
	int h = p.GetDegree();
	EXPECT_EQ(267, h);
}
TEST(TMonom, getconvolution_without_degree) {
	TMonom p("-3.5xyz");
	int h = p.GetDegree();
	EXPECT_EQ(111, h);
}
TEST(TMonom, getcoeff_simple) {
	TMonom m("3xyz");
	EXPECT_EQ(3, m.GetCoeff());
}
TEST(TMonom, getcoeff_minus_simple) {
	TMonom m("-3xyz");
	EXPECT_EQ(-3, m.GetCoeff());
}
TEST(TMonom, sum_simple_monoms) {
	TMonom m("3xyz");
	TMonom m1("5xyz");
	TMonom m2("8xyz");
	EXPECT_EQ(m2, m + m1);
}
TEST(TMonom, sub_simple_monoms) {
	TMonom m("3xyz");
	TMonom m1("5xyz");
	TMonom m2("2xyz");
	EXPECT_EQ(m2, m1-m);
}
TEST(TMonom, sum_big_monoms) {
	TMonom m("3x^2y^5z^7");
	TMonom m1("5x^2y^5z^7");
	TMonom m2("8x^2y^5z^7");
	EXPECT_EQ(m2, m + m1);
}
TEST(TMonom, sub_big_monoms) {
	TMonom m("3x^2y^5z^7");
	TMonom m1("5x^2y^5z^7");
	TMonom m2("2x^2y^5z^7");
	EXPECT_EQ(m2, m1-m);
}
TEST(TMonom, mul_simple_monoms) {
	TMonom m("3xyz");
	TMonom m1("5xyz");
	TMonom m2("15x^2y^2z^2");
	EXPECT_EQ(m2, m1 * m);
}
TEST(TMonom, mul_big_monoms) {
	TMonom m("3x^2y^2z^4");
	TMonom m1("5x^2y^3z^4");
	TMonom m2("15x^4y^5z^8");
	EXPECT_EQ(m2, m1*m);
}
TEST(TMonom, mul_simple_monoms_and_scalar) {
	TMonom m("3xyz");
	TMonom m2("15xyz");
	EXPECT_EQ(m2, m*5);
}
TEST(TMonom, mul_big_monoms_and_scalar) {
	TMonom m("3x^2y^2z^4");
	TMonom m2("15x^2y^2z^4");
	EXPECT_EQ(m2, m*5);
}
TEST(TMonom, more_monoms) {
	TMonom m("3xyz");
	TMonom m1("5xyz");
	EXPECT_EQ(true, m1>m);
}
TEST(TMonom, less_monoms) {
	TMonom m("3xyz");
	TMonom m1("5xyz");
	EXPECT_EQ(true, m < m1);
}
TEST(TMonom, more_equals_monoms) {
	TMonom m("3xyz");
	TMonom m1("5xyz");
	EXPECT_EQ(true, m1 >= m);
}
TEST(TMonom, less_equals_monoms) {
	TMonom m("3xyz");
	TMonom m1("5xyz");
	EXPECT_EQ(true, m <= m1);
}
TEST(TMonom, less_equals_monoms_2) {
	TMonom m("3xyz");
	TMonom m1("3xyz");
	EXPECT_EQ(true, m1 <= m);
}
TEST(TMonom, more_equals_monoms_2) {
	TMonom m("3xyz");
	TMonom m1("3xyz");
	EXPECT_EQ(true, m1 >= m);
}
TEST(TMonom, monoms_nums) {
	TMonom m("3x^2y^3z^2");
	EXPECT_EQ(216, m(1,2,3));
}

