/*
    给你一个整数数组 nums ，判断这个数组中是否存在长度为 3 的递增子序列。
    如果存在这样的三元组下标 (i, j, k) 且满足 i < j < k ，使得 nums[i] < nums[j] < nums[k] ，返回 true ；否则，返回 false 。
*/

// 考虑双指针法
/*
    维护两个变量 min 和 mid，分别表示当前找到的较小数和中间数。初始时将 min 和 mid 初始化为正无穷大。
*/
#include<iostream>
#include<vector>
#include<climits>
using namespace std;

class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int min = INT_MAX;
        int mid = INT_MAX;

        for(int num : nums){
            if(num <= min){
                min = num;
            }else if(num <= mid){
                mid = num;
            }else{
                return true;
            }
        }
        return false;
    }
};

int main(){
    vector<int> nums= {7,0,3,4,1,34,5,67,3,4,65,6,4,34,23};
    Solution s;
    bool a = s.increasingTriplet(nums);
    cout << a << endl;
    return 0;
}