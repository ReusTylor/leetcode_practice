/*
    给定一个字符串 s ，请你找出其中不含有重复字符的 最长子串 的长度。
*/
/*
    滑动窗口问题
    不定长度窗口求解步骤
    1. 将区间最右侧元素添加进窗口，window++;
    2. 向右移动right，从而增大窗口长度，即right++， 直到窗口中的连续元素满足要求
    3. 此时，停止增加窗口大小，转而不断将左侧元素移出窗口，window--
    4. 向右移动left，从而缩小窗口长度，即left++，知道窗口中元素不再满足要求
    5. 重复2 ~ 5
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