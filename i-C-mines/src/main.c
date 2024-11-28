#include <stdio.h>
#include "game_logic.h"
#include "cli.h"

void play_game() {
    int size, mines;

    printf("Digite o tamanho do tabuleiro (ex: 5 para 5x5): ");
    scanf("%d", &size);
    printf("Digite o número de minas: ");
    scanf("%d", &mines);

    initialize_board(size, mines);

    while (1) {
        display_board();

        printf("Escolha uma ação:\n");
        printf("1. Abrir célula (x y)\n");
        printf("2. Marcar célula (x y)\n");

        int action, x, y;
        scanf("%d %d %d", &action, &x, &y);

        if (action == 1) {
            reveal_cell(x, y);
        } else if (action == 2) {
            mark_cell(x, y);
        }

        // Verifica vitória
        int revealed_cells = 0;
        int total_cells = SIZE * SIZE - MINES;

        for (int i = 0; i < SIZE; i++) {
            for (int j = 0; j < SIZE; j++) {
                if (board[i][j].is_revealed && !board[i][j].is_mine) {
                    revealed_cells++;
                }
            }
        }

        if (revealed_cells == total_cells) {
            printf("Parabéns, você venceu! Pontuação final: %d\n", score);
            break;
        }
    }

    free_board();
}

int main() {
    play_game();
    return 0;
}
