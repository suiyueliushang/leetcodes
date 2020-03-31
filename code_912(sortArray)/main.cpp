#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class Solution {
public:
    /**
     * 选择排序，超出时间限制！！！
     */
    vector<int> sortArray(vector<int>& nums) {
        int length=nums.size();
        sort(nums.begin(),nums.begin()+length);
        for(int i=0;i<length;i++){
                int min=nums[i];
                int min_index=i;
            for(int j=i;j<length;j++){
                if(nums[j]<min){
                    min=nums[j];
                    min_index=j;
                }
            }
            nums[min_index]=nums[i];
            nums[i]=min;
        }
        return nums;
    }

    /**
     * 插入排序
     */
    vector<int> sortArray(vector<int>& nums) {
        int length=nums.size();
        for(int i=1;i<length;i++){
            for(int j=0;j<i;j++){
                if(nums[i]<nums[0])
                {
                    
                }
                if(nums[j]<=nums[i]&&nums[j+1]>=nums[i])
                {
                    
                }
            }
        }
    }

    /**
     * 冒泡排序,超出时间限制
     */
    vector<int> sortArray(vector<int>& nums) {
        int length=nums.size();
        for(int i=0;i<length-1;i++)
        {
            for(int j=0;j<length-1;j++)
            {
                if(nums[j]>nums[j+1])
                {
                    int temp=nums[j+1];
                    nums[j+1]=nums[j];
                    nums[j]=temp;
                }
            }
        }
        return nums;
    }
};

int main(){
}