/*
    有效 IP 地址 正好由四个整数（每个整数位于 0 到 255 之间组成，且不能含有前导 0），整数之间用 '.' 分隔。

    例如："0.1.2.201" 和 "192.168.1.1" 是 有效 IP 地址，但是 "0.011.255.245"、"192.168.1.312" 和 "192.168@1.1" 是 无效 IP 地址。

    给定一个只包含数字的字符串 s ，用以表示一个 IP 地址，返回所有可能的有效 IP 地址，这些地址可以通过在 s 中插入 '.' 来形成。
    你 不能 重新排序或删除 s 中的任何数字。你可以按 任何 顺序返回答案。
*/

// 类似于切割问题，但是切割的长度有限制，切割的长度为1，2，3
// startIndex是一定需要的，因为不能重复分割，记录下一层递归分割的起始位置
// 本题还需要一个变量PointNum记录添加点的数量

#include<iostream>
#include<vector>
using namespace std;

class Solution {
    vector<string> result;// 记录结果
    // startIndex 搜索的起始位置， pointNum 添加句点的数量
    // pointNum为3 说明字符串分成了4段

    bool isValid(string s, int start, int end){
        if(start > end)
            return false;
        // 只有一个0的情况是合法的
        if(s[start] == '0' && start != end)
            return false;
        
        int num = 0;
        for(int i = start; i <= end; i++){
            // 如果不是数字，不合法
            if(s[i] > '9' && s[i] < '0')
                return false;
            // 计算字符串转换为数字
            num = num * 10 + (s[i] - '0');
            if(num > 255)
                return false;
        }
        return true;
    }


    void backtracking(string s, int startIndex, int pointNum){
        if(pointNum == 3){
            if(isValid(s, startIndex, s.size() - 1)){
                result.push_back(s);
            }
            return;
        }
        // 在for (int i = startIndex; i < s.size(); i++)循环中 [startIndex, i] 这个区间就是截取的子串，需要判断这个子串是否合法。
        // 递归调用时，下一层递归的startIndex要从i+2开始（因为需要在字符串中加入分割符。同时记录分隔符的数量pointNum+1
        // 回溯时将加入的分隔符删掉，pointNum -1 

        for(int i = startIndex; i < s.size(); i++){
            if(isValid(s, startIndex, i)){ // 判断[startIndex,i]区间内子串是否合法
                s.insert(s.begin() + i + 1, '.'); // 在i的后面插入一个分隔符
                pointNum++;
                backtracking(s, i + 2, pointNum); // 插入分隔符之后下一个子串的起始位置为i+2
                pointNum--;
                s.erase(s.begin() + i + 1); // 回溯，移除分隔符
            }else break;
            
        }
    }

public:
    vector<string> restoreIpAddresses(string s) {
        if(s.size() < 4 || s.size() > 12) return result;
        backtracking(s, 0, 0);
        return result; 
    }
};