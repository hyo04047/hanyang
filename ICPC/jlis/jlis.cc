#include <iostream>
#include <vector>

using namespace std;

int k;
int cache[101];

int lis(int start, vector<int>& S){
  int& ret = cache[start];
  if(ret != -1) return ret;
  ret = 1;
  for(int next = start + 1; next < k; ++next){
    if(S[start] < S[next])
      ret = max(ret, lis(next, S) + 1);
  }
  return ret;
}

int main(){
  int case_no;
  cin >> case_no;

  vector<int> result;

  for(int it = 0; it < case_no; ++it){
    int n, m;
    cin >> n >> m;
    k = n + m;

    vector<int> A;

    for(int i = 0; i < k; i++){
      int input;
      cin >> input;
      A.push_back(input);
    }

    int maxLen = 0;
    for(int begin = 0; begin < n; ++begin){
      memset(cache, -1, sizeof(cache));
      maxLen = max(maxLen, lis(begin, A));
    }
    result.push_back(maxLen);
  }

  for(int i = 0; i < result.size(); i++)
    cout << result[i] << "\n";

  return 0;
}
