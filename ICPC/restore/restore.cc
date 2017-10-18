#include <iostream>
#include <vector>
#include <string>

using namespace std;

#define swap(x, y, t) ((t) = (x), (x) = (y), (y) = (t))

vector<string> input;
vector<string> output;
vector<vector<int> > split;

void perm(string& list, int i, int n){
  int j;
  string tmp;

  if(i == n){
    for(j = 0; j <= n; j++)
      tmp += list[j];
    output.push_back(tmp);
  }
  else{
    for(j = i; j <= n; j++){
      char temp;
      swap(list[i], list[j], temp);
      perm(list, i + 1, n);
      swap(list[i], list[j], temp);
    }
  }
}

int main(){
  int case_no;
  cin >> case_no;

  for(int it = 0; it < case_no; ++it){
    int k;
    cin >> k;
    string list;
    for(int i = 0; i < k; i++){
      string tmp;
      cin >> tmp;
      input.push_back(tmp);
      list += to_string(i);
    }

    int n = list.size();
    perm(list, 0, n - 1);

    for(int i = 0; i < output.size(); ++i){
      vector<int> tmp2;
      for(int j = 0; j < n; ++j){
        int tmp = output[i][j] - '0';
        tmp2.push_back(tmp);
      }
      split.push_back(tmp2);
    }

    string stream;
    for(int i = 0; i < split.size(); ++i){
      for(int j = 0; j < n; ++j)
        stream += input[split[j]];
    }
  }

  return 0;
}
