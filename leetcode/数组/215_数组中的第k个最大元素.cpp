//
// Created by guessever on 23-7-30.
//

/*
  给定整数数组 nums 和整数 k，请返回数组中第 k 个最大的元素。

  请注意，你需要找的是数组排序后的第 k 个最大的元素，而不是第 k 个不同的元素。

  你必须设计并实现时间复杂度为 O(n) 的算法解决此问题。
 */
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// 使用最小堆，k个最大的都保存在优先队列中，因此堆顶元素就是第k大的
class Solution {
 public:
  int findKthLargest(vector<int>& nums, int k) {
    /*std::priority_queue<数据类型, 容器类型, 比较函数> 优先队列名称;
     *std::priority_queue<int, std::vector<int>, std::less<int>> maxHeap;
     *std::priority_queue<int, std::vector<int>, std::greater<int>> minHeap;
     * */

    priority_queue<int, vector<int>, greater<int>> que;
    for(int i = 0; i < k; i++){
      que.emplace(nums[i]);
    }

    for(int i = k; i < nums.size(); i++){
      if(nums[i] > que.top()){
        que.pop();
        que.emplace(nums[i]);
      }
    }

    return que.top();

  }
};