//
// Created by Reus on 2023/8/14.
//
/*
 * 给你一个整数数组 nums 和一个整数 k ，请你返回子数组内所有元素的乘积严格小于 k 的连续子数组的数目。
 */

#include <bits/stdc++.h>
using namespace std;


class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        if(k < 2) return 0; // 特殊情况
        int left = 0;
        int right = 0;
        int window_sum = 1;
        int result = 0;
        while(right < nums.size()){
            window_sum *= nums[right];
            right++;

            while(window_sum >= k){
                window_sum /= nums[left];
                left++;
            }
            result += right - left;
        }
        return result;
    }
};

int main(){
    vector<int> nums{10,5,2,6};
    Solution s;
    cout << s.numSubarrayProductLessThanK(nums, 100);

}