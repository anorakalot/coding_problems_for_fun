class Solution
{
public:
	void sortColors(vector<int> &nums)
	{
	}
	int quicksort(vector<int> &nums, int low, int high)
	{

		// might need to add explicit base case
		if (low < high)
		{
			int pivot = partition(vector<int> & nums, low, high);

			// recursion calling
			quicksort(vector<int> & nums, low, pivot - 1);
			// low to right before pivot
			quicksort(vector<int> & nums, pivot + 1, high);
			// right after pivot to high
		}
		else
		{
			return low; // don't know if this is needed
		}
	}
	int partition(vector<int> &nums, int low, int high)
	{
	}
};