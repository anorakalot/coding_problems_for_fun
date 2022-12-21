class Solution
{
public:
	vector<int> friends;
	int index = 0;
	int first_time = 0;
	int return_val = 0; // should never be 0
	int overflow_val = 0;

	int findTheWinner(int n, int k)
	{
		// this is just to set up vector<int> the first time
		if (first_time == 0)
		{
			printf("inside first_time if statement \n");
			for (int x = 0; x < n; x++)
			{
				friends.push_back(x + 1);
			}
			for (int x = 0; x < friends.size(); x++)
			{
				printf("%i ", friends[x]);
			}
			printf("\n");
			// need to set first_time to 1 so this only runs once at the very beginning of
			// the program
			first_time = 1;
		}

		// base case
		if (friends.size() == 1)
		{
			printf("inside base case\n");
			printf("friends[0] == %i\n", friends[0]);
			return friends[0]; // should just be zero index since it's the only element left
							   // in the vector
		}

		// now to delete friend that loses the game
		index += (k - 1); // this is because we already count the index we start on
		// need to take into account overflow
		// if I used the size function more nthan this it would problably be best to cache
		// the function so I only need to run the size() once
		if (index > friends.size() - 1)
		{ // if index
			printf("in overflow if\n");
			printf("(overflowed)index == %i \n", index);
			overflow_val = (index - (friends.size() - 1)) - 1;
			printf("overflow_val == %i\n", overflow_val);
			// reason it's -1 at the end is ebcause if at 4 and last index is 3 it would just be
			// a wraparound to 0 but if it was 5 it would wraparound to index 1;
			// set index to 0 and then add
			index = 0;
			index += overflow_val;
		}
		printf("index == %i \n", index);
		friends.erase(friends.begin() + index);
		printf("friends after erase\n");
		for (int x = 0; x < friends.size(); x++)
		{
			printf("%i ", friends[x]);
		}

		// set up recursive call for global variables
		//  recursive call
		return_val = findTheWinner(n, k);

		return return_val;
		// return 0;//placeholder and chekcing fi I can add more function parameters
		//         //ok can't have  too many function parameters
	}
};