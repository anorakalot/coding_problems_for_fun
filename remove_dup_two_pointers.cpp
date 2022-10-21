class Solution
{
public:
	int removeDuplicates(vector<int> &nums)
	{
		int k = nums.size();
		int unique_val; // unique val not to be replicated
		int index_1;	// index for original
		int index_2;	// index for unique
		// setting up initial values
		unique_val = nums[0];
		index_1 = 0;
		index_2 = 0;
		for (int x = 0; x < nums.size(); x++)
		{
			printf("% i", nums[x]);
			if (nums[x] != unique_val)
			{ // moved to a different val
				unique_val = nums[x];
			}
		}
		printf("\n");
		return k;
	}
};