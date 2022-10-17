class Solution
{
public:
	int minMaxGame(vector<int> &nums)
	{
		// step 1
		while (nums.size() != 1)
		{

			// if (nums.size() ==1){//n = nums.size()
			//     return nums[0];
			// }
			// else{
			vector<int> new_nums(nums.size() / 2);
			//}
			// step 2
			for (int i = 0; i < nums.size() / 2; i++)
			{
				if (i % 2 == 0)
				{ // is even
					new_nums[i] = min(nums[2 * i], nums[(2 * i) + 1]);
				}
				else if (i % 2 == 1)
				{ // is odd
					new_nums[i] = max(nums[2 * i], nums[(2 * i) + 1]);
				}
			}
			nums = new_nums;
			for (int x = 0; x < nums.size(); x++)
			{
				printf("%i ", nums[x]);
			}
			printf("\n");
		}
		return nums[0];
		// return 0;//placeholder
	}
};