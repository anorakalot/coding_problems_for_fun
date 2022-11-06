class Solution
{
public:
	int majorityElement(vector<int> &nums)
	{
		map<int, int> num_of_times;
		vector<int> unique_vals;
		for (int x = 0; x < nums.size(); x++)
		{
			if (num_of_times[nums[x]] == 0)
			{ // if first time seeing in program
				num_of_times[nums[x]] += 1;
				// don't need count func since [] operator auto
				// makes key with value 0
				unique_vals.push_back(nums[x]);
			}
			num_of_times[nums[x]] += 1;
		}
		int max = 0;
		int max_element; // placeholder
		for (int x = 0; x < unique_vals.size(); x++)
		{
			if (num_of_times[unique_vals[x]] > max)
			{
				max = num_of_times[unique_vals[x]];
				max_element = unique_vals[x];
			}
		}
		return max_element;
	}
};
// SECOND
//     map<int,int> num_of_times;
//      vector<int> unique_vals;
//          for (int x = 0; x < nums.size(); x++){
//              if (num_of_times.count(nums[x])== 0){//if first time seeing in program
//                      num_of_times[nums[x]] = 1;
//                      //set int,int of nums[x] to 1
//                      printf("pushing back val %i\n",nums[x]);
//                      unique_vals.push_back(nums[x]);
//              }
//              else if (num_of_times.count(nums[x])>0){//if already in program
//                      num_of_times[nums[x]] += 1;
//                      // add 1 to the value of key nums[x]
//              }

//         }
//         //debug comment out later
//         for (int x= 0; x < unique_vals.size(); x++){
//             printf("unique_vals[x] == %i\n",unique_vals[x]);
//             printf("num_of_times[unique_vals[x]]== %i\n",num_of_times[unique_vals[x]]);

//         }

//         int max = 0;
//         int max_element;//placeholder
//         for (int x = 0; x < unique_vals.size(); x++){
//             if (num_of_times[unique_vals[x]] > max){
//                 max = num_of_times[unique_vals[x]];
//                 max_element = unique_vals[x];
//             }

//         }
//         //return 0; //placeholder
//         return max_element;
//     }

// FIRST
//      map<int,int> num_of_times;

//     for (int x = 0; x < nums.size(); x++){
//         if (num_of_times.count(nums[x])== 0){//if first time seeing in program
//                 num_of_times[nums[x]] = 1;
//                 //set int,int of nums[x] to 1
//         }
//         else if (num_of_times.count(nums[x])>0){//if already in program
//                 num_of_times[nums[x]] += 1;
//                 // add 1 to the value of key nums[x]
//         }

//     }
//     int max = 0;
//     int max_element;//placeholder
//     for (int x = 0; x < nums.size(); x++){
//         if (num_of_times[nums[x]] > max){
//             max = num_of_times[nums[x]];
//             max_element = nums[x];
//         }

//     }
//     //return 0; //placeholder
//     return max_element;
// }