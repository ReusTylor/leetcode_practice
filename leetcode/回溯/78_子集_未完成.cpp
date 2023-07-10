/*
    给你一个整数数组 nums ，数组中的元素 互不相同 。返回该数组所有可能的子集（幂集）。
    解集 不能 包含重复的子集。你可以按 任意顺序 返回解集。

    输入：nums = [1,2,3]
    输出：[[],[1],[2],[1,2],[3],[1,3],[2,3],[1,2,3]]
*/

// 组合问题和分割问题都是收集叶子节点，而子集问题收集树的所有节点
// 子集问题也是组合问题，因为集合是无序的


#include<iostream>
#include<vector>
using namespace std;

class Solution {
    vector<vector<int>> result;
    vector<int> path;

    void backtracking(vector<int> nums, int startIndex){
        result.push_back(path);// 收集子集，要放在终止添加的上面，否则会漏掉自己
        if(startIndex > nums.size())
            return;
        
        for(int i = startIndex; i < nums.size(); i++){
            path.push_back(nums[i]);
            backtracking(nums, i + 1);
            path.pop_back();
        }
    }
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        backtracking(nums, 0);
        return result;
    }
};

int main(){
    vector<int> nums = {1, 2, 3};
    Solution s;
    vector<vector<int>> result = s.subsets(nums);
    for(auto i : result){
        for(auto j : i){
            cout << j << " ";
        }
        cout << endl;
    }
    return 0;
}