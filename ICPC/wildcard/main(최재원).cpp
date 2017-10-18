//
//  main.cpp
//  ffk
//
//  Created by 최재원 on 2017. 7. 18..
//  Copyright © 2017년 최재원. All rights reserved.
//

#include <iostream>
#include <string>
using namespace std;

int cache[101][101];

string W, S;

bool matchMemorized(int w, int s){
    int &ret=cache[w][s];
    if(ret != -1) return ret;
    
    while(s<S.size() && w< W.size() && (W[w] == '?' || W[w]==S[s])){
        ++w;
        ++s;
    }
    
    if(w==W.size()) return ret = (s == S.size());
    
    if(W[w] == '*')
        for(int skip=0; skip+s <= S.size(); ++skip)
            if(matchMemorized(w+1, s+skip))
                return ret = 1;
    
    return ret = 0;
}

void chacheclear(){
    for(int cnt1=0; cnt1<101; ++cnt1){
        for(int cnt2=0; cnt2<101; ++cnt2){
            cache[cnt1][cnt2]=-1;
        }
    }
}

int main(int argc, const char * argv[]) {
    int C, n;
    cin>>C;
    for(int cntC=0; cntC<C; ++cntC){
        cin>>W;
        cin>>n;
        
        for(int cntn=0; cntn<n; ++cntn){
            chacheclear();
            cin>>S;
            if(matchMemorized(0, 0))
                cout<<S<<endl;
        }
    }
}
