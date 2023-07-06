/*
    找出所有相加之和为 n 的 k 个数的组合，且满足下列条件：

        只使用数字1到9
        每个数字 最多使用一次 

    返回 所有可能的有效组合的列表 。该列表不能包含相同的组合两次，组合可以以任何顺序返回。
*/
#include<iostream>
#include<vector>
using namespace std;


class Solution {
    vector<vector<int>> result;
    vector<int> path;
    void backtracking(int targetSum, int k, int sum, int startIndex){
        if(sum > targetSum){
            return;
        }
        if(path.size() == k){
            if(sum == targetSum){
                result.push_back(path);
                return;
            }
        }

        // i 指的就是1 2 3 这些数，而不是下标
        // i是从startIndex开始的
        // 注意i的剪枝操作
        for(int i = startIndex; i <= targetSum -(k-path.size()) + 1; i++){
            sum += i;
            path.push_back(i);
            backtracking(targetSum, k, sum, i + 1);
            // 回溯时记得要将sum减掉
            // 下面就是回溯的过程
            sum -= i;
            path.pop_back();
        }
    }
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        backtracking(n, k, 0, 1);
        return result;
    }
};

int main(){
    Solution s;
    vector<vector<int>> result = s.combinationSum3(3, 7);
    for(int i = 0; i < result.size(); i++){
        for(int j = 0; j < result[i].size(); j++){
            cout << result[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}