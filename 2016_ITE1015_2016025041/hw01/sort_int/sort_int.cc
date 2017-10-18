#include <iostream>
using namespace std;

int sort(int a);
int main(){
	int a;
	cin >> a;
	sort(a);
	return 0;
}
int sort(int a){
	int b[a];
	for(int i=0;i<a;i++) cin >> b[i];
	for(int j=0;j<a;j++){
		for(int k=0;k<a;k++){
			if(b[j]<b[k]){
				int temp=b[j];
				b[j]=b[k];
				b[k]=temp;
			}
		}
	}
	for(int p=0;p<a;p++) cout << b[p] << " ";
    return 0;
}
