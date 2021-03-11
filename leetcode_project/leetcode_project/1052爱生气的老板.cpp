#include<iostream>  
#include<vector>
using namespace std;

class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int X) {
        int length = customers.size(), base = 0, increase = 0, maxincrease = 0;
        for (int i = 0; i < length; i++)
            base += customers[i] * !grumpy[i];
        for (int i = 0; i < X; i++) {
            maxincrease += customers[i] * grumpy[i];
        }
        increase = maxincrease;
        for (int i = 0, j = X; j < length; i++, j++)
        {
            increase += customers[j] * grumpy[j] - customers[i] * grumpy[i];
            maxincrease = increase > maxincrease ? increase : maxincrease;
        }
        return maxincrease + base;
    }
};