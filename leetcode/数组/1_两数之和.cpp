//
// Created by guessever on 23-7-30.
//

/*
  给定一个整数数组 nums 和一个整数目标值 target，请你在该数组中找出 和为目标值 target  的那 两个 整数，并返回它们的数组下标。

  你可以假设每种输入只会对应一个答案。但是，数组中同一个元素在答案里不能重复出现。

  你可以按任意顺序返回答案。

  输入：nums = [2,7,11,15], target = 9
  输出：[0,1]
  解释：因为 nums[0] + nums[1] == 9 ，返回 [0, 1] 。

 */

#include <vector>
#include <iostream>
#include <unordered_map>
using namespace std;

class Solution {
 public:
  vector<int> twoSum(vector<int>& nums, int target) {
    // map存储数字及其对应的索引值
    unordered_map<int, int> map;

    for(int i = 0; i < nums.size(); i++){
      auto iter = map.find(target - nums[i]);
      if(iter != map.end()){
        return {i, iter->second};
      }
      map[nums[i]] = i;
    }
    return {};

  }
};