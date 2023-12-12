#include <curses.h>
#include <stdlib.h>
#include <unistd.h>
void main(){
        WINDOW* win = initscr();
        keypad(win, true);
        nodelay(win, true);
        int pos_x = 0;
        int pos_y = 0;
        int food_x = rand() % 20;
        int food_y = rand() % 20;
        int dir_x = 1;
        int dir_y = 0;
        while(true){
                int pressed = wgetch(win);
                if(pressed == KEY_LEFT){dir_x = -1;dir_y = 0;}
                if(pressed == KEY_RIGHT){dir_x = 1;dir_y = 0;}
                if(pressed == KEY_UP){dir_x = 0;dir_y = -1;}
                if(pressed == KEY_DOWN){dir_x = 0;dir_y = 1;}
                pos_x += dir_x;
                pos_y += dir_y;
                erase();
                mvaddstr(pos_y, pos_x, "*");
                mvaddstr(food_x, food_y, "&");
                usleep(100000);
                if(food_x == pos_x && food_y == pos_y){
                        food_x = rand() % 20;
                        food_y = rand() % 20;
                }
        }
        endwin();
}