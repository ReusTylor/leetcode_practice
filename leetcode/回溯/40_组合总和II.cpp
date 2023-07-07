/*
    给定一个候选人编号的集合 candidates 和一个目标数 target ，找出 candidates 中所有可以使数字和为 target 的组合。
    candidates 中的每个数字在每个组合中只能使用 一次 。
    注意：解集不能包含重复的组合。 

    输入: candidates = [10,1,2,7,6,1,5], target = 8,
    输出:
    [
    [1,1,6],
    [1,2,5],
    [1,7],
    [2,6]
    ]
*/

// 集合中有重复的元素，但是解集不能有重复的集合。
// 与组合总和的套路一致，需要一个bool数组记录同一树枝上的元素是否使用过
// 集合去重由used数组完成

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
    vector<vector<int>> result;
    vector<int> path;
    void backtracking(vector<int> candidates, int target, int sum, int startIndex, vector<bool>& used){
        if(sum > target){
            return;
        }
        if(sum == target){
            result.push_back(path);
            return;
        }
        // 如果candidates[i] == candidates[i - 1] 并且 used[i - 1] == false，
        // 就说明：前一个树枝，使用了candidates[i - 1]，也就是说同一树层使用过candidates[i - 1]。
        for(int i = startIndex; i < candidates.size() && sum + candidates[i] <= target; i++){
            // 跳过的逻辑
            if (i > 0 && candidates[i] == candidates[i - 1] && used[i - 1] == false) {
                continue;
            }
            
            sum += candidates[i];
            path.push_back(candidates[i]);
            used[i] = true;
            backtracking(candidates, target, sum, i + 1, used); // 与组合总和相比，这里是i+1，每个数字在每个组合中只能使用一次
            path.pop_back();
            used[i] = false;    

            sum -= candidates[i];
        }
    }
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<bool> used(candidates.size(), false);
        sort(candidates.begin(), candidates.end());
        backtracking(candidates, target, 0, 0, used);
        return result;
    }
};

int main(){
    vector<int> candidates{10,1,2,7,6,1,5};
    int target = 8;
    Solution s;
    vector<vector<int>> result = s.combinationSum2(candidates, target);
    for(auto i : result){
        for(auto j : i){
            cout << j << " ";
        }
        cout << endl;
    }
}