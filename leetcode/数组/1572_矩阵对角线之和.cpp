//
// Created by Reus on 2023/8/11.
//
/**
* 给你一个正方形矩阵 mat，请你返回矩阵对角线元素的和。
* 请你返回在矩阵主对角线上的元素和副对角线上且不在主对角线上元素的和。
*/
// 对角线元素的关系： i == j 或者 i + j = n - 1

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    static int diagonalSum(vector<vector<int>>& mat) {
        int n = mat.size();
        int sum = 0;
        for(int i = 0; i < n; i++){
            sum += mat[i][i] + mat[i][n - i - 1];
        }
        if(n % 2 != 0){
            sum -= mat[n/2][n/2];
        }
        return sum;
    }
};

int main(){
    vector<vector<int>> vec{{1,2,3},{4,5,6},{7,8,9}};
    cout << Solution::diagonalSum(vec) << endl;
    return 0;
}