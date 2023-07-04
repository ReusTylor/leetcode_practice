#include <iostream>
#include <vector>
using namespace std;

class NumArray {
  vector<int> preSum;
 public:
  NumArray(vector<int>& nums) {
    preSum.resize(nums.size() + 1);
    for(int i = 1; i <= nums.size(); i++){
      preSum[i] = preSum[i - 1] + nums[i - 1];
    }
  }


  int sumRange(int left, int right) {
    return preSum[right + 1] - preSum[left];
  }
};

int main(){
  vector<int> nums = {-2, 0, 3, -5, 2, -1};
  NumArray* obj = new NumArray(nums);
  cout << obj->sumRange(0, 2) << endl;

  return 0;
}