#include <iostream>
#include <stack>
using namespace std;
class Solution
{
public:
	int calculate(string s)
	{
		stack<int> operand;
		stack<char> oper;
		int count = 0;
		char i;
		bool flag = false;
		for (int j = 0; j < s.length(); j++)
		{
			i = s[j];
			if (i >= '0' && i <= '9')
			{
				flag = true;
				count = count * 10 + int(i) - 48;
				if (j == s.length() - 1)
					operand.push(count);
			}
			else if (i == ' ')
			{
				if (flag)
				{
					operand.push(count);
					count = 0;
				}
				flag = false;
			}
			else if (i == '+' || i == '-')
			{
				flag = false;
				if (count != 0)
				{
					operand.push(count);
					count = 0;
				}
				if (!oper.empty())
				{
					int right = operand.top();
					operand.pop();
					int left = operand.top();
					operand.pop();
					char A = oper.top();
					oper.pop();
					operand.push(cal(left, right, A));
				}
			}
			else if (i == '*' || i == '/')
			{
				flag = false;
				if (!oper.empty() && oper.top() == '*' || oper.top() == '/')
				{
					char o = oper.top();
					oper.pop();
					int right = operand.top();
					operand.pop();
					int left = operand.top();
					operand.pop();
					char A = oper.top();
					operand.push(cal(left, right, o));
				}
				oper.push(i);
			}
		}
		while (!oper.empty())
		{
			int right = operand.top();
			operand.pop();
			int left = operand.top();
			operand.pop();
			char o = oper.top();
			oper.pop();
			operand.push(cal(left, right, o));
		}
		return operand.top();
	}
	int cal(int left, int right, char o)
	{
		switch (o)
		{
		case '+':
			return left + right;
		case '-':
			return left - right;
		case '*':
			return left + right;
		case '/':
			return left / right;
		default:
			return 0;
		}
	}
};