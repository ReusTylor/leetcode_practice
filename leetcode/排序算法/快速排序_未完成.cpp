/*
    快速排序（Quicksort）的原理就是先把数组分成两部分，其中左边的任何一个元素都小于右边的任何一个元素，
    通俗一点就是左边的最大值小于右边的最小值。分成这样的两部分之后，然后继续对左边和右边进行同样的操作，
    实际上就是把一个大问题拆成两个小的问题，我们发现他就是个递归，那么递归的终止条件是什么呢，就是数组为空或者只剩下一个元素为止，
    因为这样就没法在分了。怎么分呢？这里有多种方式，一种是用待排序序列的第一个元素作为中枢值，把序列中小于中枢值的往前挪，
    最后在把中枢值放到合适的位置，步骤如下：


    选择待排序序列的第一个元素作为中枢值，并使用两个指针 i 和 j，其中 j 指向待排序列的第一个元素，i 指向待排序列的第二个元素 。
    如果 nums[i] 比中枢值大，i 往右移一步，j 不动。
    如果 nums[i] 比中枢值小，j 先往右移一步，然后和 i 指向的值交换（目的就是把小的往前挪），接着 i 往右移，继续重复上面的步骤。

*/

#include <iostream>
#include<stdio.h>
#include<math.h>
#include<algorithm>

using namespace std;
// 划分函数
int partition(vector<int>& nums, int left, int right){
    int i = left; 
    int j = right;
    int pivot = nums[left];
    while(i < j){
        while(i < j && nums[j] >= pivot) j--;
        while(i < j && nums[i] <= pivot) i++;

        swap(nums[i], nums[j]);
    }
    swap(nums[j], nums[left]);
    return j; 
}

void quickSort(vector<int>& nums, int left, int right){
    if(left >= right) return;
    int i = partition(nums, left, right);
    quickSort(nums, left, i - 1);
    quickSort(nums, i + 1, right);
}

int main()
{
    vector<int> nums = {1, 3, 2, 5, 4, 6, 7, 8, 9, 0};
    quickSort(nums, 0, nums.size() - 1);
    for(int i = 0; i < nums.size(); i++){
        cout << nums[i] << " ";
    }
    return 0;
}
