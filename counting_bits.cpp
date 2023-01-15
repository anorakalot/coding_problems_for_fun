class Solution
{
public:
	int i = 0;
	vector<int> return_val;
	int num_of_bits = 1;
	int num_of_ones = 0;
	bool first_time = 0;
	vector<int> countBits(int n)
	{
		// if ((i %2) == 0 && i != 0){//actually need to change i%2 since it would
		// work with numbers like 6 when it shouldn't
		// and only work for 1 2 4 8 16 32 etc
		printf("i == %i\n", i);
		if (((i & i - 1) == 0) && i != 0)
		{
			printf("in first if reset num_of_ones to 1\n");
			num_of_bits += 1;
			num_of_ones = 1;
		}
		else if (first_time == 0)
		{
			printf("in second if\n");
			num_of_ones = 0;
			first_time = 1;
		}
		else
		{ //
			printf("in third if\n");
			num_of_ones += 1;
		}

		printf("num_of_ones == %i\n", num_of_ones);
		return_val.push_back(num_of_ones);
		printf("after push_back\n");
		// should have operation before base case
		if (i == n) // base case for recusion
		{
			printf("inside base case i == n");
			return return_val;
		}
		// need to have base case before recursion so that base case can return
		// before recusive call
		i += 1; // right before recursive call
		printf("\n\n");
		return_val = countBits(n);
		return return_val;
	}
};