/*
* Desafio: Batalha Naval - Nível Novato
* Arquivo: batalha_naval.c
*
* O objetivo é criar um tabuleiro 10x10 e colocar
* dois navios de tamanho 3 (um na horizontal, um na vertical).
*/

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

    // --- 2. Posicionar os Navios ---
    // O tamanho do navio é 3

    // Navio 1: Horizontal
    // Coordenadas iniciais: Linha 2, Coluna 1
    // (Validei manualmente que 2,1 + 3 de tamanho cabe no tabuleiro 10x10)
    int navio1_linha = 2;
    int navio1_col = 1;

    // Loop para colocar o navio horizontal
    for (i = 0; i < TAM_NAVIO; i++) {
        // Altera a posicao [linha][coluna + i] para 3 (navio)
        tabuleiro[navio1_linha][navio1_col + i] = 3;
    }
    printf("Navio 1 (Horizontal) posicionado!\n");


    // Navio 2: Vertical
    // Coordenadas iniciais: Linha 4, Coluna 5
    // (Escolhi 4,5 para nao sobrepor o navio 1 e caber no tabuleiro)
    int navio2_linha = 4;
    int navio2_col = 5;

    // Loop para colocar o navio vertical
    for (i = 0; i < TAM_NAVIO; i++) {
        // Altera a posicao [linha + i][coluna] para 3 (navio)
        tabuleiro[navio2_linha + i][navio2_col] = 3;
    }
    printf("Navio 2 (Vertical) posicionado!\n\n");


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