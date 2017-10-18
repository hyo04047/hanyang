#include <iostream>
#include <vector>
#include <string>
#include <utility>
#include <map>

using namespace std;

int no, weight;
vector<string> name;
vector<int> volumn;
vector<int> urgency;
int cache[100][100];

int packing(int weight, int i){
  if(i == no)
    return 0;
  int& ret = cache[weight][i];
  if(ret != -1)
    return ret;
  ret = packing(weight, i + 1);
  if(weight >= volumn[i]){
    ret = max(ret, packing(weight - volumn[i], i + 1) + urgency[i]);
  }
  return ret;
}

void reconstruct(vector<string>& result, int weight, int i, int* count){
  if(i == no)
    return ;
  if(packing(weight, i) == packing(weight, i + 1)){
    reconstruct(result, weight, i + 1, count);
  }
  else{
    result.push_back(name[i]);
    (*count)++;
    reconstruct(result, weight - volumn[i], i + 1, count);
  }
}

int main(){
  int case_no;
  cin >> case_no;

  vector<int> max_weight;
  vector<int> result_no;
  vector<string> result;

  for(int it = 0; it < case_no; ++it){
    cin >> no >> weight;

    memset(cache, -1, sizeof(cache));

    int count = 0;

    for(int i = 0; i < no; i++){
      string input1;
      int input2, input3;
      cin >> input1 >> input2 >> input3;
      name.push_back(input1);
      volumn.push_back(input2);
      urgency.push_back(input3);
    }

    max_weight.push_back(packing(weight, 0));
    reconstruct(result, weight, 0, &count);
    result_no.push_back(count);

    name.clear();
    volumn.clear();
    urgency.clear();
  }

  int k = 0;
  for(int i = 0; i < case_no; i++){
    printf("%d %d\n", max_weight[i], result_no[i]);
    for(int j = 0; j < result_no[i]; j++){
      printf("%s\n", result[k++].c_str());
    }
  }

  return 0;
}
