#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define rOWS 20
#define cOLS 20

void generateHintMap(int mines[rOWS][cOLS], int hintMap[rOWS][cOLS]) {
    int dr[] = { -1, -1, -1, 0, 0, 1, 1, 1 };
    int dc[] = { -1, 0, 1, -1, 1, -1, 0, 1 };

    for (int row = 0; row < rOWS; row++) {
        for (int col = 0; col < cOLS; col++) {
            if (mines[row][col] == 1) {
                hintMap[row][col] = -1;
            } else {
                int ctrMines = 0;
                for (int i = 0; i < 8; i++) {
                    int newRow = row + dr[i];
                    int newCol = col + dc[i];
                    if (newRow >= 0 && newRow < rOWS && newCol >= 0 && newCol < cOLS &&
                        mines[newRow][newCol] == 1) {
                        ctrMines++;
                    }
                }
                hintMap[row][col] = ctrMines;
            }
        }
    }
}

int main() {

    srand(time(NULL));

    int mines[rOWS][cOLS];


    for (int row = 0; row < rOWS; row++) {
        for (int col = 0; col < cOLS; col++) {
            mines[row][col] = (rand()%3-1);
        }
    }

    int hintMap[rOWS][cOLS];

    generateHintMap(mines, hintMap);

    for (int row = 0; row < rOWS; row++) {
        for (int col = 0; col < cOLS; col++) {
            printf("%2d ", hintMap[row][col]);
        }
        printf("\n");
    }

    return 0;
}
