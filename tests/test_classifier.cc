// Copyright (c) 2020 [Your Name]. All rights reserved.

#define CATCH_CONFIG_MAIN

#include <catch2/catch.hpp>
#include <bayes/classifier.h>
#include <bayes/model.h>
#include <bayes/image.h>

// TODO(you): Remove this unnecessary test case.
TEST_CASE("Test correct image file storage") {
    std::vector<bayes::Image> vect;
    std::string file = "                            \n"
                       "                            \n"
                       "                            \n"
                       "                            \n"
                       "                            \n"
                       "                +++++##+    \n"
                       "        +++++######+###+    \n"
                       "       +##########+++++     \n"
                       "        #######+##          \n"
                       "        +++###  ++          \n"
                       "           +#+              \n"
                       "           +#+              \n"
                       "            +#+             \n"
                       "            +##++           \n"
                       "             +###++         \n"
                       "              ++##++        \n"
                       "                +##+        \n"
                       "                 ###+       \n"
                       "              +++###        \n"
                       "            ++#####+        \n"
                       "          ++######+\n"
                       "        ++######+           \n"
                       "       +######+             \n"
                       "    ++######+               \n"
                       "    +####++                 \n"
                       "                            \n"
                       "                            \n"
                       "                            \n"
                       "                            \n"
                       "                            \n"
                       "                            \n"
                       "                            \n"
                       "               ++#++        \n"
                       "              +#####        \n"
                       "             +######+       \n"
                       "            +#####+##+      \n"
                       "           +######++#+      \n"
                       "          +###++##++#+      \n"
                       "         +###+ +++  ##+     \n"
                       "        ++###+      ##+     \n"
                       "        +##+ +      ###     \n"
                       "       +##+         ###     \n"
                       "       ##+          ###     \n"
                       "      +##+          ##+     \n"
                       "      +##+         +#+      \n"
                       "      +##         +##+      \n"
                       "      +#+       ++#+        \n"
                       "      +##      +##+         \n"
                       "      +##+++++###++         \n"
                       "      +#########+           \n"
                       "      +#######+             \n"
                       "       ++###++              \n"
                       "                            \n"
                       "                            \n"
                       "                            \n"
                       "                           ";
    bayes::CreateList(vect, file);
    REQUIRE(vect.size() == 2);
}

TEST_CASE("Test correct index shades") {
    std::vector<bayes::Image> vect;
    std::string file =   "                            \n"
                         "                            \n"
                         "                            \n"
                         "                            \n"
                         "                            \n"
                         "                +++++##+    \n"
                         "        +++++######+###+    \n"
                         "       +##########+++++     \n"
                         "        #######+##          \n"
                         "        +++###  ++          \n"
                         "           +#+              \n"
                         "           +#+              \n"
                         "            +#+             \n"
                         "            +##++           \n"
                         "             +###++         \n"
                         "              ++##++        \n"
                         "                +##+        \n"
                         "                 ###+       \n"
                         "              +++###        \n"
                         "            ++#####+        \n"
                         "          ++######+\n"
                         "        ++######+           \n"
                         "       +######+             \n"
                         "    ++######+               \n"
                         "    +####++                 \n"
                         "                            \n"
                         "                            \n"
                         "                            ";
    bayes::CreateList(vect, file);
    bayes::Image image = vect[0];
    REQUIRE(bayes::GetShadeValue(image, 0, 0) == 0);
    REQUIRE(bayes::GetShadeValue(image, 6, 18) == 1);
    REQUIRE(bayes::GetShadeValue(image, 8, 2) == 0);
}