#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
	int surfaceArea(vector<vector<int>>& grid) {
		int length=grid.size();
		int area=0;
		for(int i=0;i<length;i++)
			for(int j=0;j<length;j++)
					if(grid[i][j]>0){
						area+=2;
						area+=grid[i][j]<<2;
						area-=i>0?(grid[i][j]>grid[i-1][j]?grid[i-1][j]:grid[i][j])<<1:0;
						area-=j>0?(grid[i][j]>grid[i][j-1]?grid[i][j-1]:grid[i][j])<<1:0;
					}
		return area;
	}
};