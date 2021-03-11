#include <iostream>
#include <vector>
using namespace std;
class Solution
{
public:
	int calculate(string s)
	{
		int length = s.length(), num = 0;
		char preOper = '+', a;
		vector<int> operand;
		for (int i = 0; i < length; i++)
		{
			a = s[i];
			if (isdigit(a))
				num = num * 10 + int(a - '0');
			else if (!isdigit(a) && a != ' ' || i == length - 1)
			{
				switch (preOper)
				{
				case '+':
					operand.push_back(num);
					break;
				case '-':
					operand.push_back(-num);
					break;
				case '*':
					operand.back() *= num;
					break;
				default:
					operand.back() /= num;
				}
				num = 0;
				preOper = a;
			}
		}
		int res = 0;
		for (int i : operand)
		{
			res += i;
		}
		return res;
	}
};
