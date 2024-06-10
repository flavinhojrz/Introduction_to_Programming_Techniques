#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"

/*
 * Um conjuto é um tipo de coleção que possui uma propriedade particular: nenhum
 * elemento se repete.
 *
 * Implemente uma função que transforme uma dada sequência qualquer de inteiros
 * em um conjunto. Ou seja, não deve haver repetição de elementos.
 * A ordem em que os elementos se encontram na sequência resultante da operação
 * deverá ser a mesma da sequência original.
 */

void conjunto(int &tamanho, int sequencia[])
{
  int i, j, k;
  for (i = 0; i < tamanho; i++)
  {
    for (j = i + 1; j < tamanho;)
    {
      if (sequencia[j] == sequencia[i])
      {
        for (k = j; k < tamanho; k++)
        {
          sequencia[k] = sequencia[k + 1];
        }
        tamanho--;
      }
      else
      {
        j++;
      }
    }
  }
}

TEST_CASE("Testando uma sequência com repetições.")
{
  int seq[] = {7, 1, 4, 1, 2, 7, 3, 2, 2, 1};
  int tam = 10;
  conjunto(tam, seq);
  CHECK(tam == 5);
  CHECK(seq[0] == 7);
  CHECK(seq[1] == 1);
  CHECK(seq[2] == 4);
  CHECK(seq[3] == 2);
  CHECK(seq[4] == 3);
}

TEST_CASE("Testando uma sequência com repetições.")
{
  int seq[] = {2,2,4,6,4,8,6,10,8};
  int tam = 9;
  conjunto(tam, seq);
  CHECK(tam == 5);
  CHECK(seq[0] == 2);
  CHECK(seq[1] == 4);
  CHECK(seq[2] == 6);
  CHECK(seq[3] == 8);
  CHECK(seq[4] == 10);
}

TEST_CASE("Testando uma sequência sem repetições.")
{
  int seq[] = {0, 9, -1, 7, 1, 4};
  int tam = 6;
  conjunto(tam, seq);
  CHECK(tam == 6);
  CHECK(seq[0] == 0);
  CHECK(seq[1] == 9);
  CHECK(seq[2] == -1);
  CHECK(seq[3] == 7);
  CHECK(seq[4] == 1);
  CHECK(seq[5] == 4);
}
