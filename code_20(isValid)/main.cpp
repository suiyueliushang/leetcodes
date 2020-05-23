#include<iostream>
#include<string>
#include<stack>
using namespace std;
class Solution {
public:
	bool isValid(string s) {
		stack<char> stack;
		for(int i=0;i<s.length();i++){
			if(s[i]=='(' || s[i]=='{' || s[i]=='['){
				stack.push(s[i]);
				if(stack.size()>s.length()-i)
					return false;
			}
			else if (!stack.empty()){
				if(s[i]=='}' && stack.top()=='{')stack.pop();
				else if (s[i]==']'&& stack.top()=='[')stack.pop();
				else if (s[i]==')'&& stack.top()=='(')stack.pop();
				else return false;
			}
			else return false;
		}
		if(stack.empty())return true;
		return false;
		}
	bool isValid(string s) {
		int left[3]={0},right[3]={0};
		for(int i=0;i<s.length();i++){
			if(s[i]=='{'||s[i]=='['||s[i]=='(' )left++;
			else if(s[i]=='}'||s[i]==')'||s[i]==']')right++;
			if(left<right)return false;
		}
		if(left!=right)return false;
		left1=0;
		right=0;
		for(int i=s.length()-1;i>=0;i--){
				if(s[i]=='{'||s[i]=='['||s[i]=='(')left++;
				else if(s[i]=='}'||s[i]==')'||s[i]==']')right++;
				if(left>right)return false;
		}
		if(left==right)return true;
		return false;
	}
};

int main(){
	Solution s;
	cout<<s.isValid("()[]{}");
}