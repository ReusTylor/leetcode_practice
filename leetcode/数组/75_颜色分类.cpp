/*
    给定一个包含红色、白色和蓝色、共 n 个元素的数组 nums ，原地对它们进行排序，使得相同颜色的元素相邻，并按照红色、白色、蓝色顺序排列。

    我们使用整数 0、 1 和 2 分别表示红色、白色和蓝色。

    必须在不使用库内置的 sort 函数的情况下解决这个问题。


    输入：nums = [2,0,2,1,1,0]
    输出：[0,0,1,1,2,2]

*/

/*
    使用两个指针分别指向左右两边，开始遍历数组，如果等于2就和右边交换，如果等于0就和左边交换，等于1就跳过
    - 遍历nums，当nums[i] == 1 i++;
    - 当nums[i] == 2, two 先 减1, 然后swap(nums[i], nums[two]);,注意这里交换后不能直接i++,而是要继续观察nums的值,因为此时的nums[i]是从后面换过来的，还需要继续判断
    - 当nums[i] == 0, zero++，而后交换nums[i]与nums[zero]，i++;当 i = two时，结束循环
*/
#include<iostream>
#include<vector>
using namespace std;


class Solution {
public:
    void sortColors(vector<int>& nums) {
        int zero = -1;
        int two = nums.size();
        // 注意这里是i < two 而不是i < nums.size()
        for(int i  = 0; i < two; ){
            if(nums[i] == 2){
                two--;
                swap(nums[i], nums[two]);
            }else if(nums[i] == 1){
                i++;
            }else{
                zero++;
                swap(nums[i], nums[zero]);
                i++;
            }
        }
    }
};

int main(){
    vector<int> nums = {2,0,2,1,1,0};
    Solution s;
    s.sortColors(nums);
    for(int i = 0; i < nums.size(); i++){
        cout << nums[i] << " ";
    }
    return 0;
}
