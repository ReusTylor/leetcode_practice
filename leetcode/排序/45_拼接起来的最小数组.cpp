//
// Created by Reus on 2023/8/10.
//
/**
* 输入一个非负整数数组，把数组里所有数字拼接起来排成一个数，打印能拼接出的所有数字中最小的一个。
 * 输入: [10,2]
 * 输出: "102"
*/

/**
 * 求拼接起来的最小数组
 * 本质上是一个排序问题，设数组nums中任意两个数字的字符串为x和y, 则规定，排序判断规则为：
 * 若拼接字符串 x+y>y+xx + y > y + xx+y>y+x ，则 xxx “大于” yyy ;
 * 反之，若 x+y<y+xx + y < y + xx+y<y+x ，则 xxx “小于” yyy ;
 * 根据以上规则，套用任何排序方法对nums执行排序即可
 */

#include <bits/stdc++.h>
using namespace std;

class Solution{
public:
    string minNumber(vector<int>& nums){
        vector<string> strs;
        for(int i = 0; i < nums.size(); i++){
            strs.push_back(to_string(nums[i]));
        }
        quickSort(strs, 0, strs.size() - 1);
        string res;
        for(string s : strs){
            res.append(s);
        }
        return res;
    }
private:
    void quickSort(vector<string>& strs, int left, int right){
        if(left >= right) return;
        int i = left;
        int j = right;
        while(i < j){
            while(strs[j] + strs[left] >= strs[left] + strs[j] && i < j) j--;
            while(strs[i] + strs[left] <= strs[left] + strs[i] && i < j) i++;
            swap(strs[i], strs[j]);
        }
        swap(strs[i], strs[left]);
        quickSort(strs, left, i - 1);
        quickSort(strs, i + 1, right);
    }
};

int main(){
    vector<int> nums{10, 2};
    Solution s;
    s.minNumber(nums);
    for(int num : nums){
        cout << num << " ";
    }
}