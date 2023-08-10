/*
    给你一个整数数组 nums ，判断是否存在三元组 [nums[i], nums[j], nums[k]] 满足 i != j、i != k 且 j != k ，
    同时还满足 nums[i] + nums[j] + nums[k] == 0 。
    
    请你返回所有和为 0 且不重复的三元组。

    注意：答案中不可以包含重复的三元组


*/
// 求三数之和 = 0；可以确定一个数，然后在剩下的数中找两个数，使得这两个数的和等于第一个数的相反数。
// 自己的代码缺失了去重的逻辑
#include <iostream>
#include<vector>
#include<algorithm>
#include <climits>
using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        vector<vector<int>> result;
        int i = 0;

        for(int i = 0; i < nums.size() - 2; i++){
            // 这里加一个判断，如果排序后第一个元素大于0,可以直接跳过
            if (nums[i] > 0) {
                return result;
            }

            // 去重a的逻辑：
            if(i > 0 && nums[i] == nums[i - 1]){
                continue;
            }
            int left = i + 1;
            int right = nums.size() - 1;
            while(left < right){
                if(nums[i] + nums[left] + nums[right] < 0){
                    left++;
                }else if(nums[i] + nums[left] + nums[right] > 0){
                    right--;
                }else{
                    result.push_back({nums[i], nums[left], nums[right]});
                    right--;
                    left++;             
                    // 去重b和c       
                    while (right > left && nums[right] == nums[right + 1]) right--;
                    while (right > left && nums[left] == nums[left - 1]) left++;

                }

            }
        }
        return result;
    }
}



int main(){
    vector<int> nums = {-1, -1, 0, 1};
    Solution s;
    vector<vector<int>> result = s.threeSum(nums);
    for(auto i : result){
        for(auto j : i){
            cout << j << " ";
        }
        cout << endl;
    }
    return 0;
}