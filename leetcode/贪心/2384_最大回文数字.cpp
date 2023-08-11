//
// Created by guessever on 23-8-11.
//
/*
给你一个仅由数字（0 - 9）组成的字符串 num 。

请你找出能够使用 num 中数字形成的 最大回文 整数，并以字符串形式返回。该整数不含 前导零 。

注意：

你 无需 使用 num 中的所有数字，但你必须使用 至少 一个数字。
数字可以重新排序。
*/

/*
 * 统计所有数字出现的次数，然后把大的数字放在回文串的外面，
 * 小的数字放在回文串里面，保证得到的回文串尽量大。本质上是一个贪心的思路。
 */
#include <bits/stdc++.h>
using namespace std;

class Solution{
 public:
  string largestPalindromic(string num){
    vector<int> nums(10, 0);
    // 统计每个数字出现的次数
    for(char c : num){
      nums[c - '0']++;
    }

    string ret = "";
    // 获取回文串的左边
    for(int i = 9; i >= 0; --i){
      // 去掉前导0的情况
      if(i == 0 && ret.empty()) break;
      // 这部分出现过的数字必须出现偶数次
      /*
       * 解释：如果有5个9， 通过9 / 2之后得到4, 那么就可以在左边的字符串中填4个9,右边也填4个9,
       * 通过下面的nums[i] -= 2 * t;语句之后，还有1个9在数组中
       */
      int t = nums[i] / 2;
      for(int j = 0; j < t; j++){
        ret.push_back(i + '0');
      }
      // 这里应该是在循环外处理
      // 这里减 t*2的原因是提前减了另一半回文子串用的
      nums[i] -= 2 * t;
    }
    string ret2 = ret;
    reverse(ret2.begin(), ret2.end());
    // 看看是否还有剩下的数，可以作为中间单独的一个数
    // 只有计数和偶数两种情况，倒序遍历找剩余的最大的一个
    for(int i = 9; i >= 0; i--)
      if(nums[i]){
        ret.push_back(i + '0');
        break;
      }
    return ret + ret2;
  }
};

int main(){
  string num = "282273898509619829360";
  Solution s;
  string result = s.largestPalindromic(num);
  cout << result << endl;
  return 0;

}