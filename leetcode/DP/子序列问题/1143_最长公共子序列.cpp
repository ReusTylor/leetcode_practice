/*
    给定两个字符串 text1 和 text2，返回这两个字符串的最长 公共子序列 的长度。如果不存在 公共子序列 ，返回 0 。

    一个字符串的 子序列 是指这样一个新的字符串：它是由原字符串在不改变字符的相对顺序的情况下删除某些字符（也可以不删除任何字符）后组成的新字符串。

    例如，"ace" 是 "abcde" 的子序列，但 "aec" 不是 "abcde" 的子序列。

    两个字符串的 公共子序列 是这两个字符串所共同拥有的子序列。

    输入：text1 = "abcde", text2 = "ace" 
    输出：3  
    解释：最长公共子序列是 "ace" ，它的长度为 3 。
*/

// 与718的区别在于不要求连续 但是要求相对顺序一致
/*
    dp[i][j]：长度为[0, i - 1]的字符串text1与长度为[0, j - 1]的字符串text2的最长公共子序列为dp[i][j]

    2. 递推公式
         text1[i - 1] 与 text2[j - 1]相同
            dp[i][j] = dp[i-1][j-1] + 1;
         text1[i - 1] 与 text2[j - 1]不相同
            那么就看text[0, i-2] 与 text2[0, j - 1]的最长公共子序列 和 text1[0, i - 1]与text2[0, j - 2]的最长公共子序列，取最大的。
    即：dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);

    3. 初始化
        text[0, i-1]和空串的最长公共子序列自然是0
        dp[i][0] = 0;
        dp[0][j] = 0;
    
*/
#include<vector>
#include<iostream>
#include<algorithm>
using namespace std;

class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        vector<vector<int>> dp(text1.size() + 1, vector<int> (text2.size() + 1, 0));
        for(int i = 1; i <= text1.size(); i++){
            for(int j = 1; j <= text2.size(); j++){
                if(text1[i - 1] == text2[j - 1]){
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                }else{
                    dp[i][j] = max(dp[i][j - 1],dp[i - 1][j]);
                }
            }
        }    
        return dp[text1.size()][text2.size()];
    }
};

int main(){
    string text1 = "abcde";
    string text2 = "ace";
    Solution s;
    cout << s.longestCommonSubsequence(text1, text2) << endl;
    return 0;
}