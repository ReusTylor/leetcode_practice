//
// Created by guessever on 23-8-1.
//

/*

给你一个字符串 s，找到 s 中最长的回文子串。

如果字符串的反序与原始字符串相同，则该字符串称为回文字符串。

输入：s = "babad"
输出："bab"
解释："aba" 同样是符合题意的答案。

 */

// 注意回文串在使用动态规划时的dp函数的定义
/*动态规划：
  dp[i][j] 表示[i, j]为首尾下标的元素是否为回文串
  根据 dp[i + 1][j - 1] 和 s[i] == s[j] 判断是否为回文子串


  注意遍历顺序，从下往上，从左往右遍历

*/
#include <string>
#include <iostream>
#include <vector>
using namespace std;

class Solution {
 public:
  string longestPalindrome(string s) {
    vector<vector<int>> dp(s.size(), vector<int>(s.size(), 0));
    int maxlength = 0;
    int left = 0;

    for(int i = s.size() - 1; i >= 0; i--){
      for(int j = i; j < s.size(); j++){
        if(s[i] == s[j]){
          if(j - i <= 1){
            dp[i][j] = true;
          }else if(dp[i + 1][j - 1]){
            dp[i][j] = true;
          }
        }
        if(dp[i][j] && maxlength <j - i + 1){
          maxlength = j - i + 1;
          left = i;
        }
      }
    }
    return s.substr(left, maxlength);
  }
};

int main(){
  Solution s;
  string s1{"babad"};
  string result = s.longestPalindrome(s1);
  cout << result << endl;
  return 0;
}