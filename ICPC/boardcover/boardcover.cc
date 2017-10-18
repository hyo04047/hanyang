#include <iostream>
#include <vector>
#include <string>

#define MAX 1024

using namespace std;

vector< vector<int> > pane;

int blockshape[4][3][2] = {{{0, 0}, {1, 0}, {1, 1}},
                           {{0, 0}, {1, 0}, {0, 1}},
                           {{0, 0}, {0, 1}, {-1, 1}},
                           {{0, 0}, {0, 1}, {1, 1}}};

bool coverable(int x, int y, int type, int set){
  for(int i = 0; i < 3; i++){
    int dx = x + blockshape[type][i][0];
    int dy = y + blockshape[type][i][1];
    if(dx >= pane[0].size() || dx < 0 || dy >= pane.size() || dy < 0)
      return false;
    if(pane[dy][dx] + set > 1)
      return false;
    pane[dy][dx] += set;
  }
  return true;
}

int cover(){
  int x_not_cover = -1, y_not_cover = -1;
  for(int i = 0; i < pane.size(); i++){
    for(int j = 0; j < pane[i].size(); j++){
      if(pane[i][j] == 0){
        x_not_cover = j;
        y_not_cover = i;
        break;
      }
    }
    if(x_not_cover != -1) break;
  }
  if(x_not_cover == -1) return 1;
  int count = 0;
  for(int i = 0; i < 4; i++){
    if(coverable(x_not_cover, y_not_cover, i, 1)){
      count += cover();
      coverable(x_not_cover, y_not_cover, i, -1);
    }
  }
  return count;
}

int main(){
  int case_no;
  cin >> case_no;

  vector<int> result;

  for(int it = 0; it < case_no; it++){
    int row, col;
    string temp;
    // cin >> row >> col;
    scanf("%d %d", &row, &col);
    getline(cin, temp);
    char board[MAX][MAX];
    for(int i = 0; i < row; i++){
      // cout << "i = " << i  <<" start"<< endl;
      string input;
      // cin >> input;
      getline(cin, input);
      for(int j = 0; j < col; j++){
        // cout << "j = " << j << endl;
        board[i][j] = input[j];
      }
      // for(int j = 0; j < col; j++){
      //   printf("%c", board[i][j]);
      // }
      // cout << endl << "i = " << i << " end" << endl;
    }
    // for(int i = 0; i < row; i++){
    //   printf("%s\n", board[i]);
    // }
    for(int i = 0; i < row; i++){
      vector<int> tmp;
      for(int j = 0; j < col; j++){
        if(board[i][j] == '#'){
          temp.push_back(1);
        }
        else{
          temp.push_back(0);
        }
      }
      pane.push_back(tmp);
    }

    int count = 0;

    for(int i = 0; i < row; i++){
      for(int j = 0; j < col; j++){
        if(pane[i][j] == 0) count++;
      }
    }
    if(count % 3 != 0){
      // cout << "if" << endl;
      result.push_back(0);
      pane.clear();
    }
    else{
      result.push_back(cover());
      pane.clear();
    }
  }

  for(int i = 0; i < case_no; i++)
    cout << result[i] << "\n";

  return 0;
}
