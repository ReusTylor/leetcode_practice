/*
    给你一个整数 n ，返回 和为 n 的完全平方数的最少数量 。

    完全平方数 是一个整数，其值等于另一个整数的平方；换句话说，其值等于一个整数自乘的积。例如，1、4、9 和 16 都是完全平方数，而 3 和 11 不是。

    1 <= n <= 10^4

    输入：n = 12
    输出：3 
    解释：12 = 4 + 4 + 4
*/

/*
    题目翻译：完全平方数相当于物品（可以重复使用）， n相当于背包，求凑满这个背包最少有多少物品
*/
#include<iostream>
#include<vector>
#include<algorithm>
#include<climits>
using namespace std;

class Solution {
public:
    int numSquares(int n) {
        vector<int> nums;
        // 第一次这里写成了 i*i < 1, 实际上应为<=1
        for(int i = 0; i * i <= n; i++){
            nums.push_back(i * i);
        }
        // 此时nums就是物品，可以重复使用，从小到大排列
        // 因为要取dp最小值，所以要将dp初始化为最大值
        vector<int> dp(n + 1, INT_MAX);
        dp[0] = 0;
        
        // 先遍历背包，再遍历物品，从小到达遍历物品（可重复使用）
        for(int i = 0; i <= n; i++){// 遍历背包
            for(int j = 1; j < nums.size(); j++){ // 遍历物品
                if(i - nums[j] >= 0)
                    dp[i] = min(dp[i], dp[i - nums[j]] + 1);
            }
        }
        return dp[n];
    }
};

int main(){
    Solution s;
    cout << s.numSquares(12) << endl;
    return 0;
}