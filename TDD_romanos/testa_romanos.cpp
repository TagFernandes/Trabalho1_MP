// Copyright (c) 2023, Thiago Fernandes

#include <iostream>
#include <string>

#define CATCH_CONFIG_MAIN
#include "romanos.hpp"
#include "catch.hpp"

using std::cout;
using std::string;

char const* decimalParaRomano(int numero) {
    static const char* const algarismos[13] =
    {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};
    static const int valores[13] =
    {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
    static char romano[16];

    romano[0] = '\0';

    // Loop pelos algarismos romanos e seus respectivos valores
    for (int i = 0; i < 13; i++) {
        while (numero >= valores[i]) {
            int len = strlen(romano);
            snprintf(romano+len, sizeof(romano)-len, "%s", algarismos[i]);
            numero -= valores[i];
        }
    }
    return romano;
}

TEST_CASE("Numeros romanos - algarismos unicos", "[romanos]") {
    for (int i = 1; i <= 3000; i++) {
        REQUIRE(romanos_para_decimal(decimalParaRomano(i)) == i);
    }
    REQUIRE(romanos_para_decimal("I") == 1);
    REQUIRE(romanos_para_decimal("V") == 5);
    REQUIRE(romanos_para_decimal("XXX") == 30);
}

TEST_CASE("Numeros romanos - algarismos invalidos", "[romanos]") {
    REQUIRE(romanos_para_decimal("G") == -1);
    REQUIRE(romanos_para_decimal("i") == -1);
    REQUIRE(romanos_para_decimal("VV") == -1);
    REQUIRE(romanos_para_decimal("DD") == -1);
    REQUIRE(romanos_para_decimal("LL") == -1);
    REQUIRE(romanos_para_decimal("VX") == -1);
    REQUIRE(romanos_para_decimal("XXXX") == -1);
    REQUIRE(romanos_para_decimal("a") == -1);
    REQUIRE(romanos_para_decimal("XVV") == -1);
    REQUIRE(romanos_para_decimal("VIIII") == -1);
    REQUIRE(romanos_para_decimal("XIXI") == -1);
}
