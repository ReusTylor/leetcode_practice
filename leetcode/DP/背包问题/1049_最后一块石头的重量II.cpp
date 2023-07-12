/*
   有一堆石头，用整数数组 stones 表示。其中 stones[i] 表示第 i 块石头的重量。

    每一回合，从中选出任意两块石头，然后将它们一起粉碎。假设石头的重量分别为 x 和 y，且 x <= y。那么粉碎的可能结果如下：

    如果 x == y，那么两块石头都会被完全粉碎；
    如果 x != y，那么重量为 x 的石头将会完全粉碎，而重量为 y 的石头新重量为 y-x。

    最后，最多只会剩下一块 石头。返回此石头 最小的可能重量 。如果没有石头剩下，就返回 0。

    输入：stones = [2,7,4,1,8,1]
    输出：1
    解释：
    组合 2 和 4，得到 2，所以数组转化为 [2,7,1,8,1]，
    组合 7 和 8，得到 1，所以数组转化为 [2,1,1,1]，
    组合 2 和 1，得到 1，所以数组转化为 [1,1,1]，
    组合 1 和 1，得到 0，所以数组转化为 [1]，这就是最优值。

 
*/
// 尽量让石头分成重量相同的两堆
// 物品重量为stones[i] 价值也为stones[i]
/*
    1. dp[j] 重量为j的背包能装的最大的重量
    2. dp[j] = max(dp[j], dp[j - stones[i]] + stones[i]);
    3. 

*/

// 这道题求的是最大能装多少
// 分割等和子集求的是 是否正好装满


#include<iostream>
#include<vector>
using namespace std;


class Solution {
public:
    int lastStoneWeightII(vector<int>& stones) {

        vector<int> dp(150001, 0);
        int sum = 0;
        for(int stone : stones)
            sum += stone;

        // sum/2向下取整
        // 分成了两堆石头，一堆总重量为dp[target], 另一堆总重量为sum - dp[target]
        // sum - dp[target] 一定 >= dp[target]
        int target = sum / 2;


        for(int i = 0; i < stones.size(); i++){
            for(int j = target; j >= stones[i]; j--){
                dp[j] = max(dp[j], dp[j - stones[i]] + stones[i]);
            }
        }
        // target 不能作为 stones的索引
        if(stones[target] == target)
            return 0;
        return sum - dp[target] - dp[target]; 
    }
};

int main(){
    vector<int> stones = {31,26,33,21,40};
    Solution s;
    int result = s.lastStoneWeightII(stones);
    cout << result << endl;
    return 0;
}