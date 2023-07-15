/*
    你是一个专业的小偷，计划偷窃沿街的房屋。每间房内都藏有一定的现金，影响你偷窃的唯一制约因素就是相邻的房屋装有相互连通的防盗系统，
    如果两间相邻的房屋在同一晚上被小偷闯入，系统会自动报警。

    给定一个代表每个房屋存放金额的非负整数数组，计算你 不触动警报装置的情况下 ，一夜之内能够偷窃到的最高金额。

    输入：[1,2,3,1]
    输出：4
    解释：偷窃 1 号房屋 (金额 = 1) ，然后偷窃 3 号房屋 (金额 = 3)。
    偷窃到的最高金额 = 1 + 3 = 4 。
*/

/*
    关键点在于，当前的房屋是不是要偷，取决于前一个房屋是不是偷了，所以当前状态和前面状态有一种依赖关系，所以是dp问题
    dp[i] ：下标i以内（包括i）的房屋，能偷到的最大金额
    如果偷第i间房，那么dp[i] = dp[i - 2] + nums[i]
    如果不偷第i间房，那么dp[i] = dp[i - 1] 这里是考虑第i - 1间房是不是偷了，如果偷了，那么第i间房就不能偷了
    所以dp[i] = max(dp[i - 2] + nums[i], dp[i - 1])

    初始化： dp[0] = nums[0]; dp[1] = max(nums[0], nums[1]);

    遍历顺序：从前往后遍历，因为dp[i]依赖于dp[i - 1]和dp[i - 2]
*/
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;



class Solution {
public:
    int rob(vector<int>& nums) {
        if (nums.size() == 0) return 0;
        if (nums.size() == 1) return nums[0];
        vector<int> dp(nums.size(), 0);
        dp[0] = nums[0];
        dp[1] = max(nums[0], nums[1]);
        for(int i = 2; i < nums.size(); i++){
            dp[i] = max(dp[i - 1], dp[i - 2] + nums[i]);
        }
        return dp[nums.size() - 1];
    }
};

int main(){
    vector<int> nums = {1, 2, 3, 1};
    Solution s;
    cout << s.rob(nums) << endl;
    return 0;
}