#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"

/*
 * Implemente uma função para contar quantas vezes um determinado caractere aparece
 * em uma string. Sua função deve receber como primeiro parâmetro uma string C (array de
 * caracteres) e, como segundo parâmetro, um caractere. Ela deve então retornar um
 * valor inteiro com a quantidade de vezes que o caracter passado no segundo parâmetro
 * ocorre na string.
 * Sua função não deve fazer distinção entre maiúsculas e minúsculas, de forma que o
 * caractere passado pode ser tanto maiúscula quanto minúscula.
 * Considere também que não haverá caractere especial na string (cedilha, letras
 * acentuadas etc.).
 */

#include <iostream>
#include <sstream>
#include <string>
using namespace std;

int conta_caractere(string str, char caracter){
	int contador = 0;
	for (int i = 0; i < str.size(); i++) {
		str[i] = tolower(str[i]);
    if(str[i] == tolower(caracter)){
			contador++;
		}
  }
  return contador;
}


TEST_CASE("Testando com uma string qualquer.") {
  char str[] = "Amou daquela vez como se fosse a ultima";
  CHECK(conta_caractere(str, 'a') == 5);
  CHECK(conta_caractere(str, 'A') == 5);
  CHECK(conta_caractere(str, ' ') == 7);
  CHECK(conta_caractere(str, 'x') == 0);
}

TEST_CASE("Testando com uma string vazia.") {
  char str[] = "";
  CHECK(conta_caractere(str, 'a') == 0);
  CHECK(conta_caractere(str, 'A') == 0);
  CHECK(conta_caractere(str, ' ') == 0);
  CHECK(conta_caractere(str, 'x') == 0);
}
