//
// Created by Reus on 2023/8/11.
//
/*
给你一个非负整数 x ，计算并返回 x 的 算术平方根 。

由于返回类型是整数，结果只保留 整数部分 ，小数部分将被 舍去 。

注意：不允许使用任何内置指数函数和算符，例如 pow(x, 0.5) 或者 x ** 0.5
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int mySqrt(int x) {
        int left = 0;
        int right = x;
        // 这里ans记录的就是ans * ans <= x 时，ans的最大值
        int ans = -1;

        while(left <= right){
            int mid = left + (right - left) / 2;
            if((long long)mid * mid  == x){
                return mid;
            }else if((long long)mid * mid < x){
                ans = mid;
                left = mid + 1;
            }else{
                right = mid - 1;
            }
        }
        return ans;
    }
};

int main(){
    int x = 8;
    Solution s;
    cout << s.mySqrt(x) << endl;
}