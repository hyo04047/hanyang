#include <stdio.h>
#include <stdbool.h>
#define      MAX_X  1024
#define      MAX_Y  1024
/**
  * draws a point given parameters as "*" and fills others as "."
  * @param[in] x    x coordinate of a point
  * @param[in] y    y coordinate of a point
  * @return true if given coordinate can be presented at the scrren
  */
bool DrawPoint(int x, int y) {
    if(x<0 || y<0){
      return false;
    }
    else return true;
}
int main() {
  int x;
  int y;
  int max_x=0;
  int max_y=0;
  char screen[MAX_Y][MAX_X]={'.'};        
  for(int i=0; i<MAX_X; i++){
    for(int j=0; j<MAX_Y; j++){
      screen[i][j]='.';
    }
  }
  while (true) {
        scanf("%d %d", &x, &y);
        if (!DrawPoint(x, y)) {
          break; 
        }

        screen[y][x]='*';

        if(x>=max_x) max_x=x;
        if(y>=max_y) max_y=y;

        for(int i=0; i<=max_y; i++){
          for(int j=0; j<=max_x; j++){
            printf("%c", screen[i][j]);
          }
          printf("\n");
        }
  }
  return 0; 
}
