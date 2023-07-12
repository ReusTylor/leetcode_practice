/*
    给你一个由 不同 整数组成的数组 nums ，和一个目标整数 target 。请你从 nums 中找出并返回总和为 target 的元素组合的个数。
    题目数据保证答案符合 32 位整数范围。

    输入：nums = [1,2,3], target = 4
    输出：7
    解释：
    所有可能的组合为：
    (1, 1, 1, 1)
    (1, 1, 2)
    (1, 2, 1)
    (1, 3)
    (2, 1, 1)
    (2, 2)
    (3, 1)
    请注意，顺序不同的序列被视作不同的组合。

*/

/*
    顺序不同的序列视作不同的组合，求的是排列的值
    
    dp[i]: 总和为i的元素组合的个数
    dp[i] = dp[i] + dp[i - nums[j]]

*/

// 如果求组合数就是外层循环遍历物品，内层遍历背包
// 如果求排列数就是外层遍历背包，内层遍历物品
// 本题是求排列数，所以将target（背包）放在外层循环，将nums(物品)放在内层循环
#include<iostream>
#include<vector>
#include<limits.h>
using namespace std;

class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        vector<int> dp(target + 1, 0);
        dp[0] = 1;
        
        for(int i = 0; i <= target; i++){
            for(int j = 0; j < nums.size(); j++){
                // 注意这里的条件判断
                if(i - nums[j] >= 0 )
                    dp[i] += dp[i - nums[j]];
            }
        }
        return dp[target];
    }
};

int main(){
    vector<int> nums = {1, 2, 3};
    int target = 4;
    Solution s;
    cout << s.combinationSum4(nums, target) << endl;
    return 0;
}