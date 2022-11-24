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

		preorder(p, p_vals);
		// just testing
		for (int x = 0; x < p_vals.size(); x++)
		{
			printf("p_vals %i\n", p_vals[x]);
		}

		preorder(q, q_vals);
		for (int x = 0; x < q_vals.size(); x++)
		{
			printf("q_vals %i\n", q_vals[x]);
		}

		if (p_vals.size() != q_vals.size())
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

		return 1; // placeholder
	}

	void preorder(TreeNode *x, vector<int> &x_vals)
	{
		printf("x->val == %i\n", x->val);
		if (x->val == 0)
		{
			x_vals.push_back(0);
		}
		else
		{
			x_vals.push_back(x->val);
		}
		if (x->left != nullptr)
		{
			preorder(x->left, x_vals);
		}
		if (x->right != nullptr)
		{
			preorder(x->right, x_vals);
		}
	}
};