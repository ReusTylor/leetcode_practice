#include<iostream>
#include<vector>
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

class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
      // 使用队列完成
      vector<vector<int>> result;
      queue<TreeNode*> que;
      if(root != nullptr)
        que.emplace(root);
      while(!que.empty()){
        int size = que.size();
        vector<int> vec;
        for(int i = 0; i < size; i++){
          TreeNode* node = que.front();
          que.pop();
          vec.emplace_back(node->val);

          if(node->left) que.emplace(node->left);
          if(node->right) que.emplace(node->right);
        }
        result.push_back(vec);
      }
      return result;
    }
};

// 递归
/*class Solution1{
public:
    void order(TreeNode* cur , vector<vector<int>>& result, int depth){
        if(cur == nullptr) return;
        if(result.size() == depth) result.push_back(vector<int>());
        result[depth].push_back(cur->val);
        order(cur->left, result, depth + 1);
        order(cur->right, result, depth + 1);
    }

    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> result;
        int depth = 0;
        order(root, result, depth);
        return result;
    }
};*/

class Solution1{
 public:
  void traversal(TreeNode* node, vector<vector<int>>& result, int depth){
    if(node == nullptr) return;
    if(result.size() == depth) result.emplace_back(vector<int>());
    result[depth].emplace_back(node->val);
    traversal(node->left, result, depth + 1);
    traversal(node->right, result, depth + 1);
  }
  vector<vector<int>> levelOrder(TreeNode* root){
    vector<vector<int>> result;
    int depth = 0;
    traversal(root, result, depth);
    return result;
  }
};



int main() {
  // Create a binary tree
  TreeNode* root = new TreeNode(3);
  root->left = new TreeNode(9);
  root->right = new TreeNode(20);
  root->right->left = new TreeNode(15);
  root->right->right = new TreeNode(7);

  Solution solution;
  vector<vector<int>> result = solution.levelOrder(root);

  // Print the level order traversal result
  for (const auto& vec : result) {
    for (int num : vec) {
      cout << num << " ";
    }
    cout << endl;
  }

  // Free the dynamically allocated memory
  delete root->left;
  delete root->right->left;
  delete root->right->right;
  delete root->right;
  delete root;

  return 0;
}