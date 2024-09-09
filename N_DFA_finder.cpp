#include <ncurses.h>
#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <time.h>

//Alumno: Peceto, Iván Gabriel      Legajo: 7197
//Comando para compilar en linux:  g++ -Wall -g ./N_DFA_finder.cpp -o NDFA -lncurses


using namespace std;

#define ESC 27
#define ENTER 10
#define MAX_ROWS 10
#define MAX_COLS 10
#define INNER_X 8
#define INNER_Y 4

int key;
int N = 6;
bool menu = true;
bool running = false;
int posx = 0;
int posy = 0;
char seq[3] = {'D', 'F', 'A'};
char **chMatrix;
int rows = 10;
int cols = 10;


/** Function: randCharArray()
 *      Returns a pointer to an array of pointers to chars with randomly generated 
 *      characters ranging from A to F
 *  Argument: row and cols
 *      The number of rows and columns of the matrix
 */
char** randCharArray(int rows, int cols);

/** Function: display_Matrix
 * 
 *  Argument: 
 */
void displayMatrix(char **arr, int rows, int cols);

int main(){
    initscr(); 
    keypad(stdscr, TRUE);

    while (menu){
        attroff(A_REVERSE);
        curs_set(0);
        clear();
        printw("> Presiona [ENTER] para iniciar el programa.\n\n");
        printw("> Presiona [ESC] para cerrar el programa.");
        refresh();

        key = getch();
        switch (key){
        case ESC:
            endwin();
            menu = false;
            break;
        case ENTER:
            running = true;
            clear();
            break;
        default:
            break;
        }
        chMatrix = randCharArray(rows, cols);

        while (running){

            displayMatrix(chMatrix, rows, cols);
            refresh();
            key = getch();
            switch (key){
            case ESC:
                running = false;
                menu = false;
                endwin();
                break;
            case KEY_F(1):
                clear();
                for (int i = 0; i < (rows*cols); i++) {
                    delete[] chMatrix[i]; 
                }
                delete[] chMatrix;  
                chMatrix = randCharArray(rows, cols);
                displayMatrix(chMatrix, rows, cols);
                break;
            /*case KEY_F(2):

                break;
            case KEY_F(3):

                break;*/
            default:
                break;
            }
        }
    }

    return 0;
}

char **randCharArray(int rows, int cols){
    srand(time(0));
    const int size = rows * cols;
    char **arr = new char*[size]; //Allocates enough memory for a size number of elements
    for(int i = 0; i<size; i++){
        arr[i] = new char[3]; //Allocates memory for the 3 random chars
        for(int j = 0; j<3; j++){
            arr[i][j] = 'A'+(rand()%N);
        }
    }
    return arr;
}

void displayMatrix(char **arr, int rows, int cols){
    int posx = INNER_X;
    int posy = INNER_Y;
    int size = rows * cols;

    for (int i = 0; i < size; i++){
        posx++;
        move(posy, posx);
        for (int j = 0; j < 3; j++){
            printw("%c", arr[i][j]);
            posx++;
        }
        if(!((i+1)%cols)){
            posy += 2;
            posx = INNER_X;
        }
    }
    refresh();
}

void findSeq(char **arr, int rows, int cols, char seq[3]){
    int posx = INNER_X;
    int posy = INNER_Y;
    int size = rows * cols;
    char nextThree[3];
    char *pNT = nextThree;

    for (int i = 0; i < size; i++){
        posx++;
        move(posy, posx);
        for (int j = 0; j < 3; j++){
            if(arr[i][j]== seq[0] && j==0){
                if (arr[i][j+1] == seq[1] && arr[i][j+1] == seq[2])
            }
            printw("%c", arr[i][j]);
            posx++;
        }
        if(!((i+1)%cols)){
            posy += 2;
            posx = INNER_X;
        }
    }
    refresh();
}