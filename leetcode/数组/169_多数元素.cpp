//
// Created by guessever on 23-8-1.
//

/*
 给定一个大小为 n 的数组 nums ，返回其中的多数元素。多数元素是指在数组中出现次数 大于 ⌊ n/2 ⌋ 的元素。
 你可以假设数组是非空的，并且给定的数组总是存在多数元素。

 输入：nums = [3,2,3]
 输出：3
 */

#include <vector>
#include <iostream>
#include <unordered_map>
using namespace std;

class Solution {
 public:
  int majorityElement(vector<int>& nums) {
    unordered_map<int, int> mp;
    for(int i = 0; i < nums.size(); i++){
      mp[nums[i]]++;
      if(mp[nums[i]] > nums.size() / 2)
      return nums[i];
    }
    return 0;
  }
};

int main(){
  Solution solution;
  vector<int> nums = {3,2,3};
  int result = solution.majorityElement(nums);
  cout << result << endl;
  return 0;

}
