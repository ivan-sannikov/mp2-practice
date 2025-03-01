#include <gtest.h>
#include "TMonom.h"


TEST(TMonom, can_create_monom) {
	ASSERT_NO_THROW(TMonom("-3xyz"));
}
TEST(TMonom, getvalue_positive) {
	TMonom p("3x");
	double h = p.GetValue();
	EXPECT_EQ(3, h);
}
TEST(TMonom, getvalue_negative) {
	TMonom p("-3x");
	double h = p.GetValue();
	EXPECT_EQ(-3, h);
}
TEST(TMonom, getvalue_double) {
	TMonom p("-3.5x");
	double h = p.GetValue();
	EXPECT_EQ(-3.5, h);
}
TEST(TMonom, getconvolution_double) {
	TMonom p("-3.5x^2");
	double h = p.GetConvolution();
	EXPECT_EQ(200, h);
}
TEST(TMonom, getconvolution_more) {
	TMonom p("-3.5x^2y^6z^7");
	double h = p.GetConvolution();
	EXPECT_EQ(267, h);
}
TEST(TMonom, getconvolution_without_degree) {
	TMonom p("-3.5xyz");
	double h = p.GetConvolution();
	EXPECT_EQ(111, h);
}
TEST(TMonom, get_monom_simple) {
	TMonom p("-3.5xyz");
	string s = p.GetMonom();
	EXPECT_EQ("-3.5xyz", s);
}
TEST(TMonom, get_monom_with_one_parametr) {
	TMonom p("-3.5x");
	string s = p.GetMonom();
	EXPECT_EQ("-3.5x", s);
}
TEST(TMonom, getmonom) {
	TMonom p("-3.5x^2y^6z^7");
	string s = p.GetMonom();
	EXPECT_EQ("-3.5x^2y^6z^7", s);
}

TEST(TMonom, getmonomcovn_simple) {
	TMonom p("4xyz");
	string s = p.GetMonomConv();
	EXPECT_EQ("xyz", s);
}

TEST(TMonom, getmonomcovn_with_one_parametr) {
	TMonom p("4x");
	string s = p.GetMonomConv();
	EXPECT_EQ("x", s);
}

TEST(TMonom, getmonomcovn) {
	TMonom p("-3.5x^2y^6z^7");
	string s = p.GetMonomConv();
	EXPECT_EQ("x^2y^6z^7", s);
}

