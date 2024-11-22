#include <stdio.h>
#include "game_logic.h"
#include "cli.h"

void play_game() { //controla o fluxo principal do jogo, enquanto a função 
    initialize_board(); //é chamada para configurar o tabuleiro inicial

    while (1) { //O jogo continua indefinidamente até que o jogador vença ou perca.
        display_board(); //O tabuleiro atual é exibido ao jogador 

        printf("Escolha uma ação:\n");
        printf("1. Abrir célula (x y)\n");
        printf("2. Marcar célula (x y)\n");

        int action, x, y;
        scanf("%d %d %d", &action, &x, &y);

        if (action == 1) {
            reveal_cell(x, y);//A célula é aberta
        } else if (action == 2) {
            mark_cell(x, y);//A célula é marcada ou desmarcada como suspeita.
        }

        // Verifica se todas as células sem mina foram abertas
        int revealed_cells = 0; //Conta as células reveladas que não contêm minas.
        int total_cells = SIZE * SIZE - MINES; //O número total de células que devem ser 
        //abertas para vencer (células totais menos o número de minas).

        for (int i = 0; i < SIZE; i++) {
            for (int j = 0; j < SIZE; j++) {
                if (board[i][j].is_revealed && !board[i][j].is_mine) {
                    revealed_cells++;
                }
            }
        }

        if (revealed_cells == total_cells) {
            //Se o número de células reveladas for igual a total_cells, o jogador venceu:
            printf("Parabéns, você venceu! Pontuação final: %d\n", score);
            break;
        }
    }
}

int main() { //chama play_game()
    play_game(); //controla o fluxo principal do jogo, enquanto a função 
    return 0;
}
