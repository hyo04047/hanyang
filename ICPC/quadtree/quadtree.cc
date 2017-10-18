#include <iostream>
#include <vector>
#include <string>

using namespace std;

#define MAX_SIZE (1024 * 1024)

// char decompressed[MAX_SIZE][MAX_SIZE];
//
// void decompress(string::iterator& it, int y, int x, int size){
//   char head = *(it++);
//   if(head == 'b' || head == 'w'){
//     for(int dy = 0; dy < size; ++dy){
//       for(int dx = 0; dx < size; ++dx){
//         decompressed[y + dy][x + dx] = head;
//       }
//     }
//   }
//   else{
//     int half = size / 2;
//     decompress(it, y, x, half);
//     decompress(it, y, x + half, half);
//     decompress(it, y + half, x, half);
//     decompress(it, y + half, x + half, half);
//   }
// }

string reverse(string::iterator& it){
  char head = *(it++);
  if(head == 'b' || head == 'w')
    return string(1, head);
  string upperleft = reverse(it);
  string upperright = reverse(it);
  string lowerleft = reverse(it);
  string lowerright = reverse(it);

  return string("x") + lowerleft + lowerright + upperleft + upperright;
}

int main(){
  int case_no;
  cin >> case_no;

  vector<string> result;

  for(int it = 0; it < case_no; it++){
    string input;
    cin >> input;

    int count = 1;
    string::iterator iter = input.begin();
    // decompress(iter, 0, 0, MAX_SIZE);
    // string tmp;
    // for(int i = 0; i < input.size(); i++){
    //   for(int j = 0; j < input.size(); j++){
    //     tmp += string(1, decompressed[i][j]);
    //   }
    // }
    // iter = tmp.begin();
    result.push_back(reverse(iter));
  }

  for(int i = 0; i < result.size(); i++)
    cout << result[i] << "\n";

  return 0;
}
