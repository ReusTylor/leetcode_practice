/*
    给你一个字符串 s ，请你统计并返回这个字符串中 回文子串 的数目。
    回文字符串 是正着读和倒过来读一样的字符串。
    子字符串 是字符串中的由连续字符组成的一个序列。
    具有不同开始位置或结束位置的子串，即使是由相同的字符组成，也会被视作不同的子串。
*/

/*
    不能按照一般的定义: dp[i] 为 下标i结尾的字符串有 dp[i]个回文串,很难找到递归关系
    dp[i][j]：表示区间范围[i,j] （注意是左闭右闭）的子串是否是回文子串，如果是dp[i][j]为true，否则为false。

    确定递推公式:
        如果s[i] != s[j] 那么dp[i][j] = false
        如果s[i] == s[j]
         1. i == j 同一个字符例如a 当然是回文子串
         2. i 与 j 相差1,例如aa,也是回文子串
         3. i 与 j 相差大于1,例如cabac，此时s[i]与s[j]已经相同了，我们看i到j区间是不是回文子串就看aba是不是回文就可以了，
            那么aba的区间就是 i+1 与 j-1区间，这个区间是不是回文就看dp[i + 1][j - 1]是否为true。
    if (s[i] == s[j]) {
        if (j - i <= 1) { // 情况一 和 情况二
            result++; // 统计回文子串的数量
            dp[i][j] = true;
        } else if (dp[i + 1][j - 1]) { // 情况三
            result++;
            dp[i][j] = true;
        }
    }


    初始化:
        dp[i][j]初始化为false
    
    确定遍历顺序
        从递推公式中可以看出，情况三是根据dp[i + 1][j - 1]是否为true，在对dp[i][j]进行赋值true的。
        dp[i + 1][j - 1] 在 dp[i][j]的左下角

        所以一定要从下到上，从左到右遍历，这样保证dp[i + 1][j - 1]都是经过计算的。
*/

#include<vector>
#include<string>
using namespace std;


class Solution {
public:
    int countSubstrings(string s) {
        vector<vector<bool>> dp(s.size(), vector<bool>(s.size(), false));
        int result = 0;
        for (int i = s.size() - 1; i >= 0; i--) {  // 注意遍历顺序
            for (int j = i; j < s.size(); j++) {
                if (s[i] == s[j]) {
                    if (j - i <= 1) { // 情况一 和 情况二
                        result++;
                        dp[i][j] = true;
                    } else if (dp[i + 1][j - 1]) { // 情况三
                        result++;
                        dp[i][j] = true;
                    }
                }
            }
        }
        return result;
    }
};





// 双指针法

class Solution {
public:
    int countSubstrings(string s){
        int result = 0;
        for(int i = 0; i < s.size(); i++){
            result += extend(s, i, i, s.size());
            result += extend(s, i, i + 1, s.size());
        }
        return result;
    }    

    int extend(const string& s, int i , int j, int n){
        int res = 0;
        while(i >= 0 && j < n && s[i] == s[j]){
            i--;
            j++;
            res++;
        }
        return res;
    }
};
