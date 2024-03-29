class Solution
{
public:
	map<int, int> already_done;
	int fib(int n)
	{
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
		return_val = fib(n - 1) + fib(n - 2);
		if (already_done[n] == 0)
		{
			already_done[n] = return_val;
		}
		return return_val;
	}
};
// vector<int>& already_done //I'm gonna use a map instead
// 2 base cases (1,0)