//
//  main.cpp
//  as
//
//  Created by 최재원 on 2017. 7. 11..
//  Copyright © 2017년 최재원. All rights reserved.
//

#include <iostream>
#include <string>
#include <vector>

using namespace std;



string reverse(string::iterator& it){
    char head = *it;
    ++it;
    if(head == 'b' || head == 'w')
        return string(1,head);
    string upperLeft = reverse(it);
    string upperRight = reverse(it);
    string lowerLeft = reverse(it);
    string lowerRight = reverse(it);
    
    return string("x") + lowerLeft + lowerRight + upperLeft + upperRight;
}


int main(int argc, const char * argv[]) {
    int C;
    vector<string> quadTree;
    string::iterator a;
    string temp;
    scanf("%d", &C);
    getline(cin,temp);// 버퍼 비워주기
    for(int cnt=0; cnt <C ; ++cnt){
        getline(cin,temp);
        quadTree.push_back(temp);
        a=temp.begin();
        temp=reverse(a);
        cout<<temp<<'\n';
    }
    
}
