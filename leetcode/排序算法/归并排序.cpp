/*
    将当前区间不断二分，直到左右区间中只有一个数字时，视其为有序区间，两两进行合并然后将两两的有序区间不断合并，最终完成排序
*/


#include<iostream>
#include<vector>
using namespace std;

void Merge(vector<int>& num, int low, int mid, int high){
    vector<int> temp(high - low + 1);

    int i = low;  // 从low到mid
    int j = mid + 1; // 从mid 到 high
    int k = 0;

    while(i <= mid && j <=high){// 从小到大合并
        if(num[i] < num[j]){
            temp[k] = num[i];
            k++;
            i++;
        }else{
            temp[k] = num[j];
            k++;
            j++;
        }

    }



}