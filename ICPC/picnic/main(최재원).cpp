//
//  main.cpp
//  qwert
//
//  Created by 최재원 on 2017. 7. 7..
//  Copyright © 2017년 최재원. All rights reserved.
//

#include <iostream>
#include <vector>

int studentcase[50][2];
int student[10];

int total;

int caseOfFreind(int maxpair, int n, int numstudent){
    if(numstudent==0){
        total++;
        return 0;
    }
    
    for(int i=n; i<maxpair; i++){
        if((student[studentcase[i][0]]==0) && (student[studentcase[i][1]]==0)){
            student[studentcase[i][0]]=1;
            student[studentcase[i][1]]=1;
            caseOfFreind(maxpair, i+1, numstudent-2);
            student[studentcase[i][0]]=0;
            student[studentcase[i][1]]=0;
        }
    }
    return 0;
}

int main(int argc, const char * argv[]) {
    int C, n, m;
    int f1,f2;
    scanf("%d", &C);
    for(int i=0; i<C; i++){
        total=0;
        scanf("%d %d", &n, &m);
        for(int j=0; j<m; j++){
            scanf("%d %d",&f1,&f2);
            studentcase[j][0]=f1;
            studentcase[j][1]=f2;
        }
        caseOfFreind(m, 0, n);
        printf("%d\n", total);
    }
}
