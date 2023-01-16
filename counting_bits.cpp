class Solution
{
public:
	int i = 0;
	int curr_i = 0;
	vector<int> return_val;
	// vector<int> dp_memo;
	map<int, int> dp_memo;
	int dp_memo_index = 0;
	int num_of_ones = 0;
	// int num_of_ones_prev=0;
	bool no_while_loop = 0;
	bool right_after_pow_of_2 = 0;
	vector<int> countBits(int n)
	{
		printf("i == %i\n", i);
		curr_i = i;
		num_of_ones = 0;
		no_while_loop = 0;
		if ((i & i - 1) == 0 && i != 0)
		{
			no_while_loop = 1;
			num_of_ones = 1;
			// right_after_pow_of_2 =1;
			dp_memo_index = 0;
		}
		// if(dp_memo_index < dp_memo.size()-1){
		//     num_of_ones = dp_memo[dp_memo_index];
		// }
		else if (dp_memo[dp_memo_index] > 0 && i != 0)
		{
			printf("inside using_dp_memo\n");
			num_of_ones = dp_memo[dp_memo_index];
			no_while_loop = 1;
		}

		while (curr_i != 0 && no_while_loop == 0)
		{
			if ((curr_i & 1) == 1)
			{
				num_of_ones += 1;
			}
			curr_i = curr_i >> 1;
		}
		// if (dp_memo_index > dp_memo.size()-1){//index bigger than current size
		//     dp_memo.push_back(num_of_ones);
		// }
		if (dp_memo[dp_memo_index] == 0 && i != 0)
		{
			printf("inside saving dp_memo\n");
			dp_memo[dp_memo_index] = num_of_ones;
		}

		// dp_memo.push_back(num_of_ones);
		// num_of_ones_prev = num_of_ones;
		return_val.push_back(num_of_ones);
		if (i == n) // base case for recusion
		{
			return return_val;
		}
		i += 1; // right before recursive call
		dp_memo_index += 1;
		return_val = countBits(n);
		return return_val;
	}
};
