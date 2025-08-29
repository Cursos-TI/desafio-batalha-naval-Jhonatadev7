#include <stdio.h>

#define TAMANHO 10      // Tamanho fixo do tabuleiro (10x10)
#define NAVIO 3         // Valor que representa um navio no tabuleiro
#define AGUA 0          // Valor que representa água no tabuleiro
#define TAMANHO_NAVIO 3 // Comprimento fixo dos navios

// Função para validar e posicionar um navio horizontal
int posicionaHorizontal(int tabuleiro[TAMANHO][TAMANHO], int linha, int coluna) {
    if (coluna + TAMANHO_NAVIO > TAMANHO) return 0; // Fora dos limites
    for (int i = 0; i < TAMANHO_NAVIO; i++) {
        if (tabuleiro[linha][coluna + i] == NAVIO) return 0; // Sobreposição
    }
    for (int i = 0; i < TAMANHO_NAVIO; i++) {
        tabuleiro[linha][coluna + i] = NAVIO;
    }
    return 1;
}

// Função para validar e posicionar um navio vertical
int posicionaVertical(int tabuleiro[TAMANHO][TAMANHO], int linha, int coluna) {
    if (linha + TAMANHO_NAVIO > TAMANHO) return 0;
    for (int i = 0; i < TAMANHO_NAVIO; i++) {
        if (tabuleiro[linha + i][coluna] == NAVIO) return 0;
    }
    for (int i = 0; i < TAMANHO_NAVIO; i++) {
        tabuleiro[linha + i][coluna] = NAVIO;
    }
    return 1;
}

// Função para validar e posicionar um navio diagonal ↘ (linha++ / coluna++)
int posicionaDiagonalPrincipal(int tabuleiro[TAMANHO][TAMANHO], int linha, int coluna) {
    if (linha + TAMANHO_NAVIO > TAMANHO || coluna + TAMANHO_NAVIO > TAMANHO) return 0;
    for (int i = 0; i < TAMANHO_NAVIO; i++) {
        if (tabuleiro[linha + i][coluna + i] == NAVIO) return 0;
    }
    for (int i = 0; i < TAMANHO_NAVIO; i++) {
        tabuleiro[linha + i][coluna + i] = NAVIO;
    }
    return 1;
}

// Função para validar e posicionar um navio diagonal ↙ (linha++ / coluna--)
int posicionaDiagonalSecundaria(int tabuleiro[TAMANHO][TAMANHO], int linha, int coluna) {
    if (linha + TAMANHO_NAVIO > TAMANHO || coluna - (TAMANHO_NAVIO - 1) < 0) return 0;
    for (int i = 0; i < TAMANHO_NAVIO; i++) {
        if (tabuleiro[linha + i][coluna - i] == NAVIO) return 0;
    }
    for (int i = 0; i < TAMANHO_NAVIO; i++) {
        tabuleiro[linha + i][coluna - i] = NAVIO;
    }
    return 1;
}

int main() {
    int tabuleiro[TAMANHO][TAMANHO];

    // Inicializa o tabuleiro com água (0)
    for (int i = 0; i < TAMANHO; i++) {
        for (int j = 0; j < TAMANHO; j++) {
            tabuleiro[i][j] = AGUA;
        }
    }

    // Tentativa de posicionar navios (coordenadas fixas no código)
    if (!posicionaHorizontal(tabuleiro, 2, 4)) {
        printf("Erro ao posicionar navio horizontal.\n");
    }
    if (!posicionaVertical(tabuleiro, 5, 7)) {
        printf("Erro ao posicionar navio vertical.\n");
    }
    if (!posicionaDiagonalPrincipal(tabuleiro, 0, 0)) {
        printf("Erro ao posicionar navio diagonal principal.\n");
    }
    if (!posicionaDiagonalSecundaria(tabuleiro, 0, 9)) {
        printf("Erro ao posicionar navio diagonal secundaria.\n");
    }

    // Exibe o tabuleiro
    printf("\n--- TABULEIRO BATALHA NAVAL ---\n\n");
    for (int i = 0; i < TAMANHO; i++) {
        for (int j = 0; j < TAMANHO; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }

    return 0;
}
