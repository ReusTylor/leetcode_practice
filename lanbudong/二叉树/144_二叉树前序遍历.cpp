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

class Solution1 {
    vector<int> res;
public:
    vector<int> preorderTraversal(TreeNode* root) {
        if(root == nullptr) return {};

        res.push_back(root->val);
        preorderTraversal(root->left);
        preorderTraversal(root->right);
        return res;
    }
};


class Solution2 {
public:
    void preorderTraversal(TreeNode* root, vector<int>& res) {
        if(root == nullptr) return;
        
        res.push_back(root->val);
        preorderTraversal(root->left, res);
        preorderTraversal(root->right, res);
    }
    
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> res;
        preorderTraversal(root, res);
        return res;
    }
};

int main(){

    TreeNode* head = new TreeNode(3);
    head->left = new TreeNode(9);
    head->right = new TreeNode(20);
    head->right->left = new TreeNode(15);
    head->right->right = new TreeNode(7);
    Solution1 s1;
    vector<int> result1 = s1.preorderTraversal(head);
    for(int a : result1){
        cout << a << endl;
    }

    Solution2 s2;
    vector<int> result2 = s2.preorderTraversal(head);
    for(int a : result2){
        cout << a << endl;
    }
    return 0;
}