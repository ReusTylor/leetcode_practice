//
// Created by Reus on 2023/8/10.
//
/**
* 将整个序列分为两部分：前面 i 个元素为有序序列，后面 n - i 个元素为无序序列。
 * 每一次排序，将无序序列的第 1 个元素，在有序序列中找到相应的位置并插入。
 * 简单来说，插入排序的算法步骤为：
    先将第 1 个元素作为一个有序序列，将第 2 ~ n 个元素作为无序序列。
    从左到右遍历一遍无序序列，对于无序序列中的每一个元素：
    遍历有序序列，找到适当的插入位置。
    将有序序列中插入位置右侧的元素依次右移一位。
    将该元素插入到适当位置。


    稳定排序， O(n^2)
*/

#include <bits/stdc++.h>
using namespace std;

class Solution{
public:
    void insert_sort(vector<int> nums){
        int n = nums.size();

        for(int i = 0; i < n; i++){

        }
    }
};

