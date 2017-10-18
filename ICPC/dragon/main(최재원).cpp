//
//  main.cpp
//  m
//
//  Created by 최재원 on 2017. 7. 28..
//  Copyright © 2017년 최재원. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

int C, n, l;
long int p;

//F=0 X=1 Y=2 +=3 -=4
int solve(long int num){
    long int div, mol;
    mol=(num-1)%6;
    div=(num-1)/3+1;
    
    if(mol==0||mol==4) return 0;
    else if(mol==1) return 1;
    else if(mol==3) return 2;
    else{
        while(mol!=1){
            mol=div%2;
            div=div/2;
        }
        if(div%2==0) return 3;
        else return 4;
    }
}

int main(int argc, const char * argv[]) {
    cin>>C;
    for(int cntC=0; cntC<C; ++C){
        cin>>n>>p>>l;
        for(long int i=p; i-p<l;++i){
            int temp=solve(i);
            if(temp==0)
                cout<<"F";
            else if(temp==1)
                cout<<"X";
            else if(temp==2)
                cout<<"Y";
            else if(temp==3)
                cout<<"+";
            else
                cout<<"-";
        }
        cout<<endl;
    }
}
