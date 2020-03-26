#include<vector>
#include<iostream>

using namespace std;

class Solution {
public:
    int numRookCaptures(vector<vector<char>>& board) {
        int posX,posY,num=0;
        for(int i=0;i<8;i++)
            for(int j=0;j<8;j++)
                if (board[i][j]=='R')
                    {
                        posX=i;
                        posY=j;
                    }
        for(int j=posY;j<8;j++){
            if (board[posX][j]=='B')
                break;
            else
                if (board[posX][j]=='p')
                    {
                    num++;
                    break;
                }
        }
        for(int j=0;j<posY;j++){
            if (board[posX][j]=='B')
                break;
            else
                if (board[posX][j]=='p')
                    {
                    num++;
                    break;
                }
        }
        for(int i=0;i<posX;i++)
        {
            if (board[i][posY]=='B')
                break;
            else
                if (board[i][posY]=='p')
                {
                    num++;
                    break;
                }
        }
        for(int i=8;i>posX;i--)
        {
            if (board[i][posY]=='B')
                break;
            else
                if (board[i][posY]=='p')
                {
                    num++;
                    break;
                }
        }
        }
};