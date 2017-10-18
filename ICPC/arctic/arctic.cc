#include <iostream>
#include <vector>
#include <math.h>
#include <queue>

using namespace std;

int n;
vector<pair<double, double> > coor;
double dist[101][101];

bool decision(double d){
  vector<bool> visited(n, false);
  visited[0] = true;
  queue<int> q;
  q.push(0);
  int install = 0;
  while(!q.empty()){
    int now = q.front();
    q.pop();
    install++;
    for(int i = 0; i < n; ++i){
      if(!visited[i] && dist[now][i] <= d){
        visited[i] = true;
        q.push(i);
      }
    }
  }
  return install == n;
}

double optimize(){
  double lo = 0, hi = 1825;
  for(int i = 0; i < 100; ++i){
    double mid = (lo + hi) / 2.0;
    if(decision(mid))
      hi = mid;
    else
      lo = mid;
  }
  return hi;
}

void calc(){
  for(int i = 0; i < n; ++i){
    for(int j = 0; j < n; ++j){
      dist[i][j] = sqrt((coor[i].first - coor[j].first) * (coor[i].first - coor[j].first)
                        + (coor[i].second - coor[j].second) * (coor[i].second - coor[j].second));
    }
  }
}

int main(){
  int case_no;
  cin >> case_no;

  vector<double> result;

  for(int it = 0; it < case_no; ++it){
    cin >> n;
    for(int i = 0; i < n; ++i){
      double input1, input2;
      cin >> input1 >> input2;
      coor.push_back(make_pair(input1, input2));
    }

    calc();
    result.push_back(optimize());
    coor.clear();
  }

  for(int i = 0; i < case_no; ++i){
    cout << result[i] << endl;
  }

  return 0;
}
