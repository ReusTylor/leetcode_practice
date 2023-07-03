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
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if(p == nullptr && q == nullptr) return true;
        if(p == nullptr || q == nullptr) return false;
        if(p->val != q->val)
            return false;
        bool left = isSameTree(p->left, q->left);
        bool right = isSameTree(p->right, q->right);
        return left && right;
    }
};

int main(){
    Solution s;
    TreeNode* head1 = new TreeNode(1);
    head1->left = new TreeNode(2);
    head1->right = new TreeNode(3);
    TreeNode* head2 = new TreeNode(1);
    head2->left = new TreeNode(3);
    head2->right = new TreeNode(3);
    cout << s.isSameTree(head1, head2) << endl;
    return 0;
}