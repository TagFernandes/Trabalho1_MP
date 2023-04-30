#include "romanos.hpp"
#include <iostream>
#include <unordered_map>
#include <cstring>

using namespace std;

int romanos_para_decimal(char const * num_romano)
{
  unordered_map<char, int> simbolos = {{'I', 1}, {'V', 5}, {'X', 10}, {'L', 50}, {'C', 100}, {'D', 500}, {'M', 1000}};
    int result = 0;
    int n = strlen(num_romano);

    if (strstr(num_romano, "VV") != nullptr) { return -1; }
    else if (strstr(num_romano, "LL") != nullptr) { return -1; }
    else if (strstr(num_romano, "DD") != nullptr) { return -1; }
    
    for(int i = 0; i < n; i++) {
        // Verifica se o algarismo romano é válido
        if(simbolos.find(num_romano[i]) == simbolos.end()) {
            return -1; // Algarismo romano inválido
        }

        // Verifica se o caractere é repetido mais de três vezes seguidas
        if(i < n - 3 && num_romano[i] == num_romano[i+1] && num_romano[i] == num_romano[i+2] && num_romano[i] == num_romano[i+3]) {
            return -1; // Algarismo romano inválido
        }

        int valor_atual = simbolos[num_romano[i]];

        // Verifica se o próximo símbolo é de valor maior ou menor
        if(i < n - 1 && simbolos[num_romano[i+1]] > valor_atual) {
            // Verifica se a combinação é válida
            if(valor_atual == 1 && (num_romano[i+1] == 'V' || num_romano[i+1] == 'X')) {
                result -= valor_atual;
            } else if(valor_atual == 10 && (num_romano[i+1] == 'L' || num_romano[i+1] == 'C')) {
                result -= valor_atual;
            } else if(valor_atual == 100 && (num_romano[i+1] == 'D' || num_romano[i+1] == 'M')) {
                result -= valor_atual;
            } else {
                return -1; // Algarismo romano inválido
            }
        } else {
            result += valor_atual;
        }
    }

    return result;
}
