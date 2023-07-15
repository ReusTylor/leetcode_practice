/*
    给定一个数组 prices ，它的第 i 个元素 prices[i] 表示一支给定股票第 i 天的价格。

    你只能选择 某一天 买入这只股票，并选择在 未来的某一个不同的日子 卖出该股票。设计一个算法来计算你所能获取的最大利润。

    返回你可以从这笔交易中获取的最大利润。如果你不能获取任何利润，返回 0 。

    输入：[7,1,5,3,6,4]
    输出：5
    解释：在第 2 天（股票价格 = 1）的时候买入，在第 5 天（股票价格 = 6）的时候卖出，最大利润 = 6-1 = 5 。
        注意利润不能是 7-1 = 6, 因为卖出价格需要大于买入价格；同时，你不能在买入前卖出股票。

*/

/*
    贪心
*/
#include <iostream>
#include <vector>
#include <algorithm>
#include<limits.h>

using namespace std;


class Solution {
public:
    int maxProfit(vector<int>& prices){
        int low = INT_MAX;
        int result = 0;
        for(int i = 0; i < prices.size(); i++){
            low = min(low, prices[i]); // 取左边的最小价格
            result  = max(result, prices[i] - low); // 直接取最大区间的利润
        }
        return result;
    }
};


/*dp
    1. dp[i][0]表示第i天持有股票所得最多现金。
       dp[i][1]表示第i天不持有股票所得最多现金。 
    2. 递推公式
       如果第i天持有股票，即dp[i][0]，那么可以由两个状态推导出来。
        第 i - 1 天持有股票，那么就保持现状，所得现金就是昨天持有股票所得现金
            dp[i-1][0]
        第i天买入股票，所得现金就是买入今天的股票后所得现金 -prices[i];
        dp[i][0] = max(dp[i - 1][0], -prices[i]);
       如果第i天不持有股票 dp[i][1]
        第i-1天就不持有股票，那么就保持现状，所得现金就是昨天不持有股票的所得现金 即：dp[i - 1][1]
        第i天卖出股票，所得现金就是按照今天股票价格卖出后所得现金即：prices[i] + dp[i - 1][0]
       同样dp[i][1]取最大的，dp[i][1] = max(dp[i - 1][1], prices[i] + dp[i - 1][0]);
*/