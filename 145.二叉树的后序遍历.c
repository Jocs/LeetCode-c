/*
 * @lc app=leetcode.cn id=145 lang=c
 *
 * [145] 二叉树的后序遍历
 *
 * https://leetcode-cn.com/problems/binary-tree-postorder-traversal/description/
 *
 * algorithms
 * Easy (74.94%)
 * Likes:    687
 * Dislikes: 0
 * Total Accepted:    300.5K
 * Total Submissions: 400.6K
 * Testcase Example:  '[1,null,2,3]'
 *
 * 给定一个二叉树，返回它的 后序 遍历。
 * 
 * 示例:
 * 
 * 输入: [1,null,2,3]  
 * ⁠  1
 * ⁠   \
 * ⁠    2
 * ⁠   /
 * ⁠  3 
 * 
 * 输出: [3,2,1]
 * 
 * 进阶: 递归算法很简单，你可以通过迭代算法完成吗？
 * 
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

void postOrder(struct TreeNode* node, int * ret, int * returnSize) {
  if (!node)
    return;
  postOrder(node->left, ret, returnSize);
  postOrder(node->right, ret, returnSize);
  ret[(*returnSize)++] = node->val;
}
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* postorderTraversal(struct TreeNode* root, int* returnSize){
  int *result = (int *)malloc(2001 * sizeof(int));
  *returnSize = 0;
  postOrder(root, result, returnSize);

  return result;
}
// @lc code=end

