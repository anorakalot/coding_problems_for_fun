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
		// printf("val = %i\n ",root->val);
		//  if (root->left == nullptr){//base case left subtree
		//       //return root
		//      return return_val;
		//  }
		//  if (root->right == nullptr){//base case right subtree
		//      return return_val;
		//  }

		//         if (root->left != nullptr){
		//             inorderTraversal(root->left);
		//         }

		//         // if (root->left == nullptr){
		//         //     return_val.push_back(root->val);
		//         // }
		//         if (root->right != nullptr){
		//             inorderTraversal(root->right);

		//         }
		// if (root->val == null){
		//     return
		// }

		//         if (root->left == nullptr){
		//             printf("val = %i",root->val);
		//         }
		//         inorderTraversal(root->left);

		//         inorderTraversal(root->right);

		//         return return_val;

		// if (root->left == nullptr){
		//     return_val.push_back(root->val);
		// }
		// return_val = inorderTraversal(root->left);
		// return_val.push_back(root->val);
		// return_val = inorderTraversal(root->right);

		if (root != nullptr)
		{
			inorderTraversal(root->left);
			inorderTraversal(root->right);
		}

		return return_val;
	}
};