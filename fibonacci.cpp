class Solution
{
public:
	int fib(int n, map<int, int> &already_done)
	{
		// vector<int>& already_done //I'm gonna use a map instead
		// 2 base cases (1,0)
		if (n == 1)
		{
			return 1;
		}
		else if (n == 0)
		{
			return 0;
		}
		int return_val;
		if (already_done[n] != 0)
		{ // already done
			return_val = already_done[n];
			return return_val;
		}
		return_val = fib(n - 1, already_done) + fib(n - 2, already_done);
		if (already_done[n] == 0)
		{
			already_done[n] = return_val;
		}
		return return_val;
	}
};