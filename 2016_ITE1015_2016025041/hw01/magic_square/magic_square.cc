#include <iostream>
using namespace std;

void square(int a,int i, int p);
int main(){
    int a,i=0,p=1;
    cin >> a;
    if(a%2!=0){
        square(a,i,p);
    }
    return 0;
}
void square(int a, int i, int p){
	int c[a][a];
        int j=(a-1)/2;
        int n=a*a;
        for(int w=0;w<a;w++){
            for(int e=0;e<a;e++){
                c[w][e]=0;
            }
        }
        c[i][j]=1;
        p+=1;
        for(int k=1;k<n;k++){
            if(i!=0 && j!=(a-1)){
                if(c[i-1][j+1]==0){
                    i-=1, j+=1;
                    c[i][j]=p, p+=1;
                }
                else{
                    i+=1;
                    c[i][j]=p, p+=1;
                }
            }
            else if(i==0 && j==(a-1)){
                i+=1;
                c[i][j]=p, p+=1;
            }
            else if(i==0 && j!=(a-1)){
                if(c[a-1][j+1]==0){
                    i=a-1, j+=1;
                    c[i][j]=p, p+=1;
                }
                else{
                    i+=1;
                    c[i][j]=p, p+=1;
                }
            }
            else if(i!=0 && j==(a-1)){
                if(c[i-1][0]==0){
                    i-=1, j=0;
                    c[i][j]=p, p+=1;
                }
                else{
                    i+=1;
                    c[i][j]=p, p+=1;
                }
            }
        }
        for(i=0;i<a;i++){
            for(j=0;j<a;j++){
                cout << c[i][j] <<  " ";
            }
            cout << "\n";
        }
}
