/*
    给定两个整数 n 和 k，返回范围 [1, n] 中所有可能的 k 个数的组合。
    你可以按 任何顺序 返回答案。

    输入：n = 4, k = 2
    输出：
    [
    [2,4],
    [3,4],
    [2,3],
    [1,2],
    [1,3],
    [1,4],
    ]
*/

// 一个集合求组合的话，就需要startIndex来控制for循环的起始位置，如果是多个集合取组合，各个组合之间互不影响，就不用startIndex了


#include<iostream>
#include<vector>
using namespace std;


class Solution {
    vector<vector<int>> result;
    vector<int> path;

    void backtracking(int n, int k, int startIndex){
        if(path.size() == k){
            result.push_back(path);
            return;
        }
        for(int i = startIndex; i <= n - (k - path.size()) + 1; i++){
            path.push_back(i);
            backtracking(n, k, i + 1);
            path.pop_back();
        }
    }
public:
    vector<vector<int>> combine(int n, int k) {
        backtracking(n, k, 1);
        return result;
    }
};

int main(){
    int n = 4;
    int k = 2;
    Solution s;
    vector<vector<int>> result = s.combine(n, k);
    for(auto i : result){
        for(auto j : i){
            cout << j << " ";
        }
        cout << endl;
    }
    return 0;
}