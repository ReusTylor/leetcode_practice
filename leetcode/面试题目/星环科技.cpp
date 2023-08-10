//
// Created by guessever on 23-8-6.
//
#include <iostream>
#include <cmath>

/*
bool isPerfectSquare(int num) {
  int sqrtNum = sqrt(num);
  return sqrtNum * sqrtNum == num;
}

int countPerfectSquarePairs(int n) {
  int count = 0;
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= n; ++j) {
      if (isPerfectSquare(i * j)) {
        ++count;
      }
    }
  }
  return count;
}

int main() {
  int n;
  std::cout << "Enter n: ";
  std::cin >> n;

  int result = countPerfectSquarePairs(n);
  std::cout << result << std::endl;

  return 0;
}*/


#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
  int n;
  cin >> n;

  int T, H;
  cin >> T >> H;

  vector<vector<int>> events(n, vector<int>(3));
  for (int i = 0; i < n; ++i) {
    cin >> events[i][0] >> events[i][1] >> events[i][2];
  }

  vector<vector<int>> dp(H + 1, vector<int>(T + 1, 0));

  for (int i = 0; i < n; ++i) {
    for (int h = H; h >= events[i][1]; --h) {
      for (int t = T; t >= events[i][0]; --t) {
        dp[h][t] = max(dp[h][t], dp[h - events[i][1]][t - events[i][0]] + events[i][2]);
      }
    }
  }

  int maxHappy = dp[H][T];
  cout << maxHappy << endl;

  return 0;
}


