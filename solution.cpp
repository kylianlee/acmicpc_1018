//
// Created by Kylian Lee on 2021/10/02.
//

#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> board;

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
      int sum = 0;
      for (int k = i; k < 8 + i; ++k) {
        for (int l = j; l < 8 + j; ++l) {
          if(board[k][l] != flag)
            sum++;
          flag = !flag;
        }
        flag = !flag;
      }
      if(min > sum)
        min = sum;
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
