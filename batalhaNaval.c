/*
* Desafio: Batalha Naval - Nível Aventureiro
* Arquivo: batalha_naval.c
*
* O objetivo é adicionar mais dois navios,
* sendo dois deles na DIAGONAL.
*/

// Biblioteca padrao de entrada/saida (para usar o printf)
#include <stdio.h>

// Define os tamanhos fixos para o tabuleiro
#define LINHAS 10
#define COLUNAS 10
// Define o tamanho fixo dos navios
#define TAM_NAVIO 3

// Funcao principal do programa
int main() {

    // 1. Criar o tabuleiro (matriz 10x10)
    // 0 = Agua
    // 3 = Navio
    int tabuleiro[LINHAS][COLUNAS];

    // Variaveis para os loops (i para linhas, j para colunas)
    int i, j;

    // --- 1. Inicializar o Tabuleiro ---
    // Colocar 0 (Agua) em todas as posicoes
    printf("Preparando o oceano (tabuleiro)...\n");

    // Loop 'for' para percorrer cada LINHA
    for (i = 0; i < LINHAS; i++) {
        // Loop 'for' para percorrer cada COLUNA dentro da linha
        for (j = 0; j < COLUNAS; j++) {
            // Define a posicao [i][j] como 0
            tabuleiro[i][j] = 0;
        }
    }
    printf("Tabuleiro inicializado com agua!\n\n");

    // --- 2. Posicionar os Quatro Navios ---
    // Todos os navios tem tamanho 3.
    // As posicoes foram escolhidas para nao sobrepor.

    // Navio 1: Horizontal
    // Coordenadas iniciais: Linha 2, Coluna 1
    // Ocupa: [2][1], [2][2], [2][3]
    int n1_lin = 2;
    int n1_col = 1;
    for (i = 0; i < TAM_NAVIO; i++) {
        tabuleiro[n1_lin][n1_col + i] = 3;
    }
    printf("Navio 1 (Horizontal) posicionado.\n");


    // Navio 2: Vertical
    // Coordenadas iniciais: Linha 4, Coluna 5
    // Ocupa: [4][5], [5][5], [6][5]
    int n2_lin = 4;
    int n2_col = 5;
    for (i = 0; i < TAM_NAVIO; i++) {
        tabuleiro[n2_lin + i][n2_col] = 3;
    }
    printf("Navio 2 (Vertical) posicionado.\n");


    // Navio 3: Diagonal (Descendo para Direita)
    // Coordenadas iniciais: Linha 0, Coluna 6
    // Ocupa: [0][6], [1][7], [2][8]
    int n3_lin = 0;
    int n3_col = 6;
    for (i = 0; i < TAM_NAVIO; i++) {
        // A linha (n3_lin + i) e a coluna (n3_col + i) aumentam juntas
        tabuleiro[n3_lin + i][n3_col + i] = 3;
    }
    printf("Navio 3 (Diagonal Direita) posicionado.\n");


    // Navio 4: Diagonal (Descendo para Esquerda)
    // Coordenadas iniciais: Linha 7, Coluna 2
    // Ocupa: [7][2], [8][1], [9][0]
    int n4_lin = 7;
    int n4_col = 2;
    for (i = 0; i < TAM_NAVIO; i++) {
        // A linha (n4_lin + i) aumenta
        // A coluna (n4_col - i) diminui
        tabuleiro[n4_lin + i][n4_col - i] = 3;
    }
    printf("Navio 4 (Diagonal Esquerda) posicionado.\n\n");


    // --- 3. Exibir o Tabuleiro ---
    printf("--- Tabuleiro Batalha Naval ---\n");

    // Loop 'for' para percorrer as LINHAS
    for (i = 0; i < LINHAS; i++) {
        
        // Loop 'for' para percorrer as COLUNAS
        for (j = 0; j < COLUNAS; j++) {
            // Imprime o valor da posicao (0 ou 3) e um espaco
            printf("%d ", tabuleiro[i][j]);
        }
        
        // Pula para a proxima linha (para o tabuleiro ficar quadrado)
        printf("\n");
    }


    // Indica que o programa terminou com sucesso
    return 0;
}