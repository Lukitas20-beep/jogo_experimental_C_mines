#ifndef CLI_H //Verifica se CLI_H não foi definido anteriormente. Se não,
//o código dentro do bloco será compilado. Isso evita que o arquivo seja incluído mais de uma vez.
#define CLI_H //Define a constante CLI_H, para que, se o arquivo for incluído novamente, 
//a condição #ifndef falhe e o código não seja processado novamente.

void display_board();  // Exibe o tabuleiro no terminal

#endif //Fecha a diretiva condicional #ifndef, que começou no início do arquivo.