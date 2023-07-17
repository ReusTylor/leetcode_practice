/*
    给定字符串 s 和 t ，判断 s 是否为 t 的子序列。

    字符串的一个子序列是原始字符串删除一些（也可以不删除）字符而不改变剩余字符相对位置形成的新字符串。
    （例如，"ace"是"abcde"的一个子序列，而"aec"不是）。


    输入：s = "abc", t = "ahbgdc"
    输出：true


*/

// 与1143.最长公共子序列的区别在于 本题如果删除元素就一定是字符串t，而1143.最长公共子序列两个字符串都可以删除元素
/*
    s是t的子序列，可以理解为 t删除一些元素之后可以得到s
*/

#include <iostream>
#include <string>
using namespace std;


class Solution {
public:
    bool numDistinct(string s, string t) {
        // 双指针法
        int i = 0, j = 0;
        while (i < s.size() || j < t.size())
        {
            /* code */
            if(s[i] == t[j]){
                i++;
                j++;
            }else{
                j++;
            }

        }
        if(i == s.size())
            return true;
        else
            return false;
    }
};

/*
    递归做法
    可以这样理解：如果s和t的最长公共子序列是s，那么就说明s是t的子序列
    dp[i][j]:以i-1为结尾的字符串和以j-1为结尾的字符串的相同子序列的长度

    判断s[i - 1] 和t[i -1]  dp[i][j] = dp[i - 1][j - 1] + 1
    
*/

class Solution1 {
public:
    bool isSubsequence(string s, string t) {

    }
};


int main(){
    string s = "axc";
    string t = "ahbgdc";
    Solution solution;
    cout << solution.numDistinct(s, t) << endl;
    return 0;
}




