class Solution
{
public:
	void nextPermutation(vector<int> &nums)
	{
		int length = nums.size();
		int i = length - 2, j = length - 1;
		for (; i >= 0 && nums[i] >= nums[i + 1]; i--)
			;
		if (i >= 0)
		{
			for (; j > i && nums[i] >= nums[j]; j--)
				;
			int temp = nums[i];
			nums[i] = nums[j];
			nums[j] = temp;
			i++;
		}
		else
			i = 0;
		j = length - 1;
		for (; i < j; i++, j--)
		{
			int temp = nums[i];
			nums[i] = nums[j];
			nums[j] = temp;
		}
	}
};