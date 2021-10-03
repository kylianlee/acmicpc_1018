//
// Created by Kylian Lee on 2021/10/02.
//

#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> board;

int checkBoard(bool flag, int x, int y){
  int sum = 0;
  for (int i = x; i < 8 + x; ++i) {
    for (int j = y; j < 8 + y; ++j) {
      if(board[i][j] != flag)
        sum++;
      flag = !flag;
    }
    flag = !flag;
  }
  return sum;
}

int main(){
  int r, c;
  cin >> r >> c;
  board.resize(r);
  for(int i = 0; i < r; i++){
    board[i].resize(c);
  }
  for(int i = 0; i < r; i++){
    for(int j = 0; j < c; j++){
      char tmp;
      cin >> tmp;
      if(tmp == 'B')
        board[i][j] = 0;
      else
        board[i][j] = 1;
    }
  }
  int min = 65;
  for (int i = 0; i <= r - 8; ++i) {
    for(int j = 0; j <= c - 8; ++j) {
      bool flag = board[i][j];
      int ret1 = checkBoard(flag, i, j);
      int ret2 = checkBoard(!flag, i, j);
      if(ret1 > ret2 && ret2 < min)
        min = ret2;
      else if(ret2 > ret1 && ret1 < min)
        min = ret1;
      else if(ret1 == ret2 && ret1 < min)
        min = ret1;
    }
  }
  cout << min;
  return 0;
}

//10 13
//BWBWBWBWBWBWB
//BBBBBBBBBBBBB
//BWBWBWBWBWBWB
//BBBBBBBBBBBBB
//BWBWBWBWBWBWB
//BBBBBBBBBBBBB
//BWBWBWBWBWBWB
//BWBWBWBWBWBWB
//BBBBBBBBBBBBB
//BWBWBWBWBWBWB

//9 10
//BBBBBBBBBB
//BWWBWBWBWB
//BWBWBWBWBW
//BWWBWBWBWB
//BWBWBBBWBW
//BWWBWBWBWB
//BWBWBWBWBW
//BWWBWBWBWB
//BWBWBWBWBW

//8 8
//BBWBWBWB
//BWBWBWBW
//WBWBWBWB
//BWBBBWBW
//WBWBWBWB
//BWBWBWBW
//WBWBWBWB
//BWBWBWBW

//10 13
//WWWWWWWWBWBWB
//WWWWWWWWWBWBW
//WWWWWWWWBWBWB
//WWWWWWWWWBWBW
//WWWWWWWWBWBWB
//WWWWWWWWWBWBW
//WWWWWWWWBWBWB
//WWWWWWWWWBWBW
//BBBBBBBBBBWBW
//BBBBBBBBBBWBW

//18 8
//WBWBWBWB
//BWBBWWBW
//WBWBWBWB
//BWBWBWBW
//WBWBWBWB
//BWBWBWBW
//WBWBWBWB
//BWBWBWBW
//WBWWBBWB
//BWBWBWBW
//WBWBWBWB
//BWBWBWBW
//WBWBWBWB
//BWBWBWBW
//WBWWWBWB
//BWBWBWBW
//WBWBWBWB
//BWBWBWBW

//10 8
//WBWWBBBW
//BWBBWWWW
//BWWWBBBW
//BWWWWWWW
//BWBBWBWB
//BWWBBBWW
//WBWBWBBW
//BWBWBWWW
//WBWWBBWW
//WBWWWBBW

//9 8
//WWWWWWWW
//WWWWWWWW
//WWWWWWWW
//WWWWWWWW
//WWWWWWWW
//WWWWWWWW
//WWWWWWWW
//WWWWWWWW
//WWWWWWWW