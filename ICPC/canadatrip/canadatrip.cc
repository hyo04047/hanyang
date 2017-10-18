#include <iostream>
#include <vector>

using namespace std;

int n, k;
vector<int> L;
vector<int> M;
vector<int> G;

bool decision(int dist){
  int ret = 0;
  for(int i = 0; i < n; ++i){
    if(dist >= L[i] - M[i])
      ret += (min(dist, L[i]) - (L[i] - M[i])) / G[i] + 1;
  }
  return ret >= k;
}

int optimize(){
  int lo = -1, hi = 8030001;
  while(lo + 1 < hi){
    int mid = (lo + hi) / 2;
    if(decision(mid))
      hi = mid;
    else
      lo = mid;
  }
  return hi;
}

int main(){
  int case_no;
  cin >> case_no;

  vector<int> result;

  for(int it = 0; it < case_no; ++it){
    cin >> n >> k;
    for(int i = 0; i < n; ++i){
      int l, m, g;
      cin >> l >> m >> g;
      L.push_back(l);
      M.push_back(m);
      G.push_back(g);
    }
    result.push_back(optimize());
    L.clear();
    M.clear();
    G.clear();
  }

  for(int i = 0; i < case_no; ++i)
    cout << result[i] << endl;

  return 0;
}
