/*
    给定字符串 s 和 t ，判断 s 是否为 t 的子序列。

    字符串的一个子序列是原始字符串删除一些（也可以不删除）字符而不改变剩余字符相对位置形成的新字符串。
    （例如，"ace"是"abcde"的一个子序列，而"aec"不是）。
*/

/*
    s是否是t的子序列 = t删除一些字符后是否等于s

    判断s是否是t的子序列,所以t的长度大于s
    dp[i][j] 以s[i - 1]和t[j - 1]结尾的最长公共子序列的长度

    if (s[i - 1] == t[j - 1])，那么dp[i][j] = dp[i - 1][j - 1] + 1;
    因为找到了一个相同的字符，相同子序列长度自然要在dp[i-1][j-1]的基础上加1

    if (s[i - 1] != t[j - 1])，此时相当于t要删除元素，t如果把当前元素t[j - 1]删除，
    那么dp[i][j] 的数值就是 看s[i - 1]与 t[j - 2]的比较结果了，即：dp[i][j] = dp[i][j - 1];


    dp[i][j] 都依赖于dp[i - 1][j - 1] 和 dp[i][j - 1]
    所以 dp[0][0] = 0, dp[i][0] = 0  dp[0][j] = 0;

*/
#include<string>
#include<iostream>
#include<vector>

using namespace std;


class Solution {
public:
    bool isSubsequence(string s, string t) {
        vector<vector<int>> dp(s.size() + 1, vector<int>(t.size() + 1, 0));
        for(int  i = 1; i <= s.size(); i++){
            for(int j = 1; j <= t.size(); j++){
                if(s[i - 1] == t[j - 1]){
                    dp[i][j] = dp[i - 1][j- 1] + 1;
                }else{
                    dp[i][j] = dp[i][j - 1];
                }
            }
        }
        if(dp[s.size()][t.size()] == s.size()) 
            return true;
        return false;
    }
};

int main(){
    string s = "abc";
    string t = "ahbgdc";
    Solution so;
    cout << so.isSubsequence(s, t) << endl;
    return 0;
}