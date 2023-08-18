//
// Created by Reus on 2023/8/15.
//


// 给定一个二进制数组 nums 和一个整数 k，
// 如果可以翻转最多 k 个 0 ，则返回 数组中连续 1 的最大个数 。

/**
* 关键在于题意的转换：
 *  最多可以把k个0变成1，求仅包含1的最长子数组的长度 ==>
 *  找出一个最长的子数组，该子数组内最多允许有K个0
*/

#include <bits/stdc++.h>
using namespace std;


class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int left = 0;
        int right = 0;

        int max_length = INT_MIN;
        while(right < nums.size()){
            if(nums[right] == 0) k--;
            right++;

            if(k < 0){
                if(nums[left] == 0){
                    k++;
                }
                left++;
            }
            max_length = max(max_length, right - left);

        }
        return max_length;
    }
};

int main(){
    vector<int> nums{0,0,1,1,0,0,1,1,1,0,1,1,0,0,0,1,1,1,1};
    Solution s;
    cout << s.longestOnes(nums, 3);
    return 0;
}
