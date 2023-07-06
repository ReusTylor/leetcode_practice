/*
    给定一个仅包含数字 2-9 的字符串，返回所有它能表示的字母组合。答案可以按 任意顺序 返回。

    给出数字到字母的映射如下（与电话按键相同）。注意 1 不对应任何字母。

    输入：digits = "23"
    输出：["ad","ae","af","bd","be","bf","cd","ce","cf"]
*/
// 相当于多个集合求组合，39 216都是一个集合求组合
#include<iostream>
#include<string>
#include<vector>

using namespace std;

// 如何将字母和数字对应起来
const string letterMap[10] = {
    "", // 0
    "", // 1
    "abc", // 2
    "def", // 3
    "ghi", // 4
    "jkl", // 5
    "mno", // 6
    "pqrs", // 7
    "tuv", // 8
    "wxyz", // 9
};
class Solution {
    // 记录结果
    vector<string> result;
    // 在循环中记录每一次的s
    string s;
    // index记录遍历了第几个数字了
    void backtracking(string digits, int index){
        // 如果遍历到了最后一个数字，那么就将s放入到result中
        if(index == digits.size()){
            result.push_back(s);
            return;
        }
        // 将string中的digit转换成int类型的变量，比如23中的2变成int 2
        int digit = digits[index] - '0';
        // 将letters是每一个按键对应的三个字母
        string letters = letterMap[digit];
        for(int i = 0; i < letters.size(); i++){
            s.push_back(letters[i]);
            backtracking(digits, index + 1);
            s.pop_back();
        }
    
    }
public:
    vector<string> letterCombinations(string digits) {
        if(digits.size() == 0)
            return result;
        backtracking(digits, 0);
        return result;
    }
};

int main(){
    Solution s;
    vector<string> result = s.letterCombinations("23");
    for(int i = 0; i < result.size(); i++){
        cout << result[i] << endl;
    }
    return 0;
}