/*
    给定两个字符串形式的非负整数 num1 和num2 ，计算它们的和并同样以字符串形式返回。

    你不能使用任何內建的用于处理大整数的库（比如 BigInteger）， 也不能直接将输入的字符串转换为整数形式。


*/

// 注意返回的是两个字符串的  和
// 采用模拟的方法，模拟以下竖式相加的过程
// 与链表相加类似



#include<iostream>
#include<string>
#include<algorithm>

using namespace std;

class Solution {
public:
    string addStrings(string num1, string num2) {
        int i = num1.size() - 1;
        int j = num2.size() - 1;
        int add = 0;
        string ans = "";
        while(i >= 0 || j >= 0 || add != 0){
            int x = i >= 0 ? num1[i] - '0' : 0;
            int y = j >= 0 ? num2[i] - '0' : 0;

            int result = x + y + add;
            add = result / 10;
            ans.push_back('0' + result % 10);

            i--;
            j--;
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }


};

int main(){
    string num1 = "123";
    string num2 = "456";
    Solution s;
    cout << s.addStrings(num1, num2) << endl;
    return 0;
}