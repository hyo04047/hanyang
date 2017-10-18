//
//  main.cpp
//  sdasd
//
//  Created by 최재원 on 2017. 7. 25..
//  Copyright © 2017년 최재원. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

const int INF=987654;
int C, n, s, input;
vector<int> sequence;

int cache[101][11];

int cal(int spoint, int epoint){
    int total=0;
    int ret=0;
    int div=0;
    for(int i=spoint; i<=epoint; ++i){
        total+=sequence[i];
    }
    div=(int)(0.5+(double)total/(epoint-spoint+1));
    
    for(int i=spoint; i<=epoint; ++i){
        ret=ret+(sequence[i]-div)*(sequence[i]-div);
    }
    return ret;
}

int solve(int spoint, int num){
    if(spoint==sequence.size()) return 0;
    
    if(num==0) return INF;
    
    int& ret=cache[spoint][num];
    if(ret!=-1) return ret;
    
    ret=INF;
    for(int length=1; spoint+length<=n;++length){
        ret=min(ret, cal(spoint,spoint+length-1)+solve(spoint+length, num-1));
    }
    return ret;
    
    
}

int main(int argc, const char * argv[]) {
    cin>>C;
    for(int cntC=0; cntC<C; ++cntC){
        cin>>n>>s;
        sequence.clear();
        for(int cntn=0; cntn<n; ++cntn){
            cin>>input;
            sequence.push_back(input);
        }
        sort(sequence.begin(), sequence.end());
        for(int i=0; i<101; ++i)
            for(int j=0;j<11; ++j)
                cache[i][j]=-1;
        int output=solve(0,s);
        cout<<output<<endl;
    }
}
