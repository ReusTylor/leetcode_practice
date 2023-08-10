//
// Created by guessever on 23-7-30.
//

/*
  给你一个字符串 s 、一个字符串 t 。返回 s 中涵盖 t 所有字符的最小子串。
  如果 s 中不存在涵盖 t 所有字符的子串，则返回空字符串 "" 。

 注意：

    对于 t 中重复字符，我们寻找的子字符串中该字符数量必须不少于 t 中该字符数量。
    如果 s 中存在这样的子串，我们保证它是唯一的答案。

  输入：s = "ADOBECODEBANC", t = "ABC"
  输出："BANC"
  解释：最小覆盖子串 "BANC" 包含来自字符串 t 的 'A'、'B' 和 'C'。

 */

#include <string>
#include <iostream>
#include <unordered_map>
#include <climits>
using namespace std;
class Solution {
 public:
  static string minWindow(string s, string t) {
    int left = 0;
    int right = 0;
    // valid匹配统计上的字符数，其实也是判断左边窗口缩小的条件
    int valid = 0;
    // 因为最后返回字符串，所以使用substr，因此需要指导起始位置和长度
    int start = 0, len = INT_MAX;
    // 统计一下需要的元素。使用两个hashmap分别统计
    unordered_map<char, int> window, need;
    for(char c : t){
      need[c]++;
    }

    while(right < s.size()){
      char c = s[right];
      right++;
      if(need.find(c) != need.end()){
        window[c]++;
        if(window[c] == need[c]){
          valid++;
        }
      }

      // 说明窗口已经满足条件，完全覆盖了串T
      // 直到窗口中的字符串不再符合要求，left 不再继续移动：
      while(valid == need.size()){
        // 更新取字符串所需要的条件，也就是start和len
        if(right - left < len){
          start = left;
          len = right - left;
        }

        char d = s[left];
        left++;
        // 如果d是need中的元素，那么windon[d]就要--，因为窗口缩小了
        // 当window[d] == need[d]
        if(need.find(d) != need.end()){
          if(window[d] == need[d])
              valid--;
          window[d]--;
        }
      }
    }
    return len == INT_MAX ? "" : s.substr(start, len);
  }
};

int main(){
  string s = "ADOBECODEBANC";
  string t = "AOB";
  Solution s1;

  string result = s1.minWindow(s, t);
  cout << result << endl;
}