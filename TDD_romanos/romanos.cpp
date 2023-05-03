// Copyright (c) 2023, Thiago Fernandes

#include "romanos.hpp"
#include <iostream>
#include <unordered_map>
#include <cstring>
#include <string>

using std::unordered_map;
using std::strlen;

int romanToDecimal(const char* romanNumeral) {
    // Tabela de valores para cada caractere romano
    std::unordered_map<char, int> romanValues = {
        {'I', 1},
        {'V', 5},
        {'X', 10},
        {'L', 50},
        {'C', 100},
        {'D', 500},
        {'M', 1000}
    };

    int result = 0;
    int previousValue = 0;

    // Itera sobre cada caractere do numeral romano
    for (int i = 0; romanNumeral[i] != '\0'; i++) {
        int currentValue = romanValues[romanNumeral[i]];

        // Caso caracter atual < anterior
        // então subtraímos o valor atual do resultado (ex: IV = 4)
        if (currentValue > previousValue) {
            result -= 2 * previousValue;
        }

        result += currentValue;
        previousValue = currentValue;
    }

    return result;
}

char const* decimal_to_Romano(int numero) {
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

int romanos_para_decimal(char const * num_romano) {
    if (strcmp(decimal_to_Romano(romanToDecimal(num_romano)),
    num_romano) == 0) {
        return romanToDecimal(num_romano);
    } else {
        return -1;
    }
}
