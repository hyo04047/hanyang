#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <string>

using namespace std;

int main() 
{
   srand(time(NULL));
   
   int random_w, random_h, random_move, w, h, n;
   char move[4] = {'U', 'D', 'L', 'R'};
   string temp;
   bool ok = false;

   cin >> w >> h >> n;

    while(true){
      if(ok == true)
         getline(cin, temp);
       
      for(int i = 0; i < h; i++)
         getline(cin, temp);

      random_w = rand() % w;
      random_h = rand() % h;
      random_move = rand() % 4;
      ok = true;

      cout << random_w << " " << random_h << " " << move[random_move] << endl;
   }

   return 0;
}
