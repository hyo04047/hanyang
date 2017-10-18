#include <iostream>
#include <vector>
#include <string>

#define MAX_INT 1024

using namespace std;

int level(string& s, int start, int end){
  string substring_ = s.substr(start, end - start + 1);

  if(substring_ == string(substring_.size(), substring_[0]))
    return 1;

  bool arithmetic = true;
  for(int i = 0; i < substring_.size() - 1; i++){
    if(substring_[i + 1] - substring_[i] != substring_[1] - substring_[0])
      arithmetic = false;
  }
  if(arithmetic && (substring_[1] - substring_[0] == 1 || substring_[1] - substring_[0] == -1))
    return 2;

  bool same = true;
  for(int i = 0; i < substring_.size(); i++){
    if(i % 2 == 0){
      if(substring_[i] != substring_[0])
        same = false;
    }
    else{
      if(substring_[i] != substring_[1])
        same = false;
    }
  }
  if(same) return 4;
  if(arithmetic) return 5;
  return 10;
}

int cache[MAX_INT];

int calculate(string& sequence, int start){
  if(start == sequence.size())
    return 0;
  int& ret = cache[start];
  if(ret != -1)
    return ret;
  ret = MAX_INT;
  for(int i = 3; i <= 5; i++){
    if(start + i <= sequence.size()){
      ret = min(ret, calculate(sequence, start + i) + level(sequence, start, start + i - 1));
    }
  }
  return ret;
}

int main(){
  int case_no;
  cin >> case_no;

  vector<int> result;

  for(int it = 0; it < case_no; ++it){
    string input;
    cin >> input;

    memset(cache, -1, sizeof(cache));

    result.push_back(calculate(input, 0));
  }

  for(int i = 0; i < result.size(); i++)
    cout << result[i] << "\n";

  return 0;
}
