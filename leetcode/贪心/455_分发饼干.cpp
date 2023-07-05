/*
    假设你是一位很棒的家长，想要给你的孩子们一些小饼干。
    但是，每个孩子最多只能给一块饼干。

    对每个孩子 i，都有一个胃口值 g[i]，这是能让孩子们满足胃口的饼干的最小尺寸；
    并且每块饼干 j，都有一个尺寸 s[j] 。
    如果 s[j] >= g[i]，我们可以将这个饼干 j 分配给孩子 i ，这个孩子会得到满足。
    
    你的目标是尽可能满足越多数量的孩子，并输出这个最大数值。


*/

// 贪心策略，用大饼干优先满足胃口大的孩子

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(), g.end());//胃口值
        sort(s.begin(), s.end());// 饼干的质量
        int index = s.size() - 1;
        int result = 0;
        for(int i = g.size() - 1; i >= 0; i--){// 遍历胃口
        // 使用一个index控制饼干数组的遍历
            if(index >= 0 && s[index] >= g[i]){
                result++;
                index--;
            }
        }
        return result;
    }
};