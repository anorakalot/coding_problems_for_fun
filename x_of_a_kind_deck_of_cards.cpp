class Solution
{
public:
	map<int, int> num_of_times_card;
	int partition_num = 0;
	bool two_rem_bool = 0;
	bool three_rem_bool = 0;
	bool hasGroupsSizeX(vector<int> &deck)
	{
		if (deck.size() == 1)
		{
			return 0;
		}

		for (int x = 0; x < deck.size(); x++)
		{
			num_of_times_card[deck[x]] += 1;
		}

		// partition_num = num_of_times_card[deck[0]];
		// if (partition_num %2==0){

		// }
		for (int x = 0; x < deck.size(); x++)
		{
			printf("for deck[x] val of == %i num_of_times_card == %i\n", deck[x], num_of_times_card[deck[x]]);
			if (num_of_times_card[deck[x]] != partition_num && num_of_times_card[deck[x]] % partition_num != 0)
			{
				printf("modulo _val %i\n", num_of_times_card[deck[x]] % partition_num);
				printf("FOUND MAP VAL NOT EQUAL TO REST OF PARTITION NUMBER\n");
				return 0;
			}
		}

		return 1; // placeholder
	}
};