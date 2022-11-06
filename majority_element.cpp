class Solution
{
public:
	int majorityElement(vector<int> &nums)
	{
		map<int, int> num_of_times;

		for (int x = 0; x < nums.size; x++)
		{
			if (nums_of_time.count(nums[x]) == 0)
			{ // if first time seeing in program
				nums_of_time[nums[x]] = 1;
			}
		}
	}
};