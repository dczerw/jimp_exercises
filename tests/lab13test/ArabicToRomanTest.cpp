//
// Created by mwypych on 01.06.17.
//

#include "ArabicRoman.h"
#include <gtest/gtest.h>
#include <string>

TEST(ArabicToRomanTest, ArabicToRomanBasic1) {
    EXPECT_EQ("I", arabicToRoman(1));
}

TEST(ArabicToRomanTest, ArabicToRomanBasic5) {
    EXPECT_EQ("V", arabicToRoman(5));
}

TEST(ArabicToRomanTest, ArabicToRomanBasic) {
    EXPECT_EQ("VIII", arabicToRoman(8));
}