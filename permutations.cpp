class Solution
{
public:
	vector<vector<int>> permute(vector<int> &nums)
	{
		vector<vector<int>> return_val;

		// testing_pushback
		//  vector<int> test_1= {5,1,6,7,2,1};
		//  vector<int> test_2 = {10,5,4,1};
		//  return_val.push_back(test_1);
		//  return_val.push_back(test_2);
		//  for (int y = 0; y < 2; y++){
		//      for (int x = 0; x < return_val[y].size(); x++){
		//          printf("%i ",return_val[y][x]);
		//      }
		//      printf("\n");
		//  }
		////
		map<vector<int>, int> been_done_before;

		return_val = permute_recur(nums, been_done_before, return_val);

		return return_val;
	}
	vector<vector<int>> permute_recur(vector<int> &nums, map<vector<int>, int> been_done_before, vector<vector<int>> return_val)
	{
		if (been_done_before[nums] == 0)
		{ // if nums hasn't been done_before
			return_val.push_back(nums);
			been_done_before[nums] = 1; // set it to 1 so that we know this permutation has already been done
		}

		return return_val;
	}
};