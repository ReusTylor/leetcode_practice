//
// Created by guessever on 23-7-29.
//
/*
 * 给你一个整数数组 nums，有一个大小为 k 的滑动窗口从数组的最左侧移动到数组的最右侧。你只可以看到在滑动窗口内的 k 个数字。
 * 滑动窗口每次只向右移动一位。返回 滑动窗口中的最大值 。
 * 输入：nums = [1,3,-1,-3,5,3,6,7], k = 3
 * 输出：[3,3,5,5,6,7]
 */

/*
 * 维护一个大小为窗口大小的大顶堆，堆顶元素为当前窗口的最大值
 * 大顶堆的元素使用二元组(nums[i],i)入队
 * 当下标达到滑动窗口的右端点时，首先判断该堆顶元素的下标是否小于当前滑动窗口的最小值
 * - 如果小于当前滑动窗口左端点时，丢弃该元素
 * - 如果不小于当前滑动窗口左端点时，该堆顶元素一定在当前窗口且为最大值
 */


#include <bits/stdc++.h>
using namespace std;

class  Solution{
 public:
  static vector<int> maxSlidingWindow(vector<int>& nums, int k) {
    vector<int>::size_type  size = nums.size();
    int n = static_cast<int>(size);
    priority_queue<pair<int, int>> q;
    vector<int> ans;
    for(int i = 0; i < k; i++){
      q.emplace(nums[i], i);
    }
    ans.push_back(q.top().first);

    for(int i = k; i < n; ++i){
      q.emplace(nums[i], i);
      while(q.top().second <= i - k){
        q.pop();
      }
      ans.push_back(q.top().first);
    }
    return ans;
  }
};

int main(){
  vector<int> nums{1,3,-1,-3,5,3,6,7};
  int k = 3;
  vector<int> result = Solution::maxSlidingWindow(nums, k);
  for(int num : result){
    cout << num << endl;
  }
  return 0;
}

/*
 * 使用单调队列
 */

