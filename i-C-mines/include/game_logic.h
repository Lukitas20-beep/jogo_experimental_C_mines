#ifndef GAME_LOGIC_H //Verifica se GAME_LOGIC_H não foi definido anteriormente. Se não foi, o código dentro do bloco será compilado. Isso impede que o arquivo 
//de cabeçalho seja incluído mais de uma vez, o que causaria conflitos e duplicação de definições.
#define GAME_LOGIC_H //Define a constante GAME_LOGIC_H, garantindo que o arquivo não seja incluído mais de uma vez.

#define SIZE 10 //Define o tamanho do tabuleiro como 10x10 (10 células em cada linha e coluna).
#define MINES 10 //Define que o jogo terá 10 minas no tabuleiro.

typedef struct {
    int is_mine;         // 1 se for uma mina, 0 caso contrário.
    int is_revealed;     // 1 se a célula estiver aberta.
    int is_marked;       // 1 se a célula estiver marcada.
    int mines_around;    // Número de minas ao redor.
} Cell;
 
void initialize_board(); //Função responsável por inicializar o tabuleiro, colocando as minas e 
//calculando o número de minas ao redor de cada célula.
void reveal_cell(int x, int y);//Função para revelar a célula na posição (x, y). Esta função 
//abriria a célula, revelando se é uma mina ou o número de minas ao redor.
void mark_cell(int x, int y);//Função para marcar ou desmarcar uma célula, indicando que o jogador 
//suspeita que aquela célula contenha uma mina.

extern Cell board[SIZE][SIZE]; // Tabuleiro global
extern int score;              // Pontuação global

#endif //Fecha o bloco condicional #ifndef iniciado no começo do arquivo, 
//garantindo que o código do cabeçalho só será processado uma vez.
