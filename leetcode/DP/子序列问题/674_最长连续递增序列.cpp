/*
    给定一个未经排序的整数数组，找到最长且 连续递增的子序列，并返回该序列的长度。

    连续递增的子序列 可以由两个下标 l 和 r（l < r）确定，如果对于每个 l <= i < r，都有 nums[i] < nums[i + 1] ，
    那么子序列 [nums[l], nums[l + 1], ..., nums[r - 1], nums[r]] 就是连续递增子序列。
*/

/*
    dp[i]: 以nums[i]结尾的最长连续递增子序列的长度
    dp[i] = dp[i - 1]+1 if nums[i] > nums[i - 1]
    dp[i] = dp[i - 1] if nums[i] <= nums[i - 1]
*/


#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int findLengthOfLCIS(vector<int>& nums) {
        if(nums.size() <= 1) return nums.size();
        vector<int> dp(nums.size(), 1);
        int result = 0;

        for(int i = 1; i < nums.size(); i++){
            if(nums[i] > nums[i - 1])  // 与300题 不连续的递增子序列的不同就在这里，不需要遍历0到i-1的所有元素，
                                       // 只需要判断nums[i]和nums[i - 1]的大小关系即可，也不需要for循环，只需要一个if判断即可
                dp[i] = dp[i - 1] + 1;
            if(dp[i] > result) result = dp[i];
        }
        return result;
    }
};


int main(){
    vector<int> nums = {1,3,5,4,7};
    Solution s;
    cout << s.findLengthOfLCIS(nums) << endl;
    return 0;
}