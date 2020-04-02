#include<vector>
#include<iostream>
using namespace std;
class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[0].size(); j++) {
                int sur = f(board, i - 1, j - 1) + f(board, i - 1, j ) + f(board, i - 1, j + 1) + f(board, i , j - 1) + f(board, i, j + 1) + f(board, i + 1, j - 1) + f(board, i + 1, j) + f(board, i + 1, j + 1);
                if (board[i][j] == 1 && (sur < 2 || sur>3)) {
                    board[i][j] = 2;
                }
                else if (board[i][j] == 0 && sur == 3) {
                    board[i][j] = -1;
                }
            }
        }
        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[0].size(); j++) {
                if (board[i][j] == 2)
                    board[i][j] = 0;
                else if (board[i][j] == -1)
                    board[i][j] = 1;
            }
        }
    }
    int f(vector<vector<int>>& board, int i, int j) {
        if (i < 0 || i >= board.size() || j < 0 || j >= board[0].size())
            return 0;
        try {
            if (board[i][j] == 2)
                return 1;
            else if (board[i][j] == -1) 
                return 0;
            else
                return board[i][j];
        }
         catch (...)
            {
                return 0;
            }
    }
};