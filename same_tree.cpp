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
	bool isSameTree(TreeNode *p, TreeNode *q)
	{
		vector<int> p_vals;
		vector<int> q_vals;

		vector<char> p_dirs;
		vector<char> q_dirs;

		preorder(p, p_vals, p_dirs);
		// just testing
		for (int x = 0; x < p_vals.size(); x++)
		{
			printf("p_vals %i\n", p_vals[x]);
		}
		for (int x = 0; x < p_dirs.size(); x++)
		{
			printf("p_dirs %c\n", p_dirs[x]);
		}

		preorder(q, q_vals, q_dirs);
		for (int x = 0; x < q_vals.size(); x++)
		{
			printf("q_vals %i\n", q_vals[x]);
		}
		for (int x = 0; x < q_dirs.size(); x++)
		{
			printf("q_dirs %c\n", q_dirs[x]);
		}

		if (p_vals.size() != q_vals.size() || p_dirs.size() != q_dirs.size())
		{
			return 0; // not same size
		}

		for (int x = 0; x < p_vals.size(); x++)
		{
			if (p_vals[x] != q_vals[x])
			{
				return 0;
			}
		}

		for (int x = 0; x < p_dirs.size(); x++)
		{
			if (p_dirs[x] != q_dirs[x])
			{
				return 0;
			}
		}
		return 1;
	}

	void preorder(TreeNode *x, vector<int> &x_vals, vector<char> &x_dirs)
	{
		// printf("x->val == %i\n",x->val);

		// if (x->val == 0){
		//     x_vals.push_back(0);
		// }
		// else{
		//    x_vals.push_back(x->val);
		// }

		if (x != NULL)
		{
			x_vals.push_back(x->val);
		}
		else if (x == NULL)
		{
			return;
		}

		if (x->left != nullptr)
		{
			x_dirs.push_back('l');
			preorder(x->left, x_vals, x_dirs);
		}
		if (x->right != nullptr)
		{
			x_dirs.push_back('r');
			preorder(x->right, x_vals, x_dirs);
		}
	}
};