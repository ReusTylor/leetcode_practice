/*
    给定一个二叉树，找出其最小深度。
    最小深度是从根节点到最近叶子节点的最短路径上的节点数量。

    输入：root = [3,9,20,null,null,15,7]
    输出：2
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



// 1. 层序遍历，找到第一个没有左右孩子的节点所在的深度，即为最小深度

class Solution {
public:
    int minDepth(TreeNode* root) {
        int depth = 0;
        queue<TreeNode*> que;
        if(root == nullptr) 
            return 0;
        que.push(root);
        
        while(!que.empty()){
            int size = que.size();
            depth++;
            for(int i = 0; i < size; i++){
                TreeNode* node = que.front();
                que.pop();
                if(!node->left && !node->right){
                    return depth;
                }

                if(node->left) que.push(node->left);
                if(node->right) que.push(node->right);
            }
        }
        return depth;
    }
};   


// 递归法
// 最小深度与最大深度的差别在于处理左右孩子不为空的逻辑
// 前序求深度，后序求高度
class Solution1 {
public:
    int getDepth(TreeNode* cur){
        if(cur == nullptr) return 0;

        int leftNode = getDepth(cur->left);

        int rightNode = getDepth(cur->right);
        // 不能这样写
        // int depth = 1 + min(leftNode, rightNode);
        if(cur->left == nullptr && cur->right != nullptr){
            return 1 + rightNode;
        }
        if(cur->right == nullptr && cur->left != nullptr){
            return 1 + leftNode;
        } 
        int result = 1 + min(leftNode, rightNode);


        return result;
    }
    int minDepth(TreeNode* root) {
        return getDepth(root);
    }
};



int main(){
    Solution1 s;
    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(9);
    root->right = new TreeNode(20, new TreeNode(15), new TreeNode(7));
    cout << s.minDepth(root) << endl;
    return 0;
}