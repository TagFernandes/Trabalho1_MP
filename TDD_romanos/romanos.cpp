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

    for(int i = 0; i < n; i++) {
        int valor_atual = simbolos[num_romano[i]];

        // Verifica se o próximo símbolo é de valor maior ou menor
        if(i < n - 1 && simbolos[num_romano[i+1]] > valor_atual) {
            result -= valor_atual;
        } else {
            result += valor_atual;
        }
    }

    return result;
}
