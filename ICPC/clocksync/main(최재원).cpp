//
//  main.cpp
//  as
//
//  Created by 최재원 on 2017. 7. 11..
//  Copyright © 2017년 최재원. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

const int INF = 9999, SWITCHES = 10, CLOCKS = 16;
int C;

const char linked[SWITCHES][CLOCKS+1] = {
    "xxx.............",
    "...x...x.x.x....",
    "....x.....x...xx",
    "x...xxxx........",
    "......xxx.x.x...",
    "x.x...........xx",
    "...x..........xx",
    "....xx.x......xx",
    ".xxxxx..........",
    "...xxx...x...x..",
};

bool areAligned(const vector<int>& clocks){
    for(int cnt=0; cnt<CLOCKS; ++cnt){
        if(clocks[cnt]!=12)
            return false;
    }
    return true;
}

void push(vector<int>& clocks, int swtch){
    for(int clock=0; clock<CLOCKS; ++clock){
        if(linked[swtch][clock] == 'x'){
            clocks[clock] +=3;
            if(clocks[clock] == 15) clocks[clock] = 3;
        }
    }
}

int solve(vector<int>& clocks, int swtch){
    if(swtch==SWITCHES) return areAligned(clocks) ? 0 : INF;
    int ret = INF;
    for(int cnt = 0; cnt<4; ++cnt){
        ret=min(ret,cnt+solve(clocks, swtch+1));
        push(clocks, swtch);
    }
    return ret;
}

int main(int argc, const char * argv[]) {
    vector<int> clocks;
    int a;
    
    scanf("%d",&C);
    for(int cnt=0; cnt<C; ++cnt){
        for(int i=0; i<CLOCKS; i++){
            scanf("%d",&a);
            clocks.push_back(a);
        }
        printf("%d\n", solve(clocks,0));
        clocks.clear();
    }
}
