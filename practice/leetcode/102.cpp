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
class Solution {
public:
  vector<vector<int>> levelOrder(TreeNode *root) {
    queue<TreeNode *> q;
    vector<vector<int>> res;

    if (root == nullptr) {
      return res;
    }
    vector<int> sub;

    q.push(root);
    q.push(nullptr);
    while (q.size() > 1) {
      auto e = q.front();
      q.pop();

      if (e != nullptr) {
        sub.push_back(e->val);
        if (e->left != nullptr) {
          q.push(e->left);
        }
        if (e->right != nullptr) {
          q.push(e->right);
        }
      } else {
        res.push_back(sub);
        sub.clear();
        q.push(nullptr);
      }
    }

    res.push_back(sub);

    return res;
  }
};
