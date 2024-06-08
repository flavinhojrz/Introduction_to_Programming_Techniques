#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"

/*
 * Dadas duas sequências de inteiros, implemente uma função para verificar se duas
 * sequências são conjuntos (elementos não se repetem) iguais, ou seja se as duas
 * sequências armazenam os mesmos elementos independentemente da ordem em que eles
 * são armazenados.
 */

bool iguais(int seq1[], int tamanho1, int seq2[], int tamanho2){
	if(tamanho1 != tamanho2){
		return false;
	}
	for(int i = 0; i < tamanho1; i++){
		bool found = false;

		for(int j = 0; j < tamanho2; j++){
			if(seq1[i] == seq2[j]){
				found = true;
			}
		}
		if(!found){
			return false;
		}
	}
	return true;
}



TEST_CASE("Testando com dois conjuntos iguais na mesma ordem.") {
  int seq1[] = { 7, 1, 4, 2, 3 };
  int seq2[] = { 7, 1, 4, 2, 3 };
  CHECK(iguais(seq1, 5, seq2, 5) == true);
}

TEST_CASE("Testando com dois conjuntos iguais, mas fora de ordem.") {
  int seq1[] = { 7, 1, 4, 2, 3 };
  int seq2[] = { 2, 3, 7, 4, 1 };
  CHECK(iguais(seq1, 5, seq2, 5) == true);
}

TEST_CASE("Testando com duas sequências de tamanho diferentes.") {
  int seq1[] = { 7, 1, 4, 2, 3 };
  int seq2[] = { 7, 1, 4, 2, 3, 8, 6 };
  CHECK(iguais(seq1, 5, seq2, 7) == false);
}

TEST_CASE("Testando com duas sequências de tamanho diferentes.") {
  int seq1[] = { 7, 1, 4, 2, 3 };
  int seq2[] = { 7, 1, 4 };
  CHECK(iguais(seq1, 5, seq2, 3) == false);
}

TEST_CASE("Testando com duas sequências de tamanho diferentes.") {
  int seq1[] = { 7, 1, 4, 2, 3 };
  int seq2[] = { 7, 1, 4, 2, 3, 8, 6 };
  CHECK(iguais(seq1, 5, seq2, 7) == false);
}

TEST_CASE("Testando com duas sequências vazias.") {
  int seq1[1] = { };
  int seq2[1] = { };
  CHECK(iguais(seq1, 0, seq2, 0) == true);
}

TEST_CASE("Testando com uma sequência vazia.") {
  int seq1[1] = { };
  int seq2[] = { 3, 6, 1 };
  CHECK(iguais(seq1, 0, seq2, 3) == false);
}

TEST_CASE("Testando com uma sequência vazia.") {
  int seq1[] = { 7, 2, 1 };
  int seq2[1] = { };
  CHECK(iguais(seq1, 3, seq2, 0) == false);
}
