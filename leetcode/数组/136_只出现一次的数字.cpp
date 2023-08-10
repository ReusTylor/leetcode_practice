//
// Created by guessever on 23-8-1.
//

/*
 给你一个 非空 整数数组 nums ，除了某个元素只出现一次以外，其余每个元素均出现两次。找出那个只出现了一次的元素。
 你必须设计并实现线性时间复杂度的算法来解决此问题，且该算法只使用常量额外空间。

 输入：nums = [2,2,1]
 输出：1

 */

/*
 * 先进行排序，然后每次走两步，查看nums[i]和nums[i - 1]是否相等
 */
#include <vector>
#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;


class Solution {
 public:
  int singleNumber(vector<int>& nums) {
    if(nums.size() == 1) return nums[0];
    sort(nums.begin(), nums.end());
    for(int i = 1; i < nums.size(); i +=2){
      if(nums[i] != nums[i - 1])
          return nums[i - 1];

    }
    return nums[nums.size() - 1];
  }

};