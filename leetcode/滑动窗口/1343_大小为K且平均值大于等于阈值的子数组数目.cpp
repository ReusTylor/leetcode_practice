/**
* 大小为K且平均值大于等于阈值的子数组的数目
*/

/*
    给你一个整数数组 arr 和两个整数 k 和 threshold 。

    请你返回长度为 k 且平均值大于等于 threshold 的子数组数目。
    输入：arr = [2,2,2,2,5,5,5,8], k = 3, threshold = 4
    输出：3
    解释：子数组 [2,5,5],[5,5,5] 和 [5,5,8] 的平均值分别为 4，5 和 6 。
     其他长度为 3 的子数组的平均值都小于 4 (threshold 的值)。
 */

/*
 * 固定窗口大小的滑动窗口题目，窗口大小为k
 * 1. result： 维护答案数目
 *    window_sum ：维护窗口大小的和
 * 2. left 和 right 都指向序列的第一个元素
 * 3. 向右移动right， 将k个元素填入窗口中
 * 4. 当窗口元素个数为k时，即right - left + 1 >= k时，判断窗口内的元素和是否大于等于阈值threshold
 *      若满足，result +1；
 *      若不满足， 向右移动left， 从而缩小窗口长度，使得窗口大小始终保持为k
 * 5. 重复3 ~ 4步，直到right到达数组末尾
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numOfSubarrays(vector<int>& arr, int k, int threshold) {
        int left = 0;
        int right = 0;
        int result = 0;
        int window_sum = 0;
        while(right < arr.size()){
            window_sum += arr[right];

            if(right - left + 1 >= k){
                if(window_sum >= k * threshold){
                    result += 1;
                }
                window_sum -= arr[left];
                left++;
            }
            right++;
        }
        return result;
    }
};
int main(){
    vector<int> arr{2,2,2,2,5,5,5,8};
    Solution s;
    cout << s.numOfSubarrays(arr, 3, 4) << endl;
    return 0;
}