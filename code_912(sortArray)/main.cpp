#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class Solution {
public:
    /**
     * 选择排序，超出时间限制！！！
     */
    vector<int> sortArray_1(vector<int>& nums) {
        int length = nums.size();
        sort(nums.begin(), nums.end());
        for (int i = 0; i < length; i++) {
            int min = nums[i];
            int min_index = i;
            for (int j = i; j < length; j++) {
                if (nums[j] < min) {
                    min = nums[j];
                    min_index = j;
                }
            }
            nums[min_index] = nums[i];
            nums[i] = min;
        }
        return nums;
    }

    /**
     * 插入排序,超出时间限制
     */
    vector<int> sortArray_2(vector<int>& nums) {
        int temp, j, length = nums.size();
        for (int i = 1; i < length; i++) {
            temp = nums[i];
            for (j = i - 1; j >= 0 && nums[j] > temp; j--) {
                nums[j + 1] = nums[j];
            }
            nums[j + 1] = temp;
        }
        return nums;
    }

    /**
     * 冒泡排序,超出时间限制
     */
    vector<int> sortArray_3(vector<int>& nums) {
        int length = nums.size();
        for (int i = 0; i < length - 1; i++)
        {
            for (int j = 0; j < length - 1; j++)
            {
                if (nums[j] > nums[j + 1])
                {
                    int temp = nums[j + 1];
                    nums[j + 1] = nums[j];
                    nums[j] = temp;
                }
            }
        }
        return nums;
    }

    /**
    * 快速排序
    */
    vector<int> sortArray_3(vector<int>& nums) {
        int length = nums.size();
        if (length <= 1)
            return nums;
        else {
            int mid = length / 2;
            vector<int> l, r;
            memcpy(static_cast<void*>(&l), static_cast<void*>(&nums), sizeof(int) * mid);
            memcpy(static_cast<void*>(&r), static_cast<void*>(&nums+mid+1), sizeof(int) *(length-mid));
            vector<int> left = sortArray_3(l);
            vector<int> right = sortArray_3(r);
            int i, j;
            vector<int>res;
            for (i = 0, j = 0; i < mid && j < length - mid;) {
                if (left[i] > right[j]) {
                    res[i + j] = right[j];
                    j++;
                }
                else {
                    res[i + j] = left[i];
                    i++;
                }
            }
            if (i >= mid ) {
                for (; j < length - mid; j++)
                    res[i + j] = right[j];
            }
            else if(j>=length-mid){
                for (; i < mid; i++)
                    res[i + j] = left[i];
            }
            return res;
        }

    }

    int* sort_(int* a, int length) {
    }
};

int main() {
    vector<int>nums = { 5, 2, 3, 1 };
    Solution s;
    vector<int>res = s.sortArray_3(nums);
    for (int i = 0; i < res.size(); i++)
        cout << res[i] << " ";

}