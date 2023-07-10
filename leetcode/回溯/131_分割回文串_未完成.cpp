/*
    给定一个字符串 s，将 s 分割成一些子串，使每个子串都是回文串。

    返回 s 所有可能的分割方案。

    示例: 输入: "aab" 输出: [ ["aa","b"], ["a","a","b"] ]

*/

/*
    切割问题
    注意事项：第一次做时，把切割的是否是回文子串作为了终止条件，这是不对的。
*/

#include<iostream>
#include<string>
#include<vector>
using namespace std;

class Solution {
    vector<vector<string>> result;
    vector<string> path; // 存放已经回文的子串
    // 还是需要startindex，因为切割过的地方不能重复切割
    bool isPalindrome(const string& s, int start, int end) {
        for (int i = start, j = end; i < j; i++, j--) {
            if (s[i] != s[j]) {
                return false;
            }
        }
        return true;
    }

    void backtracking(string s, int startIndex){
        // 如果起始位置 > s.size()，说明已经找到一组分割方案了
        if(startIndex >= s.size()){
            result.push_back(path);
            return;
        }
        // if(is_huiwen(path)){
        //     result.push_back(path);
        //     return;
        // }

        // 起始位置startIndex，那么[startIndex, i]就是要截取的子串
        for(int i = startIndex; i < s.size(); i++){
            if(isPalindrome(s, startIndex, i)){ // 是回文子串
            // 获取[startIndex,i]在s中的子串
                string str = s.substr(startIndex, i - startIndex + 1);
                path.push_back(str);
            }else{
                continue; // 不是回文，跳过
            }

            backtracking(s, i + 1);// 寻找i + 1为起始位置的子串
            path.pop_back();
        }
    }
public:
    vector<vector<string>> partition(string s) {
        backtracking(s, 0);
        return result;
    }
};

int main(){
    string s = "aab";
    Solution so;
    vector<vector<string>> result = so.partition(s);
    for(auto i : result){
        for(auto j : i){
            cout << j << " ";
        }
        cout << endl;
    }
    return 0;
}