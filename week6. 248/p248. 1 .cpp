#ifndef MINE_H
#define MINE_H

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// (1) 최대 크기 정적 배열 선언
static int MineMapMask[40][80];
static int MineMapLabel[40][80];

// 함수 원형 선언
void initMap(int width, int height, int mineCount);
void printMap(int width, int height);

#endif