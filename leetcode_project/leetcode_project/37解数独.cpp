#include <iostream>
#include <vector>
#include <set>
using namespace std;

class Solution {
public:
    void solveSudoku(vector<vector<char>>& board) {

    }
    bool solve(vector<vector<int>>& board, int row, int column,set<char> (&a)[9], set<char>(&b)[9], set<char>(&c)[9]) {
        int i;
        for (i = row; i < 9; i++) {
            for (int j = column; j < 9; j++) {
                
            }
        }
        
        for (int i = 1; i < 10; i++) {
            if (!(a[row].count(i) || b[column].count(i) || c[(row / 3) * 3+column/3].count(i))) {
                board[row][column] = i;
                a[row].insert(i);
                b[column].insert(i);
                c[(row / 3) * 3 + column / 3].insert(i);
                while(board)
                if (solve(board, row + column / 9, (column + 1) % 9, a, b, c))return true; 
            }
        }
    }
};