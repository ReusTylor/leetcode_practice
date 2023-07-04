#include<iostream>
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
 
class Solution1 {
    int max_res = 0;
    int cur_depth = 0;

public:
    void traverse(TreeNode* head){
        if(head == nullptr) return;
        cur_depth++;
        if(head->left == nullptr && head->right == nullptr){
            max_res = max(max_res, cur_depth);
        }
        traverse(head->left);
        traverse(head->right);
        cur_depth--;
    }

    int maxDepth(TreeNode* root) {
        traverse(root);
        return max_res;
    }
};


class Solution2 {
public:
    int maxDepth(TreeNode* root) {
        if(root == nullptr) return 0;
        int leftdepth = maxDepth(root->left);
        int rightdepth = maxDepth(root->right);
        int res = max(leftdepth, rightdepth) + 1;

        return res;
    }
};

// 迭代遍历 模板直接套用
class Solution3{
public:
    int maxDepth(TreeNode* root){
        if(root == nullptr)
            return 0;
        queue<TreeNode*> que;
        que.push(root);
        int depth = 0;
        while(!que.empty()){
            int size = que.size();
            depth++;
            for(int i = 0; i < size; i++){
                TreeNode* node = que.front();
                que.pop();
                if(node->left != nullptr) que.push(node->left);
                if(node->right != nullptr) que.push(node->right);
            }
        }
        return depth;
    }
};


int main(){
    Solution2 s2;
    TreeNode* head = new TreeNode(3);
    head->left = new TreeNode(9);
    head->right = new TreeNode(20);
    head->right->left = new TreeNode(15);
    head->right->right = new TreeNode(7);

    cout << s2.maxDepth(head) << endl;


    Solution1 s1;
    cout << s1.maxDepth(head) << endl;


    Solution3 s3;
    cout << s3.maxDepth(head) << endl;
    return 0;
}

