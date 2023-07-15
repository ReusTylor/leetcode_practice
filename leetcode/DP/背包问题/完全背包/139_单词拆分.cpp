/*
    给你一个字符串 s 和一个字符串列表 wordDict 作为字典。请你判断是否可以利用字典中出现的单词拼接出 s 。

    注意：不要求字典中出现的单词全部都使用，并且字典中的单词可以重复使用。

    输入: s = "leetcode", wordDict = ["leet", "code"]
    输出: true
    解释: 返回 true 因为 "leetcode" 可以由 "leet" 和 "code" 拼接成。
*/

/*
    单词物品，字符串就是背包，单词能否组成字符串s，就是问物品能不能把背包装满，拆分时可以重复使用单词，说明是一个完全背包
    dp[i]表示字符串s的前i个字符能否被拆分成字典中的单词

    递推公式：如果dp[j]是true，且[j,i]这个区间的子串出现在字典中，那么dp[i]就是true (j < i)
    所以递推公式为：dp[i] = dp[j] && [j,i]这个区间的子串出现在字典中

    初始化dp[0] = true
    
    这里应该求的是排列数，先遍历背包，再遍历物品，
*/

#include<iostream>
#include<string>
#include<vector>
#include<algorithm>

using namespace std;


class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        vector<bool> dp(s.size() + 1, false); // dp[i]表示字符串s的前i个字符能否被拆分成字典中的单词
        dp[0] = true;

        for(int i = 1; i <= s.size(); i++){
            for(int j = 0; j < i; j++){
                if(dp[j] && find(wordDict.begin(), wordDict.end(), s.substr(j, i - j)) != wordDict.end()){
                    dp[i] = true;

                }
            }
        }
        return dp[s.size()];
    }
};

int main(){
    Solution s;
    vector<string> wordDict = {"leet", "code"};
    cout << s.wordBreak("leetcode", wordDict) << endl;
    return 0;
}