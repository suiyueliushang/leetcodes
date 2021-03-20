class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> s;
        for(string& i:tokens){
            if(i!="+"&&i!="-"&&i!="*"&&i!="/"){
                s.push(atoi(i.c_str()));
            }
            else{
                int right=s.top();
                s.pop();
                int left=s.top();
                s.pop();
                switch(i[0]){
                    case'+':
                        s.push(left+right);
                        break;
                    case '-':
                        s.push(left-right);
                        break;
                    case '*':
                        s.push(left*right);
                        break;
                    default:
                        s.push(left/right);
                }
            }
        }
        return s.top();
    }
};