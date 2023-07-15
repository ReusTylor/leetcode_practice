#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int test1(string A, string B, int insert, int deletee, int replace) {
    int m = A.length();
    int n = B.length();

    
    vector<vector<int>> dp(m + 1, vector<int>(n + 1));

    // 初始化
    for (int i = 0; i <= m; i++) {
        dp[i][0] = i * deletee;  
    }
    for (int j = 0; j <= n; j++) {
        dp[0][j] = j * insert;  
    }

    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            if (A[i - 1] == B[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1];  // 相同
            } else {
                // 删除 插入 替换
                dp[i][j] = min({dp[i - 1][j] + deletee,dp[i][j - 1] + insert,dp[i - 1][j - 1] + replace});

            }
        }
    }

    return dp[m][n];
}

int main() {
    string A = "finereport";
    string B = "fanruan666";
    int insert = 2;  
    int deletee = 4;  
    int replace = 8;  

    int min = test1(A, B, insert, deletee, replace);
    cout <<  min << endl;

    return 0;
}
