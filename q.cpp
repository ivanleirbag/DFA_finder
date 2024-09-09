#include <ncurses.h>
#include <cstdlib>
#include <time.h>

int main(){
    //setlocale(LC_ALL, "");
    initscr(); 
    keypad(stdscr, TRUE);
    srand(time(0));

    int posx = 0;
    char **a = new char*[10];
    for (int i = 0; i<10; i++){
        a[i] = new char[3];
        for(int j =0; j<3; j++){
            a[i][j] = 'A'+(rand()%6);
        }
    }
    for (int i = 0; i <10; i++){
        move(0, posx);
        for(int j =0; j<3; j++){
           printw("%c", a[i][j]);
           posx++;
        }
        posx++;
    }
    refresh();
    getch();
    endwin();
    return 0;
}