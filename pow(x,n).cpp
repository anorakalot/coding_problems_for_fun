class Solution
{
public:
	double myPow(double x, int n)
	{
		double return_val;
		if (x == 0)
		{ // meaning n == 0;
			printf("x == 0\n");
			return_val = 0;
		}
		else if (n == 0)
		{ // meaning n == 0;
			printf("n == 0\n");
			return_val = 1;
		}
		else if (n > 0)
		{
			printf("going into recur_pos\n");
			printf("x == %f\n", x);
			printf("n == %f\n", n);
			return_val = myPow_recur_pos(x, x, n);
		}
		else if (n < 0)
		{
			printf("going into recur_neg\n");
			x = 1 / x;
			printf("x == %f\n", x);
			printf("n == %f\n", n);
			printf("turning x into 1/x == %f\n", x);
			return_val = myPow_recur_neg(x, x, n);
		}

		return return_val;
	}
	double myPow_recur_pos(double val, double orig_val, int n)
	{

		if (n <= 1)
		{
			printf("n<=1 val = %f\n", val);
			printf("n = %i\n", n);
			printf("returning_val\n");
			return val;
		}

		val = val * orig_val;
		printf("val after multiplying by orig_val %f\n", val);
		// printf()
		n = n - 1;
		printf("n after -1 == %i\n", n);
		double return_val;
		return_val = myPow_recur_pos(val, orig_val, n);

		return return_val;
	}
	double myPow_recur_neg(double val, double orig_val, int n)
	{

		if (n >= -1)
		{
			printf("n>=1 val = %f\n", val);
			printf("n = %i\n", n);
			printf("returning_val\n");
			return val;
		}

		val = val * orig_val;
		printf("val after multiplying by orig_val %f\n", val);
		// printf()
		n = n + 1;
		printf("n after +1 == %i\n", n);
		double return_val;
		return_val = myPow_recur_neg(val, orig_val, n);

		return return_val;
	}
};