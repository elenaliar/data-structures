//filename: path.c
//askisi5 protis ergasias
//oi sinartiseis gia tin evresi tou path ston larivintho

#include "Header.h"

int beenthere(Maze maze2, int i, int j){
    if (maze2[i][j]==1)
        return 1;
    else
        return 0;
}

int goalreached(Maze maze, int i, int j, Maze maze2){
    int d;
    Item temp;
    temp.dir=0;
    temp.x=i;
    temp.y=j;
    STACKpush(temp);
      while (!STACKempty()){
          temp = STACKpop();  //kanoume pop tin stoiva kai analoga me to dir tou struct eksetazoume mia apo tis tesseris kateuthinseis
          d = temp.dir;
          i = temp.x;
          j = temp.y;
          temp.dir++;
          STACKpush(temp);
          if (d == 0){//elegcoume tin kateuthinsi pros ta pano
              if (strncmp(&maze[i-1][j], "G", 1) == 0){//elegxoume an to apo pano stoixeio einai to G
                  maze[i][j] = '+';
                  return 1;
              }
              if (i - 1 >= 0 &&  (strncmp(&maze[i-1][j], ".", 1)==0) && beenthere(maze2, i-1, j)){
                Item temp1;
                temp1.x=i-1;
                temp1.y=j;
                temp1.dir = 0;
                maze2[i-1][j]=0;
                maze[i][j] = '+';
                STACKpush(temp1);
              }
          }
          else if (d == 1) {//elegxoume tin kateuthinsi pros ta aristera
              if (strncmp(&maze[i][j-1], "G", 1) == 0){//elegxoume an to stoixeio sta aristera einai to G
                   maze[i][j] = '+';
                  return 1;
              }
              if (j - 1 >= 0 && (strncmp(&maze[i][j-1], ".", 1) == 0) && beenthere(maze2, i, j-1)) {
                  Item temp1;
                  temp1.x = i;
                  temp1.y = j-1;
                  temp1.dir = 0;
                  maze2[i][j-1] = 0;
                  maze[i][j] = '+';
                  STACKpush(temp1);
              }
          }
          else if (d == 2) {//elegxoume tin kateuthinsi pros ta kato
              if (strncmp(&maze[i+1][j], "G", 1) == 0){//elegxoume an to apo kato stoixeio einai to G
                   maze[i][j] = '+';
                  return 1;
              }
              if (i + 1 < N && (strncmp(&maze[i+1][j], ".", 1) == 0) && beenthere(maze2, i+1, j)) {
                  Item temp1;
                  temp1.x = i+1;
                  temp1.y = j;
                  temp1.dir = 0;
                  maze2[i+1][j] = 0;
                  maze[i][j] = '+';
                  STACKpush(temp1);
              }
          }
          else if (d == 3) {//elegxoumai tin kateuthinsi pros ta deksia
              if (strncmp(&maze[i][j+1], "G", 1) == 0){//elegxoume an to stoixeio sta deksia einai to G
                   maze[i][j] = '+';
                  return 1;
              }
              if (j + 1 < N && (strncmp(&maze[i][j+1], ".", 1) == 0) && beenthere(maze2, i, j+1)) {
                  Item temp1;
                  temp1.x = i;
                  temp1.y = j+1;
                  temp1.dir = 0;
                  maze2[i][j+1] = 0;
                  maze[i][j] = '+';
                  STACKpush(temp1);
              }
          }
          else if (d>=4){//ean kamia apo tis tesseris kateythinseis den mporei na mas odigisei ston xriso pame piso apo to monopati pou                //exoume kanei
              maze2[temp.x][temp.y] = 1;
              temp = STACKpop();
          }
      }
          return 0; //ean i stoiva einai adeia simainei oti den vrethike kapoio monopati pou na mas pigainei sto xriso opote i sinartisi          //epistrefei 0
      
}
