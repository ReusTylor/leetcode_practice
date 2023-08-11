//
// Created by guessever on 23-8-11.
//

/*
  你是产品经理，目前正在带领一个团队开发新的产品。不幸的是，你的产品的最新版本没有通过质量检测。
  由于每个版本都是基于之前的版本开发的，所以错误的版本之后的所有版本都是错的。

  假设你有 n 个版本 [1, 2, ..., n]，你想找出导致之后所有版本出错的第一个错误的版本。

  你可以通过调用 bool isBadVersion(version) 接口来判断版本号 version 是否在单元测试中出错。
  实现一个函数来查找第一个错误的版本。你应该尽量减少对调用 API 的次数。

  输入：n = 5, bad = 4
  输出：4
  解释：
  调用 isBadVersion(3) -> false
  调用 isBadVersion(5) -> true
  调用 isBadVersion(4) -> true
  所以，4 是第一个错误的版本。
 */
// 使用二分法找第一个出问题的版本

#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  static int left_bound(vector<int> &nums, int target){
    int left = 0;
    int right = nums.size() - 1;

    while(left <= right){
      int mid = left + (right - left)/2;
      if(nums[mid] == target){
        // 可见，找到 target 时不要立即返回，而是缩小「搜索区间」的上界 right，在区间 [left, mid) 中继续搜索，即不断向左收缩，达到锁定左侧边界的目的。
        right = mid - 1;
      }else if(nums[mid] < target){
        left = mid + 1;
      }else if(nums[mid] > target){
        right = mid - 1;
      }
    }
    return left;
  }
};

int main(){
  vector<int> nums{1,2,3,3,3,3,3,4,5};
  int target = 3;

  cout << Solution::left_bound(nums, 3) << endl;
}

