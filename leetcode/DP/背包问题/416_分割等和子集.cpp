/*
    给你一个 只包含正整数 的 非空 数组 nums 。请你判断是否可以将这个数组分割成两个子集，使得两个子集的元素和相等。

    输入：nums = [1,5,11,5]
    输出：true
    解释：数组可以分割成 [1, 5, 5] 和 [11] 。
*/

/*
    将数组分成值相等的两部分
*/ 


#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum = 0;
        for(int num : nums){
            sum += num;
        }
        if(sum % 2 != 0)
            return false;
        int target = sum / 2;
        // 此时就变成了一个DP问题，背包容量为sum/2， 物品为nums中的数字
        // 正好装满说明找到了总和为sum/2的子集
        // 每个数组的元素不超过100，数组的大小不超过200,总和不会超过20000，只需要一半
        vector<int> dp(10001, 0);
        
        // 先遍历物品 再遍历背包，遍历背包要倒序
        for(int i = 0; i < nums.size(); i++){
            for(int j = target; j >= nums[i]; j--){
                dp[j] = max(dp[j], dp[j - nums[i]] + nums[i]);
            }
        }

        if(dp[target] == target) return true;
        return false;
    }
};


int main(){
    vector<int> nums{1,2,3,5};
    Solution s;
    bool can = s.canPartition(nums);
    cout << can << endl;

}