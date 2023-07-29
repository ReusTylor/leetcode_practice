//
// Created by guessever on 23-7-27.
//
/*
 * 给你一个 m x n 大小的矩阵 grid ，由若干正整数组成。

    执行下述操作，直到 grid 变为空矩阵：
    从每一行删除值最大的元素。如果存在多个这样的值，删除其中任何一个。
    将删除元素中的最大值与答案相加。

    注意 每执行一次操作，矩阵中列的数据就会减 1 。
    返回执行上述操作后的答案。
 */
/*
 * 将每一行按顺序排列，将求每一列最大值之和
 */
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


class Solution {
 public:
  int deleteGreatestValue(vector<vector<int>>& grid){
    // m行n列的矩阵
    int m = grid.size();
    int n = grid[0].size();
    for(int i = 0; i < m; i++){
      sort(grid.begin(), grid.end());
    }
    int result = 0;
    for(int j = 0; j < n; j++){
      int maxnum = 0;
      for(int i = 0; i < m; i++){
        maxnum = max(maxnum, grid[i][j]);
      }
      result += maxnum;
    }
    return result;
  }
};