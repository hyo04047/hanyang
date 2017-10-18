#include <iostream>
#include <vector>
#include <string>

using namespace std;

#define MAX_INT 1000000000

int n, p, l;
int length[51];
int skip;

string X_gen = "X+YF";
string Y_gen = "FX-Y";

void cal_length(){
  length[0] = 1;
  for(int i = 1; i < 51; i++)
    length[i] = min(MAX_INT, length[i - 1] * 2 + 2);
}

char curve(string& dragoncurve, int generation){
  if(generation == 0){
    return dragoncurve[skip];
  }
  for(int i = 0; i < dragoncurve.size(); ++i){
    if(dragoncurve[i] == 'X' || dragoncurve[i] == 'Y'){
      if(length[generation] <= skip)
        skip -= length[generation];
      else if(dragoncurve[i] == 'X')
        return curve(X_gen, generation - 1);
      else
        return curve(Y_gen, generation - 1);
    }
    else if(skip > 0) // "F" or "+" or "-"
      skip--;
    else
      return dragoncurve[i];
  }
}

int main(){
  int case_no;
  cin >> case_no;

  cal_length();

  vector<string> result;

  for(int it = 0; it < case_no; ++it){
    cin >> n >> p >> l;

    string tmp = "";
    string seed = "FX";
    for(int i = p; i < p + l; i++){
      skip = i - 1;
      tmp += curve(seed, n);
    }
    result.push_back(tmp);
  }

  for(int i = 0; i < case_no; ++i){
    cout << result[i] << endl;
  }

  return 0;
}
//
// FX
// FX+YF
// FX+YF+FX-YF
// FX+YF+FX-YF+FX+YF-FX+YF
// FX+YF+FX-YF+FX+YF-FX+YF+FX+YF+FX-YF-FX-YF+FX-YF
