#include <iostream>
#include <vector>

using namespace std;

int n;
vector<int> m;
vector<int> e;

int heat(){
  vector<pair<int, int> > sorting;
  for(int i = 0; i < n; ++i)
    sorting.push_back(make_pair(e[i], i));
  sort(sorting.begin(), sorting.end());
  int ret = 0, eat = 0;
  for(int i = n - 1; i >= 0; --i){
    int no = sorting[i].second;
    eat += m[no];
    ret = max(ret, eat + e[no]);
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
      int tmp;
      cin >> tmp;
      m.push_back(tmp);
    }
    for(int i = 0; i < n; ++i){
      int tmp;
      cin >> tmp;
      e.push_back(tmp);
    }
    result.push_back(heat());
    m.clear();
    e.clear();
  }

  for(int i = 0; i < case_no; ++i)
    cout << result[i] << endl;

  return 0;
}
