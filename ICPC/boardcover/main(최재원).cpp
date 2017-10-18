//
//  main.cpp
//  a
//
//  Created by 최재원 on 2017. 7. 7..
//  Copyright © 2017년 최재원. All rights reserved.
//

#include <iostream>

int total;
int board[20][20];
int C, H, W;


int search(int blanknum, int s){
    
    if(blanknum==0){
        total++;
        return 0;
    }
    
    for(int k=s; k<H*W; k++){
        int i,j;
        i=k/W;
        j=k%W;
        if(board[i][j]==0){
            if((i+1<H) && (j+1 <W) && (board[i+1][j]==0) && (board[i][j+1]==0)){
                board[i][j]=1;
                board[i+1][j]=1;
                board[i][j+1]=1;
                search(blanknum-3, k+1);
                board[i][j]=0;
                board[i+1][j]=0;
                board[i][j+1]=0;
            }
            if((i+1<H) && (j+1 <W) && (board[i+1][j+1]==0) && (board[i][j+1]==0)){
                board[i][j]=1;
                board[i+1][j+1]=1;
                board[i][j+1]=1;
                search(blanknum-3, k+1);
                board[i][j]=0;
                board[i+1][j+1]=0;
                board[i][j+1]=0;
            }
            if((i+1<H) && (j-1 >=0) && (board[i+1][j]==0) && (board[i+1][j-1]==0)){
                board[i][j]=1;
                board[i+1][j]=1;
                board[i+1][j-1]=1;
                search(blanknum-3, k+1);
                board[i][j]=0;
                board[i+1][j]=0;
                board[i+1][j-1]=0;
            }
            if((i+1<H) && (j+1 <W) && (board[i+1][j]==0) && (board[i+1][j+1]==0)){
                board[i][j]=1;
                board[i+1][j]=1;
                board[i+1][j+1]=1;
                search(blanknum-3, k+1);
                board[i][j]=0;
                board[i+1][j]=0;
                board[i+1][j+1]=0;
            }
        }
        if(j==W-1){
            for(int l=0;l<W;l++){
                if(board[i][l]==0){
                    return 0;
                }
            }
        }
    }
    return 0;
}

int main(int argc, const char * argv[]) {
    
    int numofdot=0;
    char temp;
    
    scanf("%d", &C);
    for(int i=0; i< C; i++){
        numofdot=0;
        total=0;
        
        scanf("%d %d", &H, &W);
        for(int j=0; j<H; j++){
            temp=getchar();
            for(int k=0; k<W; k++)
            {
                temp=getchar();
                if(temp=='.'){
                    board[j][k]=0;
                    numofdot++;
                }
                else
                    board[j][k]=1;
            }
        }
        if(numofdot%3!=0)
        {
            printf("0\n");
            continue;
        }
        search(numofdot,0);
        printf("%d", total);
        
    }
}
