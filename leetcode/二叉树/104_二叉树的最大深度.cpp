/*
    给定一个二叉树，找出其最大深度。

    二叉树的深度为根节点到最远叶子节点的最长路径上的节点数。

    说明: 叶子节点是指没有子节点的节点。
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

// 迭代法
class Solution {
public:
    int maxDepth(TreeNode* root) {
        queue<TreeNode*> que;
        int result = 0;
        if(root == nullptr) return result;
        que.push(root);
        while(!que.empty()){
            int size = que.size();
            result++;
            for(int i = 0; i < size; i++){
                TreeNode* node = que.front();
                que.pop();
                if(node->left) que.push(node->left);
                if(node->right) que.push(node->right);
            }
        } 
        return result;
    }
};

// 递归法
// 使用前序求的是深度，后序求的是高度
// 根节点的高度就是二叉树的最大深度


class Solution2 {
public:
// 使用后序遍历
    int getdepth(TreeNode* cur){
        if(cur == nullptr) return 0;
        int leftdepth = getdepth(cur->left);
        int rightdepth = getdepth(cur->right);
        int depth  = max(leftdepth, rightdepth) + 1;
    }
    int maxDepth(TreeNode* root) {
        return getdepth(root);
    }
};


// 前序遍历，体现了求深度回溯的过程
class solution3 {
public:
    int result;
    void getdepth(TreeNode* node, int depth) {
        result = depth > result ? depth : result; // 中

        if (node->left == NULL && node->right == NULL) return ;

        if (node->left) { // 左
            depth++;    // 深度+1
            getdepth(node->left, depth);
            depth--;    // 回溯，深度-1
        }
        if (node->right) { // 右
            depth++;    // 深度+1
            getdepth(node->right, depth);
            depth--;    // 回溯，深度-1
        }
        return ;
    }
    int maxDepth(TreeNode* root) {
        result = 0;
        if (root == NULL) return result;
        getdepth(root, 1);
        return result;
    }
};

