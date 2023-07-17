/*
    给你两个单词 word1 和 word2， 请返回将 word1 转换成 word2 所使用的最少操作数  。

    你可以对一个单词进行如下三种操作：

    插入一个字符
    删除一个字符
    替换一个字符

    输入：word1 = "horse", word2 = "ros"
    输出：3
    解释：
    horse -> rorse (将 'h' 替换为 'r')
    rorse -> rose (删除 'r')
    rose -> ros (删除 'e')
*/

/*
    dp[i][j] 表示以下标i-1为结尾的字符串word1，和以下标j-1为结尾的字符串word2，最近编辑距离为dp[i][j]

    递推公式:
    几种编辑操作:
        if (word1[i - 1] == word2[j - 1])
            不操作
        if (word1[i - 1] != word2[j - 1])
            增
            删
            换
    if(word1[i - 1] == word2[j - 1]) 不用任何编辑
        dp[i][j] = dp[i - 1][j - 1]
    if (word1[i - 1] != word2[j - 1])
        操作一:word1删除一个元素, 那么就是以下标i - 2为结尾的word1 与 j-1为结尾的word2的最近编辑距离 再加上一个操作。
            即 dp[i][j] = dp[i - 1][j] + 1;
        操作二:word2删除一个元素，那么就是以下标i - 1为结尾的word1 与 j-2为结尾的word2的最近编辑距离 再加上一个操作.
            即 dp[i][j] = dp[i][j - 1] + 1;
        注: 删除一个元素可以相当于另一个字符串增加一个元素
        操作三:替换元素，word1替换word1[i - 1]，使其与word2[j - 1]相同，此时不用增删加元素。
            即 dp[i][j] = dp[i - 1][j - 1] + 1;
        取较小的
            dp[i][j] = min({dp[i - 1][j - 1], dp[i - 1][j], dp[i][j - 1]}) + 1;

    初始化:
        dp[i][0] ：以下标i-1为结尾的字符串word1，和空字符串word2，最近编辑距离为dp[i][0]。
        那么dp[i][0]就应该是i，对word1里的元素全部做删除操作，即：dp[i][0] = i;

        同理dp[0][j] = j;

*/

#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;


class Solution {
public:
    int minDistance(string word1, string word2) {
        vector<vector<int>> dp(word1.size() + 1, vector<int>(word2.size() + 1, 0));
        for (int i = 0; i <= word1.size(); i++) dp[i][0] = i;
        for (int j = 0; j <= word2.size(); j++) dp[0][j] = j;
        for (int i = 1; i <= word1.size(); i++) {
            for (int j = 1; j <= word2.size(); j++) {
                if (word1[i - 1] == word2[j - 1]) {
                    dp[i][j] = dp[i - 1][j - 1];
                }
                else {
                    dp[i][j] = min({dp[i - 1][j - 1], dp[i - 1][j], dp[i][j - 1]}) + 1;
                }
            }
        }
        return dp[word1.size()][word2.size()];
    }
};

int main(){
    string word1 = "horse", word2 = "ros";
    Solution s;
    cout << s.minDistance(word1, word2) << endl;
    return 0;
}
