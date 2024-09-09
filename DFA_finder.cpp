//A partir de una matriz dinamica (mxn (maximo 10x10))
// cargada con caracteres aleatorios entre la A y la F 
//pero cada elemento de esa matriz esta compuesto de 3 caracteres. 
//Encuentren la combinacion DFA (puede darse entre elementos de distinta columna o fila en toda la matriz)
//Pintar los lugares donde se de la combinacion con otro color

//Alumno: Peceto, Iván Gabriel      Legajo: 7197
//Comando para compilar en linux: g++ -Wall -g ./DFA_finder.cpp -o DFA -lncursesw

#include <cstdlib>
#include <cstdio>
#include <time.h>
#include <iostream>
#include <ncurses.h>

using namespace std;

int N = 6;
int const arr_size = 100;
int const rows = 5;
int const cols = 10;
int posx = 0;
int posy = 0;
char arr2[rows][cols][3], *pA2;

/** Function: fill_array()
 *      Fills a 3D array and fills it with a sequence of 3 chars
 *       which can be the combination of chars A to F
 *  Argument: a
 *      Points to the first element of a 3D array
 *  Argument: row and cols
 *      The number of rows and columns of the array
 */
void fill_array(char *a, int rows, int cols, int depth);

void print_arr3(char *a, int rows, int cols, int depth);

void find_seq(char *a, int rows, int cols, int depth, char seq[3]);

int main(){
    setlocale(LC_ALL, ""); //Inicializo caracteres unicode   
    initscr(); 
    keypad(stdscr, TRUE);
    char seq[3];
    seq[0] = 'D';
    seq[1] = 'F';
    seq[2] = 'A';
    pA2 = &arr2[0][0][0];
    fill_array(pA2, rows, cols, 3);
    print_arr3(pA2, rows, cols, 3);
    find_seq(pA2, rows, cols, 3, seq);
    refresh();
    getchar();
    endwin();
    return 0;
}

void fill_array(char *a, int rows, int cols, int depth){
    int lenght;
    if((rows&&cols&&depth)){
        lenght = rows*cols*depth;
    }else if((rows&&cols)){
        lenght = rows*cols;
    }else{
        lenght = rows + cols + depth;
    }
    
    srand(time(0));
    for (int i=0; i<(lenght); i++){
        *a = 'A'+ (rand()%N);
        a++;
    }
}

void print_arr3(char *a, int rows, int cols, int depth){
    int lenght;
    int counter = depth;
    if(rows && cols){
        lenght = rows*cols;
    }else{
        lenght = rows + cols + depth;
    } 

    for (int i = 0; i < lenght; i++){
        while(counter){
            printf("%c",*a);
            a++;
            counter--;
        }
        counter = depth;
        printf("  ");
        if((i+1)%cols == 0){
            printf("\n");
        }
    }
    printf("\n");
}

void find_seq(char *a, int rows, int cols, int depth, char seq[3]){
    int lenght;
    int counter = depth;
    char *thrdIndex = a+3;
    int posx = 0;
    int posy = 0;
    if((rows&&cols&&depth)){
        lenght = rows*cols*depth;
    }else if((rows&&cols)){
        lenght = rows*cols;
    }else{
        lenght = rows + cols + depth;
    }

    for (int i = 0; i < lenght; i++){
        move(posy, posx);
        while(counter){
            if(a >= thrdIndex){
               if((*(a-2) == seq[0]) && (*(a-1) == seq[1]) && (*(a) == seq[2])){
                    move(posy, posx-2);
                    a = a-3;
                    for(int j = 0; j<3; j++){
                        a++;
                        attron(A_REVERSE);
                        printw("%c",*a);
                        posx++;
                        move(posy, posx);
                    }
                }
            }
            
            attroff(A_REVERSE);
            posx++;
            move(posy, posx);
            printw("%c",*a);
            a++;
            counter--;
        }
        counter = depth;
        posx += 2;
        if((i+1)%cols == 0){
            posy++;
            posx = 0;
        }
    }
    printw("\n");
    refresh();
}