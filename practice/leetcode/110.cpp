/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */

struct balance {
  bool isBalanced;
  int height;
};

balance checkBalance(TreeNode *root) {
  if (root == nullptr) {
    return {true, 0};
  }

  balance lf = checkBalance(root->left);
  balance rt = checkBalance(root->right);

  if (!lf.isBalanced || !rt.isBalanced) {
    return {false, 0};
  }
  if (abs(lf.height - rt.height) <= 1) {
    return {true, 1 + max(lf.height, rt.height)};
  }

  return {false, 1 + max(lf.height, rt.height)};
}

class Solution {
public:
  bool isBalanced(TreeNode *root) {
    if (checkBalance(root).isBalanced) {
      return true;
    }
    return false;
  }
};
