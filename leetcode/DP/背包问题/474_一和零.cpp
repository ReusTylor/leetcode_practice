/*
    给你一个二进制字符串数组 strs 和两个整数 m 和 n 。

    请你找出并返回 strs 的最大子集的长度，该子集中 最多 有 m 个 0 和 n 个 1 。

    如果 x 的所有元素也是 y 的元素，集合 x 是集合 y 的 子集 。

    输入：strs = ["10", "0001", "111001", "1", "0"], m = 5, n = 3
    输出：4
    解释：最多有 5 个 0 和 3 个 1 的最大子集是 {"10","0001","1","0"} ，因此答案是 4 。
    其他满足题意但较小的子集包括 {"0001","1"} 和 {"10","1","0"} 。{"111001"} 不满足题意，因为它含 4 个 1 ，大于 n 的值 3 。
*/

/*
 相当于两个维度的01背包
 strs数组中的元素就是物品，每个物品都是1个

 dp[i][j] ： 表示有i个0，j个1的最大子集的长度
 dp[i][j]的来源是 dp[i - zeroNum][j - oneNum] + 1， 比较与dp[i][j]的大小，取最大值
 dp[i][j] = max(dp[i][j], dp[i - zeroNum][j - oneNum] + 1)



 01背包的递推公式：dp[j] = max(dp[j], dp[j - weight[i]] + value[i]);
 对比一下就会发现，字符串的zeroNum和oneNum相当于物品的重量（weight[i]），字符串本身的个数相当于物品的价值（value[i]）
*/


#include<iostream>
#include<vector>
#include<string>
using namespace std;

class Solution {
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));

        for(string str : strs){// 先遍历物品，对物品进行操作，统计物品的重量，也就是zeroNum和oneNum
            int oneNum = 0; 
            int zeroNum = 0;

            for(char c : str){
                if(c == '0')
                    zeroNum++;
                else oneNum++;
            }

            // 两个维度的背包，因此都是从后往前遍历
            for(int i = m; i >= zeroNum; i--){
                for(int j = n; j >= oneNum; j--){
                    dp[i][j] = max(dp[i][j], dp[i - zeroNum][j - oneNum] + 1);
                }
            }
        }
        return dp[m][n];
    }
};

int main(){
    vector<string> strs = {"10", "0001", "111001", "1", "0"};
    int m = 5, n = 3;
    Solution s;
    cout << s.findMaxForm(strs, m, n) << endl;
    return 0;
}