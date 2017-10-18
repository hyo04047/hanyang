#include <iostream>
#include <vector>
#include <queue>
#include <functional>

using namespace std;

int n;
vector<int> length;

int join(){
  // sort(length.begin(), length.end());
  priority_queue<int, vector<int>, greater<int> > que;
  for(int i = 0; i < length.size(); ++i)
    que.push(length[i]);
  int ret = 0;
  while(que.size() > 1){
    int first = que.top();
    que.pop();
    int second = que.top();
    que.pop();
    que.push(first + second);
    ret += first + second;
  }
  return ret;
}

int main(){
  int case_no;
  cin >> case_no;

  vector<int> result;

  for(int it = 0; it < case_no; ++it){
    cin >> n;
    for(int i = 0; i < n; ++i){
      int input;
      cin >> input;
      length.push_back(input);
    }
    result.push_back(join());
    length.clear();
  }

  for(int i = 0; i < case_no; ++i)
    cout << result[i] << endl;

  return 0;
}
