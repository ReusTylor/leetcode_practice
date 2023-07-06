/*
    给你一个 无重复元素 的整数数组 candidates 和一个目标整数 target ，找出 candidates 中可以使数字和为目标数 target 的 所有 不同组合 ，
    并以列表形式返回。你可以按 任意顺序 返回这些组合。

    candidates 中的 同一个 数字可以 无限制重复被选取 。如果至少一个数字的被选数量不同，则两种组合是不同的。 

    对于给定的输入，保证和为 target 的不同组合数少于 150 个。

*/
#include <iostream>
#include<vector>

using namespace std;

class Solution {
    vector<vector<int>> result;
    vector<int> path;
    void backtracking(vector<int>& candidates, int target,int sum, int startIndex){

        if(sum > target){
            return;
        }
        if(sum  == target){
            result.emplace_back(path);
            return;
        }

        for(int i = startIndex; i < candidates.size(); i++){
            sum += candidates[i];
            path.emplace_back(candidates[i]);

            backtracking(candidates, target, sum, i);

            sum -= candidates[i];
            path.pop_back();
        }
    }
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        backtracking(candidates, target, 0, 0);
        return result;
    }
};

int main()
{
    vector<int> candidates = {2,3,6,7};
    int target = 7;
    Solution s;
    vector<vector<int>> result = s.combinationSum(candidates, target);
    for(auto i : result){
        for(auto j : i){
            cout << j << " ";
        }
        cout << endl;
    }
    return 0;
}