#include <iostream>
#include <vector>

using namespace std;

#define MAX 10

bool arefriend[MAX][MAX] = {false};
bool haspair[MAX] = {false};

int divide(int n){
  bool allhaspair = true;
  for(int i = 0; i < n; i++){
    if(!haspair[i]) allhaspair = false;
  }
  if(allhaspair) return 1;

  int count = 0;
  int nopair;

  for(int i = 0; i < n; i++){
    if(!haspair[i]){
      nopair = i;
      break;
    }
  }
  for(int i = nopair + 1; i < n; i++){
      if(!haspair[i] && arefriend[nopair][i]){
        haspair[nopair] = haspair[i] = true;
        count += divide(n);
        haspair[nopair] = haspair[i] = false;
      }
  }
  return count;
}

int main(){
  int case_no;
  cin >> case_no;

  vector<int> result;

  for(int it = 0; it < case_no; it++){
    int n, m;
    cin >> n >> m;

    for(int i = 0; i < m; i++){
      int row, col;
      cin >> row >> col;
      arefriend[row][col] = true;
      arefriend[col][row] = true;
    }

    result.push_back(divide(n));

    for(int i = 0; i < MAX; i++){
      for(int j = 0; j < MAX; j++){
        arefriend[i][j] = false;
      }
    }
  }

  for(int i = 0; i < case_no; i++)
    cout << result[i] << "\n";

  return 0;
}
