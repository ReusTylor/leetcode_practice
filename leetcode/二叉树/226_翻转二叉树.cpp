/*
    给你一棵二叉树的根节点 root ，翻转这棵二叉树，并返回其根节点。
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

// 迭代
class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        stack<TreeNode*> stk;
        
        if(root != nullptr)
            stk.push(root);
        while (!stk.empty())
        {
            TreeNode* node = stk.top();
            stk.pop();
            swap(node->left, node->right);
            if(node->left) stk.push(node->left);
            if(node->right) stk.push(node->right);
        }
        return root;
    }
};

// 递归
class Solution1 {
public:
    void traversal(TreeNode* cur){
        if(cur == nullptr) return;
        swap(cur->left, cur->right);
        traversal(cur->left);
        traversal(cur->right);
    }
    TreeNode* invertTree(TreeNode* root) {
        traversal(root);
        return root;
    }
};

// 层序遍历
class Solution2{
public:
    TreeNode* invertTree(TreeNode* root) {
        queue<TreeNode*> que;
        if(root != nullptr)
            que.push(root);
        while(!que.empty()){
            int size = que.size();
            for(int i = 0; i < size; i++){
                TreeNode* node = que.front();
                que.pop();
                swap(node->left, node->right);

                if(node->left) que.push(node->left);
                if(node->right) que.push(node->right);
                
            }
        }
        return root;
    }
};




int main(){
    TreeNode* root = new TreeNode(4);
    root->left = new TreeNode(2);
    root->right = new TreeNode(7);

    root->left->left = new TreeNode(1);
    root->left->right = new TreeNode(3);

    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(9);

    Solution s;
    TreeNode* result = s.invertTree(root);
    cout << result->val << endl;
    cout << result->left->val << endl;
    cout << result->right->val << endl;
    cout << result->left->left->val << endl;
    cout << result->left->right->val << endl;
    cout << result->right->left->val << endl;
    cout << result->right->right->val << endl;
    return 0;
}