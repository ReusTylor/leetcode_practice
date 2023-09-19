/*
给你一个按照非递减顺序排列的整数数组 nums，和一个目标值 target。请你找出给定目标值在数组中的开始位置和结束位置。
如果数组中不存在目标值 target，返回 [-1, -1]。
你必须设计并实现时间复杂度为 O(log n) 的算法解决此问题。

因为是排序数组，所以想到二分查找，时间复杂度为O(logn)。
如果直接遍历的话，时间复杂度是O(n)。
*/

// 在nums[mid] == target时， 还要继续查找下去
// 如果寻找左边界，那么需要更新right
// 如果寻找右边界，需要更新left
#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    int left_bound(vector<int> &nums, int target)
    {
        int left = 0;
        int right = nums.size() - 1;
        while (left <= right)
        {
            int mid = left + (right - left) / 2;
            if (nums[mid] == target)
            {
                right = mid - 1;
            }
            else if (nums[mid] < target)
            {
                left = mid + 1;
            }
            else if (nums[mid] > target)
            {
                right = mid - 1;
            }
        }
        if (left >= nums.size())
            return -1;
        return nums[left] == target ? left : -1;
    }
    int right_bound(vector<int> &nums, int target)
    {
        int left = 0;
        int right = nums.size() - 1;

        while (left <= right)
        {
            int mid = left + (right - left) / 2;
            if (nums[mid] == target)
            {
                left = mid + 1;
            }
            else if (nums[mid] < target)
            {
                left = mid + 1;
            }
            else if (nums[mid] > target)
            {
                right = mid - 1;
            }
        }
        // 注意要判断数组索引是否越界
        if (right < 0)
            return -1;
        // 判断找到的是否为target
        return nums[right] == target ? right : -1;
    }

    vector<int> searchRange(vector<int> &nums, int target)
    {
        int lbound = left_bound(nums, target);
        int rbound = right_bound(nums, target);
        return {lbound, rbound};
    }
};

// 设置一个bool变量，用于确定寻找的是左边界还是右边界

namespace easy
{
    class Solution
    {
    public:
        int bound(vector<int> &nums, int target, bool isLeft)
        {
            int left = 0;
            int right = nums.size() - 1;
            int result = -1;

            while (left <= right)
            {
                int mid = left + (right - left) / 2;
                if (nums[mid] == target)
                {
                    result = mid;
                    if (isLeft)
                        right = mid - 1;
                    else
                        left = mid + 1;
                }
                else if (nums[mid] < target)
                {
                    left = mid + 1;
                }
                else if (nums[mid] > target)
                {
                    right = mid - 1;
                }
            }

            return result;
        }

        vector<int> searchRange(vector<int> &nums, int target)
        {
            int lbound = bound(nums, target, true);
            int rbound = bound(nums, target, false);
            return {lbound, rbound};
        }
    };
}

int main()
{
    vector<int> nums = {-1, 0, 3, 5, 9, 9, 9, 12};
    Solution s;
    auto result = s.searchRange(nums, 9);
    for (auto a : result)
    {
        cout << a << " ";
    }
    cout << endl;

    easy::Solution s2;
    auto result2 = s2.searchRange(nums, 9);
    for (auto a : result2)
    {
        cout << a << " ";
    }
    return 0;
}