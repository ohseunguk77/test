#include "mine.h"

// (2) 지뢰 무작위 매설 및 인접 지뢰 계산
void initMap(int width, int height, int mineCount) {
    int count = 0;
    srand(time(NULL));

    while (count < mineCount) {
        int x = rand() % width;
        int y = rand() % height;

        if (MineMapLabel[y][x] != -1) {
            MineMapLabel[y][x] = -1;
            count++;
        }
    }

    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            if (MineMapLabel[i][j] == -1) continue;
            int near = 0;
            for (int ny = i - 1; ny <= i + 1; ny++) {
                for (int nx = j - 1; nx <= j + 1; nx++) {
                    if (ny >= 0 && ny < height && nx >= 0 && nx < width) {
                        if (MineMapLabel[ny][nx] == -1) near++;
                    }
                }
            }
            MineMapLabel[i][j] = near;
        }
    }
}

// (3) 행/열 번호가 표시된 맵 출력
void printMap(int width, int height) {
    printf("\n  ");
    for (int j = 0; j < width; j++) printf("%d", j % 10);
    printf("\n");

    for (int i = 0; i < height; i++) {
        printf("%2d ", i);
        for (int j = 0; j < width; j++) {
            if (MineMapLabel[i][j] == -1) printf("*");
            else printf("%d", MineMapLabel[i][j]);
        }
        printf("\n");
    }
}