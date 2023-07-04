/*
    给你一个下标从 0 开始的二维整数数组 nums 。一开始你的分数为 0 。你需要执行以下操作直到矩阵变为空：

    矩阵中每一行选取最大的一个数，并删除它。如果一行中有多个最大的数，选择任意一个并删除。
    在步骤 1 删除的所有数字中找到最大的一个数字，将它添加到你的 分数 中。

    请你返回最后的 分数 。

*/

// 使用排序，先将矩阵的每一行进行排序，然后按列找出每列的最大值并加起来
#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

class Solution {
public:
    int matrixSum(vector<vector<int>>& nums) {
        int result = 0;
        int m = nums.size();// 行数
        int n = nums[0].size(); // 列数

        for(int i = 0; i < m; i++){
            sort(nums[i].begin(), nums[i].end(), greater<int>());
        }

        // 按列进行遍历        
        for(int j = 0; j < n; j++){
        // 第一列中找最大的值
            int maxValue = 0;
            for(int i = 0; i < m; i++){
                maxValue = max(maxValue, nums[i][j]);
            }
            result += maxValue;
        }
        return result;
    }
};



int main(){
    vector<vector<int>> nums = {{7, 2, 1}, {6, 4, 2}, {6, 5, 3},{3, 2, 1}};
    Solution s;
    int result = s.matrixSum(nums);
    cout << result << endl;
    return 0;
}