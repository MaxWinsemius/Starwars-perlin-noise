#include <stdio.h>
#include <stdlib.h>
#include <sys/ioctl.h>
#include "perlin.c"
#include <unistd.h>

void printline (int xmax, float y, float f, int d) {
    for (int x = 0; x < xmax; x++) {
        float p = perlin2d(x,y, f, d);
        //printf("x%d,y%d,p%f\n", x, y, p);
        if (p < 0.6) {
            printf(" ");
        } else {
            printf(".");
        }
    }
    printf("\n");
}

int main(int argc, char **argv)
{
    struct winsize w;
    ioctl(STDOUT_FILENO, TIOCGWINSZ, &w);

    int xmax = w.ws_col;
    int ymax = w.ws_row - 2;
    int y = 0;

    if (argc > 1) {
        xmax = atoi(argv[1]);
    }
    if (argc > 2) {
        ymax = atoi(argv[2]);
    }
    
   // for (int y = 0; y < ymax; y++) {
   //     printline(x, y, 0.1, 4);
   // }

    while (1) {
        printline(xmax, y++, 0.1, 4);
        usleep(30000);
    }

    return 0;
}
