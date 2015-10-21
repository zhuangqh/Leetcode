#include <iostream>
#include <vector>
#include <map>

using namespace std;
/*
class Solution {
public:
  void solve(vector<vector<char> >& board, int m) {
    int row, col;
    if (m < 81) {
      row = m / 9;
      col = m % 9;
      if (board[row][col] != '.')
        solve(board, m+1);

      for (int i = 1; i <= 9; ++i) {
        if (canplace(board, row, col, i)) {
          board[row][col] = i + '0';
          solve(board, m+1);
          board[row][col] = '.';
        }
      }
    }
  }
  bool canplace(vector<vector<char> > &board, int row, int col, int num) {
    for (int i = 0; i < 9; ++i) {
      if (board[row][i] == num+'0' || board[i][col] == num+'0') {
        return false;
      }
    }

    for (int i = 0; i < 3; ++i) {
      for (int j = 0; j < 3; ++j) {
        if (board[row/3*3 + i][col/3*3 + j] == num+'0') {
          return false;
        }
      }
    }

    return true;
  }
  void solveSudoku(vector<vector<char> >& board) {
    solve(board, 0);
  }
};

*/

class Solution {
public:
  bool solve(vector<vector<char> >& board, int num) {
    if (num >= 81) return true;

    int rrow = num / 9, ccol = num % 9;

    if (board[rrow][ccol] != '.') {
      return solve(board, num+1);
    } else {
      for (char cc = '1'; cc <= '9'; ++cc) {
        if (!row[rrow][cc] && !col[ccol][cc] && !block[rrow/3*3 + ccol/3][cc]) {
          board[rrow][ccol] = cc;
          row[rrow][cc] = col[ccol][cc] = block[rrow/3*3 + ccol/3][cc] = true;
          if (solve(board, num+1)) return true;
          board[rrow][ccol] = '.';
          row[rrow][cc] = col[ccol][cc] = block[rrow/3*3 + ccol/3][cc] = false;
        }
      }

      return false;
    }
  }
  void solveSudoku(vector<vector<char> >& board) {
    for (int i = 0; i < 9; ++i) {
      for (int j = 0; j < 9; ++j) {
        char c = board[i][j];
        if (c != '.') {
          row[i][c] = col[j][c] = block[i/3*3 + j/3][c] = true;
        } else {
          row[i][c] = col[j][c] = block[i/3*3 + j/3][c] = false;
        }
      }
    }

    solve(board, 0);
  }
private:
  map<char, bool> row[9], col[9], block[9];
};
