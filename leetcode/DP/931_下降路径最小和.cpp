/*
    给你一个 n x n 的 方形 整数数组 matrix ，请你找出并返回通过 matrix 的下降路径 的 最小和 。

    下降路径 可以从第一行中的任何元素开始，并从每一行中选择一个元素。在下一行选择的元素和当前行所选元素最多相隔一列（即位于正下方或者沿对角线向左或者向右的第一个元素）。
    具体来说，位置 (row, col) 的下一个元素应当是 (row + 1, col - 1)、(row + 1, col) 或者 (row + 1, col + 1) 
*/

/*
    求出末行每行元素的和最小下降路径，然后找到其中最小的即可。
    每个坐标仅可能从他的上一排的左上 正上 右上到达，所以只需要比较这三个值即可。
    result[i][j] = matrix[i][j] + min(result[i - 1][j], min(result[i - 1][j - 1], result[i - 1][j + 1]));

    需要注意的是在第一列和最后一列，只可能从两个位置到达，需要特殊考虑

    初始化：第一行的值就是matrix的第一行的值
*/

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;


class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        vector<vector<int>> result(matrix.size(), vector<int>(matrix[0].size(), 0));

        for(int i = 0; i < matrix[0].size(); i++){
            result[0][i] = matrix[0][i];
        }
        for(int i  = 1; i < matrix.size(); i++){
            for(int j = 0; j < matrix[0].size(); j++){
                if (j == 0)
                {
                    result[i][j] = matrix[i][j] + min(result[i - 1][j], result[i - 1][j + 1]); 
                }else if(j == matrix[0].size() - 1){
                    result[i][j] = matrix[i][j] + min(result[i - 1][j], result[i - 1][j - 1]);     
                }else{
                    result[i][j] = matrix[i][j] + min(result[i - 1][j], min(result[i - 1][j - 1], result[i - 1][j + 1]));
                }
            }   
        }


        int min = result[matrix.size() - 1][0];
        for(int i = 1; i < matrix[0].size(); i++){
            if(result[matrix.size() - 1][i] < min){
                min = result[matrix.size() - 1][i];
            }
        }        
        return min;
    }
};

int main(){
    Solution s;
    vector<vector<int>> matrix = {{2,1,3},{6,5,4},{7,8,9}};
    cout << s.minFallingPathSum(matrix) << endl;
    return 0;
}