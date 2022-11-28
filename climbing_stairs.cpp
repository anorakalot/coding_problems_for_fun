class Solution
{
public:
	int return_val;
	int climbStairs(int n)
	{
		// might not need backtracking soln //if start from n backwards to 0
		// base case
		if (n == 0)
		{
			return_val += 1;
			return 1;
		}
		else if (n < 0)
		{
			return 0;
		}

		climbStairs(n - 1);
		climbStairs(n - 2);

		return return_val;
	}

	// //gonna implement a backtrack like solution
	// void climb_stairs_recur(int n, int curr_num,vector<int> current_steps ,map<vector<int>,int> already_done){

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