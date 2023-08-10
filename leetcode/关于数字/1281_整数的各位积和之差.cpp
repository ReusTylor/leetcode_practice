/**
 * 1281. 整数的各位积和之差
 * 给你一个整数 n，请你帮忙计算并返回该整数「各位数字之积」与「各位数字之和」的差。
*/

#include<bits/stdc++.h>
using namespace std;

class Solution{
public:
    static int subtractProductAndSum(int n) {
        int sum = 0;
        int product = 1;
        while(n){
            sum += n % 10;
            product *= n % 10;
            n /= 10;
        }
        return product - sum;
    }
};

int main(){
    int n = 234;
    cout << Solution::subtractProductAndSum(n)<<endl;


}
