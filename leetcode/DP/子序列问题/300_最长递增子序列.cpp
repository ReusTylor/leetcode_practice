/*
    给你一个整数数组 nums ，找到其中最长严格递增子序列的长度。

    子序列 是由数组派生而来的序列，删除（或不删除）数组中的元素而不改变其余元素的顺序。
    例如，[3,6,2,7] 是数组 [0,3,1,6,2,2,7] 的子序列。

*/
/*
    dp[i] : 以nums[i]结尾的最长递增子序列的长度

    dp[i]是从dp[j] + 1和dp[i]中取最大值，这个dp[j] 
    dp[i] = max(dp[i], dp[j] + 1) 1 <= j <= i - 1

    dp[0] = 1;
*/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        if(nums.size() <= 1) return nums.size();
        vector<int> dp(nums.size(), 1);
        int result = 0;
        for(int i = 1; i < nums.size(); i++){
            for(int j = 0; j < i; j++){
                if(nums[i] > nums[j])// 只有满足这个条件，才存在递推公式
                    dp[i] = max(dp[i], dp[j] + 1);
            }
            // if(dp[i] > result) result = dp[i]; // 取最长的子序列
            if(dp[i] > result) result = dp[i]; // 通过一个for循环找到dp数组中的最大值才是返回的结果
        }
        return result;
    }
};

int main(){
    vector<int> nums = {1,3,6,7,9,4,10,5,6
};
    Solution s;
    cout << s.lengthOfLIS(nums) << endl;
    return 0;
}