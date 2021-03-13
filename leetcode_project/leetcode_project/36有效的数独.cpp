#include <vector>
#include <set>
using namespace std;

class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        set<char>column[9];
        set<char>row[9];
        set<char> grid[9];

        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                char a = board[i][j];
                if (a != '.') {
                    if (row[i].count(a) || column[j].count(a) || grid[(i / 3) * 3 + j / 3].count(a))return false;
                    row[i].insert(a);
                    column[j].insert(a);
                    grid[(i / 3) * 3 + j / 3].insert(a);
                }
            }
        }
        return true;
    }
};