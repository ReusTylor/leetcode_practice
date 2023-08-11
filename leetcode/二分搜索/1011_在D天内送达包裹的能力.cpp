//
// Created by Reus on 2023/8/11.
//
/*
传送带上的包裹必须在 days 天内从一个港口运送到另一个港口。
传送带上的第 i 个包裹的重量为 weights[i]。每一天，我们都会按给出重量（weights）的顺序往传送带上装载包裹。
我们装载的重量不会超过船的最大运载重量。
返回能在 days 天内将传送带上的所有包裹送达的船的最低运载能力。

    输入：weights = [1,2,3,4,5,6,7,8,9,10], days = 5
    输出：15
    解释：
    船舶最低载重 15 就能够在 5 天内送达所有包裹，如下所示：
    第 1 天：1, 2, 3, 4, 5
    第 2 天：6, 7
    第 3 天：8
    第 4 天：9
    第 5 天：10
 */
/*
 * 解析：
 * 1. 确定运载量的范围
 *  在D天内运送完所有的货物，首先给船的运载量确定一个范围，为了后面的二分。
 *  - 极端情况1： 一天运送完所有的货物，此时船的运载量为所有重物之和，记为sum
 *  - 极端情况2：D天送完所有的货物，运载量 >= sum/D
 *  - 此外，船的运载量要大于货物中重量最大的那一个，因为货物不可拆分，记为weightMax
 * 2. 确定二分查找范围后，设置上下限，二分查找。上界为high，下界为low，mid为暂时的运载量，查看在运载量为mid的情况下，能用多少天
 */
#include <bits/stdc++.h>
using namespace std;

class Solution{
 public:
    int shipWithinDays(vector<int>& weights, int days) {
        int sum = 0; // 货物总重量
        int maxNum = 0; // 货物中的最大重量
        for(int i = 0; i < weights.size(); i++){
            sum += weights[i];
            maxNum = max(maxNum, weights[i]);
        }
        // 运载量下限：
        int low = max(sum / days, maxNum);


        // 运载量上限
        int high = sum;

        int ans = 0;
        while (low <= high){
            // 当前的运载量记为mid
            int mid = (low + high) / 2;
            int tempDay = 1;// 当前运载量情况下，用的天数，至少是一天
            int tempSum = 0;// 存放当前这一天已经装上的货物重量
            for (int i = 0; i < weights.size(); ++i) {
                if(tempSum + weights[i] <= mid){
                    // 当前的运载量没有超过上限时，还能继续加货物，就继续加
                    tempSum += weights[i];
                }else{
                    // 再加货物量超过运载量了，开启新的一天
                    tempDay++;
                    tempSum = weights[i];
                }
            }

            if(tempDay <= days){
                //当前运载量下，我们使用的天数如果小于规定天数，是一个可能的解，我们记录下来
                //同时降低运载量，看看还能找到更低的吗
                high = mid - 1;
                ans = mid;
            }else{
                //当前运载量我们使用的天数如果大于days天，不符合要求
                //提高运载量，看看能不能减少使用的天数
                low = mid + 1;
            }
        }
        return ans;
    }
};

int main() {
  vector<int> nums{1,2,3,4,5,6,7,8,9,10};
  int days = 5;
  Solution s;
  cout << s.shipWithinDays(nums, days) << endl;
}
