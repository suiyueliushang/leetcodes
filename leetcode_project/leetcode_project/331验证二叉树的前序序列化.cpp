#include <iostream>
#include <vector>
#include <string>
using namespace std;
#pragma warning(disable : 4996)
class Solution {
public:
    bool isValidSerialization(string preorder) {
        if (preorder.size() == 0)return true;
        vector<int>slot = {1};
        char* a=new char(preorder.size()+1),*p;
        const char* delim = ",";
        strcpy(a, preorder.c_str());
        p=strtok(a,delim);
        while (p) {
            if (slot.empty())return false;
            if (p[0] == '#') {                
                slot.back() -= 1;
                if (!slot.back())slot.pop_back();
            }
            else {
                slot.back() -= 1;
                if (!slot.back())slot.pop_back();
                slot.push_back(2);
            }
            p = strtok(NULL, delim);
        }
        if (!slot.empty())return false;
        return true;
    }
    bool isValidSerialization1(string preorder) {
        int length = preorder.length();
        int count = 1,i=0;
        while (i < length) {
            if (preorder[i] == ',') {
                i++;
                continue;
            }
            else {
                if (count <= 0)return false;
                if (preorder[i] == '#') {
                    count--;
                    i++;
                }
                else {
                    while (preorder[i++] != ',');
                    count++;
                }
            }
        }
        if (!count)return false;
        return true;
    }
};