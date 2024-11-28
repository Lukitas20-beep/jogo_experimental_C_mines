#include <stdio.h>
#include "game_logic.h"

void display_board() {
    printf("  ");
    for (int i = 0; i < SIZE; i++) printf(" %d", i);
    printf("\n");

    for (int i = 0; i < SIZE; i++) {
        printf("%d ", i);
        for (int j = 0; j < SIZE; j++) {
            if (board[i][j].is_revealed) {
                if (board[i][j].is_mine) {
                    printf("[*]");
                } else {
                    printf("[%d]", board[i][j].mines_around);
                }
            } else if (board[i][j].is_marked) {
                printf("[M]");
            } else {
                printf("[ ]");
            }
        }
        printf("\n");
    }

    printf("\nPontuação: %d\n", score);
}
