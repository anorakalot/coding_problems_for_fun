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
	// dnta = (don't need this anymore)
	// actually let's just use pointers for the queue and visited vector since it's better
	// because it checks if it's the right address instead of just the value
	// vector<vector<int>> return_val(vector<int>(100));
	// vector<vector<int>> return_val(100,vector<int>(100));
	vector<vector<int>> return_val;
	vector<int> input_vector;

	queue<TreeNode *> node_queue;
	// vector<int> visited;//might have to take into account pos of nodes to make sure
	// if 2 vals are the same it doesn't stop one from being visited.
	vector<TreeNode *> visited;
	TreeNode *curr_node;
	// TreeNode left_node;//dnta
	// TreeNode right_node; //dont' need these anymore if I just use pointers

	// map<int,int> level_for_node;//changed to int,int because of error using TreeNode as
	map<TreeNode *, int> level_for_node;
	int level = 0;
	// also might need to have a vector of ints on which level each node is at
	// this can be found by keeping track of how many times you go left down left / right ptrs

	bool valid_left = 0;
	bool valid_right = 0;
	vector<vector<int>> levelOrder(TreeNode *root)
	{
		if (root != NULL)
		{
			// node_queue.push(root->val);
			// node_queue.push(*root);
			node_queue.push(root); // just push the pointer
		}
		else
		{
			printf("in == Null else statement\n");
			return return_val;
		}

		// visited.push_back(*root);
		level_for_node[root] = 0;
		printf("node_queue.front()->val == %i\n", node_queue.front()->val);

		// visited.push_back(node_queue.front());

		while (node_queue.empty() != 1)
		{
			curr_node = node_queue.front();
			node_queue.pop();
			printf("curr_node->val == %i\n", curr_node->val);
			printf("level_for_node[curr_node] == %i\n\n", level_for_node[curr_node]);
			level = level_for_node[curr_node];
			// return_val[level].push_back(curr_node->val);
			valid_left = 1;
			// for neighbors just need to check left and right since it's a binary tree
			if (curr_node->left != nullptr)
			{
				// left_node = *curr_node.left;//dnta
				for (int x = 0; x < visited.size(); x++)
				{ // check if not in visted
					// if (left_node.val == visited[x].val){
					if (curr_node->left == visited[x])
					{
						valid_left = 0;
						break;
					}
				} // end of check visited for loop
				if (valid_left == 1)
				{
					// also need to add level_for_node here
					level_for_node[curr_node->left] = level_for_node[curr_node] + 1;
					node_queue.push(curr_node->left);
					visited.push_back(curr_node->left);
					// node_queue.push(left_node);
					// visited.push_back(left_node);
				}
			} // left end
			valid_right = 1;
			if (curr_node->right != nullptr)
			{
				// right_node = *curr_node.right; //dnta
				for (int x = 0; x < visited.size(); x++)
				{ // check if not in visted
					// if (right_node.val == visited[x].val){
					if (curr_node->right == visited[x])
					{
						valid_right = 0;
						break;
					}
				} // end of check visited for loop
				if (valid_right == 1)
				{
					level_for_node[curr_node->right] = level_for_node[curr_node] + 1;
					node_queue.push(curr_node->right);
					visited.push_back(curr_node->right);
					// node_queue.push(right_node);
					// visited.push_back(right_node);
				}
			} // right end
		}

		// if (left != nullptr){
		//     node_queue.push(root->left->val);
		// }

		return return_val;
	}
};

// that's good I used a pointer for use with the map because as a pointer you can use it
// as a key since it's just an address