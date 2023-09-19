/*
    给定一个会议时间安排的数组 intervals ，每个会议时间都会包括开始和结束的时间 intervals[i] = [starti, endi] ，
    请你判断一个人是否能够参加这里面的全部会议。

    示例 1:：
    输入: intervals = [[0,30],[5,10],[15,20]]
    输出: false
    解释: 存在重叠区间，一个人在同一时刻只能参加一个会议。
*/

// 本质是判断是否存在重叠区间

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool canAttendMeetings(vector<vector<int>> &intervals)
    {
        sort(intervals.begin(), intervals.end(), [&](auto a, auto b)
             { return a[0] < b[0]; });

        for (int i = 1; i < intervals.size(); i++)
        {
            if (intervals[i][0] < intervals[i - 1][1])
                return false;
        }
        return true;
    }
};

int main()
{
    Solution s;
    vector<vector<int>> intervals{{0, 30}, {5, 10}, {15, 20}};
    bool result = s.canAttendMeetings(intervals);
    cout << result << endl;
    return 0;
}