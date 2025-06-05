#include <stdlib.h>
#include <stdio.h>
#include <curses.h>
#include <time.h>
#include <stdbool.h>

#define LARGURA 40
#define ALTURA 20
#define TAMANHO_MAX 100
#define PAREDE '#'
#define COBRA '@'
#define COMIDA '$'
#define COR_COBRA 1
#define COR_COMIDA 2
#define COR_PAREDE 3

int ESPERA_PADRAO = 100;
int score = 0;

typedef struct {
    int x[TAMANHO_MAX];
    int y[TAMANHO_MAX];
    int comprimento;
    int direcaox;
    int direcaoy;
}Cobra;
typedef struct {
    int x;
    int y;
}Comida;


Cobra cobra;
Comida comida;
bool gameOver = FALSE;

char telaBuffer[ALTURA][LARGURA];


void gerarComida(void);
void inicializar();
void desenhar();
void atualizar();
void processarEntrada();

int main(void) {

    inicializar();

    while (!gameOver) {
        desenhar();
        processarEntrada();
        atualizar();
        napms(ESPERA_PADRAO);

    }

    endwin(); //ao finalizar o terminal ainda funciona


    return 0;
}


void inicializar() {
    initscr();
    cbreak(); //nao aguardar o enter antes de consumir
    nodelay(stdscr, TRUE); // serve para nao esperar apertar o enter quando usar a funcao getch
    noecho(); //nao desenhar na tela se eu apertar uma letra
    keypad(stdscr, TRUE); //habilita a captura de teclas especiais - seta
    curs_set(0); //nao mostrar o cursor do mouse na tela
    start_color(); //trabalhar com cores

    //criar pares de cores
    init_pair(COR_COBRA, COLOR_GREEN, COLOR_BLACK);
    init_pair(COR_COMIDA, COLOR_RED, COLOR_BLACK);
    init_pair(COR_PAREDE, COLOR_YELLOW, COLOR_BLACK);

    //inicialiar algumas propriedades da cobra
    cobra.comprimento = 1;
    cobra.x[0] = LARGURA /2 ;
    cobra.y[0] = ALTURA / 2;
    cobra.direcaox = 1;
    cobra.direcaoy = 0;

    gerarComida();

    for (int i = 0; i< ALTURA; i++) {
        for (int j = 0; j < LARGURA; j++) {
            if (i== 0 || i == ALTURA - 1 || j == 0 || j == LARGURA - 1) {
                telaBuffer[i][j] = PAREDE;
            }else {
                //percorrendo cada posicao da tela e preenchendo ela de espacos vazios
                telaBuffer[i][j] = ' ';
            }
        }
    }


}

void gerarComida() {
    comida.x = rand() % (LARGURA - 2 ) + 1;
    comida.y = rand() % (ALTURA - 2) + 1;

}

void desenhar() {


    for (int i = 1; i< ALTURA - 1; i++) {
        for (int j = 1; j < LARGURA - 1; j++) {
            telaBuffer[i][j] = ' ';
        }
    }

    telaBuffer[comida.y][comida.x] = COMIDA;


    for (int i = 0; i< cobra.comprimento; i++) {
        int x = cobra.x[i];
        int y = cobra.y[i];
        telaBuffer[y][x] = COBRA;
    }


    for (int i = 0; i< ALTURA; i++) {
        for (int j = 0; j < LARGURA; j++) {
            if (telaBuffer[i][j] == PAREDE) {
                attron(COLOR_PAIR(COR_PAREDE));
                mvaddch(i, j, telaBuffer[i][j]);
                attroff(COLOR_PAIR(COR_PAREDE));
            }else if (telaBuffer[i][j] == COBRA) {
                attron(COLOR_PAIR(COR_COBRA));
                mvaddch(i, j, telaBuffer[i][j]);
                attroff(COLOR_PAIR(COR_COBRA));
            }else if (telaBuffer[i][j] == COMIDA) {
                attron(COLOR_PAIR(COR_COMIDA));
                mvaddch(i, j, telaBuffer[i][j]);
                attroff(COLOR_PAIR(COR_COMIDA));
            }else {
                mvaddch(i, j, telaBuffer[i][j]);
            }

        }
    }

    mvprintw(ALTURA,  0, "Score: %d", score);

    refresh();
}

void atualizar() {
    int novoX = cobra.x[0] + cobra.direcaox;
    int novoY = cobra.y[0] + cobra.direcaoy;

    if (novoX <= 0 || novoX >= LARGURA - 1 || novoY <= 0 || novoY >= ALTURA - 1) {
        gameOver = TRUE;
    }

    if (novoX == comida.x && novoY == comida.y) {
        cobra.comprimento++;
        score += 10;
        gerarComida();
    }

    for (int i = cobra.comprimento - 1; i > 0; i--) {
        cobra.x[i] = cobra.x[i - 1];
        cobra.y[i] = cobra.y[i - 1];
    }


    cobra.x[0] = novoX;
    cobra.y[0] = novoY;
}

void processarEntrada() {
    int tecla = getch(); //capturar qual tecla foi digitada com essa funcao

    switch (tecla) {
        case KEY_UP :
            if (cobra.direcaoy == 0) {
                cobra.direcaoy = -1;
                cobra.direcaox = 0;
            }

            break;
        case KEY_DOWN :
            if (cobra.direcaoy == 0) {
                cobra.direcaoy = 1;
                cobra.direcaox = 0;
            }
            break;
        case KEY_LEFT :
            if (cobra.direcaox == 0) {
                cobra.direcaoy = 0;
                cobra.direcaox = -1;
            }
            break;
        case KEY_RIGHT :
            if (cobra.direcaox == 0) {
                cobra.direcaoy = 0;
                cobra.direcaox = 1;
            }
            break;
        case 'q':
            gameOver = TRUE;
            break;
        case 'x' :
            ESPERA_PADRAO -= 10;
            break;
        case 'z':
            ESPERA_PADRAO += 10;
            break;
    }

}
