class Solution
{
public:
	int num_of_seconds = 0;
	int y;
	int x;
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
		// just found out pq.size() cant be zero since it's undefined because it's stored
		// as a binary tree
		while (pq.size() > 1) //{//pq.size() > 0
							  // y = pq.top();
							  // pq.pop();
							  // printf("y == %i\n",y);
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
			printf("pq_size == %i\n", pq_size);
			printf("pq.size() == %i\n\n", pq.size());
		} // end of while loop

		if (pq.size() == 1)
		{
			num_of_seconds += pq.top();
		}
		return num_of_seconds;
	}
};