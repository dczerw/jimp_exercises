//
// Created by mwypych on 01.06.17.
//

#include "ArabicRoman.h"
#include <gtest/gtest.h>
#include <string>

TEST(ArabicToRomanTest, RomanToArabicBasic) {
    EXPECT_EQ(1, romanToArabic("I"));
}

TEST(ArabicToRomanTest, RomanToArabicTwoDigits) {
    EXPECT_EQ(18, romanToArabic("XVIII"));
}

TEST(ArabicToRomanTest, RomanToArabicThreeDigits) {
    EXPECT_EQ(159, romanToArabic("CLIX"));
}

TEST(ArabicToRomanTest, RomanToArabicFourDigitsComplicated) {
    EXPECT_EQ(1267, romanToArabic("MCCLXVII"));
}

TEST(ArabicToRomanTest, RomanToArabicFourDigitsEasy) {
    EXPECT_EQ(1500, romanToArabic("MD"));
}

TEST(ArabicToRomanTest, RomanToArabicThreeDigitsEasyVeryMuch) {
    EXPECT_EQ(327, romanToArabic("CCCXXVII"));
}