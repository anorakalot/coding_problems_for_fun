class Solution
{
public:
	int findJudge(int n, vector<vector<int>> &trust)
	{
		map<int, int> map_to_find_judge;
		int judge = -1;
		map<int, int> map_all_trusts_judge;
		map<int, vector<int>> trust_map;
		bool everyone_trusts_judge_val = 1;
		bool person_trusts_judge_val = 0;
		int potential_judge = -1;
		int graph[n][n];
		for (int y = 0; y < n; y++)
		{
			for (int x = 0; x < n; x++)
			{
				graph[y][x] = 0;
				printf("%i ", graph[y][x]);
			}
			printf("\n");
		}

		if (trust.size() == 0)
		{
			printf("inside of trust.size() == 0\n");
			// return n;
			if (n == 1)
			{
				return 1;
			}
			else
			{
				return -1;
			}
		} // handling trust size == 0 edge case

		// for (int y = 0; y < trust.size(); y++){
		//     map_to_find_judge[trust[y][0]]+=1;
		//     trust_map[trust[y][0]].push_back(trust[y][1]);
		//     printf("\n");
		// }
		for (int y = 0; y < trust.size(); y++)
		{
			printf("%i\n%i\n", trust[y][0], trust[y][1]);

			graph[trust[y][0] - 1][trust[y][1] - 1] = 1;
			// need to convert since index starts at 0
			printf("trust[y][0] == %i\n", trust[y][0]);
			map_to_find_judge[trust[y][0]] += 1;
		}
		printf("print graph\n");
		for (int y = 0; y < n; y++)
		{
			for (int x = 0; x < n; x++)
			{
				// graph[y][x] = 0;
				printf("%i ", graph[y][x]);
			}
			printf("\n");
		}

		for (int z = 1; z <= n; z++)
		{
			if (map_to_find_judge[z] == 0)
			{
				printf("z trusts no-one %i\n", z);
				//}
				// now go though array and see if everyone lists 1 in adjacency matrix
				everyone_trusts_judge_val = 1;
				for (int y = 0; y < n; y++)
				{
					// for (int x = 0; x < n; x++){

					//     //printf()
					// }
					// actually don't need it to go though each x just the one
					if (y != z - 1)
					{ // make sure not to check y value of z being checked
						if (graph[y][z - 1] != 1)
						{ // it's z-1 because index start at 0
							everyone_trusts_judge_val = 0;
							break;
						}
					}
				} // end of check_for loop in adjacency matrix
				if (everyone_trusts_judge_val == 1)
				{
					judge = z;
					break;
				}
			}
		}

		return judge; // placeholder
	}
	//[[1,3],[1,4],[2,3]] doesn't work since 4 doesn't trust 3 but every other number does
	// need to find simpler way to organize data
};