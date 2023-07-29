/*
    给你一棵 完全二叉树 的根节点 root ，求出该树的节点个数。
    完全二叉树 的定义如下：在完全二叉树中，除了最底层节点可能没填满外，其余每层节点数都达到最大值，
    并且最下面一层的节点都集中在该层最左边的若干位置。若最底层为第 h 层，则该层包含 1~ 2h 个节点。

*/

/*
    利用完全二叉树的性质
     完全二叉树只有两种情况，1. 满二叉树  2. 最后一层叶子节点没有满
     情况一： 直接使用2^n(n 是 树的深度) - 1来计算，这里的根节点深度为1
     情况二： 递归计算左右子树的节点个数，然后相加，再加上根节点。(递归到某一深度一定会有左孩子或者右孩子为满二叉树，然后用情况一来计算)

    判断是否是完全二叉树：
        如果递归向左遍历的深度等于递归向右遍历的深度，就是满二叉树
*/
#include<iostream>
#include<vector>
#include<stack>
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
    int countNodes(TreeNode* root) {

    }
};