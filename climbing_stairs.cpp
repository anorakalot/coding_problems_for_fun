class Solution
{
public:
	int return_val;
	map<int, int> already_done;
	int climbStairs(int n, int prev_n)
	{
		// might not need backtracking soln //if start from n backwards to 0
		// base case
		if (n == 0)
		{
			return_val += 1;
			if (already_done[prev_n] == 0)
			{
				already_done[prev_n] = return_val;
			}
			return 1;
		}
		else if (n < 0)
		{
			return 0;
		}
		// just use n since prev n is just used for setting already_done map
		if (already_done[n] != 0)
		{
			return_val += already_done[n];
		}
		climbStairs(n - 1, n);
		climbStairs(n - 2, n);
		return return_val;
	}
	// now all that's left is to implement

	// IGNORE BELOW NO LONGER THE APPROACH!!!!
	//  //gonna implement a backtrack like solution
	//  void climb_stairs_recur(int n, int curr_num,vector<int> current_steps ,map<vector<int>,int> already_done){

	//     if (curr_num == n){
	//         if (already_done[current_steps] != 0){
	//             printf("ERROR CURRENT STEPS ALREADY IN ALREADY DONE");
	//         }

	//     }

	//     //for (int x = )
	//     //apply choice
	//     //backtrack
	//     //undo choice
	// }
};