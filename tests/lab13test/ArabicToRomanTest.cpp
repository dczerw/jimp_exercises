//
// Created by mwypych on 01.06.17.
//

#include "ArabicRoman.h"
#include <gtest/gtest.h>
#include <string>

TEST(ArabicToRomanTest, ArabicToRomanBasic) {
    EXPECT_EQ("I", arabicToRoman(1));
}