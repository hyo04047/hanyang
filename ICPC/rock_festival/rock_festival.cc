#include <iostream>
#include <vector>

using namespace std;

int main(){
  int case_no;
  cin >> case_no;

  vector<double> result;

  for(int n = 0; n < case_no; n++){
    int day, team;
    cin >> day >> team;

    vector<int> array;
    for(int i = 0; i < day; i++){
      int tmp;
      cin >> tmp;
      array.push_back(tmp);
    }

    double min = 1024.0;
    double sum = 0.0;
    double avg;
    for(int i = team; i <= day; i++){
      for(int j = 0; j <= day - i; j++){
        sum = 0;
        for(int k = j; k < j + i; k++){
          sum += array[k];
        }
        avg = sum / i;
        if(avg < min)
          min = avg;
      }
    }

    result.push_back(min);
  }

  for(int i = 0; i < case_no; i++)
    printf("%.9f\n", result[i]);

  return 0;
}
