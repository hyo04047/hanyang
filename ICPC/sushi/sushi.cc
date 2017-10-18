#include <iostream>
#include <vector>

using namespace std;

int n;
int m;
vector<int> price;
vector<int> pref;
int cache[201];

int sushi(){
  int ret = 0;
  cache[0] = 0;
  for(int budget = 1; budget <= m; ++budget){
    int cand = 0;
    for(int dish = 0; dish < n; ++dish){
      if(budget >= price[dish])
        cand = max(cand, cache[(budget - price[dish]) % 201] + pref[dish]);
      cache[budget % 201] = cand;
      ret = max(ret, cand);
    }
  }
  return ret;
}

// int sushi(int budget){
//   int& ret = cache[budget];
//   if(ret != -1)
//     return ret;
//   ret = 0;
//   for(int dish = 0; dish < n; ++dish){
//     if(m < price[dish])
//       continue;
//     ret = max(ret, sushi(budget - price[dish]) + pref[dish]);
//   }
//   return ret;
// }

int main(){
  int case_no;
  cin >> case_no;

  vector<int> result;

  for(int it = 0; it < case_no; ++it){
    cin >> n >> m;
    m /= 100;
    for(int i = 0; i < n; ++i){
      int price_, pref_;
      cin >> price_ >> pref_;
      price.push_back(price_ / 100);
      pref.push_back(pref_);
    }
    // memset(cache, -1, sizeof(cache));
    result.push_back(sushi());
    price.clear();
    pref.clear();
  }

  for(int i = 0; i < case_no; ++i)
    cout << result[i] << endl;

  return 0;
}
