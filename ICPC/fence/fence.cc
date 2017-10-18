#include <iostream>
#include <vector>

using namespace std;

int solve(vector<int>& h, int left, int right){
  if(left == right) return h[left];
  int mid = (left + right) / 2;
  int ret = max(solve(h, 0, mid), solve(h, mid + 1, right));
  int low = mid, high = mid + 1;
  int minheight = min(h[low], h[high]);
  ret = max(ret, minheight * (high - low + 1));
  while(h[low - 1] >= minheight && low > left){
    low--;
  }
  while(h[high + 1] >= minheight && high < right){
    high++;
  }
  ret = max(ret, minheight * (high - low + 1));
  return ret;
}

int main(){
  int case_no;
  cin >> case_no;

  vector<int> result;

  for(int it = 0; it < case_no; it++){
    int n;
    cin >> n;
    vector<int> height;
    for(int i = 0; i < n; i++){
      int input;
      cin >> input;
      height.push_back(input);
    }
    result.push_back(solve(height, 0, n - 1));
    height.clear();
  }

  for(int i = 0; i < result.size(); i++)
    cout << result[i] << "\n";

  return 0;
}
