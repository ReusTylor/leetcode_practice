//
// Created by guessever on 23-8-8.
//
/*
 * 给你一个整数数组 nums，请你将该数组升序排列。
 *
 */
/*
 * 核心就是划分函数的实现
 * 1. 确定一个分解值pivot，然后进行划分
 *  主元的选取方式有很多种， 这里采用随即的方式来，对当前划分区间间[l,r]里的数等概率随即一个作为主元
 *  再将主元放到区间末尾，进行划分。
 * 2. 划分函数partition
 */

// 快排
#include <bits/stdc++.h>
using namespace std;

class Solution {
  int partition(vector<int>& vec, int left, int right){
    int i = left;
    int j = right;
    int pivot = vec[left];// 基准元素
    while(i < j){
      // 经过这个循环之后，j指向的就是第一个小于等于pivot的值
      while(i < j && vec[j] > pivot){
        j--;
      }

      if(i < j){
        swap(vec[i], vec[j]);
        i++;
      }
      // 经过这个循环后，i指向的是第一个大于pivot的值
      while(i < j && vec[i] <= pivot){
        i++;
      }
      if(i < j){
        swap(vec[i], vec[j]);//r[i]和r[j]交换后 i 向左移动一位
        j--;
      }
    }
    // 返回最终划分完成后基准元素所在的位置。
    return i;
  }
  void QuickSort(vector<int>& vec, int left, int right){
    int mid;
    if(left < right){
      mid = partition(vec, left, right);
      QuickSort(vec, left, mid - 1);
      QuickSort(vec, mid + 1, right);
    }
  }
 public:
  vector<int> sortArray(vector<int>& nums) {
    int left = 0;
    int right = nums.size() - 1;
    QuickSort(nums, left, right);
    return nums;
  }
};

int main(){
  vector<int> nums{5,2,3,1};
  Solution s;
  s.sortArray(nums);
  for(int num: nums){
    cout << num << endl;
  }
  return 0;
}


// 堆排序
// 先将排序的序列构建成大根堆，
class Solution1{
  void max_heapify(vector<int>& nums, int start, int end){
    int dad = start;
    int son = dad*2 + 1;
    while(son <= end){
      
    }
  }
public:
    vector<int> sortArray(vector<int>& nums) {

    } 
};