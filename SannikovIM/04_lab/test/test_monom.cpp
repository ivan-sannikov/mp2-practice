#include <gtest.h>
#include "TMonom.h"

/*
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
	double h = p.GetDegree();
	EXPECT_EQ(200, h);
}
TEST(TMonom, getconvolution_more) {
	TMonom p("-3.5x^2y^6z^7");
	double h = p.GetDegree();
	EXPECT_EQ(267, h);
}
TEST(TMonom, getconvolution_without_degree) {
	TMonom p("-3.5xyz");
	double h = p.GetDegree();
	EXPECT_EQ(111, h);
}
*/