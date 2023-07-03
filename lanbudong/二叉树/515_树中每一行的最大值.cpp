#include<iostream>
#include<vector>
#include<queue>
#include<climits>

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
    vector<int> largestValues(TreeNode* root) {
        if(root == nullptr)
            return {};
        vector<int> res;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            int size  = q.size();
            int max = INT_MIN;
            for(int i = 0; i < size; i++){
                TreeNode* node = q.front();
                q.pop();
                if(node->val > max)
                    max  = node->val;
                
                if(node->left) q.push(node->left);
                if(node->right) q.push(node->right);

            }
            res.push_back(max);
        }
        return res;
    }
};

int main(){
    Solution s;
    TreeNode* head = new TreeNode(3);
    head->left = new TreeNode(9);
    head->right = new TreeNode(20);
    head->right->left = new TreeNode(15);
    head->right->right = new TreeNode(7);
    vector<int> result = s.largestValues(head);
    for(int a : result)
        cout << a << endl;

    return 0;
}