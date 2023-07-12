/*
    给你一个整数数组 nums 和一个整数 target 。

    向数组中的每个整数前添加 '+' 或 '-' ，然后串联起所有整数，可以构造一个 表达式 ：

    例如，nums = [2, 1] ，可以在 2 之前添加 '+' ，在 1 之前添加 '-' ，然后串联起来得到表达式 "+2-1" 。

    返回可以通过上述方法构造的、运算结果等于 target 的不同 表达式 的数目。

    输入：nums = [1,1,1,1,1], target = 3
    输出：5
    解释：一共有 5 种方法让最终目标和为 3 。
    -1 + 1 + 1 + 1 + 1 = 3
    +1 - 1 + 1 + 1 + 1 = 3
    +1 + 1 - 1 + 1 + 1 = 3
    +1 + 1 + 1 - 1 + 1 = 3
    +1 + 1 + 1 + 1 - 1 = 3

*/

// 转动态规划   加法的总和为x，那么减法总和为sum - x，也就是x - (sum - x) = target
// 也就是x = (target + sum) /2
// 此时问题转化为装满容量为x的背包有几种方法
// 
// 本题是装满有多少种方法，是一个组合问题
// 此类问题的递推公式为 dp[j] = dp[j] + dp[j - nums[i]];
/*
    1. dp[j] 表示填满容量为j的背包 有dp[j]种方法
    2. dp[j] = dp[j] + dp[j - nums[i]];
        例如：dp[j]，j 为5，

        已经有一个1（nums[i]） 的话，有 dp[4]种方法 凑成 容量为5的背包。
        已经有一个2（nums[i]） 的话，有 dp[3]种方法 凑成 容量为5的背包。
        已经有一个3（nums[i]） 的话，有 dp[2]中方法 凑成 容量为5的背包
        已经有一个4（nums[i]） 的话，有 dp[1]中方法 凑成 容量为5的背包
        已经有一个5 （nums[i]）的话，有 dp[0]中方法 凑成 容量为5的背包
    3. 初始化
        dp[0] = 1
    4. 遍历顺序，先遍历物品，再遍历背包，在这里相当于nums在外，target在内
*/
#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int sum = 0;
        for(int num : nums){
            sum += num;
        }
        if(abs(target) > sum) return 0;
        if((target + sum) % 2 == 1) return 0;

        int bagSize = (target + sum ) / 2;
        vector<int> dp(bagSize + 1, 0);
        dp[0] = 1;
        for(int i = 0; i < nums.size(); i++){
            for(int j = bagSize; j >= nums[i]; j--){
                dp[j] += dp[j - nums[i]];
            }
        }
        return dp[bagSize];
    }
};

int main(){
    Solution s;
    vector<int> nums = {1,1,1,1,1};
    int target = 3;
    int result = s.findTargetSumWays(nums, target);
    cout << result << endl;
    return 0;

}