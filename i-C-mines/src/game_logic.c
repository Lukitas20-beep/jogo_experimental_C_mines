#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "game_logic.h"

Cell **board = NULL;
int SIZE = 0;
int MINES = 0;
int score = 0;

void initialize_board(int size, int mines) {
    SIZE = size;
    MINES = mines;
    score = 0;

    // Aloca dinamicamente a matriz de células
    board = malloc(SIZE * sizeof(Cell *));
    for (int i = 0; i < SIZE; i++) {
        board[i] = malloc(SIZE * sizeof(Cell));
    }

    // Inicializa as células
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            board[i][j].is_mine = 0;
            board[i][j].is_revealed = 0;
            board[i][j].is_marked = 0;
            board[i][j].mines_around = 0;
        }
    }

    // Coloca minas aleatórias
    srand(time(NULL));
    int mines_left = MINES;
    while (mines_left > 0) {
        int x = rand() % SIZE;
        int y = rand() % SIZE;
        if (!board[x][y].is_mine) {
            board[x][y].is_mine = 1;
            mines_left--;
        }
    }

    // Calcula as minas ao redor
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (board[i][j].is_mine) continue;

            int count = 0;
            for (int dx = -1; dx <= 1; dx++) {
                for (int dy = -1; dy <= 1; dy++) {
                    int nx = i + dx;
                    int ny = j + dy;
                    if (nx >= 0 && nx < SIZE && ny >= 0 && ny < SIZE && board[nx][ny].is_mine) {
                        count++;
                    }
                }
            }
            board[i][j].mines_around = count;
        }
    }
}

void free_board() {
    for (int i = 0; i < SIZE; i++) {
        free(board[i]);
    }
    free(board);
}

void reveal_cell(int x, int y) {
    if (x < 0 || x >= SIZE || y < 0 || y >= SIZE || board[x][y].is_revealed) return;

    board[x][y].is_revealed = 1;

    if (board[x][y].is_mine) {
        printf("Você atingiu uma mina! Fim de jogo.\n");
        free_board();
        exit(0);
    }

    score += 10;

    if (board[x][y].mines_around == 0) {
        for (int dx = -1; dx <= 1; dx++) {
            for (int dy = -1; dy <= 1; dy++) {
                if (dx != 0 || dy != 0) {
                    reveal_cell(x + dx, y + dy);
                }
            }
        }
    }
}

void mark_cell(int x, int y) {
    if (x < 0 || x >= SIZE || y < 0 || y >= SIZE || board[x][y].is_revealed) {
        printf("Movimento inválido.\n");
        return;
    }

    board[x][y].is_marked = !board[x][y].is_marked;
}
