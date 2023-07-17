/*
    给你两个字符串 s 和 t ，统计并返回在 s 的 子序列 中 t 出现的个数。

    题目数据保证答案符合 32 位带符号整数范围。


    输入：s = "rabbbit", t = "rabbit"
    输出：3
    解释：
    如下所示, 有 3 种可以从 s 中得到 "rabbit" 的方案。
    rabbbit 1234 67
    rabbbit 12 4567
    rabbbit 123 567

    字符串的一个 子序列 是指，通过删除一些（也可以不删除）字符且不干扰剩余字符相对位置所组成的新字符串。
    （例如，"ACE" 是 "ABCDE" 的一个子序列，而 "AEC" 不是）
*/

/*
    dp[i][j]：以i-1为结尾的s子序列中出现以j-1为结尾的t的个数为dp[i][j]。

    s[i - 1] == t[j - 1]
        1. 用s[i - 1] 来匹配 dp[i - 1][j - 1]  即不需要考虑当前s子串和t子串的最后一位字母, 所以只需要dp[i - 1][j - 1]
        2. 不用s[i-1]来匹配,个数为dp[i - 1][j]
    我们求的是 s 中有多少个 t，而不是 求t中有多少个s，所以只考虑 s中删除元素的情况，即 不用s[i - 1]来匹配 的情况。
*/

/*
    初始化:
    dp[i][0]表示什么呢？

    dp[i][0] 表示：以i-1为结尾的s可以随便删除元素，出现空字符串的个数。

    那么dp[i][0]一定都是1，因为也就是把以i-1为结尾的s，删除所有元素，出现空字符串的个数就是1。

    再来看dp[0][j]，dp[0][j]：空字符串s可以随便删除元素，出现以j-1为结尾的字符串t的个数。

    那么dp[0][j]一定都是0，s如论如何也变成不了t。

    最后就要看一个特殊位置了，即：dp[0][0] 应该是多少。

    dp[0][0]应该是1，空字符串s，可以删除0个元素，变成空字符串t。
*/

#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int numDistinct(string s, string t) {
        vector<vector<uint64_t>> dp(s.size() + 1, vector<uint64_t>(t.size() + 1));
        for(int i = 0; i < s.size() ; i++) dp[i][0] = 1;
        for(int j = 1; j < t.size() ; j++) dp[0][j] = 0;
        for(int i = 1; i <= s.size(); i++){
            for(int j = 1; j <= t.size(); j++){
                if(s[i - 1] == t[j - 1]){
                    dp[i][j] = dp[i -1][j - 1] + dp[i - 1][j];
                }else{
                    dp[i][j] = dp[i - 1][j];
                }
            }
        }
        return dp[s.size()][t.size()];
    }
};

int main(){
    string s = "rabbbit", t = "rabbit";
    Solution ss;
    cout << ss.numDistinct(s, t) << endl;
    return 0;
}