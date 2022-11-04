class Solution
{
public:
	vector<vector<int>> combinationSum(vector<int> &candidates, int target)
	{
		vector<vector<int>> return_val;
		int candidate_sum = 0;
		for (int x = 0; x < candidates.size(); x++)
		{
			candidate_sum += candidates[x]; // what if I use
			// candidate sum and use it for a base case for recursion
			// and check if it equals target or not
		}

		printf("candidate_sum = %i", candidate_sum);
		if (candidate_sum == target)
		{
			return_val.push_back(candidates);
			return return_val;
		}
		if (candidate_sum > target)
		{
			vector<int> new_candidates;
			new_candidates = candidates;
			new_candidates.pop_back();
			new_candidates.shrink_to_fit();
			combinationSum(new_candidates, target);
		}
		if (candidate_sum < target)
		{
			vector<int> new_candidates;
			new_candidates = candidates;
			int copy_of_back = candidates.back();
			new_candidates.push_back(copy_of_back);
			combinationSum(new_candidates, target);
		}
		return return_val;
	}
};