/*
n 个朋友在玩游戏。这些朋友坐成一个圈，按 顺时针方向 从 1 到 n 编号。
从第 i 个朋友的位置开始顺时针移动 1 步会到达第 (i + 1) 个朋友的位置（1 <= i < n），
而从第 n 个朋友的位置开始顺时针移动 1 步会回到第 1 个朋友的位置。
*/

// 使用unordered_map作为一个记录，key值表示坐的位置，value表示当前被访问的次数
// 用d记录每一步的步长
// 第 i 个朋友的位置顺时针移动1步会达到第(i + 1) mod n + 1 个朋友的位置

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> circularGameLosers(int n, int k) {
        unordered_map<int, int> mp;
        int now = 0;
        int d = k;
        while(true){
            mp[now]++;
            if(mp[now] >= 2){
                break;
            }
            now = (now + d) % n;
            d += k;
        }
        vector<int> ans;
        for(int i = 0; i < n; i++){
            if(mp[i] == false){
                ans.emplace_back(i + 1);
            }
        }
        return ans;
    }
};