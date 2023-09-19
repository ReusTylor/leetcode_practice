#include <iostream>
#include <vector>

using namespace std;

double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2)
{
    int n1 = nums1.size(), n2 = nums2.size();
    if (n1 > n2)
    {
        return findMedianSortedArrays(nums2, nums1);
    }
    int k = (n1 + n2 + 1) >> 1;
    int l = 0, r = n1 - 1;
    while (l <= r)
    {
        int m1 = l + ((r - l) >> 1);
        int m2 = k - m1;
        if (nums1[m1] <= nums2[m2 - 1])
        {
            l = m1 + 1;
        }
        else
        {
            r = m1 - 1;
        }
    }
    int n1_l = l == 0 ? INT_MIN : nums1[l - 1];
    int n1_r = l == n1 ? INT_MAX : nums1[l];
    int n2_l = k - l == 0 ? INT_MIN : nums2[k - l - 1];
    int n2_r = k - l == n2 ? INT_MAX : nums2[k - l];

    int res = max(n1_l, n2_l);
    if ((n1 + n2) % 2 == 1)
    {
        return (double)res;
    }
    else
    {
        return (double)(res + min(n1_r, n2_r)) / 2.0;
    }
}

int main()
{
    string a, b;
    cin >> a >> b;
    vector<int> nums_a, nums_b;
    string tmp = "";
    for (int i = 0; i < a.size(); i++)
    {
        if (a[i] != ',')
        {
            tmp += a[i];
        }
        else
        {
            nums_a.push_back(stoi(tmp));
            tmp = "";
        }
    }
    nums_a.push_back(stoi(tmp));
    tmp = "";
    for (int i = 0; i < b.size(); i++)
    {
        if (a[i] != ',')
        {
            tmp += b[i];
        }
        else
        {
            nums_b.push_back(stoi(tmp));
            tmp = "";
        }
    }
    nums_b.push_back(stoi(tmp));
    printf("%.1f", findMedianSortedArrays(nums_a, nums_b));
    return 0;
}