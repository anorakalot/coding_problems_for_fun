class Solution
{
public:
	vector<vector<int>> permute(vector<int> &nums)
	{
		vector<vector<int>> return_val;
		map<vector<int>, int> been_done_before;

		int num_of_perms = nums.size(); // start off 3
		printf("start_val num_of_perms = %i\n", num_of_perms);
		printf("nums.size()-1 = %lu\n", nums.size() - 1);
		for (int x = nums.size() - 1; x > 0; x--)
		{
			printf("x == %i \n", x);
			num_of_perms *= x;
		}
		printf("num_of_perms = %i\n", num_of_perms);
		int num_of_curr_perms = 0;
		vector<int> permutation;
		map<int, int> used_num_in_permutation;
		permute_backtrack_recur(nums, permutation, used_num_in_permutation, return_val); // num_of_perms,num_of_curr_perms);

		return return_val;
	}
	// vector<vector<int>> make backtrack void already I save the return_val as a function parameter
	void permute_backtrack_recur(vector<int> &nums, vector<int> &permutation, map<int, int> used_num_in_permutation, vector<vector<int>> return_val)
	{
		if (permutation.size() == nums.size())
		{
			// add to return_val;
			return_val.push_back(permutation);
			return;
		}

		for (int x = 0; x < nums.size(); x++)
		{
			if (used_num_in_permutation[nums[x]] == 0)
			{
				permutation.push_back(nums[x]);													 // apply choices
				used_num_in_permutation[nums[x]] = 1;											 // just do this so we know we already used this val
				permute_backtrack_recur(nums, permutation, used_num_in_permutation, return_val); // backtrack
				int index_to_erase = 0;
				for (int x = 0; x < permutation.size(); x++)
				{ // undo choice
					if (permutation[x] == nums[x])
					{
						permutation.erase(permutation.begin() + index_to_erase);
						break;
					}
					index_to_erase += 1;
				}
			}
		}

		return;
	}
};