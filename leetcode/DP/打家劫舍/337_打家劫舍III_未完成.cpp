/*
    在上次打劫完一条街道之后和一圈房屋后，小偷又发现了一个新的可行窃的地区。这个地区只有一个入口，我们称之为“根”。
    除了“根”之外，每栋房子有且只有一个“父“房子与之相连。一番侦察之后，聪明的小偷意识到“这个地方的所有房屋的排列类似于一棵二叉树”。 
    如果两个直接相连的房子在同一天晚上被打劫，房屋将自动报警。

    计算在不触动警报的情况下，小偷一晚能够盗取的最高金额。
*/


/*
    树形DP
*/
/*
    1. 确定递归函数的参数和返回值
        要求一个节点偷与不偷的两个状态得到的金钱，那么返回值就是一个长度为2的数组，返回的即为dp数组，dp[0]表示不偷，dp[1]表示偷该节点得到的最大金钱
    
    2. 终止条件
        如果遇到空节点的话，很明显，无论偷还是不偷都是0，所以就返回

    3. 遍历顺序
        首先明确的是使用后序遍历。 因为要通过递归函数的返回值来做下一步计算。
        通过递归左节点，得到左节点偷与不偷的金钱。
        通过递归右节点，得到右节点偷与不偷的金钱。

    4. 单层递归逻辑
        如果是偷当前节点，那么左右孩子就不能偷，val1 = cur->val + left[0] + right[0];
        如果不偷当前节点，那么左右孩子就可以偷，至于到底偷不偷一定是选一个最大的，
        所以：val2 = max(left[0], left[1]) + max(right[0], right[1]);
        最后当前节点的状态就是{val2, val1}; 即：{不偷当前节点得到的最大金钱，偷当前节点得到的最大金钱}

        
    5. 举例推导dp数组


*/
#include<iostream>
#include<vector>
using namespace std;

 
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    int rob(TreeNode* root) {
        vector<int> result = robTree(root);
        return max(result[0], result[1]);
    }

    vector<int> robTree(TreeNode* cur){
        if(cur == nullptr) return vector<int>{0, 0};
        vector<int> left = robTree(cur->left);
        vector<int> right = robTree(cur->right);
        // 偷cur，那么就不能偷左右节点
        int val1 = cur->val + left[0] + right[0];
        int val2 = max(left[0], left[1]) + max(right[0], right[1]);
        return {val2, val1};    
    }
};