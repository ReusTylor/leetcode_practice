/*
    给你一个整数数组 coins ，表示不同面额的硬币；以及一个整数 amount ，表示总金额。

    计算并返回可以凑成总金额所需的 最少的硬币个数 。如果没有任何一种硬币组合能组成总金额，返回 -1 。

    你可以认为每种硬币的数量是无限的。

    输入：coins = [1, 2, 5], amount = 11
    输出：3 
    解释：11 = 5 + 5 + 1
*/

/*
    求最少的硬币个数，其实也是求组合数，然后求最小值，所以也是完全背包问题
    dp[i] ： 凑成i元的最少硬币个数
    dp[i] = min(dp[i], dp[i - coins[j]] + 1)
*/
#include<iostream>
#include<vector>
#include<limits.h>
using namespace std;


class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount + 1, INT_MAX);
        // 初始化时，需要将dp[i]都初始化成最大的数，否则就会在比较过程中被初始值覆盖
        // 所以下标非0的元素都应该是最大值
        dp[0] = 0;
        // 先遍历物品，再遍历背包
        for(int i = 0; i < coins.size(); i++){
            for(int j = coins[i]; j <= amount; j++){
                if(dp[j - coins[i]] != INT_MAX) // 如果dp[j - coins[i]]是初始值则跳过
                    dp[j] = min(dp[j], dp[j - coins[i]] + 1);
            }
        }

        if(dp[amount] == INT_MAX) return -1;
        return dp[amount];
    }
};

int main(){
    vector<int> coins = {1, 2, 5};
    int amount = 11;
    Solution s;
    cout << s.coinChange(coins, amount) << endl;
    return 0;
}