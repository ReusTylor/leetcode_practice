#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

class Solution {
// 在集合中找数，考虑用map
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> map;
        for(int i = 0; i < nums.size(); i++){
            auto it = map.find(target - nums[i]);
            if(it != map.end())
                return {i ,it->second};
            map[nums[i]] = i;
        }
        return {};
        
    }
};
int main(){
    int target = 18;
    vector<int> nums = {2, 7, 11, 15};
    Solution s;
    auto result = s.twoSum(nums, target);
    for(auto a : result)
        cout << a << " ";
    return 0;
}