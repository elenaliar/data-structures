//
//  filename: Header.h
//  askisi5 protis ergasias

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "Item.h"
#include "STACK.h"
#define N 6

typedef char Maze[N][N];
int beenthere(Maze maze2, int i, int j);
int goalreached(Maze maze, int i, int j, Maze maze2);
