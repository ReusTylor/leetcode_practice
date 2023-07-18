/*
    给你一个二叉树的根节点 root ， 检查它是否轴对称。
*/


/*
    递归法：
        1. 要比较的是根节点的两个子树是否是相互翻转的，进而判断这个树是不是对称树，所以要比较的是两个树
        2. 终止条件：
                左节点为空，右节点不为空，不对称，return false
                左不为空，右为空，不对称 return false
                左右都为空，对称，返回true
                左右都不为空，比较节点数值，不相同就return false
        3. 确定单层递归的逻辑
            单层递归的逻辑就是处理左右节点不为空的情况，且数值相同的情况。
                比较二叉树外侧是否对称：传入的是左节点的左孩子，右节点的右孩子。
                比较内侧是否对称，传入左节点的右孩子，右节点的左孩子。
                如果左右都对称就返回true ，有一侧不对称就返回false 。
*/

#include<iostream>
#include<vector>
#include<stack>
#include<queue>
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
    bool compare(TreeNode* left, TreeNode* right){
        if(left == nullptr && right != nullptr) return false;
        else if(left != nullptr && right == nullptr) return false;
        else if(left == nullptr && right == nullptr) return true;
        else if(left->val != right->val) return false;
        // 此时是左右节点都不为空，且数值相同的情况
        // 此时才做递归，做下一层的判断
        bool outside = compare(left->left, right->right);
        bool inside = compare(left->right, right->left);
        bool isSame = outside && inside;

        return isSame;


    }
    bool isSymmetric(TreeNode* root) {
        if(root == nullptr) return true;
        return compare(root->left, root->right);
    }
};