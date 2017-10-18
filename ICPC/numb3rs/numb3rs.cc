#include <iostream>
#include <vector>

using namespace std;

int n, d, p;
int t;
int q;

vector<int> path;

int connected_no(vector<vector<int> >& adj, int i){
  int result = 0;
  for(int j = 0; j < n; j++){
    if(adj[i][j] == 1)
      result++;
  }
  return result;
}

double search(vector<vector<int> >& adj){
  if(path.size() == d + 1){
    if(path.back() != q)
      return 0;
    else{
      double prob = 1.0;
      for(int i = 0; i < path.size() - 1; i++){
        prob /= connected_no(adj, i);
      }
      return prob;
    }
  }
  double prob = 0;
  for(int i = 0; i < n; i++){
    if(adj[path.back()][i]){
      path.push_back(i);
      prob += search(adj);
      path.pop_back();
    }
  }
  return prob;
}

int main(){
  int case_no;
  cin >> case_no;

  vector<int> result;

  for(int it = 0; it < case_no; ++it){
    cin >> n >> d >> p;

    vector<vector<int> > adj;
    for(int i = 0; i < n; i++){
        int tmp1, tmp2, tmp3, tmp4, tmp5;
        cin >> tmp1 >> tmp2 >> tmp3 >> tmp4 >> tmp5;
        adj[i].push_back(tmp1);
        adj[i].push_back(tmp2);
        adj[i].push_back(tmp3);
        adj[i].push_back(tmp4);
        adj[i].push_back(tmp5);
    }

    cin >> t;
    for(int i = 0; i < t; i++){
      cin >> q;
      result.push_back(search(adj));
      path.clear();
    }
  }

  for(int i = 0; i < case_no; i++){
    for(int j = 0; j < t; j++){
      cout << result[i * t + j] << " ";
    }
    cout << endl;
  }

  return 0;
}
