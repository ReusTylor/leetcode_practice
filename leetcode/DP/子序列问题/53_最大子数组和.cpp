/*
    给你一个整数数组 nums ，请你找出一个具有最大和的连续子数组（子数组最少包含一个元素），返回其最大和。
    子数组 是数组中的一个连续部分。

    输入：nums = [-2,1,-3,4,-1,2,1,-5,4]
    输出：6
    解释：连续子数组 [4,-1,2,1] 的和最大，为 6 
    
*/
/*
    dp[i]：  以nums[i]为结尾的最大连续子数组的和
    dp[i] 的两种情况（因为要求是必须连续的子数组，所以如果不选nums[i]的话，那么dp[i]是不能等于dp[i - 1]的，因为这种情况下就不连续了。
    ****************************
    nums[i]是一定要选的
    ****************************
        1. dp[i - 1] + nums[i]，即：nums[i]加入当前连续子序列和
        2. nums[i]，即：从头开始计算当前连续子序列和
    dp[i] = max(dp[i - 1] + nums[i], nums[i])

    dp[0]应为nums[0]即dp[0] = nums[0]。

    递推公式中dp[i]依赖于dp[i - 1]的状态，需要从前向后遍历
*/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        if (nums.size() == 0) return 0;
        vector<int> dp(nums.size());
        dp[0] = nums[0];
        int result = dp[0];
        for (int i = 1; i < nums.size(); i++) {
            dp[i] = max(dp[i - 1] + nums[i], nums[i]); // 状态转移公式
            if (dp[i] > result) result = dp[i]; // result 保存dp[i]的最大值
        }
        return result;
    }
};

int main(){
    vector<int> nums = {-2,1,-3,4,-1,2,1,-5,4};
    Solution s;
    cout << s.maxSubArray(nums) << endl;
    return 0;
}

