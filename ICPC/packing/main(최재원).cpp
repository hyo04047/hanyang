//
//  main.cpp
//  asdwqd
//
//  Created by 최재원 on 2017. 7. 25..
//  Copyright © 2017년 최재원. All rights reserved.
//

#include <iostream>
#include <vector>
#include <string>

using namespace std;
int C,n,W, capacity;
int volume[100], need[100];
int cache[1001][100];
string name[100];
vector<string> pick;

int pack(int capacity, int item){
    if(item==n) return 0;
    
    int& ret=cache[capacity][item];
    if(ret!=-1) return ret;
    
    ret=pack(capacity, item+1);
    if(capacity>=volume[item]){
        ret=max(ret, pack(capacity-volume[item],item+1)+need[item]);
    }
    return ret;
}

void reconstruct(int capacity, int item, vector<string>& picked){
    if(item==n) return;
    if(pack(capacity,item)==pack(capacity, item+1)){
        reconstruct(capacity, item+1, picked);
    }
    else{
        picked.push_back(name[item]);
        reconstruct(capacity-volume[item], item+1, picked);
    }
}

int main(int argc, const char * argv[]) {
    // insert code here...
    string input1;
    int input2, input3;
    cin>>C;
    for(int cntC=0;cntC<C;++cntC){
        cin>>n>>W;
        for(int cntn=0;cntn<n;++cntn){
            cin>>input1>>input2>>input3;
            name[cntn]=input1;
            volume[cntn]=input2;
            need[cntn]=input3;
        }
        for(int i=0;i<1002;++i){
            for(int j=0;j<101;++j){
                cache[i][j]=-1;
            }
        }
        int output1=pack(W, 0);
        pick.clear();
        //reconstruct(W, 0, pick);
        //int output2=(int)picked.size();
        cout<<output1<<endl;
        /*
        for(int i=0;i<3;++i){
            cout<<pick[i]<<endl;
        }*/
    }
    
}
