/*
   给定一个包含 n + 1 个整数的数组 nums ，其数字都在 [1, n] 范围内（包括 1 和 n），可知至少存在一个重复的整数。

    假设 nums 只有 一个重复的整数 ，返回 这个重复的数 。

    你设计的解决方案必须 不修改 数组 nums 且只用常量级 O(1) 的额外空间。

    输入：nums = [1,3,4,2,2]
    输出：2
*/

/*
    最简单的是使用哈希，但是不符合空间复杂度的要求
*/

#include<iostream>
#include<vector>
#include<unordered_set>
using namespace std;

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        unordered_set<int> s;
        for(int num : nums){
            if(s.find(num) != s.end()){
                return num;
            }
            s.emplace(num);
        }
        return 0;
    }
};

/*
    弗洛伊德判圈法
*/
class Solution2{
    int findDuplicate(vector<int>& nums){
        int slow = 0, fast = 0;
        do{
            slow = nums[slow];
            fast = nums[nums[fast]];
        }while(slow != fast);
        slow = 0;
        while(slow != fast){
            slow = nums[slow];
            fast = nums[fast];
        }
        return slow;
    }
};

/*
    二分法
*/
// n + 1 个整数，放在长度为 n 的数组里，根据「抽屉原理」，至少会有 1 个整数是重复的；
class Solution3{
    int findDuplicate(vector<int>& nums){
        int len = nums.size();

        int left = 1;
        int right = len - 1;
        while(left < right){
            int mid = left + (right - left) / 2;
            // 统计nums中小于等于mid的元素的个数
            int count = 0;
            for(int num : nums){
                if(num <= mid){
                    count++;
                }
            }
            if(count > mid){
                right = mid;
            }else{
                left = mid + 1;
            }
        }
        return left;
    }
};


int main(){
    vector<int> nums = {1,3,4,2,2};
    Solution s;
    cout << s.findDuplicate(nums) << endl;
    return 0;
}