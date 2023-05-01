// Copyright (c) 2023, Thiago Fernandes

#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "romanos.hpp"

TEST_CASE("Numeros romanos - algarismos unicos", "[romanos]") {
    REQUIRE(romanos_para_decimal("I") == 1);
    REQUIRE(romanos_para_decimal("V") == 5);
    REQUIRE(romanos_para_decimal("XX") == 20);
    REQUIRE(romanos_para_decimal("XL") == 40);
    REQUIRE(romanos_para_decimal("I") == 1);
    REQUIRE(romanos_para_decimal("II") == 2);
    REQUIRE(romanos_para_decimal("III") == 3);
    REQUIRE(romanos_para_decimal("IV") == 4);
    REQUIRE(romanos_para_decimal("V") == 5);
    REQUIRE(romanos_para_decimal("VI") == 6);
    REQUIRE(romanos_para_decimal("VII") == 7);
    REQUIRE(romanos_para_decimal("VIII") == 8);
    REQUIRE(romanos_para_decimal("IX") == 9);
    REQUIRE(romanos_para_decimal("X") == 10);
    REQUIRE(romanos_para_decimal("MMCM") == 2900);
    REQUIRE(romanos_para_decimal("MMCMXC") == 2990);
    REQUIRE(romanos_para_decimal("MMCMXCIX") == 2999);
    REQUIRE(romanos_para_decimal("MMM") == 3000);
    REQUIRE(romanos_para_decimal("IX") == 9);
}

TEST_CASE("Numeros romanos - algarismos invalidos", "[romanos]") {
    REQUIRE(romanos_para_decimal("G") == -1);
    REQUIRE(romanos_para_decimal("i") == -1);
    REQUIRE(romanos_para_decimal("VV") == -1);
    REQUIRE(romanos_para_decimal("VX") == -1);
    REQUIRE(romanos_para_decimal("XXXX") == -1);
    REQUIRE(romanos_para_decimal("a") == -1);
    REQUIRE(romanos_para_decimal("XVV") == -1);
    REQUIRE(romanos_para_decimal("VIIII") == -1);
}
