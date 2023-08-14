/*
 * 给定一个含有 n 个正整数的数组和一个正整数 target 。

    找出该数组中满足其和 ≥ target 的长度最小的 连续子数组 [numsl, numsl+1, ..., numsr-1, numsr] ，
    并返回其长度。如果不存在符合条件的子数组，返回 0 。

    输入：target = 7, nums = [2,3,1,2,4,3]
    输出：2
    解释：子数组 [4,3] 是该条件下的长度最小的子数组。
 *
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int left = 0;
        int right = 0;
        int window_sum = 0;
        int min_length = INT_MAX;
        while(right < nums.size()){
            window_sum += nums[right];
            while(window_sum >= target){
                min_length = min(min_length, right - left + 1);
                window_sum -= nums[left];
                left++;
            }
            right++;

        }
        return (min_length == INT_MAX ? 0 : min_length);
    }
};

int main(){
    Solution s;
    vector<int> nums{2,3,1,2,4,3};
    cout << s.minSubArrayLen(7, nums) << endl;
}
