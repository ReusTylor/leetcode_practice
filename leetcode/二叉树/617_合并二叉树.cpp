/**
* 合并二叉树
 * 给你两棵二叉树： root1 和 root2 。
     想象一下，当你将其中一棵覆盖到另一棵之上时，两棵树上的一些节点将会重叠（而另一些不会）。
     你需要将这两棵树合并成一棵新二叉树。合并的规则是：如果两个节点重叠，那么将这两个节点的值相加作为合并后节点的新值；
     否则，不为 null 的节点将直接作为新二叉树的节点。
   返回合并后的二叉树
   注意: 合并过程必须从两个树的根节点开始。

   输入：root1 = [1,3,2,5], root2 = [2,1,3,null,4,null,7]
   输出：[3,4,5,5,4,null,7]
*/

/*
 * 深度优先搜索：
 *  从根节点同时开始遍历两个二叉树，并将对应的节点进行合并。
 *  - 若两个二叉树的对应节点都为空，合并后的二叉树的对应节点也为空
 *  - 若两个二叉树的对应节点只有一个为空，则合并后的二叉树的对应节点为其中的非空节点。
 *  - 若两个二叉树的对应节点都不为空，则合并后的二叉树的对应节点的值为两个二叉树的对应节点的值之和，此时需要显性合并两个节点。
 *  对一个节点进行合并之后，还要对该节点的左右子树分别进行合并，是一个递归的过程。
 */

/*
 * 递归逻辑
 *
 */

#include <bits/stdc++.h>
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
    TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2) {
        if(root1 == nullptr) return root2;
        if(root2 == nullptr) return root1;
        // 单层的递归逻辑
        root1->val += root2->val;
        root1->left = mergeTrees(root1->left, root2->left);
        root1->right = mergeTrees(root1->right, root2->right);
        return root1;
    }
};
