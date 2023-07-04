### 寻找左侧边界的二分搜索
```C++
int left_bound(vector<int> &nums, int target){
    int left = 0;
    int right = nums.size() - 1;

    while(left <= right){
        int mid = left + (right - left)/2;
        if(nums[mid] == target){
            // 可见，找到 target 时不要立即返回，而是缩小「搜索区间」的上界 right，在区间 [left, mid) 中继续搜索，即不断向左收缩，达到锁定左侧边界的目的。
            right = mid - 1;
        }else if(nums[mid] < target){
            left = mid + 1;
        }else if(nums[mid] > target){
            right = mid - 1;
        }
    }
    return left;
}
```


### 寻找右边界的二分查找
```C++
int left_bound(vector<int> &nums, int target){
    int left = 0;
    int right = nums.size() - 1;

    while(left <= right){
        int mid = left + (right - left)/2;
        if(nums[mid] == target){
            // 可见，找到 target 时不要立即返回，而是缩小「搜索区间」的上界 right，在区间 [left, mid) 中继续搜索，即不断向左收缩，达到锁定左侧边界的目的。
            left = mid + 1;
        }else if(nums[mid] < target){
            left = mid + 1;
        }else if(nums[mid] > target){
            right = mid - 1;
        }
    }
    return right;
}
```