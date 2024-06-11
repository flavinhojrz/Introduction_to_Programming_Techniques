#include <iostream>
using namespace std;

// Função que verifica se uma posição é válida e livre 
bool isValidMove(int maze[][100], bool visited[][100], int L, int C, int x, int y) {
  return (x >= 0 && x < L && y >= 0 && y < C && maze[x][y] == 0 && !visited[x][y]);
}

bool findPath(int maze[][100], bool visited[][100], int L, int C, int x, int y, int endX, int endY) {
	// Verifica se chegou na saída
	if (x == endX && y == endY) {
		return true;
	}
	
	// Verifica se a posição atual é válida
	if (!isValidMove(maze, visited, L, C, x, y)) {
		return false;
	}
	
	// Marca a posição atual como visitada
	visited[x][y] = true;
	
	// Movimentos possíveis: cima, baixo, esquerda, direita
	int moves[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
	
	// Tenta todos os movimentos possíveis
	for (int i = 0; i < 4; i++) {
		int newX = x + moves[i][0];
		int newY = y + moves[i][1];
		
		// Continua a busca a partir da nova posição
		if (findPath(maze, visited, L, C, newX, newY, endX, endY)) {
			return true;
		}
}
	
	return false;
}

int main() {
    int L, C;
    cin >> L >> C;
    
    int maze[100][100];
    bool visited[100][100] = {false};
    
    for (int i = 0; i < L; i++) {
        for (int j = 0; j < C; j++) {
            cin >> maze[i][j];
        }
    }
    
    int startX, startY, endX, endY;
    cin >> startX >> startY >> endX >> endY;
    
    if (findPath(maze, visited, L, C, startX, startY, endX, endY)) {
        cout << "sim" << endl;
    } else {
        cout << "não" << endl;
    }
    
    return 0;
}
