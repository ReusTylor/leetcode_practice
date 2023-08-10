//
// Created by guessever on 23-8-7.
//
/*
 * 给定一个含有 n 个正整数的数组和一个正整数 target 。
   找出该数组中满足其和 ≥ target 的长度最小的 连续子数组 [numsl, numsl+1, ..., numsr-1, numsr] ，
   并返回其长度。如果不存在符合条件的子数组，返回 0 。
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  int minSubArrayLen(int target, vector<int>& nums) {
    int left = 0;
    int right = 0;
    int sum  = 0;
    int length = INT_MAX;
    while(right < nums.size()){
      sum += nums[right];
      while(sum >= target){
        length = min(length, right - left + 1);
        sum -= nums[left];
        left++;
      }
      right++;
    }
    return length;
  }
};

int main(){
  vector<int> nums{2,3,1,2,4,3};
  int target = 7;
  Solution s;
  int result = s.minSubArrayLen(target, nums);
  cout << result << endl;
}