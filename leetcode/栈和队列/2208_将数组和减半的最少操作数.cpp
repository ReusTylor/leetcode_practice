/*
    给你一个正整数数组nums。每一次操作中，你可以从nums中选择任意一个数并将它减小到恰好一半。（
    注意，在后续操作中你可以对减半过的数继续执行操作）

    请你返回将 nums 数组和 至少 减少一半的 最少 操作数。

*/
/*
    思路：
        贪心算法，每次找数组中的最大值减半，用堆维护数组的最大元素
        每次取最大的减一半，再插入堆中，直到当前和小于等于总和的一半为止。
*/


class Solution {
public:
    int halveArray(vector<int>& nums) {
        priority_queue<double> que(nums.begin(), nums.end());
        int res = 0;
        double sum = accumulate(nums.begin(), nums.end(), 0.0);
        double sum2 = 0.0;
        while(sum2 < sum / 2){
            double x = que.top();
            que.pop();

            sum2 += x / 2;
            que.push(x / 2);
            res++;
        }
        return res;
    }
};