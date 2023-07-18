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

class  Solution{
public:
    void traversal(TreeNode* cur, vector<int>& vec) {
        if (cur == NULL) return;
        traversal(cur->left, vec);  // 左
        vec.push_back(cur->val);    // 中
        traversal(cur->right, vec); // 右
    }

    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> result;
        traversal(root, result);
        return result;
    }
};

// 中序遍历时，需要借助指针的遍历来帮助访问节点，栈用来处理栈上的元素
class Solution1 {
public:
    vector<int> inorderTraversal(TreeNode* root) {
       stack<TreeNode*> stk;   
       vector<int> result;
       TreeNode* cur = root;
       while(cur != nullptr || !stk.empty()){
            if(cur != nullptr){
                stk.emplace(cur);
                cur = cur->left;
            }else{
                cur = stk.top();
                stk.pop();
                result.emplace_back(cur->val);
                cur = cur->right;
            }
       }
       return result;
    }
};

