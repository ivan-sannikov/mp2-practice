#include <gtest.h>
#include "TPolinom.h"


TEST(TPolinom, can_create_polinom) {
	ASSERT_NO_THROW(TPolinom p1("1z+2x"));
}
TEST(TPolinom, can_create_copy_polinom) {
	TPolinom p("z+2x");
	ASSERT_NO_THROW(TPolinom p1(p));
 }
TEST(TPolinom, copied_polinom_is_equal_to_source_one) {
	TPolinom p("z+2x");
	TPolinom p1(p);
	TPolinom p2(p);
	EXPECT_EQ(p2, p1);
}
TEST(TPolinom, can_compare_polinom) {
	TPolinom p("1z+2x");
	TPolinom p1("z+2x");
	EXPECT_EQ(p, p1);
}
TEST(TPolinom, can_equate_polinoms) {
	TPolinom p("1z+2x");
	TPolinom p1("2z+2x");
	p = p1;
	EXPECT_EQ(p, p1);
}
TEST(TPolinom, can_sum_polinom_and_scalar){
    TPolinom p("1z+2x");
    TPolinom p1("2x+1z+1");
	TPolinom p2;
	p2 = p + 1;
    EXPECT_EQ(p1, p2);
}
TEST(TPolinom, can_sum_polinom_and_scalar_with_minus){
    TPolinom p("1z+2x");
    TPolinom p1("2x+1z-1");
    TPolinom p2;
    p2 = p + (-1.0);
    EXPECT_EQ(p1, p2);
}
TEST(TPolinom, can_sub_polinom_and_scalar){
    TPolinom p("1z+2x");
    TPolinom p1("2x+1z-1");
    TPolinom p2 = p - 1;
    EXPECT_EQ(p1, p2);
}
TEST(TPolinom, can_sub_polinom_and_scalar_with_minus){
    TPolinom p("1z+2x");
    TPolinom p1("2x+1z+1");
    TPolinom p2;
    p2 = p - (-1.0);
    EXPECT_EQ(p1, p2);
}

TEST(TPolinom, can_sum_polinoms) {
	TPolinom p("5x+3z");
	TPolinom p1("1z+3x");
	TPolinom p2("2z+2x");
	p2 = p2 + p1;
	EXPECT_EQ(p2, p);
}

TEST(TPolinom, can_sum_big_polinoms) {
	TPolinom p("5x^2y^5z^2+3x^3y^2z^3");
	TPolinom p1("2xyz+z+3x^2y^2z^2");
	TPolinom p2("3x^3y^2z^3+5x^2y^5z^2+3x^2y^2z^2+2xyz+z");
	p = p + p1;
	EXPECT_EQ(p2, p);
}

TEST(TPolinom, can_sub_polinoms) {
	TPolinom p("-1x+1z");
	TPolinom p1("1z+3x");
	TPolinom p2("2z+2x");
	p2 = p2 - p1;
	EXPECT_EQ(p2, p);
}

TEST(TPolinom, can_multiply_polinoms) {
	TPolinom p("1z+2x");
	TPolinom p1("1z+3x");
	TPolinom p2("6x^2+5xz+1z^2");
	p = p * p1;
 	EXPECT_EQ(p2, p);
}
TEST(TPolinom, can_sum_polinom_and_monom) {
	TPolinom p("1z+2x");
	TMonom p1("1z");
	TPolinom p2("2x+2z");
	p = p + p1;
	EXPECT_EQ(p2, p);
}
TEST(TPolinom, can_sub_polinom_and_monom) {
	TPolinom p("2x+1z");
	TMonom p1("1z");
	TPolinom p2("2z+2x");
	p2 = p2 - p1;
	EXPECT_EQ(p2, p);
}
TEST(TPolinom, can_multiply_polinom_and_monom) {
	TPolinom p("1z+2x");
	TMonom p1("2z");
	TPolinom p2("4xz+2z^2");
	p = p * p1;
	EXPECT_EQ(p2, p);
}
TEST(TPolinom, can_multiply_polinom_and_scalar) {
	TPolinom p("1z+2x");
	TPolinom p2("16x+8z");
	p = p * 8;
	EXPECT_EQ(p2, p);
}
TEST(TPolinom, can_diff_x_sample_polinom) {
	TPolinom p("1z+2xy");
	TPolinom p2("2y");
	TPolinom p3 = p.DiffX();
	EXPECT_EQ(p2, p3);
}
TEST(TPolinom, can_diff_y_sample_polinom) {
	TPolinom p("1z+2x+3yz");
	TPolinom p2("3z");
	TPolinom p3 = p.DiffY();
	EXPECT_EQ(p2, p3);
}
TEST(TPolinom, can_diff_z_sample_polinom) {
	TPolinom p("1xz+2x");
	TPolinom p2("1x");
	TPolinom p3 = p.DiffZ();
	EXPECT_EQ(p2, p3);
}
TEST(TPolinom, can_diff_x_polinom) {
	TPolinom p("5xyz+6x^2y^7z^3");
	TPolinom p2("12xy^7z^3+5yz");
	TPolinom p3 = p.DiffX();
	EXPECT_EQ(p2, p3);
}
TEST(TPolinom, can_diff_y_polinom) {
	TPolinom p("5xyz+6x^2y^7z^3");
	TPolinom p2("42x^2y^6z^3+5xz");
    TPolinom p3 = p.DiffY();
    EXPECT_EQ(p2, p3);
}
TEST(TPolinom, can_diff_z_polinom) {
	TPolinom p("5xyz+6x^2y^7z^3");
	TPolinom p2("18x^2y^7z^2+5xy");
    TPolinom p3 = p.DiffZ();
    EXPECT_EQ(p2, p3);
}

TEST(TPolinom, can_multiply_form)
{
	TMonom m1("-z");
	TPolinom p1("1-x");
	TPolinom p2("x+1");
	TPolinom p3("-x^2+1");
	EXPECT_EQ(p3, p1 * p2);
}

TEST(TPolinom, can_multiply_form1)
{
	TPolinom p1("1-x");
	TPolinom p2("x+1+x^2");
	TPolinom p3("-x^3+1");
	EXPECT_EQ(p3, p1 * p2);
}

TEST(TPolinom, can_sum_form)
{
	TPolinom p1("1-x");
	TPolinom p2("x+1");
	TPolinom p3("2");
	EXPECT_EQ(p3, p1 + p2);
}

TEST(TPolinom, can_sub_form)
{
	TPolinom p1("1-x");
	TPolinom p2("x+1");
	TPolinom p3("-2x");
	EXPECT_EQ(p3, p1 - p2);
}

TEST(TPolinom, can_multiply_form2)
{
	TPolinom p1("5xyz-2zy");
	TPolinom p2("-1+4z-5x^2y");
	TPolinom p3("10x^2y^2z-25x^3y^2z+20xyz^2-5xyz-8yz^2+2yz");
	EXPECT_EQ(p3, p1 * p2);
}