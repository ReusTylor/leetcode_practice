/*
    给你一个字符串 s ，找出其中最长的回文子序列，并返回该序列的长度。

    子序列定义为：不改变剩余字符顺序的情况下，删除某些字符或者不删除任何字符形成的一个序列。

*/
/*
    dp[i][j]：字符串s在[i, j]范围内最长的回文子序列的长度为dp[i][j]。

    s[i]与s[j]相同，那么dp[i][j] = dp[i + 1][j - 1] + 2;
    s[i] != s[j]     dp[i][j] = max(dp[i + 1][j], dp[i][j - 1]);


    遍历i的时候一定要从下到上遍历，这样才能保证下一行的数据是经过计算的
    j 可以正常从左到有遍历
*/

#include<iostream>
#include<vector>
using namespace std;


class Solution {
public:
    int longestPalindromeSubseq(string s) {
        vector<vector<int>> dp(s.size(), vector<int>(s.size(), 0));
        for (int i = 0; i < s.size(); i++) dp[i][i] = 1;
        for (int i = s.size() - 1; i >= 0; i--) {
            for (int j = i + 1; j < s.size(); j++) {
                if (s[i] == s[j]) {
                    dp[i][j] = dp[i + 1][j - 1] + 2;
                } else {
                    dp[i][j] = max(dp[i + 1][j], dp[i][j - 1]);
                }
            }
        }
        return dp[0][s.size() - 1];
    }
};
