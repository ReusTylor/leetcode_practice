//
// Created by guessever on 23-8-6.
//

#include <iostream>
#include <vector>
#include <climits>


using namespace std;

class Solution{
  int pos = 0;
 public:
  int min_Num(vector<int> vec, int start, int end){
    int minNum = INT_MAX;
    for(int i = start; i < end; i++){
      if(vec[i] < minNum){
        minNum = vec[i];
      }
    }
    return minNum;
  }
  int min_strong(vector<int> nums){

    for(int i = 0; i < nums.size(); i++){
      if(nums[i] == -1){
        pos = i;
        break;
      }
    }

    return min_Num(nums, 0, pos) + min_Num(nums, pos + 1, nums.size());

  }

};



int main(){
/*  int n;
  std::cin >> n;

  std::vector<int> strengths(n + 1);
  for (int i = 1; i <= n; ++i) {
    std::cin >> strengths[i];
  }*/
  vector<int> strengths{7, -1, 6, 2 ,5};

  Solution s;
  int result = s.min_strong(strengths);
  cout << result << endl;
  return result;
}