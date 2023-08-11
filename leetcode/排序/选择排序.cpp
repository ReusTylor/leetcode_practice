//
// Created by Reus on 2023/8/10.
//
/**
 * 将序列分为两部分：前边 i - 1 个元素为已排序部分，后边 n - i + 1 个元素为未排序部分。
 * 第 i 趟排序从未排序部分 n − i + 1 (i = 1, 2, …, n − 1) 个元素中选择一个值最小的元素与未排序部分最前面那个元素交换位置，
 * 即与整个序列的第 i 个位置上的元素交换位置。如此下去，直到所有元素都变为已排序部分，排序结束。
 */

#include <bits/stdc++.h>
using namespace std;

class Solution{
public:
    static void selection_sort(vector<int>& nums){
        int n = static_cast<int>(nums.size());
        for(int i = 0; i < n - 1; i++){
            int min = i;
            for(int j = i + 1; j < n; j++){
                if(nums[j] < nums[min]){
                    min = j;
                }
            }
            swap(nums[i], nums[min]);
        }
    }
};

int main(){
    vector<int> nums{22, 34, 3, 32, 82, 55, 89, 50, 37, 5, 64, 35, 9, 70};
    Solution::selection_sort(nums);
    for(int num :nums){
        cout << num <<endl;
    }
    return 0;
}
