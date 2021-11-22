//
//  filename: main.c
//  askisi5 protis ergasias

#include "Header.h"



int main(void){
    int i, j, k;
    int sx, sy; //oi sintetagmenes apo to simeio tou lavirinthou pou ksekiname
    char tmp;
    char tmp2;
    Maze maze;
    Maze maze2;  /*enas deuteros pinkas idion diastaseon me ton arxiko poy tha mas deixnei poia stoixeia tou arxikou exoun episkeftei kathos vriskoume to path*/
    for (i=0; i<N; i++){
        for (j=0; j<N; j++){
            maze2[i][j] = 1;
        }
    }
    
    for(k=0; k<5; k++){//auto to for einai gia na vrei to starting point
        if (k==0)
            scanf("%c", &tmp);
        else if (k==1)
            scanf("%d", &sx);
        else if (k==2)
            scanf("%c", &tmp);
        else if (k==3)
            scanf("%d", &sy);
        else if (k==4)
            scanf("%c", &tmp);
    }
    scanf("%c", &tmp2);  //epeidi o pinakas einai tipou char xoris auto to scanf tha metrouse os stoixeio tou pinaka tin allagi grammis
    
    for (i=0; i<N; i++){
        for (j=0; j<N; j++){
            scanf("%c", &maze[i][j]);
        }
        scanf("%c", &tmp2);  //epeidi o pinakas einai tipou char xoris auto to scanf tha metrouse os stoixeio tou pinaka tin allagi grammis
    }
    printf("the given maze is:\n");
    for (i=0; i<N; i++){
        for (j=0; j<N; j++){
            printf("%c ", maze[i][j]);
        }
        printf("\n");
    }
    
    if (goalreached(maze, sx, sy, maze2)){
        printf("there is a path that leads from starting point (%d,%d) to the gold\n", sx, sy);
        maze[sx][sy] = 'S';
        for (i=0; i<N; i++){
            for (j=0; j<N; j++){
                printf("%c ", maze[i][j]);
            }
            printf("\n");
        }
    }
    else
        printf("there is no path that leads from starting point (%d,%d) to the gold\n", sx, sy);
    return 0;
}


