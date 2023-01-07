class Solution
{
public:
	bool cups_still_have_water = 1;
	int num_of_seconds = 0;
	int y;
	int x;
	int pq_size = 0;
	int fillCups(vector<int> &amount)
	{
		priority_queue<int> pq;
		for (int x = 0; x < amount.size(); x++)
		{
			if (amount[x] > 0)
			{
				pq.push(amount[x]);
			}
		}
		pq_size = pq.size();
		while (pq_size) // pq.size() > 0
		{
			y = pq.top();
			pq.pop();
			x = pq.top();
			pq.pop();
			printf("at beg:\ny == %i\nx==%i\n", y, x);
			if (y >= 1 && x >= 1)
			{
				printf("inside first if both\n");
				y -= 1;
				x -= 1;
				if (y > 0)
				{
					pq.push(y);
				}
				if (x > 0)
				{
					pq.push(x);
				}

				num_of_seconds += 1;
				printf("y == %i\nx== %i\n\n", y, x);
			}
			else if (y >= 1)
			{
				printf("inside second if y only\n");
				y -= 1;
				if (y > 0)
				{
					pq.push(y);
				}
				num_of_seconds += 1;
				printf("y == %i\nx== %i\n\n", y, x);
			}
			else if (x >= 1)
			{
				printf("inside third if x only\n");
				x -= 1;
				if (x > 0)
				{
					pq.push(x);
				}
				num_of_seconds += 1;
				printf("y == %i\nx== %i\n\n", y, x);
			}
			pq_size = pq.size();
			printf("pq_size == %i\n", pq_size);
			printf("pq.size() == %i\n\n", pq.size());
		} // end of while loop

		return num_of_seconds;
	}
};