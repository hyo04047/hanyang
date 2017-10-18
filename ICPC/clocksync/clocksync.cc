#include <iostream>
#include <vector>

using namespace std;

#define min(x, y) ((x < y) ? (x) : (y))

const int INF = 9999, SWITCHES = 10, CLOCKS = 16;

const char linked[SWITCHES][CLOCKS + 1] = {
  "xxx.............",
  "...x...x.x.x....",
  "....x.....x...xx",
  "......xxx.x.x...",
  "x.x...........xx",
  "...x..........xx",
  "....xx........xx",
  ".xxxxx..........",
  "...xxx...x...x.."
};

bool areAligned(const vector<int>& clocks){
  for(int i = 0; i < CLOCKS; i++){
    if(clocks[i] != 12) return false;
  }
  return true;
}

void push(vector<int>& clocks, int swtch){
  for(int clock = 0; clock < CLOCKS; ++clock){
    if(linked[swtch][clock] == 'x'){
      clocks[clock] += 3;
      if(clocks[clock] == 15) clocks[clock] = 3;
    }
  }
}

int solve(vector<int>& clocks, int swtch){
  if(swtch == SWITCHES) return areAligned(clocks) ? 0 : INF;

  int ret = INF;
  for(int cnt = 0; cnt < 4; ++cnt){
    ret = min(ret, cnt + solve(clocks, swtch + 1));
    push(clocks, swtch);
  }

  return ret;
}

int main(){
  int case_no;
  cin >> case_no;

  vector<int> result;

  vector<int> clocks;
  int input;

  for(int it = 0; it < case_no; it++){
    for(int i = 0; i < CLOCKS; i++){
      cin >> input;
      // scanf("%d", &input);
      clocks.push_back(input);
    }
    for(int i = 0; i < clocks.size(); i++){
      cout << clocks[i] << ;
    }
    result.push_back(solve(clocks, 0));
    clocks.clear();
  }

  for(int i = 0; i < result.size(); i++)
    cout << result[i] << "\n";

  return 0;
}
