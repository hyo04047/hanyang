#include <iostream>
#include <vector>
#include <string>
#include <memory>
#include <algorithm>

using namespace std;

int cache[101][101];

string wildcard, file_name;

bool matchMemorized(int w, int s/*, string& wildcard, string& file_name*/){
  int& ret = cache[w][s];
  if(ret != -1)
    return ret;
  // while(s < file_name.size() && w < wildcard.size() && (wildcard[w] == '?' || wildcard[w] == file_name[s])){
  //   ++w;
  //   ++s;
  // }
  if(w < wildcard.size() && s < file_name.size() && (wildcard[w] == '?' || wildcard[w] == file_name[s]))
    return ret = matchMemorized(w + 1, s + 1/*, wildcard, file_name*/);
  if(w == wildcard.size())
    return ret = (s == file_name.size());
  if(wildcard[w] == '*'){
    // for(int skip = 0; skip + s < file_name.size(); ++skip)
    //   if(matchMemorized(w + 1, s + skip))
    if(matchMemorized(w + 1, s/*, wildcard, file_name*/) || (s < file_name.size() && matchMemorized(w, s + 1/*, wildcard, file_name*/)))
        return ret = 1;
  }
  return ret = 0;
}

int main(){
  int case_no;
  cin >> case_no;

  vector<string> result;

  for(int it = 0; it < case_no; ++it){
    result.push_back("---------------");
    vector<string> tmp;

    // string wildcard;
    cin >> wildcard;

    int file_no;
    cin >> file_no;

    for(int i = 0; i < file_no; i++){
      // string file_name;
      memset(cache, -1, sizeof(cache));
      cin >> file_name;
      if(matchMemorized(0, 0/*, wildcard, file_name*/))
        tmp.push_back(file_name);
    }

    sort(tmp.begin(), tmp.end());
    for(int i = 0; i < tmp.size(); i++){
      result.push_back(tmp[i]);
    }
  }

  for(int i = 0; i < result.size(); i++)
    cout << result[i] << "\n";

  return 0;
}
