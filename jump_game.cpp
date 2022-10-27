class Solution
{
public:
	bool canJump(vector<int> &nums)
	{
		bool return_val;
		int index = 0;
		return_val = canJump_recur(nums, index);

		// return 0;
		return return_val;
	}
	bool canJump_recur(vector<int> &nums, int index)
	{
		if (index == nums.size() - 1)
		{
			return 1;
		}
		else if (index < nums.size() - 1)
		{
			// logic code choose different index num
		}
		else if (index > nums.size() - 1)
		{
			// logic code
		}
		return 0;
	}
};