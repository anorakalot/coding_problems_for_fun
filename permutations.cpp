class Solution
{
public:
	vector<vector<int>> permute(vector<int> &nums)
	{
		vector<vector<int>> return_val;
		int num_of_perms;
		num_of_perms = nums.size(); // start off 3
		printf("start_val num_of_perms = %i\n", num_of_perms);
		printf("nums.size()-1 = %lu\n", nums.size() - 1);
		for (int x = nums.size() - 1; x > 0; x--)
		{
			printf("x == %i \n", x);
			num_of_perms *= x;
		}
		printf("num_of_perms = %i\n", num_of_perms);
		int num_of_curr_perms = 0;
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
		return_val = permute_recur(nums, been_done_before, return_val, num_of_perms, num_of_curr_perms);
		return return_val;
	}
	vector<vector<int>> permute_recur(vector<int> &nums, map<vector<int>, int> been_done_before, vector<vector<int>> return_val,
									  int num_of_perms, int num_of_curr_perms)
	{

		if (been_done_before[nums] == 0)
		{ // if nums hasn't been done_before
			printf("UNIQUE PERM NUMS VECTOR \n");
			for (int x = 0; x < nums.size(); x++)
			{
				printf("%i ", nums[x]);
			}
			printf("\n");
			return_val.push_back(nums);
			been_done_before[nums] = 1; // set it to 1 so that we know this permutation has already been done
			num_of_curr_perms += 1;
			if (num_of_curr_perms >= num_of_perms)
			{ // found the total number of possible permutations
				return return_val;
			}
		}

		return return_val;
	}
};