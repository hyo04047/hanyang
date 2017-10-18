//
//  main.cpp
//  programming study
//
//  Created by 최재원 on 2017. 7. 4..
//  Copyright © 2017년 최재원. All rights reserved.
//

#include <iostream>

int main(int argc, const char * argv[]) {
    int C;
    int N,L;
    int arr[1000];
    double total=0;
    double min=9999;
    scanf("%d",&C);
    for(int i=0 ; i<C ; i++){
        scanf("%d %d",&N, &L);
        for(int j=0; j <N; j++){
            scanf("%d",&arr[j]);
        }
        for(int j=L; j<=N; j++){//몇개인지
            for(int k=0; k<N-j; k++){//어디서부터 시작인지
                for(int l=k; l<k+j;l++){//시작부터 몇개까지 더해보기
                    total+=arr[l];
                }
                if(min > total/j){
                    min=total/j;
                }
                total=0;
            }
        }
        printf("%lf\n", min);
        
        
    }
}
