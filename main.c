#include <stdio.h>
#include <stdbool.h>
#include <ncurses.h>
#include <assert.h>
#include <stdlib.h>

#define S 65
#define INIT_BASE_HEIGHT 50
#define CORRECT(x) ((x) < 0 ? 0 : ((x) >= S ? S - 1 : (x)))

int map[S][S] = {{0}};

enum { GREEN = 1, BLUE, CYAN, LIGHT_GREEN};

void set_diamond(int x, int y) {
}

void diamond() {
    int x,y, i, curx, cury, tx,ty;
    int mid = S;
    int sum;
		bool was_neven;

#if (S <= 1)
    puts("S must be greater than 1");
    assert(false);
#endif

#if 0
	map[0][0] = ((rand() % 0xff) + INIT_BASE_HEIGHT) & 0xff;
	map[0][S-1] = ((rand() % 0xff) + INIT_BASE_HEIGHT) & 0xff;
	map[S-1][0] = ((rand() % 0xff) + INIT_BASE_HEIGHT) & 0xff;
	map[S-1][S-1] = ((rand() %0xff) + INIT_BASE_HEIGHT) & 0xff;
#endif
    map[0][0] = 1;
    map[0][S-1] = 1;
    map[S-1][0] = 1;
    map[S-1][S-1] = 1;

    while(true) {

//NEXT_STEP:

(void) was_neven;
			was_neven = (mid & 1);
			mid >>= 1;
        if (mid <= 0) break;

        for (x = 1;; x++) {
            curx = x * mid;
						//if (x > 1) curx += 1;
						if (x > 1) curx += curx - mid;
#if 0
            printf("exp curx:%d was_neven:%d curx++:%d\n",curx, was_neven, curx+1);
            if (curx + (was_neven ? 1 : 0) >= S) break;
#endif
            if (curx >= S) break;
            for (y = 1;; y++) {
                cury = y * mid;
								if (y > 1) cury += cury - mid;
            		//if (cury + (was_neven ? 1 : 0) >= S) goto NEXT_STEP;
                if (cury >= S) break;
                printf("(%d,%d) mid:%d\n",curx,cury, mid);
                sum = i = 0;

                tx = CORRECT(curx - mid);
                ty = CORRECT(cury - mid);
                sum += map[tx][tx];

                tx = CORRECT(curx - mid);
                ty = CORRECT(cury + mid);
                sum += map[tx][tx];

                tx = CORRECT(curx + mid);
                ty = CORRECT(cury - mid);
                sum += map[tx][tx];

                tx = CORRECT(curx + mid);
                ty = CORRECT(cury + mid);
                sum += map[tx][tx];

                assert(curx >= 0 && curx < S && cury >= 0 && cury < S);

                //map[curx][cury] = (sum / 4) & 0xff;
                map[curx][cury] = 1;

                tx = curx;
                ty = cury - mid;
                if (ty >= 0) {
                    printf("sub (%d,%d), mid:%d\n", tx, ty, mid);
                    map[tx][ty] = 1;
                }
                tx = curx;
                ty = cury + mid;
                if (ty < S) {
                    printf("sub (%d,%d), mid:%d\n", tx, ty, mid);
                    map[tx][ty] = 1;
                }
                tx = curx- mid;
                ty = cury;
                if (tx >= 0) {
                    printf("sub (%d,%d), mid:%d\n", tx, ty, mid);
                    map[tx][ty] = 1;
                }
                tx = curx+ mid;
                ty = cury;
                if (tx < S) {
                    printf("sub (%d,%d), mid:%d\n", tx, ty, mid);
                    map[tx][ty] = 1;
                }
            }
        }
    }
}

#if 0
int main() {
    int i;
    int j;
    int k;
    int colour;
    int rv;
    char input;

    initscr(); // ncurses
    if(has_colors() == FALSE) {
        endwin();
        printf("Your terminal does not support color\n");
        return 1;
    }
    start_color();
    rv = init_pair(BLUE, COLOR_BLUE, COLOR_BLACK);
    rv |= init_pair(GREEN, COLOR_GREEN, COLOR_BLACK);
    rv |= init_pair(CYAN, COLOR_CYAN, COLOR_BLACK);
    rv |= init_pair(LIGHT_GREEN, COLOR_GREEN, COLOR_WHITE);
    if (rv) {
        printf("Something is wrong with the colours\n");
        return 1;
    }

    diamond();

    for (i = 0; i < S; i++) {
        for (j = 0; j < S; j++) {

            k = 2 * i + 2 * j;
            if (j & 1) k--;

            if (map[i][j] < 20) colour = BLUE;
            if (map[i][j] < 30) colour = CYAN;
            if (map[i][j] < 50) colour = GREEN;
            else colour = LIGHT_GREEN;

            assert(map[i][j] != 0);
            attron(COLOR_PAIR(colour));
            mvwprintw(stdscr, j, k, "%c ", 254);//, map[i][j]);
            //mvwprintw(stdscr, j, k, "%d ", map[i][j] > 0);//, map[i][j]);
            //mvwprintw(stdscr, j, k, "%d ", map[i][j]);//, map[i][j]);
            //attroff(COLOR_PAIR(colour));
        }
    }
    attrset(0);
    refresh();
    while((input = getch())) {
        switch (input) {
        case 'q' :
            goto END_MAIN;
        default:
            break;
        }
    }

END_MAIN:
    endwin();
}
#endif

int main() {
    int i,j;
    diamond();
    puts("end diamond");
    for (i = 0; i < S; i++) {
        for (j = 0; j < S; j++) {
            if (map[i][j] == 0) {
                printf("(%d,%d)\n", i, j);
                assert(map[i][j] != 0);
            }
        }
    }
}
