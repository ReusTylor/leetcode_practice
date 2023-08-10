/*
    给定一个字符串 s ，请你找出其中不含有重复字符的 最长子串 的长度。
*/
/*
    滑动窗口问题
*/


#include <iostream>
#include<string>
#include<unordered_map>

using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        // 定义left 和 right分别为窗口的左右两边
        int left = 0, right = 0;
        unordered_map<char, int> window;
        int result = 0;
        while(right < s.size()){
            char c = s[right];
            right++;
            window[c]++;
            // 大于1说明有重复元素，所以窗口缩小
            while (window[c] > 1)
            {
                char d = s[left];
                left++;
                window[d]--;
            }
            // 经过窗口缩小后，此时没有重复元素了，记录最大值
            result = max(result , right - left);
            
        }
        return result;

    }
};

int main(){
    Solution s;
    string sstring = "abcabaabc";
    int result = s.lengthOfLongestSubstring(sstring);
    cout << result << endl;
    return 0;
}