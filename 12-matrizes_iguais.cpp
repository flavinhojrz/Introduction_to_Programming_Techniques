#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"

/*
 * Implemente uma função para verificar se duas matrizes são iguais, ou seja se para
 * cada elemento de uma matriz o elemento de mesma linha e coluna da outra matriz são
 * iguais.
 * Sua função deve receber como parâmetro a primeira matriz seguida de suas dimensões
 * e depois a segunda matriz seguida de suas dimensões. A função deve retornar verdadeiro
 * se todos os elementos forem iguais ou falso caso contrário.
 */

#include <stdbool.h>

bool eh_igual(int a[][4], int a_rows, int a_cols, int b[][4], int b_rows, int b_cols) {
  if (a_rows != b_rows || a_cols != b_cols) {
    return false;
  }

  for (int i = 0; i < a_rows; ++i) {
    for (int j = 0; j < a_cols; ++j) {
      if (a[i][j] != b[i][j]) {
        return false;
      }
    }
  }

  return true;
}



TEST_CASE("Testando matrizes com as mesmas dimensões.") {
  int a[3][4] = {
    { 7, 1, 4, 2 },
    { 1, 2, 1, 9 },
    { 4, 1, 7, 0 }
  };
  int b[3][4] = {
    { 7, 1, 4, 2 },
    { 1, 2, 1, 9 },
    { 4, 1, 7, 0 }
  };
  CHECK(eh_igual(a, 3, 4, b, 3, 4) == true);
}

TEST_CASE("Testando matrizes com as mesmas dimensões, mas elementos diferentes.") {
  int a[3][4] = {
    { 7, 1, 4, 2 },
    { 1, 2, 1, 9 },
    { 4, 1, 7, 0 }
  };
  int b[3][4] = {
    { 7, 1, 4, 2 },
    { 1, 2, 1, 9 },
    { 4, 1, 5, 0 }
  };
  CHECK(eh_igual(a, 3, 4, b, 3, 4) == false);
}

TEST_CASE("Testando matrizes com as dimensões diferentes.") {
  int a[2][4] = {
    { 7, 1, 4, 2 },
    { 1, 2, 1, 9 }
  };
  int b[3][4] = {
    { 7, 1, 4, 2 },
    { 1, 2, 1, 9 },
    { 4, 1, 5, 0 },
  };
  CHECK(eh_igual(a, 2, 4, b, 3, 4) == false);
}
