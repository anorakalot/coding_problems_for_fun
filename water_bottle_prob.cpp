class Solution
{
public:
	int numWaterBottles(int numBottles, int numExchange)
	{
		int return_val = 0;
		return_val += numBottles;
		int addition_val = 0;
		int remainder_val = 0;
		while (numBottles >= numExchange)
		{
			addition_val = numBottles / numExchange;
			remainder_val = numBottles % numExchange;
			numBottles = addition_val + remainder_val;
			// numBottles /= numExchange;

			return_val += addition_val;
		}
		return return_val;
	}
};