#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"

/*
 * Implemente uma função para calcular a multiplicação de duas matrizes.
 * Sua função deve receber como parâmetro 3 matrizes. As duas primeiras serão
 * multiplicadas e a terceira será alterada para conter o resultado da multiplicação.
 * Lembre-se de alterar as dimensões da terceira matriz com o tamanho da matriz
 * calculada.
 *
 * Para saber mais sobre multiplicação de matrizes, você pode ver em:
 *   - https://pt.wikipedia.org/wiki/Produto_de_matrizes
 *   - https://pt.khanacademy.org/math/precalculus/x9e81a4f98389efdf:matrices/x9e81a4f98389efdf:multiplying-matrices-by-matrices/a/multiplying-matrices
 *
 * A função retorna um booleano informando se foi possível realizar a multiplicação
 * das duas matrizes passadas. Ou seja, retorna true se foi possível ou false caso
 * contrário.
 *
 * Re-utilize a função da atividade anterior (matrizes iguais) para saber se a matriz
 * resultante da multiplicação é igual à matriz esperada.
 */

const int TAM_MAX = 20;

TEST_CASE("Testando com matrizes quadradas.")
{
	int a[TAM_MAX][TAM_MAX] = {
			{7, 1, 4},
			{1, 2, 1},
			{4, 1, 7}};
	int b[TAM_MAX][TAM_MAX] = {
			{1, 4, 2},
			{2, 1, 9},
			{1, 7, 0}};
	int esperada[TAM_MAX][TAM_MAX] = {
			{13, 50, 23},
			{6, 14, 20},
			{14, 56, 17}};
	int calculada[TAM_MAX][TAM_MAX];
	int lin, col;
	CHECK(multiplica(a, 3, 3, b, 3, 3, calculada, lin, col) == true);
	CHECK(eh_igual(esperada, 3, 3, calculada, lin, col) == true);
}

TEST_CASE("Testando com matrizes quaisquer, sendo possível calcular a matriz.")
{
	int a[TAM_MAX][TAM_MAX] = {
			{7, 1, 4, -1, -2},
			{1, 2, 1, 0, 3},
			{4, 1, 7, -2, 1}};
	int b[TAM_MAX][TAM_MAX] = {
			{1, 4},
			{2, 1},
			{1, 7},
			{7, 0},
			{2, -2}};
	int esperada[TAM_MAX][TAM_MAX] = {
			{4, 61},
			{12, 7},
			{1, 64}};
	int calculada[TAM_MAX][TAM_MAX];
	int lin, col;
	CHECK(multiplica(a, 3, 5, b, 5, 3, calculada, lin, col) == true);
	CHECK(eh_igual(esperada, 3, 2, calculada, lin, col) == true);
}

TEST_CASE("Testando com matrizes quaisquer, não sendo possível calcular a matriz.")
{
	int a[TAM_MAX][TAM_MAX] = {
			{7, 1, 4, -1, -2},
			{1, 2, 1, 0, 3},
			{4, 1, 7, -2, 1}};
	int b[TAM_MAX][TAM_MAX] = {
			{1, 4},
			{2, 1},
			{7, 0},
			{2, -2}};
	int calculada[TAM_MAX][TAM_MAX];
	int lin, col;
	CHECK(multiplica(a, 3, 5, b, 5, 3, calculada, lin, col) == false);
}
