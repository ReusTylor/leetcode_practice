/*
    给你一个长度为 n 的整数数组 nums 和 一个目标值 target。请你从 nums 中选出三个整数，使它们的和与 target 最接近。
    返回这三个数的和。
    假定每组输入只存在恰好一个解。

    输入：nums = [-1,2,1,-4], target = 1
    输出：2
    解释：与 target 最接近的和是 2 (-1 + 2 + 1 = 2) 。
*/
// 与三数之和相同，使用双指针法，先将数组排序
#include<iostream>
#include<vector>
#include<algorithm>
#include<limits.h>
using namespace std;

class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        int closestDiff = INT_MAX;
        int result = INT_MAX;
        // <= n - 3 是因为还有双指针的位置，所以不需要遍历到最后一个位置
        for(int i = 0; i <= n - 3; i++){
            int left = i + 1;
            int right = n - 1;
            // 这里不能相等，如果相等，left和right指向同一个位置，导致一个元素用了两次
            while(left < right){
                int sum = nums[left] + nums[right] + nums[i];
                int diff = abs(target - sum);
                if(diff == 0){
                    return target;
                }
                if(closestDiff > diff){
                    closestDiff = diff;
                    result = sum;
                }
                if(sum < target){
                    left++;
                }else{
                    right--;
                }
            }

        }
        return result;
    }
};


int main(){
    vector<int> nums = {-1,2,1,-4};
    int target = 1;
    Solution s;
    int result = s.threeSumClosest(nums, target);
    cout << result << endl;
    return 0;
}

