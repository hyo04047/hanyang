#include <iostream>
#include <vector>

using namespace std;

// void normalize(vector<int>& num){
//   num.push_back(0);
//   for(int i = 0; i < num.size(); ++i){
//     if(num[i] < 0){
//       int borrow = (abs(num[i]) + 1) / 2;
//       num[i + 1] -= borrow;
//       num[i] += borrow * 2;
//     }
//     else{
//       num[i + 1] += num[i] / 2;
//       num[i] %= 2;
//     }
//   }
//   while(num.size() > 1 && num.back() == 0) num.pop_back();
// }

vector<int> multiply(const vector<int>& left, const vector<int>& right){
  vector<int> result_(left.size() + right.size() + 1, 0);
  for(int i = 0; i < left.size(); ++i)
    for(int j = 0; j < right.size(); ++j)
      result_[i + j] += left[i] * right[j];
  // normalize(result_);
  return result_;
}

int main(){
  int case_no;
  cin >> case_no;

  vector<int> result;

  for(int it = 0; it < case_no; ++it){
    string member_;
    string fan_;
    cin >> member_ >> fan_;

    vector<int> member(member_.size());
    vector<int> fan(fan_.size());

    for(int i = 0; i < member_.size(); ++i){
      member[i] = (member_[i] == 'M');
    }
    for(int i = 0; i < fan_.size(); ++i){
      fan[fan_.size() - i - 1] = (fan_[i] == 'M');
    }
    vector<int> output = multiply(member, fan);
    int count = 0;
    for(int i = member_.size() - 1; i < fan_.size(); ++i){
      if(output[i] == 0) count++;
    }
    result.push_back(count);
    member.clear();
    fan.clear();
  }

  for(int i = 0; i < result.size(); i++)
    cout << result[i] << "\n";

  return 0;
}
