/*

* Desafio: Batalha Naval - Nível Mestre
*/

// Bibliotecas padrao
#include <stdio.h>
#include <stdlib.h> // Necessaria para a funcao abs() (valor absoluto)

// --- Constantes do Jogo ---

// Tabuleiro principal
#define LINHAS 10
#define COLUNAS 10

// Navios
#define TAM_NAVIO 3

// Tamanho das matrizes de habilidade (ex: 5x5)
#define TAM_SKILL 5 

// Marcadores do Tabuleiro
#define AGUA 0
#define NAVIO 3
#define SKILL 5 // Novo marcador para area de habilidade

// Funcao principal do programa
int main() {

    // 1. Criar o tabuleiro (matriz 10x10)
    int tabuleiro[LINHAS][COLUNAS];

    // Variaveis para os loops (i para linhas, j para colunas)
    int i, j;

    // --- 1. Inicializar o Tabuleiro ---
    // Colocar AGUA (0) em todas as posicoes
    printf("Preparando o oceano (tabuleiro)...\n");

    for (i = 0; i < LINHAS; i++) {
        for (j = 0; j < COLUNAS; j++) {
            tabuleiro[i][j] = AGUA;
        }
    }
    printf("Tabuleiro inicializado com agua!\n\n");

    // --- 2. Posicionar os Quatro Navios ---
    // (Mesmos navios do Nível Aventureiro)

    // Navio 1: Horizontal [2][1], [2][2], [2][3]
    int n1_lin = 2, n1_col = 1;
    for (i = 0; i < TAM_NAVIO; i++) {
        tabuleiro[n1_lin][n1_col + i] = NAVIO;
    }
    printf("Navio 1 (Horizontal) posicionado.\n");

    // Navio 2: Vertical [4][5], [5][5], [6][5]
    int n2_lin = 4, n2_col = 5;
    for (i = 0; i < TAM_NAVIO; i++) {
        tabuleiro[n2_lin + i][n2_col] = NAVIO;
    }
    printf("Navio 2 (Vertical) posicionado.\n");

    // Navio 3: Diagonal Direita [0][6], [1][7], [2][8]
    int n3_lin = 0, n3_col = 6;
    for (i = 0; i < TAM_NAVIO; i++) {
        tabuleiro[n3_lin + i][n3_col + i] = NAVIO;
    }
    printf("Navio 3 (Diagonal Direita) posicionado.\n");

    // Navio 4: Diagonal Esquerda [7][2], [8][1], [9][0]
    int n4_lin = 7, n4_col = 2;
    for (i = 0; i < TAM_NAVIO; i++) {
        tabuleiro[n4_lin + i][n4_col - i] = NAVIO;
    }
    printf("Navio 4 (Diagonal Esquerda) posicionado.\n\n");


    // --- 3. HABILIDADES ESPECIAIS (Nível Mestre) ---
    printf("Calculando areas de efeito das habilidades...\n");

    // Variaveis para os loops da matriz de skill (si, sj)
    int si, sj; 
    // Variaveis para as coordenadas do tabuleiro (bi, bj)
    int bi, bj;
    
    // O centro da matriz de skill 5x5 é o indice 2
    int centro_skill = TAM_SKILL / 2; // 5 / 2 = 2


    // --- Habilidade 1: CRUZ ---
    // Origem no tabuleiro: [4][4] (será o centro da cruz)
    int skill_cruz[TAM_SKILL][TAM_SKILL];
    int origem_cruz_lin = 4;
    int origem_cruz_col = 4;

    // 1.A: Construir a matriz da Cruz (5x5)
    for (si = 0; si < TAM_SKILL; si++) {
        for (sj = 0; sj < TAM_SKILL; sj++) {
            // Se estiver na linha central (si==2) OU coluna central (sj==2)
            if (si == centro_skill || sj == centro_skill) {
                skill_cruz[si][sj] = 1; // 1 = Afetado
            } else {
                skill_cruz[si][sj] = 0; // 0 = Nao Afetado
            }
        }
    }

    // 1.B: Sobrepor a Cruz no tabuleiro
    for (si = 0; si < TAM_SKILL; si++) {
        for (sj = 0; sj < TAM_SKILL; sj++) {
            // Se essa parte da skill (1) afeta...
            if (skill_cruz[si][sj] == 1) {
                // Calcula a coordenada real no tabuleiro
                bi = origem_cruz_lin - centro_skill + si;
                bj = origem_cruz_col - centro_skill + sj;

                // Validar se esta DENTRO do tabuleiro (0 a 9)
                if (bi >= 0 && bi < LINHAS && bj >= 0 && bj < COLUNAS) {
                    // Marca o tabuleiro com o valor da skill
                    tabuleiro[bi][bj] = SKILL;
                }
            }
        }
    }
    printf("Habilidade CRUZ aplicada em [4][4].\n");


    // --- Habilidade 2: OCTAEDRO (Losango) ---
    // Origem no tabuleiro: [1][7] (afetara o navio 3)
    int skill_octa[TAM_SKILL][TAM_SKILL];
    int origem_octa_lin = 1;
    int origem_octa_col = 7;

    // 2.A: Construir a matriz do Octaedro (5x5)
    for (si = 0; si < TAM_SKILL; si++) {
        for (sj = 0; sj < TAM_SKILL; sj++) {
            // Distancia de Manhattan do centro (abs(i-2) + abs(j-2))
            int dist = abs(si - centro_skill) + abs(sj - centro_skill);
            
            // Se a distancia for <= centro (2), faz parte do losango
            if (dist <= centro_skill) {
                skill_octa[si][sj] = 1;
            } else {
                skill_octa[si][sj] = 0;
            }
        }
    }
    
    // 2.B: Sobrepor o Octaedro no tabuleiro
    for (si = 0; si < TAM_SKILL; si++) {
        for (sj = 0; sj < TAM_SKILL; sj++) {
            if (skill_octa[si][sj] == 1) {
                bi = origem_octa_lin - centro_skill + si;
                bj = origem_octa_col - centro_skill + sj;

                // Validar limites do tabuleiro
                if (bi >= 0 && bi < LINHAS && bj >= 0 && bj < COLUNAS) {
                    tabuleiro[bi][bj] = SKILL;
                }
            }
        }
    }
    printf("Habilidade OCTAEDRO aplicada em [1][7].\n");


    // --- Habilidade 3: CONE (Apontando para baixo) ---
    // Origem no tabuleiro: [7][7] (o TOPO do cone)
    int skill_cone[TAM_SKILL][TAM_SKILL];
    int origem_cone_lin = 7; // Linha do topo
    int origem_cone_col = 7; // Coluna do topo
    
    // 3.A: Construir a matriz do Cone (5x5)
    for (si = 0; si < TAM_SKILL; si++) {
        for (sj = 0; sj < TAM_SKILL; sj++) {
            // O cone comeca em (0, centro) e abre 'si' para cada lado
            // (si=0, j=2)
            // (si=1, j=1,2,3)
            // (si=2, j=0,1,2,3,4)
            if (sj >= (centro_skill - si) && sj <= (centro_skill + si)) {
                skill_cone[si][sj] = 1;
            } else {
                skill_cone[si][sj] = 0;
            }
        }
    }

    // 3.B: Sobrepor o Cone no tabuleiro
    // A logica e diferente: a origem [7][7] é o [0][centro] da skill
    for (si = 0; si < TAM_SKILL; si++) {
        for (sj = 0; sj < TAM_SKILL; sj++) {
            if (skill_cone[si][sj] == 1) {
                // A linha do tabuleiro cresce com 'si'
                bi = origem_cone_lin + si;
                // A coluna do tabuleiro é calculada a partir do centro
                bj = origem_cone_col - centro_skill + sj;

                // Validar limites
                if (bi >= 0 && bi < LINHAS && bj >= 0 && bj < COLUNAS) {
                    tabuleiro[bi][bj] = SKILL;
                }
            }
        }
    }
    printf("Habilidade CONE aplicada em [7][7].\n\n");


    // --- 4. Exibir o Tabuleiro Final ---
    printf("--- Tabuleiro Batalha Naval (Mestre) ---\n");
    printf("(0=Agua, 3=Navio, 5=Efeito de Habilidade)\n");

    for (i = 0; i < LINHAS; i++) {
        for (j = 0; j < COLUNAS; j++) {
            // Imprime o valor da posicao e um espaco
            printf("%d ", tabuleiro[i][j]);
        }
        // Pula para a proxima linha
        printf("\n");
    }

    // Indica que o programa terminou com sucesso
    return 0;
}