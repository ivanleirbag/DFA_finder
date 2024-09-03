//A partir de una matriz dinamica (mxn (maximo 10x10))
// cargada con caracteres aleatorios entre la A y la F 
//pero cada elemento de esa matriz esta compuesto de 3 caracteres. 
//Encuentren la combinacion DFA (puede darse entre elementos de distinta columna o fila en toda la matriz)
//Pintar los lugares donde se de la combinacion con otro color

//Alumno: Peceto, Iván Gabriel      Legajo: 7197
//Comando para compilar en linux: g++ -Wall -g ./DFA_finder.cpp -o DFA

#include <cstdlib>
#include <cstdio>
#include <time.h>
#include <iostream>

using namespace std;

int N = 100;
int const arr_size = 100;
int const rows = 5;
int const cols = 10;

char arr2[rows][cols], *pA2;

/** Function: fill_array()
 *      Fills a 2D array and fills it with a sequence of 3 chars
 *       which can be the combination of chars A to F
 *  Argument: a
 *      Points to the first element of a 2D array
 *  Argument: row and cols
 *      The number of rows and columns of the array
 */
void fill_array(char *a, int rows, int cols);




int main(){
    pA2 = &arr2[0][0];
    char elem[3];
    for (int i=0; i<3; i++){
        elem[i] = 'A'+i;
    }
    char *pA = elem;
    cout << *(pA+2) << endl;
    return 0;
}

void fill_array(){

}