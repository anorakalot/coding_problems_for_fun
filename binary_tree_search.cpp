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
	TreeNode *searchBST(TreeNode *root, int val)
	{
		TreeNode *return_val;
		if (root->val == val)
		{
			printf("found root->val== val == %i\n", root->val);
			return root;
		}

		if (root->left == NULL && root->right == NULL)
		{
			// TreeNode* empty_val;
			// empty_val->val = 0;
			// printf("empty_val->val == %i\n",empty_val->val);
			// empty_val->val = 0;
			return root;
		}

		// if (root->left != nullptr){
		if (root->left != NULL)
		{
			printf("if root->left != null\n");
			return_val = searchBST(root->left, val);
			if (return_val->val == val)
			{ // return_val != NULL &&
				return return_val;
			}
		}
		if (root->right != nullptr)
		{
			printf("if root->right != null\n");
			return_val = searchBST(root->right, val);
			if (return_val->val == val)
			{
				return return_val;
			}
		}
		//         if (return_val->val !=val){
		//             return NULL;
		//         }
		//         else{
		//         return return_val;

		//         }
		return return_val;
	}
};
// if (root->left == nullptr){
//     return NULL;
// }
// if (root->right == nullptr){
//     return NULL;
// }