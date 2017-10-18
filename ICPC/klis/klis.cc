#include <iostream>
#include <vector>
#include <utility>

using namespace std;

#define MAX_INT 2000000000

int n, k;
int cache[501];
int cache2[501];
int skip;

int lis(int start, vector<int>& S){
  int& ret = cache[start + 1];
  if(ret != -1)
    return ret;
  ret = 1;
  for(int next = start + 1; next < n; ++next){
    if(start == -1 || S[start] < S[next])
      ret = max(ret, lis(next, S) + 1);
  }
  return ret;
}

int count(int start, vector<int>& S){
  if(lis(start, S) == 1)
    return 1;
  int& ret = cache2[start + 1];
  if(ret != -1)
    return ret;
  ret = 0;
  for(int next = start + 1; next < n; ++next){
    if((start == -1 || S[start] < S[next]) && lis(start, S) == lis(next, S) + 1){
      ret = min<long long>(MAX_INT, (long long)ret + count(next, S));
    }
  }
  return ret;
}

void reconstruct(int start, vector<int>& S, vector<int>& list){
  if(start != -1)
    list.push_back(S[start]);
  vector<pair<int, int> > followers;
  for(int next = start + 1; next < n; ++next){
    if((start == -1 || S[start] < S[next]) && lis(start, S) == lis(next, S) + 1){
      followers.push_back(make_pair(S[next], next));
    }
  }
  sort(followers.begin(), followers.end());
  for(int i = 0; i < followers.size(); ++i){
    int idx = followers[i].second;
    int cnt = count(idx, S);
    if(cnt <= skip)
      skip -= cnt;
    else{
      reconstruct(idx, S, list);
      break;
    }
  }
}

int main(){
  int case_no;
  cin >> case_no;

  vector<int> length;
  vector<vector<int> > result;
  vector<int> output;

  for(int it = 0; it < case_no; ++it){
    cin >> n >> k;
    vector<int> sequence;
    for(int i = 0; i < n; i++){
      int tmp;
      cin >> tmp;
      sequence.push_back(tmp);
    }

    memset(cache, -1, sizeof(cache));
    memset(cache2, -1, sizeof(cache2));

    skip = k - 1;
    length.push_back(lis(-1, sequence) - 1);
    reconstruct(-1, sequence, output);
    result.push_back(output);
    output.clear();
  }

  for(int i = 0; i < case_no; i++){
    cout << length[i] << endl;
    for(auto j = result[i].begin(); j != result[i].end(); j++){
      cout << *j << " ";
    }
    cout << endl;
  }

  return 0;
}
