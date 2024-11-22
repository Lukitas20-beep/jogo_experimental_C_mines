#include <stdio.h>
#include <stdlib.h>
#include <time.h> //Para inicializar o gerador de números aleatórios.
#include "game_logic.h"

Cell board[SIZE][SIZE];
int score = 0;

void initialize_board() { //Responsável por configurar o tabuleiro inicial.
    srand(time(NULL)); //Tem o objetivo de inicializar o gerador de números aleatórios usado no programa. 

    // Inicializa todas as células
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            board[i][j].is_mine = 0; //Indica se a célula contém uma mina.
            board[i][j].is_revealed = 0; //Indica se a célula foi revelada.
            board[i][j].is_marked = 0; //Indica se a célula foi marcada pelo jogador como possível mina.
            board[i][j].mines_around = 0; //Número de minas adjacentes.
        }
    }

    // Coloca minas aleatoriamente
    int mines = MINES;
    while (mines > 0) {
        //rand para selecionar posições aleatórias no tabuleiro. Horizontal e verticalmente
        int x = rand() % SIZE;
        int y = rand() % SIZE;
        if (!board[x][y].is_mine) { //Verifica se a posição já contém uma mina
            board[x][y].is_mine = 1; //Coloca uma mina na célula
            mines--; //Decrementa o contador de minas restantes.
        }
    }

    // Calcula minas ao redor
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (board[i][j].is_mine) continue; //Para cada célula que não contém uma mina, conta o número de minas
            //nas células adjacentes (incluindo diagonais).

            int count = 0;
            for (int dx = -1; dx <= 1; dx++) { //Utiliza dois laços aninhados (dx e dy) para percorrer a vizinhança de cada célula.
                for (int dy = -1; dy <= 1; dy++) { 
                    int nx = i + dx;
                    int ny = j + dy;
                    if (nx >= 0 && nx < SIZE && ny >= 0 && ny < SIZE && board[nx][ny].is_mine) {
                        //Verifica se as coordenadas adjacentes estão dentro 
                        //dos limites do tabuleiro e se contêm uma mina.
                        count++;
                    }
                }
            }
            board[i][j].mines_around = count;
        }
    }
}

void reveal_cell(int x, int y) { //Revela o conteúdo de uma célula e lida com as consequências (pontuação, fim de jogo, propagação).
    if (x < 0 || x >= SIZE || y < 0 || y >= SIZE || board[x][y].is_revealed) return;
    //Objetivo: Impede ações inválidas: Fora dos limites e células já reveladas

    board[x][y].is_revealed = 1; //Marca a célula como revelada (is_revealed = 1).

    if (board[x][y].is_mine) { //Se a célula contém uma mina, o jogo termina (exit(0)).
        printf("Você atingiu uma mina! Fim de jogo.\n");
        exit(0);
    }

    score += 10; //Adiciona 10 pontos à pontuação por revelar uma célula sem mina.

    if (board[x][y].mines_around == 0) { 
    //Se a célula não tem minas ao redor, revela automaticamente todas as células adjacentes usando a mesma lógica
    //anteriormente usadas
    //A recursão continua enquanto células com mines_around == 0 forem encontradas.
        for (int dx = -1; dx <= 1; dx++) {
            for (int dy = -1; dy <= 1; dy++) {
                if (dx != 0 || dy != 0) {
                    reveal_cell(x + dx, y + dy);
                }
            }
        }
    }
}

void mark_cell(int x, int y) { //Marca ou desmarca uma célula como possível mina.
    if (x < 0 || x >= SIZE || y < 0 || y >= SIZE || board[x][y].is_revealed) {
        printf("Movimento inválido.\n");
        return;
    }//Impede ações inválidas:
    //Coordenadas fora dos limites do tabuleiro.    AA
    //Célula já revelada.                           II

    if (board[x][y].is_marked) {
        board[x][y].is_marked = 0;
        //Remove a marcação (is_marked = 0) se já estiver marcada.
    } else {
        board[x][y].is_marked = 1;
        //Marca a célula (is_marked = 1) se não estiver marcada.
    }
}
