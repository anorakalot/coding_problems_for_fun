/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution
{
public:
	vector<int> inorderTraversal(TreeNode *root)
	{
		vector<int> return_val;
		if (root->left == nullptr)
		{ // base case left subtree
			// return root
			return return_val;
		}
		if (root->right == nullptr)
		{ // base case right subtree
			return return_val;
		}

		inorderTraversal(root->left);
		inorderTraversal(root->right)

			return return_val;
	}
};