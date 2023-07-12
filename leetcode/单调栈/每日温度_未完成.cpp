/*
    给定一个整数数组 temperatures ，表示每天的温度，返回一个数组 answer ，
    其中 answer[i] 是指对于第 i 天，下一个更高温度出现在几天后。如果气温在这之后都不会升高，请在该位置用 0 来代替。

    输入: temperatures = [73,74,75,71,69,72,76,73]
    输出: [1,1,4,2,1,1,0,0]
*/


#include<iostream>
#include<vector>
#include<stack>
using namespace std;


class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        //递增栈
        stack<int> st;
        vector<int> result(temperatures.size(), 0);
        st.push(0);
        for(int i = 1; i < temperatures.size(); i++){
            // 因为栈中存储的是下标而不是具体的值
            if(temperatures[i] < temperatures[st.top()]){
                st.push(i);
            }else if(temperatures[i] == temperatures[st.top()]){
                st.push(i);
            }else{
                while (!st.empty() && temperatures[i] > temperatures[st.top()])
                {
                    /* code */
                    result[st.top()] = i - st.top();
                    st.pop();
                }
                st.push(i);               
            }
        }
        return result;
    }
};

int main(){
    vector<int> T = {73,74,75,71,69,72,76,73};
    Solution s;
    vector<int> result = s.dailyTemperatures(T);
    for(int a : result){
        cout << a << " ";
    }
    return 0;
}