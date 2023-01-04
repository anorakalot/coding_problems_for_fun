class Solution
{
public:
	int total_xor_val = 0;
	int curr_xor_val = 0;
	vector<int> curr_nums;
	map<vector<int>, int> nums_used_before;
	int erase_index = 0;
	int subsetXORSum(vector<int> &nums)
	{
		// changes curr_nums.size()== nums.size() to curr_nums.size() <= nums.size()
		if (nums_used_before[curr_nums] == 0 && curr_nums.size() <= nums.size())
		{
			// meaning hasn't been used before
			// need to now do xor_total
			printf("inside goal reached\n");
			// for (int x = 0; x < c)
			for (int x = 0; x < curr_nums.size(); x++)
			{
				printf("curr_nums[%i] == %i\n", x, curr_nums[x]);
				if (x == 0)
				{
					curr_xor_val = curr_nums[x];
				}
				else
				{
					curr_xor_val = curr_xor_val ^ curr_nums[x];
				}
			} // eofl
			// printf("\n");
			total_xor_val += curr_xor_val;
			printf("curr_xor_val == %i\n", curr_xor_val);
			printf("total_xor_val == %i\n", total_xor_val);
			printf("end of inside goal if at start of func\n\n");
			// don't forget to set nums_used_before == 1 so it doesn't go off again for
			// this particular value
			nums_used_before[curr_nums] = 1;
		}

		for (int x = 0; x < nums.size(); x++)
		{ // i think error is here since
			// from the print statements it seems to just keep adding 1 over and over
			// and the prev_used map has it bee a new vector since it technically is
			// error is because e3ach time subsetXORsum is called it starts this loop at the beginning

			// so it only goes to 1 and then calls the function again
			// need to add if choices valid part
			if (curr_nums.size() < nums.size())
			{ // //&& nums_used_before[curr_nums] ==0){
				curr_nums.push_back(nums[x]);
				printf("pushed_back nums[x] == %i\n", nums[x]);
				subsetXORSum(nums);
				erase_index = 0;
				for (int z = 0; z < curr_nums.size(); z++)
				{
					if (curr_nums[z] == nums[x])
					{
						printf("erasing curr_nums[z] == %i\n", curr_nums[z]);
						curr_nums.erase(curr_nums.begin() + z);
						curr_nums.shrink_to_fit();
						break; // this fixed the error of having the code run over time
					}
				}
			}
		}

		// issue is that currently it is doing some permutation stuff
		// and not more subset stuff

		return total_xor_val;
		// return 5^1^6;//placeholder / checking xor operator
	} // end of entire function
};