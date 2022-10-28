class Solution
{
public:
	bool isPowerOfTwo(int n)
	{
		bool return_val;
		// edgecase for  n==1 put this here
		if (n == 1)
		{
			return 1;
		}
		if (n == 0)
		{
			return 0;
		}
		if (n < 0)
		{ // if value is negative return 0;
			return 0;
		}
		return_val = p_of_two_recur(n, 2);
		return return_val;
	}
	bool p_of_two_recur(int orig_input_val, unsigned long int x)
	{
		bool return_val_recur;
		if (x > orig_input_val)
		{
			return 0;
		}
		if (x == orig_input_val)
		{
			return 1;
		}
		x = 2 * x;
		// printf("x == %i\n",x);
		return_val_recur = p_of_two_recur(orig_input_val, x);
		return return_val_recur;
	}
};