#include <stdio.h>
#include "cli.h"
#include "game_logic.h"

void display_board() { //A função não recebe parâmetros nem retorna valores. Seu propósito é exibir o tabuleiro de jogo no console.
    printf("  "); //Adiciona um pequeno deslocamento visual antes dos números das colunas.
    for (int i = 0; i < SIZE; i++) printf(" %d", i); //Itera de 0 até SIZE
    printf("\n");

    for (int i = 0; i < SIZE; i++) { //itera sobre as linhas do tabuleiro
        printf("%d ", i); //Imprime o índice da linha antes de cada linha do tabuleiro.
        for (int j = 0; j < SIZE; j++) {  //Itera pelas colunas
            if (board[i][j].is_revealed) { //Verifica se a célula board[i][j] está revelada
                if (board[i][j].is_mine) { //Campo booleano indicando se a célula contém uma mina.
                    printf("[*]"); // Mina
                } else {
                    printf("[%d]", board[i][j].mines_around); // Número
                    //Caso contrário, imprime o número de minas adjacentes (board[i][j].mines_around).
                }
            } else if (board[i][j].is_marked) { // Campo booleano indicando se a célula foi marcada como possível mina.
                printf("[M]"); // Marcado
            } else {
                printf("[ ]"); // Oculto
            }
        }
        printf("\n"); //Pula para a próxima linha ao final de cada linha do tabuleiro.
    }

    printf("\nPontuação: %d\n", score); //Exibe a pontuação atual do jogador. 
}
