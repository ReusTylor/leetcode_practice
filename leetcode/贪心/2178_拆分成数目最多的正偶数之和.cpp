/*
    给你一个整数 finalSum 。请你将它拆分成若干个 互不相同 的正偶数之和，且拆分出来的正偶数数目 最多 。

    比方说，给你 finalSum = 12 ，那么这些拆分是 符合要求 的（互不相同的正偶数且和为 finalSum）：(2 + 10) ，(2 + 4 + 6) 和 (4 + 8) 。
    它们中，(2 + 4 + 6) 包含最多数目的整数。注意 finalSum 不能拆分成 (2 + 2 + 4 + 4) ，因为拆分出来的整数必须互不相同。

    请你返回一个整数数组，表示将整数拆分成 最多 数目的正偶数数组。
    如果没有办法将 finalSum 进行拆分，请你返回一个 空 数组。你可以按 任意 顺序返回这些整数。

*/



#include<iostream>
#include<vector>
using namespace std;


class Solution {
public:
    vector<long long> maximumEvenSplit(long long finalSum) {
        vector<long long> result;
        if(finalSum % 2 != 0) return result;

        for(int i = 2; i <= finalSum; i += 2){
            result.emplace_back(i);
            finalSum -= i;
        } 

        result.back() += finalSum;
        return result;
    }
};

int main(){
    Solution s;
    vector<long long> result = s.maximumEvenSplit(12);
    for(auto i : result){
        cout << i << " ";
    }
    return 0;
}