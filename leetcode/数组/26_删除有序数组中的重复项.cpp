/**
 * 删除有序数组中的重复项
 * 给你一个 升序排列 的数组 nums ，请你 原地 删除重复出现的元素，使每个元素 只出现一次 ，
 * 返回删除后数组的新长度。元素的 相对顺序 应该保持 一致 。然后返回 nums 中唯一元素的个数。
 */

/*
输入：nums = [1,1,2]
输出：2, nums = [1,2,_]
解释：函数应该返回新的长度 2 ，并且原数组 nums 的前两个元素被修改为 1, 2 。不需要考虑数组中超出新长度后面的元素。
*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int removeDuplicates(vector<int> &nums)
    {
        int slow = 0;
        int fast = 0;

        while (fast < nums.size())
        {
            if (nums[fast] == nums[slow])
            {
                fast++;
            }
            else
            {
                nums[++slow] = nums[fast++];
            }
        }
        return slow + 1;
    }
};

int main()
{
    vector<int> nums{1, 1, 2};
    Solution s;
    int result = s.removeDuplicates(nums);
    cout << result << endl;
    return 0;
}