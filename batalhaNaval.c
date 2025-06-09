#include <stdio.h>

// Desafio Batalha Naval - MateCheck
// Este código inicial serve como base para o desenvolvimento do sistema de Batalha Naval.
// Siga os comentários para implementar cada parte do desafio.
// Aluno: André Santos

// Define o tamanho do tabuleiro como 10x10
#define TAM 10

// Função que imprime qualquer matriz TAMxTAM no console
void imprimirMatriz(int matriz[TAM][TAM]) {
    for (int i = 0; i < TAM; i++) {
        for (int j = 0; j < TAM; j++) {
            printf("%d ", matriz[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}
/*
 * Função para aplicar uma habilidade em formato de cone
 * O cone se expande para baixo em 3 níveis: 1 ponto, 3 pontos, 5 pontos
 * Parâmetros:
 *   matriz - matriz do tabuleiro a ser alterada
 *   x, y   - coordenadas iniciais do cone (ponta superior)
 */
void aplicarCone(int matriz[TAM][TAM], int x, int y) {
    // Verifica se o cone cabe no tabuleiro
    if (x + 2 >= TAM || y < 2 || y > TAM - 3) return;
    // Linha 1 (topo)
    matriz[x][y] = 1;
    // Linha 2
    matriz[x + 1][y - 1] = 1;
    matriz[x + 1][y] = 1;
    matriz[x + 1][y + 1] = 1;
    // Linha 3 (base mais larga)
    for (int j = y - 2; j <= y + 2; j++) {
        matriz[x + 2][j] = 1;
    }
}
/*
 * Função para aplicar habilidade em cruz
 * A cruz se expande nas 4 direções a partir de um centro
 * Parâmetros:
 *   matriz - matriz do tabuleiro
 *   x, y   - ponto central da cruz
 */
void aplicarCruz(int matriz[TAM][TAM], int x, int y) {
 // Verifica se a cruz cabe no tabuleiro
    if (x < 1 || x >= TAM - 1 || y < 2 || y >= TAM - 2) return;

    // Linha vertical (3ª linha de cima pra baixo) — 5 colunas
    for (int j = y - 2; j <= y + 2; j++) {
        matriz[j][y] = 1;
    }

    // Coluna horizontal (3 linhas) — no centro da cruz
    for (int i = x - 1; i <= x + 1; i++) {
        matriz[x][i] = 1;
    }
}
/*
 * Função para aplicar habilidade em forma de octaedro (rombo/losango)
 * Parâmetros:
 *   matriz - matriz do tabuleiro
 *   x, y   - ponto central do octaedro
 */
void aplicarOctaedro(int matriz[TAM][TAM], int x, int y) {
    // Verifica se a forma cabe no tabuleiro
    if (x < 1 || x >= TAM - 1 || y < 1 || y >= TAM - 1) return;

    // Marca os quatro pontos em cruz (sem diagonais)
    matriz[x][y] = 1;
    matriz[x - 1][y] = 1;
    matriz[x + 1][y] = 1;
    matriz[x][y - 1] = 1;
    matriz[x][y + 1] = 1;
}

int main() {
    // Nível Novato - Posicionamento dos Navios
    // Sugestão: Declare uma matriz bidimensional para representar o tabuleiro (Ex: int tabuleiro[5][5];).
    // Sugestão: Posicione dois navios no tabuleiro, um verticalmente e outro horizontalmente.
    // Sugestão: Utilize `printf` para exibir as coordenadas de cada parte dos navios.

    // Nível Aventureiro - Expansão do Tabuleiro e Posicionamento Diagonal
    // Sugestão: Expanda o tabuleiro para uma matriz 10x10.
    // Sugestão: Posicione quatro navios no tabuleiro, incluindo dois na diagonal.
    // Sugestão: Exiba o tabuleiro completo no console, mostrando 0 para posições vazias e 3 para posições ocupadas.

    // Nível Mestre - Habilidades Especiais com Matrizes
    // Sugestão: Crie matrizes para representar habilidades especiais como cone, cruz, e octaedro.
    // Sugestão: Utilize estruturas de repetição aninhadas para preencher as áreas afetadas por essas habilidades no tabuleiro.
    // Sugestão: Exiba o tabuleiro com as áreas afetadas, utilizando 0 para áreas não afetadas e 1 para áreas atingidas.

    // Exemplos de exibição das habilidades:
    // Exemplo para habilidade em cone:
    // 0 0 1 0 0
    // 0 1 1 1 0
    // 1 1 1 1 1
    
    // Exemplo para habilidade em octaedro:
    // 0 0 1 0 0
    // 0 1 1 1 0
    // 0 0 1 0 0

    // Exemplo para habilidade em cruz:
    // 0 0 1 0 0
    // 1 1 1 1 1
    // 0 0 1 0 0

    // Declara três matrizes 10x10, todas preenchidas inicialmente com 0
    int cone[TAM][TAM] = {0};
    int cruz[TAM][TAM] = {0};
    int octaedro[TAM][TAM] = {0};

    // Aplica as habilidades a partir de um ponto central seguro (para não sair da matriz)
    aplicarCone(cone, 2, 4); // Aplica cone a partir da linha 2, coluna 4
    aplicarCruz(cruz, 4, 4);  // Aplica cruz no centro (4,4)
    aplicarOctaedro(octaedro, 4, 4); // Aplica octaedro no centro (4,4)

    // Exibe as matrizes resultantes no console
    printf("Cone:\n");
    imprimirMatriz(cone);

    printf("Cruz:\n");
    imprimirMatriz(cruz);

    printf("Octaedro:\n");
    imprimirMatriz(octaedro);

    return 0;
}
