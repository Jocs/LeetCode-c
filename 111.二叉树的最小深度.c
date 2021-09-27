/*
 * @lc app=leetcode.cn id=111 lang=c
 *
 * [111] 二叉树的最小深度
 *
 * https://leetcode-cn.com/problems/minimum-depth-of-binary-tree/description/
 *
 * algorithms
 * Easy (48.43%)
 * Likes:    596
 * Dislikes: 0
 * Total Accepted:    270.8K
 * Total Submissions: 557.3K
 * Testcase Example:  '[3,9,20,null,null,15,7]'
 *
 * 给定一个二叉树，找出其最小深度。
 * 
 * 最小深度是从根节点到最近叶子节点的最短路径上的节点数量。
 * 
 * 说明：叶子节点是指没有子节点的节点。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：root = [3,9,20,null,null,15,7]
 * 输出：2
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：root = [2,null,3,null,4,null,5,null,6]
 * 输出：5
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 树中节点数的范围在 [0, 10^5] 内
 * -1000 
 * 
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
void travel(struct TreeNode * node, int height, int * result) {
  if (!node->left && !node->right) {
    int curHeight = height + 1;
    *result = *result > curHeight ? curHeight : *result;
  }
  if (node->left) {
    travel(node->left, height + 1, result);
  }
  if (node->right) {
    travel(node->right, height + 1, result);
  }
}

int minDepth(struct TreeNode* root){
  if (!root)
    return 0;
  int result = INT32_MAX;
  travel(root, 0, &result);

  return result;
}
// @lc code=end

