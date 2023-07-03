/*
    差分数组
*/

#include<iostream>
#include<vector>
#include<assert.h>

using namespace std;

class Difference{
    int* diff;
public:
    Difference(vector<int>& nums, int length){
        assert(length > 0);
        diff = new int[length]();
        diff[0] = nums[0];

        for(int i = 1; i < length; i++){
            diff[i] = nums[i] - nums[i - 1];
        }
    }

    // 给区间[i, j]加上val
    void increment(int i , int j, int val){
        diff[i] += val;
        if(j + 1 < sizeof(diff) / sizeof(int)){
            diff[j + 1] -= val;
        }
    }

    int* result(){
        int* res = new int[sizeof(diff) / sizeof(int)];
        res[0] = diff[0];
        for(int i = 1; i < sizeof(diff) / sizeof(int); i++){
            res[i] = res[i - 1] + diff[i];
        }
    }

};


class Solution {
public:
    vector<int> corpFlightBookings(vector<vector<int>>& bookings, int n) {
       vector<int> nums(n, 0);
       Difference df(nums);
       for(int i = 0; i < bookings.size(); i++){
        diff.
       }
    }
};
