#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    bool availRow[9][9];
    bool availColumn[9][9];
    bool availGrid[9][9];
    vector<pair<int, int>> spaces;

    void solveSudoku(vector<vector<char>>& board) {
        memset(availRow, false, sizeof(availRow));
        memset(availColumn, false, sizeof(availRow));
        memset(availGrid, false, sizeof(availRow));
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                char q = board[i][j];
                if (q == '.'){
                    spaces.emplace_back(i,j);
                }
                else {
                    availRow[i][q-'1'] = true;
                    availColumn[j][q - '1'] = true;
                    availGrid[(i / 3) * 3 + j / 3][q-'1']=true;
                }
            }
        }
        solve(board, 0);
    }
    bool solve(vector<vector<char>>& board, int index) {
        if (index==spaces.size())return true;
        auto[row, column] = spaces[index];
        for (char i = '1'; i <= '9';i++) {
            if (!(availRow[row][i-'1']||availColumn[column][i-'1'] || availGrid[(row / 3) * 3 + column / 3][i - '1'])) {
                board[row][column] = i;
                availRow[row][i - '1'] = true;
                availColumn[column][i - '1']=true;
                availGrid[(row / 3) * 3 + column / 3][i - '1']=true;
                if (solve(board,index+1))return true; 
                board[row][column] = '.';
                availRow[row][i - '1'] = false;
                availColumn[column][i - '1'] = false;
                availGrid[(row / 3) * 3 + column / 3][i - '1'] = false;
            }
        }
        return false;
    }
};

int main() {
    Solution s;
    vector<vector<char>> board = { {'5', '3', '.', '.', '7', '.', '.', '.', '.'}, {'6', '.', '.', '1', '9', '5', '.', '.', '.'}, {'.', '9', '8', '.', '.', '.', '.', '6', '.'}, {'8', '.', '.', '.', '6', '.', '.', '.', '3'}, {'4', '.', '.', '8', '.', '3', '.', '.', '1'}, {'7', '.', '.', '.', '2', '.', '.', '.', '6'}, {'.', '6', '.', '.', '.', '.', '2', '8', '.'}, {'.', '.', '.', '4', '1', '9', '.', '.', '5'}, {'.', '.', '.', '.', '8', '.', '.', '7', '9'} };
    s.solveSudoku(board);
    for (auto i : board) {
        for (char j : i)
            cout << j << " ";
        cout << endl;
    }
}
