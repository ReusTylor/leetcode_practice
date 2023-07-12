/*
    给你一个整数数组 coins 表示不同面额的硬币，另给一个整数 amount 表示总金额。

    请你计算并返回可以凑成总金额的硬币组合数。如果任何硬币组合都无法凑出总金额，返回 0 。

    假设每一种面额的硬币有无限个。 

    题目数据保证结果符合 32 位带符号整数。


    输入：amount = 5, coins = [1, 2, 5]
    输出：4
    解释：有四种方式可以凑成总金额：
    5=5
    5=2+2+1
    5=2+1+1+1
    5=1+1+1+1+1
*/

// 因为每一种面额有无限个，所以是完全背包问题, 求组合数，想到组合数的常用第推公式：dp[i] = dp[i] + dp[i - coins[j]]
/*
    dp[i]:凑成i元的硬币组合数
    dp[i] = dp[i] + dp[i - coins[j]]
*/


#include<iostream>
#include<vector>
using namespace std;


class Solution {
public:
    int change(int amount, vector<int>& coins) {
        vector<int> dp(amount + 1, 0);
        // 必须初始化dp[0] = 1，否则后面所有都为0
        dp[0] = 1;
        
        for(int i = 0; i < coins.size(); i++){
            for(int j = coins[i]; j <= amount; j++){
                dp[j] += dp[j - coins[i]];
            }
        }
        return dp[amount];

    }
};

int main(){
    int amount = 5;
    vector<int> coins = {1, 2, 5};
    Solution s;
    cout << s.change(amount, coins) << endl;
    return 0;
}