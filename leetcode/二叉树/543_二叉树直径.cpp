/* 
    二叉树的直径就是一个节点的左右子树最大深度之和
*/
#include<iostream>

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
    int diameter = 0;
public:
    void traverse(TreeNode* root){
        if(root == nullptr)
            return;
        int leftMax = maxDepth(root->left);
        int rightMax = maxDepth(root->right);
        int curDiameter = leftMax + rightMax;

        diameter = max(diameter, curDiameter);

        traverse(root->left);
        traverse(root->right);
    }


    int diameterOfBinaryTree(TreeNode* root) {
        traverse(root);
        return diameter;
    }

    int maxDepth(TreeNode* root){
        if(root == nullptr)
            return 0;
        int leftMax = maxDepth(root->left);
        int rightMax = maxDepth(root->right);
        return 1 + max(leftMax, rightMax);
    }
};



int main(){
    Solution s;
    TreeNode* head = new TreeNode(3);
    head->left = new TreeNode(9);
    head->right = new TreeNode(20);
    head->right->left = new TreeNode(15);
    head->right->right = new TreeNode(7);

    cout << s.diameterOfBinaryTree(head) << endl;
}