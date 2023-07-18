/*
   给你二叉树的根节点 root ，返回它节点值的 前序 遍历。 
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
    void traversal(TreeNode* cur, vector<int>& vec){
        if(cur == nullptr) return;
        vec.push_back(cur->val);
        traversal(cur->left, vec);
        traversal(cur->right, vec);
    }
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> result;
        traversal(root, result);
        return result;
    }
};


// 迭代法
class Solution1
{
public:
    vector<int> preorderTraversal(TreeNode* root){
        stack<TreeNode*> stk;
        vector<int> result;
        if(root != nullptr)
            stk.emplace(root);
        while(!stk.empty()){
            TreeNode* tmp = stk.top();
            stk.pop();
            result.emplace_back(tmp->val);

            if(tmp->right) stk.push(tmp->right);
            if(tmp->left) stk.push(tmp->left);
        }
        return result;
    }
};