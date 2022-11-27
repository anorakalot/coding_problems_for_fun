class Solution
{
public:
	int fib(int n, vector<int> already_done)
	{

		if (n == 1)
		{
			return 1;
		}
		else if (n == 0)
		{
			return 0;
		}

		return fib(n - 1) + fib(n - 2);
	}
};