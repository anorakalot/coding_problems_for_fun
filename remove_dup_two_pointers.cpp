class Solution
{
public:
	int removeDuplicates(vector<int> &nums)
	{
		// int k = nums.size();
		int k = 0;
		int unique_val; // unique val not to be replicated
		int index_1;	// index for original//actually unique now
		int index_2;	// index for unique
		int swap;
		// setting up initial values
		unique_val = nums[0];
		k = 1;		 // accounting for first value
		index_1 = 0; // think should be one since
		// actually zero have it plus one whenever new unique val is found
		// and switch
		index_2 = 0;
		for (int x = 0; x < nums.size(); x++)
		{
			printf("% i", nums[x]);
			if (nums[x] != unique_val)
			{ // moved to a different val
				unique_val = nums[x];
				index_1 += 1; // move index_1
				k += 1;		  // up value of
				// initiate swap
				swap = nums[x];
				nums[x] = nums[index_1];
				nums[index_1] = swap;
				// index_2 = x+1;
			}
		}
		printf("\n");
		return k;
	}
};