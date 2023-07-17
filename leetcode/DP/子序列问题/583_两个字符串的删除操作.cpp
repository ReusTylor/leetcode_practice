/*
    给定两个单词 word1 和 word2 ，返回使得 word1 和  word2 相同所需的最小步数。

    每步 可以删除任意一个字符串中的一个字符。

    输入: word1 = "sea", word2 = "eat"
    输出: 2
    解释: 第一步将 "sea" 变为 "ea" ，第二步将 "eat "变为 "ea"
*/

/*
    我的思考:
        求最大公共子序列的长度,除了最长公共子序列之外都是需要删除的,所以最小步数就是两个字符串的长度和减去最长公共子序列的长度
*/
#include<iostream>
#include<vector>
using namespace std;


class Solution {
public:
    int minDistance(string word1, string word2) {
        vector<vector<int>> dp(word1.size() + 1 , vector<int>(word2.size() + 1 , 0));

        for(int i = 1; i <= word1.size(); i++){
            for(int j = 1; j <= word2.size(); j++){
                if(word1[i - 1] == word2[j - 1]){
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                }else{
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                }
            
            }
        }
        return word1.size() + word2.size() - 2 * dp[word1.size()][word2.size()];

    }
};

int main(){
    string word1 = "sea", word2 = "eat";
    Solution ss;
    cout << ss.minDistance(word1, word2) << endl;
    return 0;
}