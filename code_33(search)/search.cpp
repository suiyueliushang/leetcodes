class Solution
{
public:
	int search(vector<int> &nums, int target)
	{
		int len = nums.size();
		int left = 0, right = len - 1, mid;
		while (left <= right)
		{
			mid = (left + right) / 2;
			if (mid < len - 1 && nums[mid] > nums[mid + 1])
				break;
		}
	}
};