//
// Created by Reus on 2023/8/11.
//
/*
给你一个下标从 1 开始的整数数组 numbers ，该数组已按 非递减顺序排列  ，请你从数组中找出满足相加之和等于目标数 target 的两个数。
 如果设这两个数分别是 numbers[index1] 和 numbers[index2] ，则 1 <= index1 < index2 <= numbers.length 。

以长度为 2 的整数数组 [index1, index2] 的形式返回这两个整数的下标 index1 和 index2。

你可以假设每个输入 只对应唯一的答案 ，而且你 不可以 重复使用相同的元素。

你所设计的解决方案必须只使用常量级的额外空间。

 输入：numbers = [2,7,11,15], target = 9
输出：[1,2]
解释：2 与 7 之和等于目标数 9 。因此 index1 = 1, index2 = 2 。返回 [1, 2] 。
 */

// 对数组中的每个数字i，在他后面的数组中使用二分法找target - i
#include <bits/stdc++.h>
using namespace std;

class Solution {
    // 返回的是(target - i)的坐标
    int search(vector<int>& nums, int start, int end, int target){
        int left = start;
        int right = end;
        while(left <= right){
            int mid = left + (right - left) / 2;
            if(nums[mid] == target){
                return mid;
            }else if(nums[mid] < target){
                left = mid + 1;
            }else{
                right = mid - 1;
            }
        }
        return -1;
    }
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int n = numbers.size();
        for (int i = 0; i < n; ++i) {
            int pos = search(numbers, i + 1, n - 1, target - numbers[i]);
            if(pos != -1){
                return {i + 1, pos + 1};
            }
        }
        return {-1, -1};
    }
};

int main() {

    vector<int> numbers{5, 25, 75};
    Solution s;
    vector<int> result = s.twoSum(numbers, 100);
    for (int num: result) {
        cout << num << endl;
    }
    return 0;
}