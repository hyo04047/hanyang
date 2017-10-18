//
//  main.cpp
//  ffk
//
//  Created by 최재원 on 2017. 7. 18..
//  Copyright © 2017년 최재원. All rights reserved.
//

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> A,B;
vector<int> temp;
int cache[51];

int solve(){
    int cnt=0, a=0, b=0, ret=0;
    while(a<A.size()||b<B.size()){
        if(a>=A.size()||b>=B.size()){
            ++a;
            ++b;
        }
        else if(A[a]<B[b])
            ++a;
        else if(A[a]>B[b])
            ++b;
        else{
            ++a;
            ++b;
        }
        ++ret;
        ++cnt;
    }
    return ret;
    
    
}

void cacheclear(){
    for(int cnt1=0;cnt1<51; ++cnt1){
        cache[cnt1]=-1;
    }
}

int main(int argc, const char * argv[]) {
    int C, n, m;
    int input;
    
    cin>>C;
    for(int cntC=0; cntC<C; ++cntC){
        cin>>n>>m;
        A.clear();
        B.clear();
        
        for(int cntn=0; cntn<n; ++cntn){
            cin>>input;
            A.push_back(input);
        }
        for(int cntm=0; cntm<m; ++cntm){
            cin>>input;
            B.push_back(input);
        }
        sort(A.begin(),A.end());
        sort(B.begin(),B.end());
        cout<<solve()<<endl;
    }
}
