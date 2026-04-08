#include "mine.h"

int main() {
    int width, height, mineCount;

    printf("맵 크기(가로 세로) 입력: ");
    scanf("%d %d", &width, &height);

    if (width > 80) width = 80;
    if (height > 40) height = 40;

    printf("지뢰 개수 입력: ");
    scanf("%d", &mineCount);

    initMap(width, height, mineCount);
    printMap(width, height);

    return 0;
}