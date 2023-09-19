//
// Created by Reus on 2023/8/11.
//
/*
 * 定一个排序数组和一个目标值，在数组中找到目标值，并返回其索引。如果目标值不存在于数组中，返回它将会被按顺序插入的位置。
 *  请必须使用时间复杂度为 O(log n) 的算法
 */
// 经典二分

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int searchInsert(vector<int> &nums, int target)
    {
        int left = 0;
        int right = nums.size() - 1;

        while (left <= right)
        {
            int mid = left + (right - left) / 2;
            if (nums[mid] == target)
            {
                return mid;
            }
            else if (nums[mid] < target)
            {
                left = mid + 1;
            }
            else
            {
                right = mid - 1;
            }
        }
        return left;
    }
};

int main()
{
    Solution s;
    vector<int> nums{1, 2, 3, 4, 5};
    int result = s.searchInsert(nums, 3);
    cout << result << endl;
    return 0;
}