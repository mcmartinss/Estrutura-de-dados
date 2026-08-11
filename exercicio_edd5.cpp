#include <stdio.h>

#define LINHAS 3
#define COLUNAS 4

// Função recursiva para resolver o labirinto
int resolverLabirinto(char labirinto[LINHAS][10], int linha, int coluna) {
    // 1. Verificação de limites da matriz
    if (linha < 0 || linha >= LINHAS || coluna < 0 || coluna >= COLUNAS) {
        return 0;
    }

    // 2. Se for uma parede ('1') ou um caminho já visitado ('.'), não pode avançar
    if (labirinto[linha][coluna] == '1' || labirinto[linha][coluna] == '.') {
        return 0;
    }

    // 3. Caso Base: Encontrou a saída ('F')
    if (labirinto[linha][coluna] == 'F') {
        return 1;
    }

    // 4. Marca a posição atual como visitada (evita loops infinitos)
    // Se não for o ponto inicial 'S', marcamos com '.'
    char temp = labirinto[linha][coluna];
    if (labirinto[linha][coluna] != 'S') {
        labirinto[linha][coluna] = '.';
    }

    // 5. Testa os 4 movimentos possíveis: cima, baixo, esquerda, direita
    if (resolverLabirinto(labirinto, linha - 1, coluna) == 1) return 1; // Cima
    if (resolverLabirinto(labirinto, linha + 1, coluna) == 1) return 1; // Baixo
    if (resolverLabirinto(labirinto, linha, coluna - 1) == 1) return 1; // Esquerda
    if (resolverLabirinto(labirinto, linha, coluna + 1) == 1) return 1; // Direita

    // 6. Se nenhum caminho funcionou a partir daqui, desmarca a posição (Backtracking)
    if (temp != 'S') {
        labirinto[linha][coluna] = temp;
    }

    return 0; // Caminho sem saída
}

int main() {
    // Exemplo do enunciado
    char labirinto[LINHAS][10] = {
        {'S', '0', '1', '0'},
        {'1', '0', '1', '0'},
        {'0', '0', '0', 'F'}
    };

    // Ponto de início 'S' está na posição (0, 0)
    int inicioLinha = 0;
    int inicioColuna = 0;

    int resultado = resolverLabirinto(labirinto, inicioLinha, inicioColuna);

    if (resultado == 1) {
        printf("Saida: 1 (Caminho para a saída encontrado!)\n");
    } else {
        printf("Saida: 0 (Nao existe caminho ate a saída)\n");
    }

    return 0;
}
