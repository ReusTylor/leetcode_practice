//
//使用逗号分割字符串，有点问题 大致就这个意思
/*
 * 输入 string = “abs, eft,s" ch = ','
 * 输出 [abs, eft, s]
 */

#include <bits/stdc++.h>
using namespace std;

class Solution{
public:
    vector<string> cutString(string& s){
        vector<string> result;
        int left = 0;
        for(int i = 0; i < s.size(); i++){
            if(s[i] == ','){
                string str = s.substr(left , i - left);
                result.emplace_back(str);
                left = i + 1;
            }
        }
        string s1 = s.substr(left, s.size());
        result.emplace_back(s1);
        return result;
    }
};

int main(){
    string s = "abs, eft,s";
    Solution s1;
    vector<string> res = s1.cutString(s);
    for(string& str : res){
        cout << str << ",";
    }
    cout << endl;
}