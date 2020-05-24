#include<iostream>
#include<unordered_map >
using namespace std;
class Solution {
public:
	/**
	 * 滑动窗口1.0版本
	 * 基础滑动窗口
	 * 最终超时，没办法通过
	 */
	// string minWindow(string s, string t) {
	// 	int slength=s.length();
	// 	int tlength=t.length();
	// 	if(slength*tlength==0 || slength<tlength)return "";
	// 	unordered_map <char,int>tchar,window;
	// 	tchar=count_string(t);
	// 	int left=0,right=tlength-1,min_left=-1,min_right=slength-1;
	// 	while(right<slength){
	// 		window=count_string(s.substr(left,right-left+1));
	// 		if(is_override(window,tchar)){
	// 			if(right-left<min_right-min_left){
	// 				min_left=left;
	// 				min_right=right;
	// 			}
	// 			left++;
	// 		}
	// 		else right++;
	// 	}
	// 	if(min_left==-1)return "";
	// 	else return s.substr(min_left,min_right-min_left+1);
	// }

	unordered_map <char,int> count_string(string s){
		unordered_map  <char,int> m;
		for(int i=0;i<s.length();i++)
		{
			if(m.find(s[i])==m.end())
				m[s[i]]=1;
			else m[s[i]]++;
		}
		return m;
	}
	bool is_override(unordered_map <char,int>unordered_map1,unordered_map <char,int>unordered_map2){
		unordered_map <char,int>::iterator iter2;
		for(iter2=unordered_map2.begin();iter2!=unordered_map2.end();iter2++){
			if(unordered_map1.count(iter2->first)==0||unordered_map1[iter2->first]<iter2->second)
				return false;
		}
		return true;
	}
	int char_in_t(string s,unordered_map <char,int>m,int *&r){
		r=new int [s.length()];
		int j=0;
		for(int i=0;i<s.length();i++){
			if(m.count(s[i])==1)
				r[j++]=i;
		}
		return j;
	}
	string minWindow(string s, string t) {
		int slength=s.length();
		int tlength=t.length();
		if(slength*tlength==0 || slength<tlength)return "";
		unordered_map <char,int>tchar;
		tchar=count_string(t);
		int *r;
		int rlength=char_in_t(s,tchar,r);
		if(rlength<tlength)return "";
		int left=0,right=tlength-1,min_left=-1,min_right=slength-1;
		while(left<=right&&right<rlength){
			unordered_map <char,int> window;
			for(int i=left;i<=right;i++){
				if(window.count(s[r[i]])==0)
					window[s[r[i]]]=1;
				else window[s[r[i]]]++;
			}
			if(is_override(window,tchar)){
				if(r[right]-r[left]<min_right-min_left){
					min_left=r[left];
					min_right=r[right];
				}
				left++;
			}
			else right++;
		}
		if(min_left==-1)return "";
		else return s.substr(min_left,min_right-min_left+1);
	}
};
#include<map>
int main(){
	map<char,int>a;
	a['a']++;
	cout<<a['b']<<endl;
}