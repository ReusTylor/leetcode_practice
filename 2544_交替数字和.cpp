// 使用一个flag变量来确定正负

#include<iostream>
#include<stack>
#include<algorithm>
#include<cmath>
using namespace std;



class Solution {
public:
    int alternateDigitSum(int n) {
        // 转成单个的数
        int sum = 0;
        int param = 2;
        stack<int> stk;
        while(n > 0){
            stk.push(n % 10);
            n /= 10;
        }
        while(!stk.empty()){
            int a = stk.top();
            stk.pop();
            sum += pow(-1, param) * a;
            param++;
        }
        return sum;
    }
};


int main(){
    Solution s;
    int result = s.alternateDigitSum(521);
    cout << result << endl;
    return 0;
}