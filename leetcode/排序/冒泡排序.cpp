//
// Created by Reus on 2023/8/10.
//
#include <bits/stdc++.h>
using namespace std;

class Solution{
public:
    static void bubbleSort(vector<int>& nums){
        int n = static_cast<int>(nums.size());

        // 第i趟排序
        for(int i  = 0; i < n; i++){
            // 优化方式，在一次排序中，如果没有发生交换，说明已经有序了，可以直接return;
            int flag = false;
            // 第i趟排序时是从0到n - i - 1
            for(int j  = 0; j < n - i - 1; j++){
                if(nums[j] > nums[j + 1]){
                    swap(nums[j], nums[j + 1]);
                    flag = true;
                }
            }
            if(flag == false){
                return;
            }
        }

    }
};

int main(){
    vector<int> nums{61, 17, 29, 22, 34, 60, 72, 21, 50, 1, 62};
    Solution::bubbleSort(nums);
    for(int num :nums){
        cout << num <<endl;
    }
    return 0;
}