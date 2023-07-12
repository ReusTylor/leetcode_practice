/*
    给定一个正整数 n ，将其拆分为 k 个 正整数 的和（ k >= 2 ），并使这些整数的乘积最大化。

    返回 你可以获得的最大乘积 。
    输入: n = 2
    输出: 1
    解释: 2 = 1 + 1, 1 × 1 = 1。
*/

/*
    1. dp[i]：拆分i时能得到的最大乘积为dp[i]
    2. dp[i] = max(dp[i], max(dp[i-j]*j, i*(i-j)));
    3. 初始化
    4. 遍历顺序，先有dp[i-j]再有dp[i]
    5. 枚举验证
*/


// 这个题目的重点在于遍历中约束条件的思考
// 递推公式的思考，注意max只能有两个参数
#include<iostream>
#include<vector>
#include<iostream>
using namespace std;

class Solution {
public:
    int integerBreak(int n) {
        vector<int> dp(n + 1);
        dp[2] = 1;

        for(int i = 3; i <= n; i++){
            // j的结束条件是 j < i - 1 ，其实 j < i 也是可以的，不过可以节省一步
            // 例如让j = i - 1，的话，其实在 j = 1的时候，这一步就已经拆出来了，重复计算，所以 j < i - 1
            for(int j = 1; j <= i - 1; j++){
                dp[i] = max(dp[i], max(dp[i - j] * j, j* (i - j)));
            }
        }

        return dp[n];
    }
};

int main(){
    Solution s;
    int result = s.integerBreak(4);
    cout << result << endl;
    return 0;
}