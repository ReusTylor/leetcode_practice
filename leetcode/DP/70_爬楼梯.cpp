/*
    假设你正在爬楼梯。需要 n 阶你才能到达楼顶。
    每次你可以爬 1 或 2 个台阶。你有多少种不同的方法可以爬到楼顶呢？
    
    输入：n = 2
    输出：2
    解释：有两种方法可以爬到楼顶。
    1. 1 阶 + 1 阶
    2. 2 阶
*/

/*
    关键点在于dp[0]的确定，当我们dp[0] = 0时，前三个数并不符合dp[n] = dp[n - 1] + dp[n - 2]的规律
    所以可以初始化dp[0] = 0, dp[1] = 1, dp[2] = 2
    之后符合规律的dp[n] = dp[n - 1] + dp[n - 2]
*/
#include<iostream>
#include<vector>   
using namespace std;

class Solution{
public:
    int climbStairs(int n){
        vector<int> dp(n + 1);
        if(n <= 2) return n;
        dp[0] = 0;
        dp[1] = 1;
        dp[2] = 2;
        //dp[n] n阶台阶有dp[n]种方法
        for(int i = 3; i <= n; i++){
            dp[i] = dp[i - 1] + dp[i - 2];
        }
        return dp[n];
    }

    int great_climbStairs(int n){
        vector<int> dp(3);
        if(n <= 2) return n;
        dp[1] = 1;
        dp[2] = 2;
        for(int i = 3; i <= n; i++){
            int sum = dp[1] + dp[2];
            dp[1] = dp[2];
            dp[2] = sum;
        }
        // 注意返回值
        return dp[2];
    }
};

int main(){
    int n;
    cin >> n;
    Solution s;
    int result = s.great_climbStairs(n);
    cout << result << endl;
}