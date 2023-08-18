//
// Created by Reus on 2023/8/14.
//

/*
 * 给定一个未经排序的整数数组，找到最长且 连续递增的子序列，并返回该序列的长度。
 * 连续递增的子序列 可以由两个下标 l 和 r（l < r）确定，如果对于每个 l <= i < r，都有 nums[i] < nums[i + 1] ，
 * 那么子序列 [nums[l], nums[l + 1], ..., nums[r - 1], nums[r]] 就是连续递增子序列。
 */
// 窗口长度不定的滑动窗口
#include <bits/stdc++.h>
using namespace std;


class Solution {
public:
    int findLengthOfLCIS(vector<int>& nums) {
        int left = 0;
        int right = 0;
        int window_length = INT_MIN;
        // 因为下面要出现right+1，所以这里要right < nums.size() - 1
        while(right < nums.size() - 1){
            if(nums[right] < nums[right + 1]){
                right++;
            // 如果nums[right] >= nums[right + 1], 说明这一段的递增就到此为止了，将左右指针都跳到右指针的位置
            }else{
                window_length = max(right - left + 1, window_length);
                left = right + 1;
                right = right + 1;
            }
        }
        window_length = max(right - left + 1, window_length);
        return window_length;
    }
};

