//
// Created by guessever on 23-8-11.
//
/*
请你将一些箱子装在 一辆卡车 上。给你一个二维数组 boxTypes ，其中 boxTypes[i] = [numberOfBoxesi, numberOfUnitsPerBoxi] ：

numberOfBoxesi 是类型 i 的箱子的数量。
numberOfUnitsPerBoxi 是类型 i 每个箱子可以装载的单元数量。

整数 truckSize 表示卡车上可以装载 箱子 的 最大数量 。只要箱子数量不超过 truckSize ，你就可以选择任意箱子装到卡车上。

返回卡车可以装载 单元 的 最大 总数。
   输入：boxTypes = [[1,3],[2,2],[3,1]], truckSize = 4
    输出：8
    解释：箱子的情况如下：
    - 1 个第一类的箱子，里面含 3 个单元。
    - 2 个第二类的箱子，每个里面含 2 个单元。
    - 3 个第三类的箱子，每个里面含 1 个单元。
    可以选择第一类和第二类的所有箱子，以及第三类的一个箱子。
    单元总数 = (1 * 3) + (2 * 2) + (1 * 1) = 8
*/

// 贪心：每次都拿剩下的箱子里单元数量最大的箱子即可，对boxTypes按照numberOfUnitsPerBox 进行排列。

#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
    sort(boxTypes.begin(), boxTypes.end(), [](const vector<int>& a, const vector<int>& b){
      return a[1] > b[1];
    });

    int res = 0;
    for(auto& boxType : boxTypes){
      int numberOfBoxes = boxType[0];
      int numberOfUnitsPerBox = boxType[1];
      if(numberOfBoxes < truckSize){
        res += numberOfBoxes * numberOfUnitsPerBox;
        truckSize -= numberOfBoxes;
      }else{
        res += truckSize * numberOfUnitsPerBox;
        break;
      }
    }
    return res;
  }
};

int main(){
  vector<vector<int>> box{{1, 3}, {2, 2}, {3, 1}};
  Solution s;
  int result = s.maximumUnits(box, 4);
  cout << result << endl;
}