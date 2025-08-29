#include <stdio.h>

#define TAMANHO 10      // Tamanho fixo do tabuleiro (10x10)
#define NAVIO 3         // Valor que representa um navio no tabuleiro
#define AGUA 0          // Valor que representa água no tabuleiro
#define TAMANHO_NAVIO 3 // Comprimento fixo dos navios

int main() {
    int tabuleiro[TAMANHO][TAMANHO];

    // Inicializa o tabuleiro com água (0)
    for (int i = 0; i < TAMANHO; i++) {
        for (int j = 0; j < TAMANHO; j++) {
            tabuleiro[i][j] = AGUA;
        }
    }

    // Definição das coordenadas iniciais dos navios
    // Navio 1 - horizontal
    int linhaH = 2;  // Linha inicial do navio horizontal
    int colunaH = 4; // Coluna inicial do navio horizontal

    // Navio 2 - vertical
    int linhaV = 5;  // Linha inicial do navio vertical
    int colunaV = 7; // Coluna inicial do navio vertical

    // Validação: verificar se o navio horizontal cabe dentro do tabuleiro
    if (colunaH + TAMANHO_NAVIO > TAMANHO) {
        printf("Erro: O navio horizontal ultrapassa os limites do tabuleiro.\n");
        return 1;
    }

    // Validação: verificar se o navio vertical cabe dentro do tabuleiro
    if (linhaV + TAMANHO_NAVIO > TAMANHO) {
        printf("Erro: O navio vertical ultrapassa os limites do tabuleiro.\n");
        return 1;
    }

    // Posiciona o navio horizontal no tabuleiro
    for (int i = 0; i < TAMANHO_NAVIO; i++) {
        // Verifica sobreposição
        if (tabuleiro[linhaH][colunaH + i] == NAVIO) {
            printf("Erro: Sobreposição detectada ao posicionar o navio horizontal.\n");
            return 1;
        }
        tabuleiro[linhaH][colunaH + i] = NAVIO;
    }

    // Posiciona o navio vertical no tabuleiro
    for (int i = 0; i < TAMANHO_NAVIO; i++) {
        // Verifica sobreposição
        if (tabuleiro[linhaV + i][colunaV] == NAVIO) {
            printf("Erro: Sobreposição detectada ao posicionar o navio vertical.\n");
            return 1;
        }
        tabuleiro[linhaV + i][colunaV] = NAVIO;
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
